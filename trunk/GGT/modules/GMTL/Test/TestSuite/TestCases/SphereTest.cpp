/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: SphereTest.cpp,v $
 * Date modified: $Date: 2003-09-06 20:22:30 $
 * Version:       $Revision: 1.6 $
 * -----------------------------------------------------------------
 *
 *********************************************************** ggt-head end */
/*************************************************************** ggt-cpr beg
*
* GGT: The Generic Graphics Toolkit
* Copyright (C) 2001, 2002 Allen Bierbaum
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
#include "SphereTest.h"
#include "../Suites.h"
#include <cppunit/extensions/MetricRegistry.h>

#include <gmtl/Sphere.h>
#include <gmtl/SphereOps.h>
#include <gmtl/Containment.h>

#include <gmtl/Intersection.h>
#include <gmtl/LineSeg.h>

namespace gmtlTest
{
   CPPUNIT_TEST_SUITE_REGISTRATION(SphereTest);
   CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SphereMetricTest, Suites::metric());

   void SphereTest::testCreation()
   {
      gmtl::Sphere<float> test_sph;

      CPPUNIT_ASSERT( test_sph.mCenter[0] == 0.0f );
      CPPUNIT_ASSERT( test_sph.mCenter[1] == 0.0f );
      CPPUNIT_ASSERT( test_sph.mCenter[2] == 0.0f );
      CPPUNIT_ASSERT( test_sph.mRadius == 0.0f );
   }

   void SphereMetricTest::testTimingCreation()
   {
      // Test overhead of creation
      const long iters(400000);
      float use_value(0);
      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::Sphere<float> test_sph2;
         use_value = use_value + test_sph2.mRadius + 1.0f;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/SphereCreationOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( use_value > 0.0f );
   }

   void SphereTest::testCopyConstruct()
   {
      gmtl::Sphere<float> test_sph;

      test_sph.mCenter[0] = 2.0f;
      test_sph.mCenter[1] = 4.0f;
      test_sph.mCenter[2] = 8.0f;
      test_sph.mRadius = 25.0f;

      gmtl::Sphere<float> test_sph_copy(test_sph);

      CPPUNIT_ASSERT( test_sph_copy.mCenter[0] == 2.0f);
      CPPUNIT_ASSERT( test_sph_copy.mCenter[1] == 4.0f);
      CPPUNIT_ASSERT( test_sph_copy.mCenter[2] == 8.0f);
      CPPUNIT_ASSERT( test_sph_copy.mRadius == 25.0f);
   }

   void SphereMetricTest::testTimingCopyConstruct()
   {
      // Test copy construction overhead
      const long iters(400000);
      gmtl::Sphere<float> test_sph2;
      test_sph2.mCenter[0] = 2.0f;
      float use_value(0);     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::Sphere<float> test_sph2_copy(test_sph2);
         use_value += test_sph2_copy.mCenter[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/CopyConstructOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testConstructors()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 25.0f );
      CPPUNIT_ASSERT( test_sph.mCenter[0] == 1.0f);
      CPPUNIT_ASSERT( test_sph.mCenter[1] == 2.0f);
      CPPUNIT_ASSERT( test_sph.mCenter[2] == 3.0f);
      CPPUNIT_ASSERT( test_sph.mRadius == 25.0f);
   }

   void SphereMetricTest::testTimingConstructors()
   {
      // Test constructor
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the copiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         gmtl::Sphere<float> test_sph2( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 25.0f );

         use_value = use_value + test_sph2.mCenter[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/ConstructorsOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   // -- Test accessors --//
   void SphereTest::testGetCenter()
   {
      gmtl::Point<float, 3> center( 1.0f, 2.0f, 3.0f );
      gmtl::Sphere<float> test_sph( center, 25.0f );
      CPPUNIT_ASSERT( test_sph.getCenter() == center );
   }

   void SphereMetricTest::testTimingGetCenter()
   {
      gmtl::Point<float, 3> center( 1.0f, 2.0f, 3.0f );
      gmtl::Sphere<float> test_sph( center, 25.0f );

      // Test getCenter overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         center = test_sph.getCenter();
         use_value = use_value + center[0];
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/GetCenterOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testGetRadius()
   {
      float radius = 25.0f;
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), radius );
      CPPUNIT_ASSERT( test_sph.getRadius() == radius );
   }

   void SphereMetricTest::testTimingGetRadius()
   {
      float radius = 25.0f;
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), radius );

      // Test getCenter overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         radius = test_sph.getRadius();
         use_value = use_value + radius;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/GetRadiusOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( use_value > 0.0f );
   }

   // -- Test setters --//
   void SphereTest::testSetCenter()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), 25.0f );
      gmtl::Point<float, 3> center( 2.0f, 4.0f, 1.0f );
      test_sph.setCenter( center );
      CPPUNIT_ASSERT( test_sph.getCenter() == center );
   }

   void SphereMetricTest::testTimingSetCenter()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), 25.0f );
      gmtl::Point<float, 3> center( 2.0f, 4.0f, 1.0f );

      // Test getCenter overhead
      const long iters(400000);

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         center.set( (float)iter, (float)iter, (float)iter );
         test_sph.setCenter( center );
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/SetCenterOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testSetRadius()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), 25.0f );
      test_sph.setRadius( 45.0f );
      CPPUNIT_ASSERT( test_sph.getRadius() == 45.0f );
   }

   void SphereMetricTest::testTimingSetRadius()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>( 1.0f, 2.0f, 3.0f ), 25.0f );
      // Test getCenter overhead
      const long iters(400000);
      float use_value(0.0f);     // A temp just here to use the objs so the compiler (hopefully) does not opt them out

      CPPUNIT_METRIC_START_TIMING();

      for( long iter=0;iter<iters; ++iter)
      {
         test_sph.setRadius( (float)iter );
         use_value = use_value + test_sph.mRadius;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/SetRadiusOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   // -- Test comparison -- //
   void SphereTest::testEqualityCompare()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 4.0f);
      gmtl::Sphere<float> test_sph2(test_sph1);

      CPPUNIT_ASSERT( test_sph1 == test_sph2);
      CPPUNIT_ASSERT(! (test_sph1 != test_sph2));

      test_sph2 = test_sph1;     // Set equal, vary center
      test_sph2.mCenter[0] = 21.10f;
      CPPUNIT_ASSERT( test_sph1 != test_sph2);
      CPPUNIT_ASSERT(! (test_sph1 == test_sph2));

      test_sph2 = test_sph1;     // Set equal, vary radius
      test_sph2.mRadius = 21.10f;
      CPPUNIT_ASSERT( test_sph1 != test_sph2);
      CPPUNIT_ASSERT(! (test_sph1 == test_sph2));
   }

   void SphereMetricTest::testTimingEqualityCompare()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 4.0f);
      gmtl::Sphere<float> test_sph2(test_sph1);

      // Test comparison performance
      // Test constructor
      const float iters(400000);
      unsigned true_count(0);
      unsigned false_count(0);

      // -- Equality
      CPPUNIT_METRIC_START_TIMING();
      test_sph1.mCenter.set( 0.0f, 0.0f, 0.0f );
      test_sph1.mRadius = 2000.0f;
      test_sph2 = test_sph1;
      test_sph2.mRadius = 1000.0f;

      for( float iter=0;iter<iters; ++iter)
      {
         test_sph1.mRadius += 1.0f;
         test_sph2.mRadius += 2.0f;
         if(test_sph1 == test_sph2)
            true_count++;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/EqualityCompareOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      // -- Inequality
      CPPUNIT_METRIC_START_TIMING();
      test_sph1.mCenter.set( 0.0f, 0.0f, 0.0f );
      test_sph1.mRadius = 2000.0f;
      test_sph2 = test_sph1;
      test_sph2.mRadius = 1000.0f;

      for( float iter=0;iter<iters; ++iter)
      {
         test_sph1.mRadius += 1.0f;
         test_sph2.mRadius += 2.0f;
         if(test_sph1 != test_sph2)
            false_count++;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/InequalityCompareOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

   }

   // -- Test comparison -- //
   void SphereTest::testIsEqual()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 4.0f );
      gmtl::Sphere<float> test_sph2(test_sph1);
      float eps(0.0f);

      for(eps=0.0f;eps<10.0f;eps += 0.05f)
      {
         CPPUNIT_ASSERT( gmtl::isEqual(test_sph1, test_sph2, eps) );
      }

      test_sph1.mCenter.set(1.0f, 1.0f, 1.0f);
      test_sph1.mRadius = 1.0f;
      for(unsigned elt=0; elt<4; elt++)
      {
         test_sph2 = test_sph1;     // Set equal, vary elt 0
         if ( elt < 3 ) {
            test_sph2.mCenter[elt] = 21.0f;
         } else {
            test_sph2.mRadius = 21.0f;
         }
         CPPUNIT_ASSERT( !gmtl::isEqual(test_sph1, test_sph2, 10.0f) );
         CPPUNIT_ASSERT( !gmtl::isEqual(test_sph1, test_sph2, 19.9f) );
         CPPUNIT_ASSERT( gmtl::isEqual(test_sph1, test_sph2, 20.1f) );
         CPPUNIT_ASSERT( gmtl::isEqual(test_sph1, test_sph2, 22.0f) );
      }
   }

   void SphereMetricTest::testTimingIsEqual()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(1.0f, 2.0f, 3.0f), 4.0f );
      gmtl::Sphere<float> test_sph2(test_sph1);

      // Test comparison performance
      // Test constructor
      const float iters(400000);
      unsigned true_count(0);

      // -- Equality
      CPPUNIT_METRIC_START_TIMING();
      test_sph1.mCenter.set(0.0f, 0.0f, 0.0f);
      test_sph1.mRadius = 2000.0f;
      test_sph2 = test_sph1;
      test_sph2.mRadius = 1000.0f;

      for( float iter=0;iter<iters; ++iter)
      {
         test_sph1.mRadius += 1.0f;
         test_sph2.mRadius += 2.0f;
         if(gmtl::isEqual(test_sph1, test_sph2, 1.0f) )
            true_count++;
         if(gmtl::isEqual(test_sph1, test_sph2, 0.1f) )
            true_count++;
         if(gmtl::isEqual(test_sph1, test_sph2, 100000.0f) )
            true_count++;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/isEqualOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   //---------------------------------------------------------------------------
   // Containment tests
   //---------------------------------------------------------------------------
   void SphereTest::testIsInVolumePoint()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Point<float, 3> pt( 0.5, 0.5f, 0.5f );
      CPPUNIT_ASSERT( gmtl::isInVolume(test_sph, pt) );
      pt[0] = 5.0f;
      CPPUNIT_ASSERT( ! gmtl::isInVolume(test_sph, pt) );
   }

   void SphereMetricTest::testTimingIsInVolumePoint()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Point<float, 3> pt( 0.5, 0.5f, 0.5f );

      // test isInVolume performace
      const float iters(400000);
      unsigned true_count(0);
      pt.set( 0.0f, 0.0f, 0.0f );

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0;iter<iters; ++iter)
      {
         pt[0] += 0.05f;
         if ( gmtl::isInVolume(test_sph, pt) ) {
            true_count++;
         }
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/isInVolumePointOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testIsInVolumeSphere()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Sphere<float> sph( gmtl::Point<float, 3>(0.5f, 0.5f, 0.5f ), 2.0f);
      CPPUNIT_ASSERT( gmtl::isInVolume(test_sph, sph) );
      sph.mCenter[0] = 5.0f;
      CPPUNIT_ASSERT( ! gmtl::isInVolume(test_sph, sph) );
   }

   void SphereMetricTest::testTimingIsInVolumeSphere()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Sphere<float> sph( gmtl::Point<float, 3>(0.5f, 0.5f, 0.5f ), 2.0f);

      // test isInVolume performace
      const float iters(400000);
      unsigned true_count(0);
      sph.mCenter.set( 0.0f, 0.0f, 0.0f );

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0;iter<iters; ++iter)
      {
         sph.mCenter[0] += 0.05f;
         if ( gmtl::isInVolume(test_sph, sph) ) {
            true_count++;
         }
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/isInVolumeSphereOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testIsOnVolume()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Point<float, 3> pt( 0.0, 0.0f, 4.0f );

      // zero tolerance
      CPPUNIT_ASSERT( gmtl::isOnVolume(test_sph, pt) );
      pt[0] = 1.0f;
      CPPUNIT_ASSERT( ! gmtl::isOnVolume(test_sph, pt) );

      // epsilon tolerance
      pt.set( 0.0f, 0.0f, 4.0f );
      float eps(0.0f);
      for ( eps=0.0f; eps<10.0f; eps+=0.05f )
      {
         CPPUNIT_ASSERT( gmtl::isOnVolume(test_sph, pt, eps) );
      }

      for ( unsigned elt=0; elt<3; ++elt )
      {
         pt.set( 0.0f, 0.0f, 0.0f );
         pt[elt] = 2.0f;
         CPPUNIT_ASSERT( gmtl::isOnVolume(test_sph, pt, 21.0f) );
         CPPUNIT_ASSERT( gmtl::isOnVolume(test_sph, pt, 2.0f) );
         CPPUNIT_ASSERT( ! gmtl::isOnVolume(test_sph, pt, 1.9f) );
         CPPUNIT_ASSERT( ! gmtl::isOnVolume(test_sph, pt, 1.0f) );
      }
   }

   void SphereMetricTest::testTimingIsOnVolume()
   {
      gmtl::Sphere<float> test_sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 4.0f);
      gmtl::Point<float, 3> pt( 0.0, 0.0f, 4.0f );

      // test isOnVolume performance
      const float iters(400000);
      unsigned true_count(0);
      float eps(0.0f);
      pt.set( 0.0f, 0.0f, 0.0f );

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0; iter<iters; ++iter )
      {
         eps += 0.01f;
         pt[2] += 0.1f;
         if ( gmtl::isOnVolume( test_sph, pt, eps ) )
            ++true_count;
         if ( gmtl::isOnVolume( test_sph, pt ) )
            ++true_count;
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/isOnVolumeOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testExtendVolumePoint()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 1.0f );
      gmtl::Point<float, 3> pt1( 2.0f, 0.0f, 0.0f );
      gmtl::Point<float, 3> pt2( pt1 );
      gmtl::Sphere<float> test_sph2;

      for (unsigned elt=0; elt<3; elt++ )
      {
         test_sph2 = test_sph1;
         pt1.set( 0.0f, 0.0f, 0.0f );
         pt1[elt] = 3.0f;
         pt2.set( 0.0f, 0.0f, 0.0f );
         pt2[elt] = 1.0f;
         gmtl::extendVolume( test_sph2, pt1 );
         CPPUNIT_ASSERT( test_sph2.mCenter == pt2 );
         CPPUNIT_ASSERT( test_sph2.mRadius == 2.0f );
      }
   }

   void SphereMetricTest::testTimingExtendVolumePoint()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 1.0f );
      gmtl::Point<float, 3> pt1( 2.0f, 0.0f, 0.0f );

      // test extendVolume performance
      const float iters(400000);
      test_sph1.mCenter.set( 0.0f, 0.0f, 0.0f );
      test_sph1.mRadius = 0.0f;
      pt1.set( 0.0f, 0.0f, 0.0f );

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0; iter<iters; ++iter )
      {
         pt1[0] += 2.0f;
         pt1[1] += 1.0f;
         pt1[2] += 2.5f;
         gmtl::extendVolume( test_sph1, pt1 );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/extendVolumePointOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testExtendVolumeSphere()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 0.0f );
      gmtl::Sphere<float> sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 0.0f );
      gmtl::Point<float, 3> pt1( 0.0f, 0.0f, 0.0f );
      gmtl::Sphere<float> test_sph2;

      for (unsigned elt=0; elt<3; ++elt )
      {
         test_sph2 = test_sph1;
         test_sph2.mCenter.set( 0.0f, 0.0f, 0.0f );
         test_sph2.mRadius = 1.0f;
         sph.mCenter.set( 0.0f, 0.0f, 0.0f );
         sph.mCenter[elt] = 5.0f;
         sph.mRadius = 2.0f;
         pt1.set( 0.0f, 0.0f, 0.0f );
         pt1[elt] = 3.0f;
         gmtl::extendVolume( test_sph2, sph );
         CPPUNIT_ASSERT( test_sph2.mCenter == pt1 );
         CPPUNIT_ASSERT( test_sph2.mRadius == 4.0f );
      }
   }

   void SphereMetricTest::testTimingExtendVolumeSphere()
   {
      gmtl::Sphere<float> test_sph1( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 0.0f );
      gmtl::Sphere<float> sph( gmtl::Point<float, 3>(0.0f, 0.0f, 0.0f), 0.0f );

      // test extendVolume performance
      const float iters(400000);
      test_sph1.mCenter.set( 0.0f, 0.0f, 0.0f );
      test_sph1.mRadius = 0.0f;
      sph.mCenter.set( 0.0f, 0.0f, 0.0f );
      sph.mRadius = 0.0f;

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0; iter<iters; ++iter )
      {
         sph.mCenter[0] += 2.0f;
         sph.mCenter[1] += 1.0f;
         sph.mCenter[2] += 2.5f;
         sph.mRadius += 0.5f;
         gmtl::extendVolume( test_sph1, sph );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/extendVolumeSphereOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void SphereTest::testMakeVolumePoint()
   {
      gmtl::Sphere<float> test_sph;
      std::vector< gmtl::Point<float, 3> > pts;

      pts.push_back( gmtl::Point<float, 3>(1.0f, 0.0f, 0.0f) );
      pts.push_back( gmtl::Point<float, 3>(0.0f, 5.0f, 0.0f) );
      pts.push_back( gmtl::Point<float, 3>(0.0f, 5.0f, 10.0f) );
      pts.push_back( gmtl::Point<float, 3>(0.0f, 5.0f, -10.0f) );

      gmtl::makeVolume( test_sph, pts );

      gmtl::Point<float, 3> pt(0.25f, 3.75f, 0.0f);
      CPPUNIT_ASSERT( gmtl::Math::isEqual( test_sph.mRadius, 10.08f, 0.01f ) );
      CPPUNIT_ASSERT( test_sph.mCenter == pt);
   }

   void SphereMetricTest::testTimingMakeVolumePoint()
   {
      gmtl::Sphere<float> test_sph;
      std::vector< gmtl::Point<float, 3> > pts;

      // test makeVolume performance
      const float iters(2500);
      for ( unsigned i=0; i<100; ++i )
      {
         gmtl::Point<float, 3> pt;
         pt[0] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         pt[1] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         pt[2] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         pts.push_back( pt );
      }

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0; iter<iters; ++iter )
      {
         pts[(int)iter % pts.size()][2] += 12.0f;
         gmtl::makeVolume( test_sph, pts );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/makeVolumePointOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
/*
   void SphereTest::testMakeVolumeSphere()
   {
      gmtl::Sphere<float> test_sph;
      std::vector< gmtl::Sphere<float> > spheres;

      spheres.push_back( gmtl::Sphere<float>( gmtl::Point<float, 3>(7.0f, 0.0f, 0.0f), 1.0f ) );
      spheres.push_back( gmtl::Sphere<float>( gmtl::Point<float, 3>(3.0f, 0.0f, 0.0f), 1.0f ) );
      spheres.push_back( gmtl::Sphere<float>( gmtl::Point<float, 3>(5.0f, 2.0f, 0.0f), 1.0f ) );
      spheres.push_back( gmtl::Sphere<float>( gmtl::Point<float, 3>(5.0f, -2.0f, 0.0f), 1.0f ) );

      gmtl::makeVolume( test_sph, spheres );

      gmtl::Point<float, 3> pt( 5.0f, 0.0f, 0.0f );
      CPPUNIT_ASSERT( test_sph.mRadius == 3.0f );
      CPPUNIT_ASSERT( test_sph.mCenter == pt );

      // test makeVolume performance
      const float iters(400000);
      for ( unsigned i=0; i<1000; ++i )
      {
         gmtl::Point<float, 3> pt;
         pt[0] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         pt[1] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         pt[2] = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );
         float rad = gmtl::Math::rangeRandom( -10000.0f, 10000.0f );

         spheres.push_back( gmtl::Sphere<float>(pt, rad) );
      }

      CPPUNIT_METRIC_START_TIMING();
      for ( float iter=0; iter<iters; ++iter )
      {
         spheres[(int)iter % spheres.size()].mCenter[2] += 32.0f;
         gmtl::makeVolume( test_sph, spheres );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("SphereTest/makeVolumeSphereOverhead", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
*/
   // give the offset of the sphere and ray
   // tests point, ray, and lineseg against sphere intersection
   void SphereTest::testSphereIntersect( float x, float y, float z )
   {
      float t0, t1;
      int hits;

      // Point
      // in
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Point3f point( x, y, z );
         bool result = gmtl::intersect( sphere, point );
         assert( result == true );
      }
      // out
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Point3f point( 1.0001f+x, y, z );
         bool result = gmtl::intersect( sphere, point );
         assert( result == false );
      }
      // on
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Point3f point( x, y, z-1.0f );
         bool result = gmtl::intersect( sphere, point );
         assert( result == true );
      }

      // Ray
      // origin to out
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 1, 0, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 1.0 );
      }
      // interior point to out
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 0.5f+x, y, z ), gmtl::Vec3f( 1, 0, 0 ) );

         float t0, t1;
         int hits;
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.5 );
      }
      // edge to in
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( -1, 0, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 2 );
         assert( t0 == 0.0 );
         assert( t1 == 2.0 );
      }
      // edge to out
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( 1, 0, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.0 );
      }
      // outside through 1 edge (tangent surface)
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 1.0f+x, -1.0f+y, z ), gmtl::Vec3f( 0, 1, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 1.0 );
      }
      // outside through 2 edges
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 0.0f+x, -4.0f+y, 0.0f+z ), gmtl::Vec3f( 0, 1, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 2 );
         assert( t0 == 3.0 );
         assert( t1 == 5.0 );
      }
      // outside to near miss
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( 1.0001f+x, -1.0f+y, z ), gmtl::Vec3f( 0, 1, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // outside to away
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( x, 6.0f+y, z ), gmtl::Vec3f( 0, 1, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // zero length ray inside sphere
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::Rayf ray( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 0, 0, 0 ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
      }
      
      

      

      // LineSeg
      // origin to interior point
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 0.5f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // origin to edge
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 1.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 1.0 );
      }
      // origin to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 4.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.25 );
      }
      // interior point to origin
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 0.5f+x, y, z ), gmtl::Vec3f( -0.5f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // interior point to interior point
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 0.5f+x, y, z ), gmtl::Vec3f( -1.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // interior point to edge
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, 0.5f+y, z ), gmtl::Vec3f( 0.0f, -1.5f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 1.0 );
      }
      // interior point to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y, z+0.5f ), gmtl::Vec3f( 0.0f, 0.0f, -2.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( gmtl::Math::isEqual( t0, 0.75f, 0.0001f ) );
      }
      // edge to origin
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( -1.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.0 );
      }
      // edge to interior point
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( -1.5f, 0.2f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.0 );
      }
      // edge to edge
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( -2.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 2 );
         assert( t0 == 0.0 );
         assert( t1 == 1.0 );
      }
      // edge through edge to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( -4.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 2 );
         assert( t0 == 0.0 );
         assert( t1 == 0.5 );
      }
      // edge to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 1.0f+x, y, z ), gmtl::Vec3f( 45.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.0 );
      }
      // outside to origin
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 2.0f+x, y, z ), gmtl::Vec3f( -2.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.5 );
      }
      // outside to interior point
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, 1.5f+y, z ), gmtl::Vec3f( 0.0f, -2.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.25 );
      }
      // outside to edge
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y, 45.0f+z ), gmtl::Vec3f( 0.0f, 0.0f, -44.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( gmtl::Math::isEqual( t0, 1.0f, 0.00001f ) );
      }
      // outside through 1 edge (tangent surface) to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, -2.0f+y, 1.0f+z ), gmtl::Vec3f( 0.0f, 4.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 1 );
         assert( t0 == 0.5f );
      }
      // outside through 2 edges to outside
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, -2.0f+y, z ), gmtl::Vec3f( 0.0f, 4.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == true );
         assert( hits == 2 );
         assert( t0 == 0.25f );
         assert( t1 == 0.75f );
      }
      // outside to outside near miss
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( x, y-2.0f, z+1.0001f ), gmtl::Vec3f( 0.0f, 4.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }

      // outside to outside away from sphere
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 2.0f+x, y, z ), gmtl::Vec3f( 2.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }

      // outside to outside towards sphere
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf ray( gmtl::Point3f( 3.0f+x, y, z ), gmtl::Vec3f( -1.0f, 0.0f, 0.0f ) );
         bool result = gmtl::intersect( sphere, ray,  hits, t0, t1 );
         assert( result == false );
      }
      // zero length seg inside sphere
      {
         gmtl::Spheref sphere( gmtl::Point3f( x, y, z ), 1 );
         gmtl::LineSegf seg( gmtl::Point3f( x, y, z ), gmtl::Vec3f( 0, 0, 0 ) );
         bool result = gmtl::intersect( sphere, seg,  hits, t0, t1 );
         assert( result == true );
      }
 
   }

   void SphereTest::testSphereIntersections()
   {
      for (float x = -20; x < 20; x+= 0.5f)
      for (float y = -20; y < 20; y+= 1.25f)
      for (float z = -20; z < 20; z+= 0.75f)
         SphereTest::testSphereIntersect( x*10.0f, y*10.0f, z*10.0f );
   }
}
