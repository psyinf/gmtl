/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: VecBaseTest.cpp,v $
 * Date modified: $Date: 2002-03-21 21:32:34 $
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
#include "VecBaseTest.h"
#include <cppunit/extensions/MetricRegistry.h>

#include <gmtl/VecBase.h>

namespace gmtlTest
{
   void VecBaseTest::testVecBaseCreation()
   {
      gmtl::VecBase<double, 3> vec;
      vec[0] = 0.0f; // use the var

      /*
      CPPUNIT_ASSERT( vec[0] == 0.0f);
      CPPUNIT_ASSERT( vec[1] == 0.0f);
      CPPUNIT_ASSERT( vec[2] == 0.0f);
      */
   }

   void VecBaseTest::testTimingVecBaseCreation()
   {
      // Test overhead of creation
      const long iters(400000);
      float use_value(0);
      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::VecBase<float, 2> test_vec2;
         test_vec2[0] = 1.0f;
         gmtl::VecBase<float, 3> test_vec3;
         test_vec3[0] = 2.0f;
         gmtl::VecBase<float, 4> test_vec4;
         test_vec4[0] = 3.0f;

         use_value = use_value + test_vec2[0] + test_vec3[0] + test_vec4[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("VecBaseTest/VecCreationOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( use_value > 0.0f );
   }

   void VecBaseTest::testCopyConstruct()
   {
      gmtl::VecBase<double, 3> test_vec;

      test_vec[0] = 2.0f;
      test_vec[1] = 4.0f;
      test_vec[2] = 8.0f;

      gmtl::VecBase<double, 3> test_vec_copy(test_vec);

      CPPUNIT_ASSERT( test_vec_copy[0] == 2.0f);
      CPPUNIT_ASSERT( test_vec_copy[1] == 4.0f);
      CPPUNIT_ASSERT( test_vec_copy[2] == 8.0f);
   }

   void VecBaseTest::testTimingCopyConstruct()
   {
      // Test copy construction overhead
      const long iters(400000);
      gmtl::VecBase<float, 2> test_vec2;
      test_vec2[0] = 2.0f;
      gmtl::VecBase<float, 3> test_vec3;
      test_vec2[0] = 3.0f;
      gmtl::VecBase<float, 4> test_vec4;
      test_vec2[0] = 4.0f;
      float use_value;     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::VecBase<float, 2> test_vec2_copy(test_vec2);
         use_value += test_vec2_copy[0];
         gmtl::VecBase<float, 3> test_vec3_copy(test_vec3);
         use_value += test_vec3_copy[0];
         gmtl::VecBase<float, 4> test_vec4_copy(test_vec4);
         use_value += test_vec4_copy[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("VecBaseTest/CopyConstructOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }


   void VecBaseTest::testConstructors()
   {
      gmtl::VecBase<float, 4> test_vec4(1.0f, 2.0f, 3.0f, 4.0f);
      CPPUNIT_ASSERT( test_vec4[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec4[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec4[2] == 3.0f);
      CPPUNIT_ASSERT( test_vec4[3] == 4.0f);

      gmtl::VecBase<float, 3> test_vec3(1.0f, 2.0f, 3.0f);
      CPPUNIT_ASSERT( test_vec3[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec3[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec3[2] == 3.0f);

      gmtl::VecBase<float, 2> test_vec2(1.0f, 2.0f);
      CPPUNIT_ASSERT( test_vec2[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec2[1] == 2.0f);

      gmtl::VecBase<float, 1> test_vec1(1.0f);
      CPPUNIT_ASSERT( test_vec1[0] == 1.0f);

   }

   void VecBaseTest::testTimingConstructors()
   {
      // Test constructor
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::VecBase<float, 4> test_vec4(1.0f, 2.0f, 3.0f, 4.0f);
         gmtl::VecBase<float, 3> test_vec3(1.0f, 2.0f, 3.0f);
         gmtl::VecBase<float, 2> test_vec2(1.0f, 2.0f);
         gmtl::VecBase<float, 1> test_vec1(1.0f);

         use_value = use_value + test_vec4[3] + test_vec3[2] + test_vec2[1] + test_vec1[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("VecBaseTest/ConstructorsOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void VecBaseTest::testSet()
   {
      gmtl::VecBase<float, 4> test_vec4;
      test_vec4.set(1.0f, 2.0f, 3.0f, 4.0f);
      CPPUNIT_ASSERT( test_vec4[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec4[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec4[2] == 3.0f);
      CPPUNIT_ASSERT( test_vec4[3] == 4.0f);

      gmtl::VecBase<float, 3> test_vec3;
      test_vec3.set(1.0f, 2.0f, 3.0f);
      CPPUNIT_ASSERT( test_vec3[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec3[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec3[2] == 3.0f);

      gmtl::VecBase<float, 2> test_vec2;
      test_vec2.set(1.0f, 2.0f);
      CPPUNIT_ASSERT( test_vec2[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec2[1] == 2.0f);

      gmtl::VecBase<float, 1> test_vec1;
      test_vec1.set(1.0f);
      CPPUNIT_ASSERT( test_vec1[0] == 1.0f);
   }

   void VecBaseTest::testTimingSet()
   {
      // Test constructor
      gmtl::VecBase<float, 1> test_vec1;
      gmtl::VecBase<float, 2> test_vec2;
      gmtl::VecBase<float, 3> test_vec3;
      gmtl::VecBase<float, 4> test_vec4;
      const float iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( float iter=0;iter<iters; ++iter)
      {
         test_vec4.set(iters+0, iters+1, iters+2, iters+3);
         test_vec3.set(iters+0, iters+1, iters+2);
         test_vec2.set(iters+0, iters+1);
         test_vec1.set(iters+0);

         use_value = use_value + test_vec4[3] + test_vec3[2] + test_vec2[1] + test_vec1[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("VecBaseTest/SetOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( use_value > 0.0f );
   }

   void VecBaseTest::testSetPtr()
   {
      float data[4] = {1.0f, 2.0f, 3.0f, 4.0f};

      gmtl::VecBase<float, 4> test_vec4;
      test_vec4.set(data);
      CPPUNIT_ASSERT( test_vec4[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec4[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec4[2] == 3.0f);
      CPPUNIT_ASSERT( test_vec4[3] == 4.0f);

      gmtl::VecBase<float, 3> test_vec3;
      test_vec3.set(data);
      CPPUNIT_ASSERT( test_vec3[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec3[1] == 2.0f);
      CPPUNIT_ASSERT( test_vec3[2] == 3.0f);

      gmtl::VecBase<float, 2> test_vec2;
      test_vec2.set(data);
      CPPUNIT_ASSERT( test_vec2[0] == 1.0f);
      CPPUNIT_ASSERT( test_vec2[1] == 2.0f);

      gmtl::VecBase<float, 1> test_vec1;
      test_vec1.set(data);
      CPPUNIT_ASSERT( test_vec1[0] == 1.0f);
   }

   void VecBaseTest::testTimingSetPtr()
   {
      float data[4] = {1.0f, 2.0f, 3.0f, 4.0f};
      gmtl::VecBase<float, 1> test_vec1;
      gmtl::VecBase<float, 2> test_vec2;
      gmtl::VecBase<float, 3> test_vec3;
      gmtl::VecBase<float, 4> test_vec4;
      // Test constructor
      const float iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( float iter=0;iter<iters; ++iter)
      {
         data[0] += 1.0f; data[1] += 2.0f; data[2] += 4.0f; data[3] += 8.0f;    // Just make sure data changes
         test_vec4.set(data);
         test_vec3.set(data);
         test_vec2.set(data);
         test_vec1.set(data);

         use_value = use_value + test_vec4[3] + test_vec3[2] + test_vec2[1] + test_vec1[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("VecBaseTest/SetPtrOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( use_value > 0.0f );
   }


   void VecBaseTest::testGetData()
   {
      float* data;
      gmtl::VecBase<float, 4> test_vec4(1.0f, 2.0f, 3.0f, 4.0f);
      data = test_vec4.getData();
      CPPUNIT_ASSERT( data[0] == 1.0f);
      CPPUNIT_ASSERT( data[1] == 2.0f);
      CPPUNIT_ASSERT( data[2] == 3.0f);
      CPPUNIT_ASSERT( data[3] == 4.0f);

      gmtl::VecBase<float, 3> test_vec3(1.0f, 2.0f, 3.0f);
      data = test_vec3.getData();
      CPPUNIT_ASSERT( data[0] == 1.0f);
      CPPUNIT_ASSERT( data[1] == 2.0f);
      CPPUNIT_ASSERT( data[2] == 3.0f);

      gmtl::VecBase<float, 2> test_vec2(1.0f, 2.0f);
      data = test_vec2.getData();
      CPPUNIT_ASSERT( data[0] == 1.0f);
      CPPUNIT_ASSERT( data[1] == 2.0f);
   }
}