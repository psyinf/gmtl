/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: QuatOpsTest.cpp,v $
 * Date modified: $Date: 2003-02-25 05:19:24 $
 * Version:       $Revision: 1.9 $
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
#include "QuatOpsTest.h"
#include "../Suites.h"
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/MetricRegistry.h>

#include <gmtl/Quat.h>
#include <gmtl/QuatOps.h>
#include <gmtl/Generate.h>

namespace gmtlTest
{
   CPPUNIT_TEST_SUITE_REGISTRATION(QuatOpsTest);
   CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(QuatOpsMetricTest, Suites::metric());

   void QuatOpsMetricTest::testQuatTimingNegate()
   {
      gmtl::Quat<float> q4;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::negate( q4 );
         q4[1] += q4[2];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/negate(quat)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingOperatorMinus()
   {
      gmtl::Quat<float> q4;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q4 = -q4;
         q4[1] += q4[2];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/operator-(quat)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingMult()
   {
      gmtl::Quat<float> q2, q4;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::mult( q4, q2, q4 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/mult(q1,q2)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }
   void QuatOpsMetricTest::testQuatTimingOperatorMult()
   {
      gmtl::Quat<float> q2, q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q4 = q2 * q4;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/operator*()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingDiv()
   {
      gmtl::Quat<float> q3, q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::div( q4, q4, q3 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/invert()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingLerp()
   {
      gmtl::Quat<float> from, result;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::lerp( result, ((float)iter) / ((float)iters), from, result );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/lerp()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( result[2] != 1234.5f );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::slerp( result, ((float)iter) / ((float)iters), from, result );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/slerp()", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( result[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingVectorMult()
   {
      gmtl::Quat<float> q3, q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::mult( q4, q3, q4[2] );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/mult(q,scalar)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingVectorAdd()
   {
      gmtl::Quat<float> q3, q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::add( q4, q4, q3 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/add(r,q1,q2)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingVectorSub()
   {
      gmtl::Quat<float> q3, q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::sub( q4, q4, q3 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/sub(r,q1,q2)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingVectorDot()
   {
      gmtl::Quat<float> q1, q2;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q1[2] += gmtl::dot( q1, q2 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/dot(q1,q2)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q1[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingNorm()
   {
      gmtl::Quat<float> q1;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q1[2] += gmtl::lengthSquared( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/lengthSquared(q)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q1[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingMag()
   {
      gmtl::Quat<float> q1;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q1[2] += gmtl::length( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/length(q)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q1[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingNormalize()
   {
      gmtl::Quat<float> q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::normalize( q4 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/normalize(q)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingConj()
   {
      gmtl::Quat<float> q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::conj( q4 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/conj(q)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }

   void QuatOpsMetricTest::testQuatTimingInvert()
   {
      gmtl::Quat<float> q4;
      const long iters(10000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::invert( q4 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("QuatOpsTest/invert(q)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      // Make sure the compiler doesn't optimize out
      CPPUNIT_ASSERT( q4[2] != 1234.5f );
   }





   ///////////////////////////////////////////////
   // real tests...
   ///////////////////////////////////////////////





   void QuatOpsTest::testQuatMult()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 1, 2, 3, 4 ), q4( 5, 6, 7, 8 ), q5, q6;
      gmtl::mult( q5, q3, q4 );
      gmtl::mult( q6, q4, q3 );

      gmtl::Quat<float> expected_result1( 24, 48, 48, -6 ), expected_result2( 32, 32, 56, -6 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q5, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q6, eps ) );

      // operator* should be same
      gmtl::Quat<float> q7, q8;
      q7 = q3 * q4;
      q8 = q4 * q3;
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q7, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q8, eps ) );

      gmtl::Quat<float>  bokbokbok( 9, 10, 11, 12 ), expected_result3( 122, 476, 638, -1296 );
      q6 = q4 * q3 * bokbokbok;
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result3, q6, eps ) );
   }

   void QuatOpsTest::testQuatDiv()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 1, 2, 3, 4 ), q4( 5, 6, 7, 8 ), q5, q6;
      gmtl::div( q5, q3, q4 );
      gmtl::div( q6, q4, q3 );

      gmtl::Quat<float> expected_result1( 0.173913f, 0.347826f, -0.0f, -1.52174f ), expected_result2( 4, 8, 0, 35 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q5, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q6, eps ) );
   }

   void QuatOpsTest::testQuatVectorMult()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 1, 2, 3, 4 ), q5;
      gmtl::mult( q5, q3, 23.0f );

      gmtl::Quat<float> expected_result1( 1 * 23.0f, 2 * 23.0f, 3 * 23.0f, 4 * 23.0f );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q5, eps ) );
   }

   void QuatOpsTest::testQuatVectorAdd()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 1, 2, 3, 4 ), q5, q6( 2, 3, 4, 5 );
      gmtl::add( q5, q3, q6 );

      gmtl::Quat<float> expected_result1( 3, 5, 7, 9 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q5, eps ) );
   }

   void QuatOpsTest::testQuatVectorSub()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 1, 2, 3, 4 ), q5, q6( 2, 3, 4, 5 );
      gmtl::sub( q5, q3, q6 );

      gmtl::Quat<float> expected_result1( -1, -1, -1, -1 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q5, eps ) );
   }

   void QuatOpsTest::testQuatVectorDot()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::dot( gmtl::Quat<float>( 1, 0, 0, 0 ), gmtl::Quat<float>( 1, 0, 0, 0 ) ), 1.0f, eps ) );
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::dot( gmtl::Quat<float>( 1, 0, 0, 0 ), gmtl::Quat<float>( 0, 1, 0, 0 ) ), 0.0f, eps ) );
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::dot( gmtl::Quat<float>( 1, 0, 0, 0 ), gmtl::Quat<float>( 1, 1, 0, 0 ) ), 1.0f, eps ) );
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::dot( gmtl::Quat<float>( 1, 0, 0, 10 ), gmtl::Quat<float>( 1, 0, 0, 223 ) ), 2231.0f, eps ) );
   }

   void QuatOpsTest::testQuatNorm()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q1( 1,1,1,1 );
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::lengthSquared( q1 ), 4.0f, eps ) );
   }

   void QuatOpsTest::testQuatMag()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q1( 1,1,1,1 );
      CPPUNIT_ASSERT( gmtl::Math::isEqual( gmtl::length( q1 ), 2.0f, eps ) );
   }

   void QuatOpsTest::testQuatNormalize()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 0,0,342334,0 ), q5( 342334,-342334,342334,-342334 );
      gmtl::normalize( q3 );
      gmtl::normalize( q5 );

      gmtl::Quat<float> expected_result1( 0, 0, 1, 0 ), expected_result2( 0.5, -0.5, 0.5, -0.5 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q3, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q5, eps ) );

      CPPUNIT_ASSERT( gmtl::isNormalized( expected_result1 ) );
      CPPUNIT_ASSERT( gmtl::isNormalized( expected_result2 ) );
   }

   void QuatOpsTest::testQuatConj()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 0,0,342334,0 ), q5( 342334,-342334,342334,-342334 );
      gmtl::conj( q3 );
      gmtl::conj( q5 );

      gmtl::Quat<float> expected_result1( 0, 0, -342334, 0 ), expected_result2( -342334,342334,-342334,-342334 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q3, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q5, eps ) );
   }

   void QuatOpsTest::testQuatNegate()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q3( 0,0,342334,0 ), q5( 342334,-342334,342334,-342334 );
      gmtl::Quat<float> expected_result1( 0, 0, -342334, 0 ), expected_result2( -342334,342334,-342334,342334 );

      // test operator-
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, -q3, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, -q5, eps ) );

      // test negate(quat)
      gmtl::negate( q3 );
      gmtl::negate( q5 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q3, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q5, eps ) );
   }

   void QuatOpsTest::testQuatInvert()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q( 0.2f, 0.33f, 0.44f, 0.101f ), expected_result( -0.567053f, -0.935637f, -1.24752f, 0.286362f );
      gmtl::Quat<float> q2( q );
      gmtl::Quat<float> q3( gmtl::invert( q2 ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result, q3, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result, q2, eps ) );

      gmtl::Quat<float> q4( gmtl::makeInvert( q ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result, q4, eps ) );
   }

   void QuatOpsTest::testQuatLerp()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q1( 1, 2, 3, 4 ), q2( 9, 8, 7, 6 );
      gmtl::normalize( q1 ); // make sure they are valid rotation quaternions
      gmtl::normalize( q2 );
      gmtl::Quat<float> expected_result1( q1 ), res1;
      gmtl::Quat<float> expected_result2( q2 ), res2;

      gmtl::lerp( res1, 0.0f, q1, q2 );
      gmtl::lerp( res2, 1.0f, q1, q2 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, res1, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, res2, eps ) );

      /// @todo, test interpolated values...
   }

   void QuatOpsTest::testQuatSlerp()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q1( 100, 2, 3, 4 ), q2( 9.01f, 8.4f, 7.1f, 6 );
      gmtl::normalize( q1 ); // make sure they are valid rotation quaternions
      gmtl::normalize( q2 );
      gmtl::Quat<float> expected_result1( q1 ), res1;
      gmtl::Quat<float> expected_result2( q2 ), res2;

      gmtl::slerp( res1, 0.0f, q1, q2 );
      gmtl::slerp( res2, 1.0f, q1, q2 );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, res1, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, res2, eps ) );

      /// test interpolated values...
      gmtl::Vec3f quadrant[8];
      quadrant[0].set(  1.0f,  1.0f,  1.0f );
      quadrant[1].set( -1.0f,  1.0f,  1.0f );
      quadrant[2].set( -1.0f,  1.0f, -1.0f );
      quadrant[3].set(  1.0f,  1.0f, -1.0f );
      quadrant[4].set(  1.0f, -1.0f, -1.0f );
      quadrant[5].set(  1.0f, -1.0f,  1.0f );
      quadrant[6].set( -1.0f, -1.0f,  1.0f );
      quadrant[7].set( -1.0f, -1.0f, -1.0f );

      //gmtl::Quatf expected_result0, expected_result180, expected_result90, expected_result_0001;

      // create one quat for each of the 8 quadrants...
      gmtl::Quatf q0[8], q180[8], q90[8], q_0001[8];
      for (unsigned int x = 0; x < 8; ++x)
      {
         gmtl::normalize( quadrant[x] );
         gmtl::setRot( q0[x],     gmtl::AxisAnglef( gmtl::Math::deg2Rad( 0.0f ),    quadrant[x] ) );
         gmtl::setRot( q180[x],   gmtl::AxisAnglef( gmtl::Math::deg2Rad( 180.0f ),  quadrant[x] ) );
         gmtl::setRot( q90[x],    gmtl::AxisAnglef( gmtl::Math::deg2Rad( 90.0f ),   quadrant[x] ) );
         gmtl::setRot( q_0001[x], gmtl::AxisAnglef( gmtl::Math::deg2Rad( 0.0001f ), quadrant[x] ) );

         /// @todo test these:

         // same yields same
         // gmtl::slerp( result, 0.0f, q0[x], q0[x] ); // yields q0
         // gmtl::slerp( result, 0.5f, q0[x], q0[x] ); // yields q0
         // gmtl::slerp( result, 1.0f, q0[x], q0[x] ); // yields q0

         // 180 deg - there is more than one valid path to take,
         // gmtl::slerp( result, 0.0f, q0[x], q180[x] ); // yields q0
         // gmtl::slerp( result, 0.5f, q0[x], q180[x] ); // not sure what to test here...
         // gmtl::slerp( result, 1.0f, q0[x], q180[x] ); // yields q180

         // 90 deg
         // gmtl::slerp( result, 0.0f, q0[x], q90[x] ); // yields q0
         // gmtl::slerp( result, 0.5f, q0[x], q90[x] ); // yields shortest path
         // gmtl::slerp( result, 1.0f, q0[x], q90[x] ); // yields q90

         // .0001 deg
         // gmtl::slerp( result, 0.0f, q0[x], q_0001[x] ); // yields q0
         // gmtl::slerp( result, 0.5f, q0[x], q_0001[x] ); // yields shortest path (very close to q0 or q_0001)
         // gmtl::slerp( result, 1.0f, q0[x], q_0001[x] ); // yields q_0001
      }

      /// @todo given 8 quadrants, (8 quats), test each quat against every other quat (56 total checks)
      //        note: might have to test with two different angled quats, not sure...
   }

   /** @todo, squad, meantangent, exp, log */

}
