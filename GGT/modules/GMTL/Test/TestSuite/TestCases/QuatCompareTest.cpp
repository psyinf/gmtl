
/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: QuatCompareTest.cpp,v $
 * Date modified: $Date: 2002-03-18 22:48:57 $
 * Version:       $Revision: 1.1 $
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
#include "QuatCompareTest.h"
#include <cppunit/extensions/MetricRegistry.h>

namespace gmtlTest
{
   void QuatCompareTest::testQuatEquiv()
   {
      testEquiv<float>::go();
      testEquiv<double>::go();
   }

   void QuatCompareTest::testQuatEqualityFloatTest()
   {
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
      testEqual<float>::go();
   }

   void QuatCompareTest::testQuatEqualityDoubleTest()
   {
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
      testEqual<double>::go();
   }

   void QuatCompareTest::testQuatTimingOpEqualityTest()
   {
      // Test overhead of creation
      const long iters(400000);

      gmtl::Quat<float> src_quat11;
      gmtl::Quat<float> src_quat22;
      gmtl::Quat<float> src_quat33;
      gmtl::Quat<float> src_quat34;
      gmtl::Quat<float> src_quat44;
      gmtl::Quat<double> src_quat101;

      // half of them will be equal
      src_quat11[0] = 1.0f;
      src_quat22[2] = 1.0f;
      src_quat33[3] = 2.0f;

      gmtl::Quat<float> test_quat11( src_quat11 );
      gmtl::Quat<float> test_quat22( src_quat22 );
      gmtl::Quat<float> test_quat33( src_quat33 );
      gmtl::Quat<float> test_quat34( src_quat34 );
      gmtl::Quat<float> test_quat44( src_quat44 );
      gmtl::Quat<double> test_quat101( src_quat101 );

      // half will be not equal
      src_quat34[0] = 2.0f;
      src_quat44[1] = 3.0f;
      src_quat101[3] = 1.0;

      unsigned true_count(0);

      CPPUNIT_METRIC_START_TIMING();
      for( long iter=0;iter<iters; ++iter)
      {
         if (src_quat11 == test_quat11)
            ++true_count;
         if (src_quat22 == test_quat22)
            ++true_count;
         if (src_quat33 == test_quat33)
            ++true_count;
         if (src_quat34 == test_quat34)
            ++true_count;
         if (src_quat44 == test_quat44)
            ++true_count;
         if (src_quat101 == test_quat101)
            ++true_count;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatCompareTest/operator==", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out true_count
      CPPUNIT_ASSERT( true_count > 0 );
   }

   void QuatCompareTest::testQuatTimingOpNotEqualityTest()
   {
      // Test overhead of creation
      const long iters(400000);

      gmtl::Quat<float> src_quat11;
      gmtl::Quat<float> src_quat22;
      gmtl::Quat<float> src_quat33;
      gmtl::Quat<float> src_quat34;
      gmtl::Quat<float> src_quat44;
      gmtl::Quat<double> src_quat101;

      // half will be equal
      src_quat11[0] = 1.0f;
      src_quat22[2] = 1.0f;
      src_quat33[3] = 2.0f;

      gmtl::Quat<float> test_quat11( src_quat11 );
      gmtl::Quat<float> test_quat22( src_quat22 );
      gmtl::Quat<float> test_quat33( src_quat33 );
      gmtl::Quat<float> test_quat34( src_quat34 );
      gmtl::Quat<float> test_quat44( src_quat44 );
      gmtl::Quat<double> test_quat101( src_quat101 );

      // half will be not equal
      src_quat34[0] = 2.0f;
      src_quat44[1] = 3.0f;
      src_quat101[3] = 1.0f;

      unsigned true_count(0);

      CPPUNIT_METRIC_START_TIMING();
      for( long iter=0;iter<iters; ++iter)
      {
         if (src_quat11 != test_quat11)
            ++true_count;
         if (src_quat22 != test_quat22)
            ++true_count;
         if (src_quat33 != test_quat33)
            ++true_count;
         if (src_quat34 != test_quat34)
            ++true_count;
         if (src_quat44 != test_quat44)
            ++true_count;
         if (src_quat101 != test_quat101)
            ++true_count;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatCompareTest/operator!=", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out true_count
      CPPUNIT_ASSERT( true_count > 0 );
   }

   void QuatCompareTest::testQuatTimingIsEqualTest()
   {
      // Test overhead of creation
      const long iters(400000);

      gmtl::Quat<float> src_quat11;
      gmtl::Quat<float> src_quat22;
      gmtl::Quat<float> src_quat33;
      gmtl::Quat<float> src_quat34;
      gmtl::Quat<float> src_quat44;
      gmtl::Quat<double> src_quat101;

      // half will be equal
      src_quat11[0] = 1.0f;
      src_quat22[1] = 1.0f;
      src_quat33[2] = 2.0f;

      gmtl::Quat<float> test_quat11( src_quat11 );
      gmtl::Quat<float> test_quat22( src_quat22 );
      gmtl::Quat<float> test_quat33( src_quat33 );
      gmtl::Quat<float> test_quat34( src_quat34 );
      gmtl::Quat<float> test_quat44( src_quat44 );
      gmtl::Quat<double> test_quat101( src_quat101 );

      // half will be not equal
      src_quat34[3] = 23.0f;
      src_quat44[2] = 234.0f;
      src_quat101[1] = 1234.0f;

      unsigned true_count(0);

      CPPUNIT_METRIC_START_TIMING();
      for( long iter=0;iter<iters; ++iter)
      {
         if (gmtl::isEqual( src_quat11,  test_quat11, 0.0f ))
            ++true_count;
         if (gmtl::isEqual( src_quat22,  test_quat22, 0.2f ))
            ++true_count;
         if (gmtl::isEqual( src_quat33,  test_quat33, 0.3f ))
            ++true_count;
         if (gmtl::isEqual( src_quat34,  test_quat34, 0.6f ))
            ++true_count;
         if (gmtl::isEqual( src_quat44,  test_quat44, 0.8f ))
            ++true_count;
         if (gmtl::isEqual( src_quat101, test_quat101, 111.1 ))
            ++true_count;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatCompareTest/isEqual(...)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out true_count
      CPPUNIT_ASSERT( true_count > 0 );
   }

   void QuatCompareTest::testQuatTimingEquiv()
   {
      gmtl::Quatf quat1(1.0, 2.0, 34.0, 4.0),
                       quat2(-1.0, -2.0, -34.0, -4.0);

      unsigned true_count(0);
      const long iters(200000);
      CPPUNIT_METRIC_START_TIMING();
      for( long iter=0;iter<iters; ++iter)
      {
         if (gmtl::isEquiv( quat1, quat2, 0.0001f ) )
            ++true_count;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatCompareTest/isEquiv(quat,quat,tol)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out true_count
      CPPUNIT_ASSERT( true_count > 0 );
   }
}
