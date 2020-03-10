//
// Created by jorge on 06/03/2020.
//
#define BOOST_TEST_MODULE RouteMinLengthJorge

#include <boost/test/unit_test.hpp>
#include <route.h>
#include <position.h>

BOOST_AUTO_TEST_SUITE(Route_MinLongitude_N0833029) // The extension with N-number has been given to make sure I can run only my test suite without name clashes

BOOST_AUTO_TEST_CASE( noPointsThrowsException )
{
    BOOST_CHECK_EQUAL(true, true);
}

/* GPS longitude varies between +-180 degrees */
BOOST_AUTO_TEST_CASE( longitudesOver180AreCorrected )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( longitudesUnderMinus180AreCorrected )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( integerOverflowDoesNotBreakFunctionality )
{
    BOOST_CHECK_EQUAL(true, true);
}


BOOST_AUTO_TEST_CASE( minLongitudeWorksWithNormalIntegerValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( minLongitudeWorksWithNormalDecimalValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( minLongitudeWorksWithNegativeIntegerValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( minLongitudeWorksWithNegativeDecimalValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( mixedPositiveAndNegativeIntegerValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( mixedPositiveAndNegativeDecimalValues )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( allPointsSameLongitude )
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( pointsWithoutLongitudeAreNotConsidered )
{
    // Create a bunch of points
    // Add a few points with no longitude
    // Test if the function ignores them and still returns the min point among the points with longitude data
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_CASE( morePositionsThanVectorMaxSizeThrowsLengthException )
{
    // TODO to implement
    // initialise vector of gps::position
    // get the max_size of the vector
    // until we have exceded the max size, we generate and store a new position in a file
    // boost throws: instantiate a new gps::route object, std::length_error
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_SUITE_END()
