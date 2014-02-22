// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2014, Oracle and/or its affiliates.

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle

#include <iostream>

#ifndef BOOST_TEST_MODULE
#define BOOST_TEST_MODULE test_intersection
#endif

#ifdef GEOMETRY_TEST_DEBUG
#define BOOST_GEOMETRY_DEBUG_TRAVERSE
#define BOOST_GEOMETRY_DEBUG_SEGMENT_IDENTIFIER
#endif

#include <boost/test/included/unit_test.hpp>

#include "test_intersection1.hpp"

#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/multi/geometries/multi_linestring.hpp>
#include <boost/geometry/algorithms/intersection.hpp>

typedef bg::model::point<double,2,bg::cs::cartesian>  point_type;
typedef bg::model::segment<point_type>                segment_type;
typedef bg::model::linestring<point_type>             linestring_type;
typedef bg::model::multi_linestring<linestring_type>  multi_linestring_type;



//===========================================================================
//===========================================================================
//===========================================================================


BOOST_AUTO_TEST_CASE( test_intersection_linestring_linestring )
{
#ifdef GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** LINESTRING / LINESTRING INTERSECTION ***" << std::endl;
    std::cout << std::endl;
#endif

    typedef linestring_type L;
    typedef multi_linestring_type ML;

    typedef test_intersection_of_geometries<L, L, ML> tester;

    tester()
        (from_wkt<L>("LINESTRING(0 0,5 0)"),
         from_wkt<L>("LINESTRING(3 0,4 0)"),
         from_wkt<ML>("MULTILINESTRING((3 0,4 0))"),
         "lli01");

    tester()
        (from_wkt<L>("LINESTRING(0 0,4 0)"),
         from_wkt<L>("LINESTRING(3 0,6 0)"),
         from_wkt<ML>("MULTILINESTRING((3 0,4 0))"),
         "lli01-2");

    tester()
        (from_wkt<L>("LINESTRING(0 0,6 0)"),
         from_wkt<L>("LINESTRING(0 0,4 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,4 0))"),
         "lli01-4");

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<L>("LINESTRING(0 0,1 1,2 0,3 1,4 0,5 0,6 1,7 -1,8 0)"),
         from_wkt<ML>("MULTILINESTRING((4 0,5 0))"),
         "lli01-6");

    tester()
        (from_wkt<L>("LINESTRING(-20 0,20 0)"),
         from_wkt<L>("LINESTRING(0 0,1 1,2 0,3 1,4 0,5 0,6 1,7 -1,8 0)"),
         from_wkt<ML>("MULTILINESTRING((4 0,5 0))"),
         "lli01-7");

    tester()
        (from_wkt<L>("LINESTRING(0 0,4 0)"),
         from_wkt<L>("LINESTRING(2 0,4 0)"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0))"),
         "lli01-8");

    tester()
        (from_wkt<L>("LINESTRING(0 0,2 0)"),
         from_wkt<L>("LINESTRING(4 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING()"),
         "lli01-10");

    tester()
        (from_wkt<L>("LINESTRING(0 0,2 0)"),
         from_wkt<L>("LINESTRING(2 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING()"),
         "lli01-11");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,4 0)"),
         from_wkt<L>("LINESTRING(3 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING((3 0,4 0))"),
         "lli01-11a");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,4 0)"),
         from_wkt<L>("LINESTRING(3 0,4 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING((3 0,4 0))"),
         "lli01-11b");

    tester()
        (from_wkt<L>("LINESTRING(0 0,5 0,10 0)"),
         from_wkt<L>("LINESTRING(2 0,6 0,8 0)"),
         from_wkt<ML>("MULTILINESTRING((2 0,5 0,8 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,6 0,8 0))"),
         "lli01-11c");

    tester()
        (from_wkt<L>("LINESTRING(0 0,6 0)"),
         from_wkt<L>("LINESTRING(2 0,4 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING((2 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0,5 0))"),
         "lli01-12");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,5 5,10 5,15 0)"),
         from_wkt<L>("LINESTRING(-1 6,0 5,15 5)"),
         from_wkt<ML>("MULTILINESTRING((5 5,10 5))"),
         "lli02");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0))"),
         "lli03");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,5 5,10 5,15 0,20 0)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0))"),
         "lli04");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,25 1)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0)(15 0,20 0))"),
         "lli05");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,30 0)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,30 0))"),
         "lli05-1");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,31 0)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,30 0))"),
         "lli06");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,31 0)"),
         from_wkt<L>("LINESTRING(-1 0,25 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,25 0,30 0))"),
         "lli07");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,31 0)"),
         from_wkt<L>("LINESTRING(-1 0,19 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,19 0,30 0))"),
         "lli08");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,30 0,31 1)"),
         from_wkt<L>("LINESTRING(-1 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,30 0))"),
         "lli09");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,5 5,10 5,15 0,20 0,30 0,31 1)"),
         from_wkt<L>("LINESTRING(-1 -1,0 0,1 0,2 1,3 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0),(15 0,30 0))"),
         "lli10");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,4 0,5 5,10 5,15 0,20 0,\
                                 30 0,31 1)"),
         from_wkt<L>("LINESTRING(-1 -1,0 0,1 0,2 0,2.5 1,3 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0,2 0),(3 0,4 0),\
                      (15 0,20 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0,2 0),(3 0,4 0),\
                      (15 0,30 0))"),
         "lli11");

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,1 0,4 0,5 5,10 5,15 0,31 0)"),
         from_wkt<L>("LINESTRING(-1 -1,0 0,1 0,2 0,2.5 1,3 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0,2 0),\
                      (3 0,4 0),(15 0,30 0))"),
         "lli11-1");

    tester()
        (from_wkt<L>("LINESTRING(0 0,2 0,3 1)"),
         from_wkt<L>("LINESTRING(0 0,2 0,3 1)"),
         from_wkt<ML>("MULTILINESTRING((0 0,2 0,3 1))"),
         "lli12");

    tester()
        (from_wkt<L>("LINESTRING(0 0,2 0,3 1)"),
         from_wkt<L>("LINESTRING(3 1,2 0,0 0)"),
         from_wkt<ML>("MULTILINESTRING((0 0,2 0,3 1))"),
         from_wkt<ML>("MULTILINESTRING((3 1,2 0,0 0))"),
         "lli12-1");

   tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 1,3 5,4 0)"),
         from_wkt<L>("LINESTRING(1 0,2 1,3 5,4 0,5 10)"),
         from_wkt<ML>("MULTILINESTRING((1 0,2 1,3 5,4 0))"),
         "lli13");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 0,2.5 0,3 1)"),
         from_wkt<L>("LINESTRING(0 0,2 0,2.5 0,3 1)"),
         from_wkt<ML>("MULTILINESTRING((0 0,1 0,2 0,2.5 0,3 1))"),
         from_wkt<ML>("MULTILINESTRING((0 0,2 0,2.5 0,3 1))"),
         "lli14");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 1,3 5,4 0)"),
         from_wkt<L>("LINESTRING(1 0,2 1,3 5)"),
         from_wkt<ML>("MULTILINESTRING((1 0,2 1,3 5))"),
         "lli15");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 1,3 2)"),
         from_wkt<L>("LINESTRING(0.5 0,1 0,3 2,4 5)"),
         from_wkt<ML>("MULTILINESTRING((0.5 0,1 0,2 1,3 2))"),
         from_wkt<ML>("MULTILINESTRING((0.5 0,1 0,3 2))"),
         "lli16");

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 1,3 2)"),
         from_wkt<L>("LINESTRING(4 5,3 2,1 0,0.5 0)"),
         from_wkt<ML>("MULTILINESTRING((0.5 0,1 0,2 1,3 2))"),
         from_wkt<ML>("MULTILINESTRING((0.5 0,1 0,3 2))"),
         "lli16-r");

    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1,30 1)"),
         from_wkt<L>("LINESTRING(1 1,2 0,3 1,20 1,25 1)"),
         from_wkt<ML>("MULTILINESTRING((20 1,25 1))"),
         "lli17");

    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1,21 0,30 0)"),
         from_wkt<L>("LINESTRING(1 1,2 0,3 1,20 1,25 0)"),
         from_wkt<ML>("MULTILINESTRING()"),
         "lli18");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,5 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(5 1,4 0,4 1,20 1,5 0,1 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19-r");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19a");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(4 0,4 1,20 1,5 0,1 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19a-r");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,5 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0),(4 0,5 0))"),
         "lli19b");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,5 0,6 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0),(4 0,5 0))"),
         "lli19c");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,3 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0),(4 0,3 0))"),
         "lli19d");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,3 0,3 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0),(4 0,3 0))"),
         "lli19e");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,4 0,5 0,5 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0),(4 0,5 0))"),
         "lli19f");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(5 1,5 0,4 0,4 1,20 1,5 0,1 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((5 0,4 0),(5 0,1 0))"),
         "lli19f-r");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(1 0,5 0,20 1,4 1,5 0,5 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19g");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<L>("LINESTRING(5 1,5 0,4 1,20 1,5 0,1 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,5 0))"),
         "lli19g-r");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0,30 30,10 30,10 -10,15 0,40 0)"),
         from_wkt<L>("LINESTRING(5 5,10 0,10 30,20 0,25 0,25 25,50 0,35 0)"),
         from_wkt<ML>("MULTILINESTRING((20 0,25 0),(10 30,10 0),\
                      (35 0,40 0),(20 0,25 0))"),
         from_wkt<ML>("MULTILINESTRING((20 0,25 0),(10 0,10 30),\
                                       (40 0,35 0))"),
         "lli20");

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0,30 30,10 30,10 -10,15 0,40 0)"),
         from_wkt<L>("LINESTRING(5 5,10 0,10 30,20 0,25 0,25 25,50 0,15 0)"),
         from_wkt<ML>("MULTILINESTRING((15 0,30 0),(10 30,10 0),\
                      (15 0,40 0))"),
         from_wkt<ML>("MULTILINESTRING((10 0,10 30),(20 0,25 0),(40 0,15 0))"),
         "lli20a");

#if !defined(BOOST_GEOMETRY_DIFFERENCE_DO_NOT_REMOVE_DUPLICATE_TURNS) \
    || defined(GEOMETRY_TEST_INCLUDE_FAILING_TESTS)
    // the following example produces duplicate turns (when the 2nd LS
    // is reversed)
    tester()
        (from_wkt<L>("LINESTRING(0 0,18 0,19 0,30 0)"),
         from_wkt<L>("LINESTRING(2 2,5 -1,15 2,18 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((18 0,19 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((18 0,20 0))"),
         "lli21"
         );
#endif
}




BOOST_AUTO_TEST_CASE( test_intersection_linestring_multilinestring )
{
#ifdef GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** LINESTRING / MULTILINESTRING INTERSECTION ***"
              << std::endl;
    std::cout << std::endl;
#endif

    typedef linestring_type L;
    typedef multi_linestring_type ML;

    typedef test_intersection_of_geometries<L, ML, ML> tester;

    // the inertsection code automatically reverses the order of the
    // geometries according to the geometry IDs.
    // all calls below are actually reversed, and internally the
    // intersection of the linestring with the multi-linestring is
    // computed.

    // disjoint linestrings
    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1)"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 2,4 3),(1 1,2 2,5 3))"),
         from_wkt<ML>("MULTILINESTRING()"),
         "lmli01"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1)"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),(1 1,3 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0))"),
         "lmli02"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1)"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),(1 1,3 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,5 0))"),
         "lmli03"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,10 0,20 1)"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0))"),
         "lmli04"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,101 0))"),
         "lmli07"
        );

    tester()
        (from_wkt<L>("LINESTRING(-1 1,0 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,0 0,50 0),\
                      (19 -1,20 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         "lmli07a"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,0 0,50 0),\
                      (19 -1,20 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         "lmli07b"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,2 0),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,101 0))"),
         "lmli08"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,2 0.5,3 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,2 0.5),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((3 0,101 0))"),
         "lmli09"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,1 0,1.5 0,2 0.5,3 0,101 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,1 0,2 0.5),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,1.5 0),(3 0,101 0))"),
         "lmli10"
        );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                      (1 1,2 0,18 0,19 1),(2 1,3 0,17 0,18 1),\
                      (3 1,4 0,16 0,17 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli12"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0,20 1),\
                      (2 0,18 0,19 1),(3 0,17 0,18 1),\
                      (4 0,16 0,17 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli13"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1,19 1,18 0,2 0,\
                       1 1,2 1,3 0,17 0,18 1,17 1,16 0,4 0,3 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli14"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 2,6 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli15"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (6 0,4 2,2 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli15a"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 2,5 0,6 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli16"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,20 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (6 0,5 0,4 2,2 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli16a"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 0,5 2,20 2,25 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli17"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 0,5 2,20 2,25 0,26 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli17a"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,5 -1,15 2,18 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "lmli18"
         );

    tester()
        (from_wkt<L>("LINESTRING(0 0,18 0,19 0,30 0)"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,5 -1,15 2,18 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,18 0,19 0))"),
         "lmli18a"
         );
}





BOOST_AUTO_TEST_CASE( test_intersection_multilinestring_linestring )
{
#ifdef GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** MULTILINESTRING / LINESTRING INTERSECTION ***"
              << std::endl;
    std::cout << std::endl;
#endif

    typedef linestring_type L;
    typedef multi_linestring_type ML;

    typedef test_intersection_of_geometries<ML, L, ML> tester;

    // the inertsection code automatically reverses the order of the
    // geometries according to the geometry IDs.
    // all calls below are actually reversed, and internally the
    // intersection of the linestring with the multi-linestring is
    // computed.

    // disjoint linestrings
    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<L>("LINESTRING(1 1,2 2,4 3)"),
         from_wkt<ML>("MULTILINESTRING()"),
         "mlli01"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<L>("LINESTRING(1 1,2 0,4 0)"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0))"),
         "mlli02"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<L>("LINESTRING(-1 -1,1 0,101 0,200 -1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,101 0))"),
         "mlli03"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<L>("LINESTRING(0 1,1 0,19 0,20 1,19 1,18 0,2 0,\
                       1 1,2 1,3 0,17 0,18 1,17 1,16 0,4 0,3 1)"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(18 0,2 0),\
                       (3 0,17 0),(16 0,4 0))"),
         "mlli04"
         );
}






BOOST_AUTO_TEST_CASE( test_intersection_multilinestring_multilinestring )
{
#ifdef GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** MULTILINESTRING / MULTILINESTRING INTERSECTION ***"
              << std::endl;
    std::cout << std::endl;
#endif

    typedef multi_linestring_type ML;

    typedef test_intersection_of_geometries<ML, ML, ML> tester;

    // disjoint linestrings
    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 2,4 3),(1 1,2 2,5 3))"),
         from_wkt<ML>("MULTILINESTRING()"),
         "mlmli01"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),(1 1,3 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(2 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(3 0,4 0))"),
         "mlmli02"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),(1 1,3 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,5 0),(2 0,5 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(3 0,5 0))"),
         "mlmli03"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(2 0,4 0))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0))"),
         "mlmli04"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 1),(1 0,7 0),\
                       (10 10,20 10,30 20))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),\
                       (10 20,15 10,25 10,30 15))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(2 0,4 0),(15 10,20 10))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(15 10,20 10))"),
         "mlmli05"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,10 0,20 10),(1 0,7 0),\
                       (10 10,20 10,30 20))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 0,4 0),\
                       (-1 -1,0 0,9 0,11 10,12 10,13 3,14 4,15 5),\
                       (10 20,15 10,25 10,30 15))"),
         from_wkt<ML>("MULTILINESTRING((0 0,9 0),(13 3,15 5),\
                      (1 0,7 0),(11 10,12 10),(15 10,20 10))"),
         from_wkt<ML>("MULTILINESTRING((2 0,4 0),(0 0,9 0),(13 3,14 4,15 5),\
                      (11 10,12 10),(15 10,20 10))"),
         "mlmli06"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,101 0))"),
         "mlmli07"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((-1 1,0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,0 0,50 0),\
                      (19 -1,20 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,50 0),(20 0,101 0))"),
         "mlmli07a"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((-1 -1,0 0,50 0),\
                      (19 -1,20 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((0 0,50 0),(20 0,101 0))"),
         "mlmli07b"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,2 0),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,101 0))"),
         "mlmli08"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,1 0,2 0.5,3 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,2 0.5),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((3 0,101 0))"),
         "mlmli09"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,1 0,1.5 0,2 0.5,3 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 1,1 0,2 0.5),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,1.5 0),(3 0,101 0))"),
         "mlmli10"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,1 1,100 1,101 0),\
                       (0 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,1 1,2 1,3 0,4 0,5 1,6 1,\
                       7 0,8 0,9 1,10 1,11 0,12 0,13 1,14 1,15 0),\
                       (-1 -1,1 0,101 0,200 -1))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 1),(5 1,6 1),(9 1,10 1),\
                       (13 1,14 1),(1 0,101 0))"),
         from_wkt<ML>("MULTILINESTRING((1 1,2 1),(5 1,6 1),(9 1,10 1),\
                       (13 1,14 1),(3 0,4 0),(7 0,8 0),(11 0,12 0),\
                       (1 0,101 0))"),
         "mlmli11"
        );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                      (1 1,2 0,18 0,19 1),(2 1,3 0,17 0,18 1),\
                      (3 1,4 0,16 0,17 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(2 0,18 0),(3 0,17 0),\
                      (4 0,16 0))"),
         "mlmli12"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0,20 1),\
                      (2 0,18 0,19 1),(3 0,17 0,18 1),\
                      (4 0,16 0,17 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(2 0,18 0),(3 0,17 0),\
                      (4 0,16 0))"),
         "mlmli13"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1,19 1,18 0,2 0,\
                       1 1,2 1,3 0,17 0,18 1,17 1,16 0,4 0,3 1))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(18 0,2 0),\
                       (3 0,17 0),(16 0,4 0))"),
         "mlmli14"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 2,6 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli15"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (6 0,4 2,2 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli15a"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 2,5 0,6 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(5 0,6 0))"),
         "mlmli16"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,20 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (6 0,5 0,4 2,2 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0),(6 0,5 0))"),
         "mlmli16a"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 0,5 2,20 2,25 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli17"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,4 0,5 2,20 2,25 0,26 2))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli17a"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,5 -1,15 2,18 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli18"
         );

    tester()
        (from_wkt<ML>("MULTILINESTRING((0 0,18 0,19 0,30 0))"),
         from_wkt<ML>("MULTILINESTRING((0 1,1 0,19 0,20 1),\
                       (2 2,5 -1,15 2,18 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,18 0,19 0))"),
         from_wkt<ML>("MULTILINESTRING((1 0,19 0))"),
         "mlmli18a"
         );
}
