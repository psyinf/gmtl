/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: GenerateTest.cpp,v $
 * Date modified: $Date: 2002-03-19 23:06:49 $
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
* modify it under th MathPrimitives  [PrimName]Ops.h  Vec & Point [100%] -ab
Quat [] -km Transforquations XformInterface? Xform.h   Collision detection CollisionInterface? Intersection.h   Bounding volumes BoundingInterface? Containment.h   Math factories MathFactories Builder.h  e terms of the GNU Lesser General Public
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
#include "GenerateTest.h"
#include <cppunit/extensions/MetricRegistry.h>

namespace gmtlTest
{
   //-- vec tests --//

   void GenerateTest::testMakeVecFromQuat()
   {
      gmtl::Quat<float> quat( 0.0f,21.0f,31.0f,1234.0f );
      gmtl::Vec<float, 3> vec( gmtl::makeVec( quat ) );
      CPPUNIT_ASSERT( vec[0] == 0.0f );
      CPPUNIT_ASSERT( vec[1] == 21.0f );
      CPPUNIT_ASSERT( vec[2] == 31.0f );
   }
   
   void GenerateTest::testMakeNormalVecFromVec()
   {
      {
         const float eps = 0.001f;
         const gmtl::Vec<float, 3> vec( 0.1f, 0.0f, 0.0f ), expected( 1, 0, 0 );
         gmtl::Vec<float, 3> result( gmtl::makeNormal( vec ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected, result, eps ) );
      }
      
      {
         const float eps = 0.001f;
         const gmtl::Vec<float, 3> vec( 0.1f, 128943139.0f, 0.0f ), expected( 0, 1, 0 );
         gmtl::Vec<float, 3> result( gmtl::makeNormal( vec ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected, result, eps ) );
      }
      
      {
         const float eps = 0.001f;
         const gmtl::Vec<float, 3> vec( 0.0f, 0.0f, 0.001f ), expected( 0, 0, 1 );
         gmtl::Vec<float, 3> result( gmtl::makeNormal( vec ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected, result, eps ) );
      }
   }
   
   //-- quat tests --//

   void GenerateTest::testQuatMakePure()
   {
      gmtl::Vec<float, 3> vec( 121, 232, 343 );
      gmtl::Quat<float> quat( gmtl::makePure( vec ) );
      CPPUNIT_ASSERT( quat[gmtl::Xelt] == 121 );
      CPPUNIT_ASSERT( quat[gmtl::Yelt] == 232 );
      CPPUNIT_ASSERT( quat[gmtl::Zelt] == 343 );
   }
   
   void GenerateTest::testQuatMakeConj()
   {
      gmtl::Quat<float> quat( 0.0f,21.0f,31.0f,1234.0f );
      gmtl::Quat<float> quat2 = gmtl::makeConj( quat );
      
      // make sure the func didn't munge the data...
      CPPUNIT_ASSERT( quat[gmtl::Xelt] == 0.0f );
      CPPUNIT_ASSERT( quat[gmtl::Yelt] == 21.0f );
      CPPUNIT_ASSERT( quat[gmtl::Zelt] == 31.0f );
      CPPUNIT_ASSERT( quat[gmtl::Welt] == 1234.0f );
      
      // make sure invert worked.
      CPPUNIT_ASSERT( quat2[gmtl::Xelt] == -0.0f );
      CPPUNIT_ASSERT( quat2[gmtl::Yelt] == -21.0f );
      CPPUNIT_ASSERT( quat2[gmtl::Zelt] == -31.0f );
      CPPUNIT_ASSERT( quat2[gmtl::Welt] == 1234.0f );
   }
   
   void GenerateTest::testQuatMakeInvert()
   {
      // test out mult( result, quat, quat )
      const float eps = 0.0001f;
      gmtl::Quat<float> q( 0.2, 0.33, 0.44, 0.101 ), expected_result( -0.567053, -0.935637, -1.24752, 0.286362 );
      gmtl::Quat<float> q4( gmtl::makeInvert( q ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result, q4, eps ) );
   }
   
   void GenerateTest::testQuatMakeRot()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q1, q2;
      q1 = gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( 90.0f ), 1.0f, 0.0f, 0.0f );
      q2 = gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( 32.0f ), 0.0f, 1.0f, 0.0f );
      gmtl::Quat<float> expected_result1( 0.707107, 0, 0, 0.707107 );
      gmtl::Quat<float> expected_result2( 0, 0.275637, 0, 0.961262 );

      CPPUNIT_ASSERT( gmtl::isEqual( expected_result1, q1, eps ) );
      CPPUNIT_ASSERT( gmtl::isEqual( expected_result2, q2, eps ) );
      CPPUNIT_ASSERT( gmtl::isNormalized( q1, eps ) );
      CPPUNIT_ASSERT( gmtl::isNormalized( q2, eps ) );
      
      // values from VR Juggler math lib...
      std::vector< gmtl::Quat<float> > quats;
      quats.push_back( gmtl::Quat<float>( 0, 0, 0, -1       ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.173648, -0, -0.984808) );
      quats.push_back( gmtl::Quat<float>( -0, -0.34202, -0, -0.939693 ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.5, -0, -0.866025     ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.642788, -0, -0.766044) );
      quats.push_back( gmtl::Quat<float>( -0, -0.766044, -0, -0.642788) );
      quats.push_back( gmtl::Quat<float>( -0, -0.866025, -0, -0.5     ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.939693, -0, -0.34202 ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.984808, -0, -0.173648) );
      quats.push_back( gmtl::Quat<float>( -0, -1, -0, 0    ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.984808, -0, 0.173648 ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.939693, -0, 0.34202  ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.866025, -0, 0.5      ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.766044, -0, 0.642788 ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.642788, -0, 0.766044 ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.5, -0, 0.866025      ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.34202, -0, 0.939693  ) );
      quats.push_back( gmtl::Quat<float>( -0, -0.173648, -0, 0.984808 ) );
      quats.push_back( gmtl::Quat<float>( 0, 0, 0, 1                  ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.173648, 0, 0.984808    ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.34202, 0, 0.939693     ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.5, 0, 0.866025         ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.642788, 0, 0.766044    ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.766044, 0, 0.642788    ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.866025, 0, 0.5         ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.939693, 0, 0.34202     ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.984808, 0, 0.173648    ) );
      quats.push_back( gmtl::Quat<float>( 0, 1, 0, 0       ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.984808, 0, -0.173648   ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.939693, 0, -0.34202    ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.866025, 0, -0.5        ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.766044, 0, -0.642788   ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.642788, 0, -0.766044   ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.5, 0, -0.866025        ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.34202, 0, -0.939693    ) );
      quats.push_back( gmtl::Quat<float>( 0, 0.173648, 0, -0.984808   ) );
      quats.push_back( gmtl::Quat<float>( -0, 0, -0, -1    ) );
      
      /// @todo check this against another math lib other than VR Juggler...
      int count = 0;
      for (int x = -360; x <= 360; x += 20)
      {
         gmtl::Quat<float> q3;
         CPPUNIT_ASSERT( count >= 0 );
         gmtl::setRot( q2, gmtl::Math::deg2Rad( float(x) ), 0.0f, 1.0f, 0.0f );
         gmtl::setRot( q3, gmtl::Math::deg2Rad( float(x) ), gmtl::Vec3f( 0.0f, 1.0f, 0.0f ) );
         CPPUNIT_ASSERT( gmtl::isEqual( quats[count], q2, eps ) );
         CPPUNIT_ASSERT( gmtl::isEqual( q3, q2, eps ) );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( float(x) ), 0.0f, 1.0f, 0.0f ) == q2 );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( float(x) ), gmtl::Vec3f( 0.0f, 1.0f, 0.0f ) ) == q3 );
         count++;
      }
   }

   void GenerateTest::testQuatGetRot()
   {
      const float eps = 0.0001f;
      std::vector<gmtl::Vec4f> quats;
      quats.push_back( gmtl::Vec4f( 6.28319, 2, 0, 0           ) );
      quats.push_back( gmtl::Vec4f( 5.93412, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 5.58505, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 5.23599, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 4.88692, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 4.53786, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 4.18879, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 3.83972, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 3.49066, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 3.14159, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 2.79253, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 2.44346, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 2.0944, -0, -1, -0         ) );
      quats.push_back( gmtl::Vec4f( 1.74533, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 1.39626, -0, -1, -0        ) );
      quats.push_back( gmtl::Vec4f( 1.0472, -0, -1, -0         ) );
      quats.push_back( gmtl::Vec4f( 0.698132, -0, -1, -0       ) );
      quats.push_back( gmtl::Vec4f( 0.349066, -0, -0.999999, -0 ) );
      quats.push_back( gmtl::Vec4f( 0, 0, 0, 0                 ) );
      quats.push_back( gmtl::Vec4f( 0.349066, 0, 0.999999, 0   ) );
      quats.push_back( gmtl::Vec4f( 0.698132, 0, 1, 0          ) );
      quats.push_back( gmtl::Vec4f( 1.0472, 0, 1, 0            ) );
      quats.push_back( gmtl::Vec4f( 1.39626, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 1.74533, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 2.0944, 0, 1, 0            ) );
      quats.push_back( gmtl::Vec4f( 2.44346, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 2.79253, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 3.14159, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 3.49066, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 3.83972, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 4.18879, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 4.53786, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 4.88692, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 5.23599, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 5.58505, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 5.93412, 0, 1, 0           ) );
      quats.push_back( gmtl::Vec4f( 6.28319, 2, 0, 0           ) );
      
      /// @todo check this against another math lib other than VR Juggler...   (all the vals above look sane, but... )
      float a, b, c, fg;
      gmtl::Quat<float> q2;
      int count = 0;
      for (int x = -360; x <= 360; x += 20)
      {
         q2 = gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( float(x) ), 0.0f, 1.0f, 0.0f );
         gmtl::getRot( q2, fg, a, b, c );
         CPPUNIT_ASSERT( gmtl::isEqual( quats[count], gmtl::Vec4f( fg, a, b, c ), eps ) );
         ++count;
      }
   }
   
   void GenerateTest::testQuatMakeGetMakeRot()
   {
      const float eps = 0.0001f;
      gmtl::Quat<float> q2, q3;
      float fg, a, b, c, fg1, a1, b1, c1;
      for (int x = -360; x <= 360; x += 20)
      {
         q2 = gmtl::makeRot<gmtl::Quat<float> >( gmtl::Math::deg2Rad( float(x) ), 0.0f, 1.0f, 0.0f );
         gmtl::getRot( q2, fg, a, b, c );
         q3 = gmtl::makeRot<gmtl::Quat<float> >( fg, a, b, c );
         gmtl::getRot( q3, fg1, a1, b1, c1 );
         CPPUNIT_ASSERT( gmtl::isEqual( q3, q2, eps ) );
         
         CPPUNIT_ASSERT( gmtl::Math::isEqual( fg1, fg, eps ) );
         CPPUNIT_ASSERT( gmtl::Math::isEqual( a1, a, eps ) );
         CPPUNIT_ASSERT( gmtl::Math::isEqual( b1, b, eps ) );
         CPPUNIT_ASSERT( gmtl::Math::isEqual( c1, c, eps ) );
      }
   }

   
   //-- timing tests --//
   
   
   void GenerateTest::testGenTimingMakeNormalVec1()
   {
      gmtl::Vec<double, 4> vec4d;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         vec4d = gmtl::makeNormal( vec4d );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(vec4d)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( vec4d[0] != 10000.0f && vec4d[1] != 10000.0f && vec4d[2] != 10000.0f );
   }
   
   void GenerateTest::testGenTimingMakeNormalVec2()
   {
      gmtl::Vec<float, 4> vec4f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         vec4f = gmtl::makeNormal( vec4f );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(vec4f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( vec4f[0] != 10000.0f && vec4f[1] != 10000.0f && vec4f[2] != 10000.0f );
   }
   void GenerateTest::testGenTimingMakeNormalVec3()
   {
      gmtl::Vec<double, 3> vec3d;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         vec3d = gmtl::makeNormal( vec3d );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(vec3d)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( vec3d[0] != 10000.0f && vec3d[1] != 10000.0f && vec3d[2] != 10000.0f );
   }
   
   void GenerateTest::testGenTimingMakeNormalVec4()
   {
      gmtl::Vec<float, 3> vec3f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         vec3f = gmtl::makeNormal( vec3f );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( vec3f[0] != 10000.0f && vec3f[1] != 10000.0f && vec3f[2] != 10000.0f );
   }
   
   void GenerateTest::testGenTimingMakeInvert1()
   {
      gmtl::Quat<double> q1;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q1 = gmtl::makeInvert( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeInvert(quatd)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( q1[0] != 10000.0f );
   }
   
   void GenerateTest::testGenTimingMakeInvert2()
   {
      gmtl::Quat<float> q2;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q2 = gmtl::makeInvert( q2 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeInvert(quatf)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( q2[0] != 10000.0f );
   }
   
   void GenerateTest::testGenTimingMakeConj()
   {
      gmtl::Quat<double> q1;
      const long iters(50000);
      CPPUNIT_METRIC_START_TIMING();
      
      for (long iter = 0; iter < iters; ++iter)
      {
         q1 = gmtl::makeConj( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeConj(quatd)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q2;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q2 = gmtl::makeConj( q2 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeConj(quatf)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( q2[0] != 10000.0f );
      CPPUNIT_ASSERT( q1[0] != 10000.0f );
   }   
   
   void GenerateTest::testGenTimingMakePure()
   {
      gmtl::Quat<double> q1;
      gmtl::Vec<double, 3> v1;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      
      for (long iter = 0; iter < iters; ++iter)
      {
         q1 = gmtl::makePure( v1 );
         q1[2] -= v1[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makePure(vec3d)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q2;
      gmtl::Vec<float, 3> v2;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q2 = gmtl::makePure( v2 );
         q2[2] += v2[0];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makePure(vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( q2[0] != 10000.0f );
      CPPUNIT_ASSERT( q1[0] != 10000.0f );
   }   
   
   void GenerateTest::testGenTimingMakeVec()
   {
      gmtl::Quat<double> q1;
      gmtl::Vec<double, 3> v1;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      
      for (long iter = 0; iter < iters; ++iter)
      {
         v1 = gmtl::makeVec( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeVec(quatd)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q2;
      gmtl::Vec<float, 3> v2;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         v2 = gmtl::makeVec( q2 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeVec(quatf)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( v2[0] != 10000.0f );
      CPPUNIT_ASSERT( v1[0] != 10000.0f );
   }   
   
   void GenerateTest::testGenTimingMakeNormalQuat()
   {
      gmtl::Quat<double> q1;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      
      for (long iter = 0; iter < iters; ++iter)
      {
         q1 = gmtl::makeNormal( q1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(quatd)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q2;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q2 = gmtl::makeNormal( q2 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeNormal(quatf)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( q2[0] != 10000.0f );
      CPPUNIT_ASSERT( q1[0] != 10000.0f );
   }  
   
   void GenerateTest::testGenTimingMakeRot()
   {
      double bokd = 1;
      float bokf = 1;
      gmtl::Quat<double> q1;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      
      for (long iter = 0; iter < iters; ++iter)
      {
         q1 = gmtl::makeRot<gmtl::Quat<double> >( bokd, bokd, bokd, bokd );
         bokd += q1[2];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatd,d,d,d,d)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q2; bokf = 1.0f;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q2 = gmtl::makeRot<gmtl::Quat<float> >( bokf, bokf, bokf, bokf );
         bokf -= q2[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatf,f,f,f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      
      gmtl::Quat<double> q3; bokd = 1.0f;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q3  = gmtl::makeRot<gmtl::Quat<double> >( bokd, gmtl::makeNormal( gmtl::Vec<double, 3>( bokd, bokd, bokd ) ) );
         bokd *= q3[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatd,d,vecd)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      gmtl::Quat<float> q4; bokf = 1.0f;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q4 = gmtl::makeRot<gmtl::Quat<float> >( bokf, gmtl::makeNormal( gmtl::Vec<float, 3>( bokf, bokf, bokf ) ) );
         bokf += q4[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatf,f,vecf)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      
      
      gmtl::Quat<double> q5;
      gmtl::Vec<double, 3> v4, v5;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q5 = gmtl::makeRot<gmtl::Quat<double> >( v4, v5 );
         v4[2] += q5[1];
         v5[0] -= q5[2];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatd,vec3d,vec3d)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      
      gmtl::Quat<float> q6;
      gmtl::Vec<float, 3> v6, v7;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         q6 = gmtl::makeRot<gmtl::Quat<float> >( v6, v7 );
         v6[2] += q6[1];
         v7[0] -= q6[2];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/makeRot(quatf,vec3f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      float a, b, c, d;
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::getRot( q6, a, b, c, d );
         q6[0] = a + b - c - d;
         a += q6[1];
         b -= q6[2] * -0.22;
         c += q6[1] + 0.1f;
         d -= q6[2] - 0.99;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE( "GenTest/getRot(quatf,f,f,f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      
      // force intelligent compilers to do all the iterations (ie. to not optimize them out), 
      // by using the variables computed...
      CPPUNIT_ASSERT( bokf != 0.998f );
      CPPUNIT_ASSERT( bokd != 0.0998 );
      CPPUNIT_ASSERT( q1[0] != 10000.0f );
      CPPUNIT_ASSERT( q2[1] != 10000.0f );
      CPPUNIT_ASSERT( q3[2] != 10000.0f );
      CPPUNIT_ASSERT( q4[3] != 10000.0f );
      CPPUNIT_ASSERT( q5[0] != 10000.0f );
      CPPUNIT_ASSERT( q6[1] != 10000.0f );
   }
}
