/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: TriTest.h,v $
 * Date modified: $Date: 2002-03-11 18:18:38 $
 * Version:       $Revision: 1.8 $
 * -----------------------------------------------------------------
 *
 *********************************************************** ggt-head end */
/*************************************************************** ggt-cpr beg
*
* GGT: The Generic Graphics Toolkit
* Copyright (C) 2001,2002 Allen Bierbaum
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
 ************************************************************ ggt-cpr end */
#include <gmtl/gmtlConfig.h>
#include <iostream>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include <gmtl/Tri.h>
#include <gmtl/Vec.h>
#include <gmtl/TriOps.h>

namespace gmtlTest
{

class TriTest : public CppUnit::TestCase
{
public:
   TriTest( std::string name = "TriTest")
   : CppUnit::TestCase (name)
   {}

   virtual ~TriTest()
   {}

   virtual void setUp()
   {}

   virtual void tearDown()
   {}

   void testCreation()
   {
      gmtl::Tri<float> test_tri;
      gmtl::Point<float, 3> zero(0,0,0);
      CPPUNIT_ASSERT(test_tri[0] == zero);
      CPPUNIT_ASSERT(test_tri[1] == zero);
      CPPUNIT_ASSERT(test_tri[2] == zero);

      // test overhead of creation
      const long iters(400000);
      CPPUNIT_METRIC_START_TIMING();

      for ( long iter=0; iter<iters; ++iter )
      {
         gmtl::Tri<float> test_tri2;
         test_tri2[0][0] = 1.0f;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/TriCreationOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testCopyConstruct()
   {
      gmtl::Tri<float> test_tri;
      test_tri[0][0] = 2.0f;
      test_tri[1][1] = 4.0f;
      test_tri[2][2] = 1.0f;

      gmtl::Tri<float> test_tri_copy(test_tri);

      CPPUNIT_ASSERT(test_tri_copy[0][0] == 2.0f);
      CPPUNIT_ASSERT(test_tri_copy[1][1] == 4.0f);
      CPPUNIT_ASSERT(test_tri_copy[2][2] == 1.0f);

      // test copy construction overhead
      const long iters(400000);
      gmtl::Tri<float> test_tri2;
      test_tri2[0][0] = 2.0f;
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully does not opt them out

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         gmtl::Tri<float> test_tri2_copy( test_tri2 );
         use_value += test_tri2_copy[0][0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/CopyConstructOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testConstructors()
   {
      gmtl::Tri<float> test_tri(
            gmtl::Point<float, 3>(0,0,0),
            gmtl::Point<float, 3>(1,0,0),
            gmtl::Point<float, 3>(0,1,0)
      );
      gmtl::Point<float, 3> zero(0,0,0);
      gmtl::Point<float, 3> unitX(1,0,0);
      gmtl::Point<float, 3> unitY(0,1,0);
      CPPUNIT_ASSERT(test_tri[0] == zero);
      CPPUNIT_ASSERT(test_tri[1] == unitX);
      CPPUNIT_ASSERT(test_tri[2] == unitY);

      // Test constructor overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully does not opt them out

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         gmtl::Tri<float> test_tri2(
               gmtl::Point<float, 3>( 2.0f, 0.0f, -5.0f ),
               gmtl::Point<float, 3>( 1.0f, 2.0f, -5.0f ),
               gmtl::Point<float, 3>( 1.0f, -2.0f, -5.0f )
         );
         use_value = use_value + test_tri2[0][0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/ConstructorsOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   //---------------------------------------------------------------------------
   // Begin testing accessors
   //---------------------------------------------------------------------------
   void testVertexAccessor()
   {
      gmtl::Point<float, 3> pt0( 2.0f, 0.0f, -5.0f );
      gmtl::Point<float, 3> pt1( 1.0f, 2.0f, -5.0f );
      gmtl::Point<float, 3> pt2( 1.0f, -2.0f, -5.0f );
      gmtl::Tri<float> test_tri( pt0, pt1, pt2 );
      CPPUNIT_ASSERT( test_tri[0] == pt0 );
      CPPUNIT_ASSERT( test_tri[1] == pt1 );
      CPPUNIT_ASSERT( test_tri[2] == pt2 );

      // test operator[] overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully does not opt them out

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         pt0 = test_tri[0];
         use_value = use_value + pt0[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/operator[]Overhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testEdges()
   {
      gmtl::Point<float, 3> p0( 0.0f, 0.0f, 0.0f );
      gmtl::Point<float, 3> p1( 1.0f, 0.0f, 0.0f );
      gmtl::Point<float, 3> p2( 0.0f, 1.0f, 0.0f );
      gmtl::Tri<float> test_tri( p0, p1, p2 );

      gmtl::Vec<float, 3> e0 = p1 - p0;
      gmtl::Vec<float, 3> e1 = p2 - p1;
      gmtl::Vec<float, 3> e2 = p0 - p2;
      CPPUNIT_ASSERT( test_tri.edge(0) == e0 );
      CPPUNIT_ASSERT( test_tri.edge(1) == e1 );
      CPPUNIT_ASSERT( test_tri.edge(2) == e2 );

      // test edge(..) overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully does not opt them out

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         e0 = test_tri.edge( iter % 3 );
         use_value = use_value + e0[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/edgeOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   //---------------------------------------------------------------------------
   // Begin testing comparators
   //---------------------------------------------------------------------------
   void testEqualOps()
   {
      gmtl::Tri<float> test_tri1(
            gmtl::Point<float, 3>(0,0,0),
            gmtl::Point<float, 3>(1,0,0),
            gmtl::Point<float, 3>(0,1,0)
      );
      gmtl::Tri<float> test_tri2( test_tri1 );
      gmtl::Tri<float> test_tri3( test_tri1 );
      test_tri3[0][1] = 2.0f;

      CPPUNIT_ASSERT( test_tri1 == test_tri1 );
      CPPUNIT_ASSERT( !(test_tri1 != test_tri1) );

      CPPUNIT_ASSERT( test_tri1 == test_tri2 );
      CPPUNIT_ASSERT( !(test_tri1 != test_tri2) );
      CPPUNIT_ASSERT( test_tri2 == test_tri1 );
      CPPUNIT_ASSERT( !(test_tri2 != test_tri1) );

      CPPUNIT_ASSERT( !(test_tri1 == test_tri3) );
      CPPUNIT_ASSERT( test_tri1 != test_tri3 );
      CPPUNIT_ASSERT( !(test_tri3 == test_tri1) );
      CPPUNIT_ASSERT( test_tri3 != test_tri1 );

      // test equal ops overhead
      const long iters(400000);
      long true_values(0);

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         if ( test_tri1 == test_tri2 )
            ++true_values;
         if ( test_tri1 != test_tri2 )
            ++true_values;
         if ( test_tri1 == test_tri3 )
            ++true_values;
         if ( test_tri1 != test_tri3 )
            ++true_values;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/EqualOpsOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testIsEqual()
   {
      gmtl::Tri<float> test_tri1(
            gmtl::Point<float, 3>(0,0,0),
            gmtl::Point<float, 3>(2,0,0),
            gmtl::Point<float, 3>(1,2,0)
      );
      gmtl::Tri<float> test_tri2(test_tri1);
      float eps(0.0f);
      for ( eps=0.0f; eps<10.0f; eps+=0.05f )
      {
         CPPUNIT_ASSERT( gmtl::isEqual(test_tri1, test_tri2, eps) );
      }

      for( unsigned p=0; p<3; ++p )
      {
         for( unsigned elt=0; elt<3; ++elt )
         {
            test_tri2 = test_tri1;
            test_tri2[p][elt] += 20.0f;
            CPPUNIT_ASSERT( !gmtl::isEqual(test_tri1, test_tri2, 10.0f) );
            CPPUNIT_ASSERT( !gmtl::isEqual(test_tri1, test_tri2, 19.9f) );
            CPPUNIT_ASSERT( gmtl::isEqual(test_tri1, test_tri2, 20.1f) );
            CPPUNIT_ASSERT( gmtl::isEqual(test_tri1, test_tri2, 22.0f) );
         }
      }

      // test isEqual overhead
      const long iters(400000);
      long true_count(0);

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         test_tri1[0][1] += 0.1f;
         test_tri2[0][1] += 0.2f;
         if(gmtl::isEqual(test_tri1, test_tri2, 1.0f) )
            true_count++;
         if(gmtl::isEqual(test_tri1, test_tri2, 0.1f) )
            true_count++;
         if(gmtl::isEqual(test_tri1, test_tri2, 100000.0f) )
            true_count++;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/IsEqualOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testCenter()
   {
      gmtl::Tri<float> test_tri(
            gmtl::Point<float, 3>(0,0,0),
            gmtl::Point<float, 3>(4,0,0),
            gmtl::Point<float, 3>(2,4,0)
      );
      gmtl::Vec<float, 3> center = gmtl::center(test_tri);
      gmtl::Vec<float, 3> correctCenter(2,(4.0f/3.0f),0);
      CPPUNIT_ASSERT( center == correctCenter );

      // test center overhead
      const long iters(400000);
      float use_value(0.0f);

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         test_tri[1][1] += 2.0f;
         center = gmtl::center(test_tri);
         use_value = use_value + center[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/CenterOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   void testNormal()
   {
      gmtl::Tri<float> test_tri(
            gmtl::Point<float, 3>(0,0,0),
            gmtl::Point<float, 3>(4,0,0),
            gmtl::Point<float, 3>(2,4,0)
      );
      gmtl::Vec<float, 3> normal = gmtl::normal(test_tri);
      gmtl::Vec<float, 3> correctNormal(0,0,1);
      CPPUNIT_ASSERT( normal == correctNormal );

      // test normal overhead
      const long iters(400000);
      float use_value(0.0f);

      CPPUNIT_METRIC_START_TIMING();
      for ( long iter=0; iter<iters; ++iter )
      {
         test_tri[1][1] += 2.0f;
         normal = gmtl::normal(test_tri);
         use_value = use_value + normal[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("TriTest/NormalOverhead", iters, 0.075f, 0.1f); // warn at 7.5%, error at 10%
   }

   static CppUnit::Test* suite()
   {
      CppUnit::TestSuite* test_suite = new CppUnit::TestSuite ("TriTest");
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testCreation", &TriTest::testCreation));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testCopyConstruct", &TriTest::testCopyConstruct));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testConstructors", &TriTest::testConstructors));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testVertexAccessor", &TriTest::testVertexAccessor));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testEdges", &TriTest::testEdges));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testEqualOps", &TriTest::testEqualOps));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testIsEqual", &TriTest::testIsEqual));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testCenter", &TriTest::testCenter));
      test_suite->addTest( new CppUnit::TestCaller<TriTest>("testNormal", &TriTest::testNormal));
      return test_suite;
   }

   static CppUnit::Test* interactiveSuite()
   {
      CppUnit::TestSuite* test_suite = new CppUnit::TestSuite ("InteractiveTriTest");
      //test_suite->addTest( new CppUnit::TestCaller<ThreadTest>("interactiveCPUGrind", &ThreadTest::interactiveTestCPUGrind));
      return test_suite;
   }
};

} // namespace gmtlTest
