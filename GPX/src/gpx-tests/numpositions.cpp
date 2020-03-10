#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

/* The main complication of the Route.numPositions() function is that it should report
 * the number of Positions *after* any Positions that are closer to another point than
 * 'granularity' have been dropped.
 *
 * The test suite starts by testing some basic cases where no points are dropped.
 * First the minimal edge case: a route containing a single point.  Then a small
 * typical route is tested.
 * 
 * Next the dropping behaviour is tested, considering cases where some/all of the
 * points are within 'granularity' of each other, and then the corner case when a
 * point is only within 'granularity' of a previously dropped point.
 * 
 * Finally, the boundary cases where points are very close to the 'granularity'
 * distance apart are tested.
 */

BOOST_AUTO_TEST_SUITE( Route_numPositions )

const bool isFileName = true; // All GPX data in this suite is loaded from files.
const metres horizontalGridUnit = 100000;

// The shortest possible route (a single point).
BOOST_AUTO_TEST_CASE( singleton_route )
{
   Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx", isFileName);
   BOOST_CHECK_EQUAL( route.numPositions(), 1 );
}

// All route points are more than 'granularity' apart.
BOOST_AUTO_TEST_CASE( noPointsTooClose )
{
   const metres granularity = horizontalGridUnit / 10;
   Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName, granularity);
   // A line of 5 points, equally spaced one grid unit apart.

   BOOST_CHECK_EQUAL( route.numPositions(), 5 );
}

// All route points are within 'granularity' of each other.
BOOST_AUTO_TEST_CASE( allPositionsTooClose )
{
    const metres granularity = horizontalGridUnit * 5;
    Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName, granularity);
    // A line of 5 points, equally spaced one grid unit apart.

    BOOST_CHECK_EQUAL( route.numPositions(), 1 ); // All except A discarded
}

// Some, but not, all route points are more than 'granularity' apart.
BOOST_AUTO_TEST_CASE( somePositionsTooClose )
{
   const metres granularity = horizontalGridUnit * 1.5;
   Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName, granularity);
   // A 5-point route, A&B are close, and Q&W are close.

   BOOST_CHECK_EQUAL( route.numPositions(), 3 ); // B and W discarded
}

// All route points have a neighbour closer than 'granularity', but not all points are
// within 'granularity' of each other.
BOOST_AUTO_TEST_CASE( allPositionsHaveTooCloseNeighbours )
{
    const metres granularity = horizontalGridUnit * 1.5;
    Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName, granularity);
    // A line of 5 points, equally spaced one grid unit apart.

    BOOST_CHECK_EQUAL( route.numPositions(), 3 ); // F and P discarded
}

// Adjacent route points are slightly more than 'granularity' apart.
BOOST_AUTO_TEST_CASE( allPositionsJustBeyondGranularity )
{
   const metres granularity = horizontalGridUnit * 0.99;
   Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName, granularity);
   // A line of 5 points, equally spaced one grid unit apart.

   BOOST_CHECK_EQUAL( route.numPositions(), 5 );
}

// Adjacent route points are slightly less than 'granularity' apart.
BOOST_AUTO_TEST_CASE( allPositionsJustWithinGranularity )
{
   const metres granularity = horizontalGridUnit * 1.01;
   Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName, granularity);
   // A line of 5 points, equally spaced one grid unit apart.

   BOOST_CHECK_EQUAL( route.numPositions(), 3 ); // F and P discarded
}

BOOST_AUTO_TEST_SUITE_END()
