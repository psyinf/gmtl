/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: QuatClassTest.h,v $
 * Date modified: $Date: 2002-02-22 19:45:18 $
 * Version:       $Revision: 1.2 $
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
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include <gmtl/gmtlConfig.h>
#include <gmtl/Quat.h>

namespace gmtlTest
{

   class QuatClassTest : public CppUnit::TestCase
   {
   public:
      QuatClassTest( std::string name = "QuatClassTest" )
         : CppUnit::TestCase( name )
      {
      }

      virtual ~QuatClassTest()
      {}

      virtual void setUp()
      {
      }

      virtual void tearDown()
      {
      }

      void testQuatClassTestCreation()
      {
         // test that it initializes to the multiplication identity
         gmtl::Quatf q;
         CPPUNIT_ASSERT( q[gmtl::Xelt] == 0.0f );
         CPPUNIT_ASSERT( q[gmtl::Yelt] == 0.0f );
         CPPUNIT_ASSERT( q[gmtl::Zelt] == 0.0f );
         CPPUNIT_ASSERT( q[gmtl::Welt] == 1.0f );
         
         // try out get...
         float x = 102, y = 103, z = 101, w = 100;
         q.get( x, y, z, w );
         CPPUNIT_ASSERT( x == 0.0f );
         CPPUNIT_ASSERT( y == 0.0f );
         CPPUNIT_ASSERT( z == 0.0f );
         CPPUNIT_ASSERT( w == 1.0f );

         // try out set...
         q.set( 1, 2, 3, 4 );
         CPPUNIT_ASSERT( q[gmtl::Xelt] == 1.0f );
         CPPUNIT_ASSERT( q[gmtl::Yelt] == 2.0f );
         CPPUNIT_ASSERT( q[gmtl::Zelt] == 3.0f );
         CPPUNIT_ASSERT( q[gmtl::Welt] == 4.0f );

         // try out setting with brackets
         q[gmtl::Xelt] = 5;
         q[gmtl::Yelt] = 6;
         q[gmtl::Zelt] = 7;
         q[gmtl::Welt] = 8;
         CPPUNIT_ASSERT( q[gmtl::Xelt] == 5.0f );
         CPPUNIT_ASSERT( q[gmtl::Yelt] == 6.0f );
         CPPUNIT_ASSERT( q[gmtl::Zelt] == 7.0f );
         CPPUNIT_ASSERT( q[gmtl::Welt] == 8.0f );
         q.get( x, y, z, w );
         CPPUNIT_ASSERT( x == 5.0f );
         CPPUNIT_ASSERT( y == 6.0f );
         CPPUNIT_ASSERT( z == 7.0f );
         CPPUNIT_ASSERT( w == 8.0f );

         // try out element constructor
         gmtl::Quatf q2( 10, 11, 12, 13 );
         CPPUNIT_ASSERT( q2[gmtl::Xelt] == 10.0f );
         CPPUNIT_ASSERT( q2[gmtl::Yelt] == 11.0f );
         CPPUNIT_ASSERT( q2[gmtl::Zelt] == 12.0f );
         CPPUNIT_ASSERT( q2[gmtl::Welt] == 13.0f );

         // try out copy constructor
         gmtl::Quatf q3( q );
         CPPUNIT_ASSERT( q3[gmtl::Xelt] == 5.0f );
         CPPUNIT_ASSERT( q3[gmtl::Yelt] == 6.0f );
         CPPUNIT_ASSERT( q3[gmtl::Zelt] == 7.0f );
         CPPUNIT_ASSERT( q3[gmtl::Welt] == 8.0f );
         
         // try out operator=() function
         gmtl::Quatf q4;
         CPPUNIT_ASSERT( q4[gmtl::Xelt] == 0.0f );
         CPPUNIT_ASSERT( q4[gmtl::Yelt] == 0.0f );
         CPPUNIT_ASSERT( q4[gmtl::Zelt] == 0.0f );
         CPPUNIT_ASSERT( q4[gmtl::Welt] == 1.0f );
         q4 = q2;
         CPPUNIT_ASSERT( q4[gmtl::Xelt] == 10.0f );
         CPPUNIT_ASSERT( q4[gmtl::Yelt] == 11.0f );
         CPPUNIT_ASSERT( q4[gmtl::Zelt] == 12.0f );
         CPPUNIT_ASSERT( q4[gmtl::Welt] == 13.0f );
         
         // check out the const identities...
         gmtl::Quatf q9( gmtl::QUAT_IDENTITYF );
         CPPUNIT_ASSERT( q9[gmtl::Xelt] == 0.0f );
         CPPUNIT_ASSERT( q9[gmtl::Yelt] == 0.0f );
         CPPUNIT_ASSERT( q9[gmtl::Zelt] == 0.0f );
         CPPUNIT_ASSERT( q9[gmtl::Welt] == 1.0f );
         
         gmtl::Quatf q10( gmtl::QUAT_MULT_IDENTITYF );
         CPPUNIT_ASSERT( q10[gmtl::Xelt] == 0.0f );
         CPPUNIT_ASSERT( q10[gmtl::Yelt] == 0.0f );
         CPPUNIT_ASSERT( q10[gmtl::Zelt] == 0.0f );
         CPPUNIT_ASSERT( q10[gmtl::Welt] == 1.0f );
         
         gmtl::Quatf q11( gmtl::QUAT_ADD_IDENTITYF );
         CPPUNIT_ASSERT( q11[gmtl::Xelt] == 0.0f );
         CPPUNIT_ASSERT( q11[gmtl::Yelt] == 0.0f );
         CPPUNIT_ASSERT( q11[gmtl::Zelt] == 0.0f );
         CPPUNIT_ASSERT( q11[gmtl::Welt] == 0.0f );
      }
      
      void testQuatTimingDefaultConstructor()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of def constructor
            gmtl::Quatf q;
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/DefaultConstructor", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }
   
      void testQuatTimingElementConstructor()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of element constructor
            gmtl::Quatf q2( 10, 11, 12, 13 );
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/ElementConstructor", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }

      void testQuatTimingCopyConstructor()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q( 67, 68, 69, 60 );
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of copy constructor
            gmtl::Quatf q3( q );
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/CopyConstructor", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }
   
         
      void testQuatTimingGet()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q;
         float x = 102, y = 103, z = 101, w = 100;
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of get...
            q.get( x, y, z, w );
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/get()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }

      void testQuatTimingSet()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q;
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of set...
            q.set( 1, 2, 3, 4 );
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/set()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }

      void testQuatTimingOpBracket()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q;
         float x = 102, y = 103, z = 101, w = 100;
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of brackets
            q[gmtl::Xelt] = x;
            q[gmtl::Yelt] = y;
            q[gmtl::Zelt] = z;
            q[gmtl::Welt] = w;
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/operator[]()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }
  
      void testQuatTimingGetData()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q;
         float w = 100;
         float* d = NULL;
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of getData...
            const float* d = q.getData();
            w = d[3];
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/getData()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }

      void testQuatTimingOpEqual()
      {
         const long iters( 400000 );
         CPPUNIT_METRIC_START_TIMING();
         gmtl::Quatf q4, q2( 0, 2, 1, 3 );
         for (long iter = 0; iter < iters; ++iter)
         {
            // performance of operator=() function
            q4 = q2;
         }
         CPPUNIT_METRIC_STOP_TIMING();
         CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatTest/operator=()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      }

      static CppUnit::Test* suite()
      {
         CppUnit::TestSuite* test_suite = new CppUnit::TestSuite ("QuatClassTest");
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingDefaultConstructor", &QuatClassTest::testQuatTimingDefaultConstructor));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingElementConstructor", &QuatClassTest::testQuatTimingElementConstructor));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingCopyConstructor", &QuatClassTest::testQuatTimingCopyConstructor));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingGet", &QuatClassTest::testQuatTimingGet));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingSet", &QuatClassTest::testQuatTimingSet));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingOpBracket", &QuatClassTest::testQuatTimingOpBracket));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingGetData", &QuatClassTest::testQuatTimingGetData));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatTimingOpEqual", &QuatClassTest::testQuatTimingOpEqual));
         test_suite->addTest( new CppUnit::TestCaller<QuatClassTest>("testQuatClassTestCreation", &QuatClassTest::testQuatClassTestCreation));
         return test_suite;
      }

      static CppUnit::Test* interactiveSuite()
      {
         CppUnit::TestSuite* test_suite = new CppUnit::TestSuite ("InteractiveQuatClassTest");
         //test_suite->addTest( new CppUnit::TestCaller<ThreadTest>("interactiveCPUGrind", &ThreadTest::interactiveTestCPUGrind));
         return test_suite;
      }

   protected:

   };

} // end namespace
