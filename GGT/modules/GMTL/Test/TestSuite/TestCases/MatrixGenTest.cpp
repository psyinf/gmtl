/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: MatrixGenTest.cpp,v $
 * Date modified: $Date: 2002-03-20 07:11:22 $
 * Version:       $Revision: 1.4 $
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
#include "MatrixGenTest.h"
#include <cppunit/extensions/MetricRegistry.h>
#include <gmtl/MatrixOps.h>
#include <gmtl/Generate.h>

namespace gmtlTest
{

   void MatrixGenTest::testMatrixsetTrans()
   {
      float eps = 0.001f;
      // 2D rot/trans
      {
         gmtl::Matrix<float, 2, 3> mat23, expected_result23;
         gmtl::Vec2f trans_vec( 32, 33 );
         expected_result23.set( 1, 0, 32,
                                0, 1, 33 );
         gmtl::setTrans( mat23, trans_vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result23, mat23, eps ) );
         CPPUNIT_ASSERT( gmtl::getTrans<gmtl::Vec2f>(mat23) == trans_vec );

         // make sure that make and set return the same...
         CPPUNIT_ASSERT( expected_result23 == gmtl::makeTrans<gmtl::Matrix23f>( gmtl::Vec2f( 32, 33 ) ) );
      }
      // 2D rot/trans/skew
      {
         gmtl::Matrix33f mat33, expected_result33;
         gmtl::Vec2f trans_vec( 32, 33 );
         expected_result33.set( 1, 0, 32,
                                0, 1, 33,
                                0, 0, 1 );
         gmtl::setTrans( mat33, trans_vec);
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );
         CPPUNIT_ASSERT( gmtl::getTrans<gmtl::Vec2f>(mat33) == trans_vec);

         // make sure that make and set return the same...
         CPPUNIT_ASSERT( expected_result33 == gmtl::makeTrans<gmtl::Matrix33f>( gmtl::Vec2f( 32, 33 ) ) );
      }
      // 2D rot/trans/skew set by homogeneous vector
      {
         gmtl::Matrix33f mat33, expected_result33;
         gmtl::Vec3f trans_vec( 32, 33, 0.5f );
         expected_result33.set( 1, 0, 64,
                                0, 1, 66,
                                0, 0, 1 );
         gmtl::setTrans( mat33, trans_vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );
         CPPUNIT_ASSERT( gmtl::getTrans<gmtl::Vec3f>(mat33) == gmtl::Vec3f(64.0f, 66.0f, 1.0f) );
      }
      // 3D rot/trans
      {
         gmtl::Matrix34f mat34, expected_result34;
         gmtl::Vec3f trans_vec( 32, 33, 34 );
         expected_result34.set( 1, 0, 0, 32,
                                0, 1, 0, 33,
                                0, 0, 1, 34 );
         gmtl::setTrans( mat34, trans_vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat34, eps ) );
         CPPUNIT_ASSERT( gmtl::getTrans<gmtl::Vec3f>(mat34) == trans_vec );
      }
      // 3D rot/trans set by homogeneous vector
      {
         gmtl::Matrix34f mat34, expected_result34;
         gmtl::Vec4f trans_vec( 32, 33, 34, 0.5f );
         expected_result34.set( 1, 0, 0, 64,
                                0, 1, 0, 66,
                                0, 0, 1, 68 );
         gmtl::setTrans( mat34, trans_vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat34, eps ) );
         CPPUNIT_ASSERT( gmtl::getTrans<gmtl::Vec3f>(mat34) == gmtl::Vec3f(64.0f, 66.0f, 68.0f) );
      }
      // 3D rot/trans/skew
      {
         gmtl::Matrix44f mat44, expected_result44;
         expected_result44.set( 1, 0, 0, 32,
                                0, 1, 0, 33,
                                0, 0, 1, 34,
                                0, 0, 0, 1  );
         gmtl::setTrans( mat44, gmtl::Vec3f( 32, 33, 34 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );
      }
      // 3D rot/trans/skew set by homogeneous vector...
      {
         gmtl::Matrix44f mat44, expected_result44;
         expected_result44.set( 1, 0, 0, 64,
                                0, 1, 0, 66,
                                0, 0, 1, 68,
                                0, 0, 0, 1  );
         gmtl::setTrans( mat44, gmtl::Vec4f( 32, 33, 34, 0.5f ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );
      }

      // --- Test standalone makeTrans(trans) against setTrans(mat,trans) -- //
      {
         gmtl::Matrix44f expected_mat;
         gmtl::Vec3f trans3(1.0, 2.0, 3.0f);
         gmtl::setTrans(expected_mat, trans3);
         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeTrans<gmtl::Matrix44f>(trans3),
                                        expected_mat, eps ) );

      }
   }

   void MatrixGenTest::testMatrixsetAxes()
   {
      const float eps = 0.001f;
      const float a = 98234576.0f;
      {
         gmtl::Matrix33f mat33, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat33[x] = a;
         expected_result33.set( 0, 1, 0,
                                1, 0, 0,
                                0, 0, -1  );
         gmtl::setAxes( mat33, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );
         CPPUNIT_ASSERT( gmtl::makeAxes<gmtl::Matrix33f>( gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) ) == mat33 );
      }
      {
         gmtl::Matrix44f mat44, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat44[x] = a;
         expected_result44.set( 0, 1, 0, a,
                                1, 0, 0, a,
                                0, 0, -1, a,
                                a, a, a, a  );
         gmtl::setAxes( mat44, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setAxes( new_mat, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::makeAxes<gmtl::Matrix44f>( gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) ) == new_mat );
      }
   }

   void MatrixGenTest::testMatrixsetDirCos()
   {
      const float eps = 0.001f;
      const float a = 98234576.0f;
      {
         gmtl::Matrix33f mat33, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat33[x] = a;
         expected_result33.set( 0, 1, 0,
                                1, 0, 0,
                                0, 0, -1  );
         gmtl::setDirCos( mat33, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );
         CPPUNIT_ASSERT( gmtl::makeDirCos<gmtl::Matrix33f>( gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) ) == mat33 );
      }
      {
         gmtl::Matrix44f mat44, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat44[x] = a;
         expected_result44.set( 0, 1, 0, a,
                                1, 0, 0, a,
                                0, 0, -1, a,
                                a, a, a, a  );
         gmtl::setDirCos( mat44, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setDirCos( new_mat, gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) );
         CPPUNIT_ASSERT( gmtl::makeDirCos<gmtl::Matrix44f>( gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,0,-1 ) ) == new_mat );
      }
   }


   void MatrixGenTest::testMatrixsetScale()
   {
      const float eps = 0.001f;
      const float a = 98234576.0f;
      // 2D rot/trans
      {
         gmtl::Matrix<float, 2, 3> mat23, expected_result23;
         for (int x = 0; x < 6; ++x)
            mat23[x] = a;
         expected_result23.set( 32, a, a,
                                a, 33, a );
         gmtl::setScale( mat23, gmtl::Vec2f( 32, 33 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result23, mat23, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix23f new_mat;
         gmtl::setScale( new_mat, gmtl::Vec2f( 32, 33 ) );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix23f >( gmtl::Vec2f( 32, 33 ) ) == new_mat );
      }
      // 2D rot/trans/skew
      {
         gmtl::Matrix33f mat33, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat33[x] = a;
         expected_result33.set( 32, a, a,
                                a, 33, a,
                                a, a, a );
         gmtl::setScale( mat33, gmtl::Vec2f( 32, 33 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix33f new_mat;
         gmtl::setScale( new_mat, gmtl::Vec2f( 32, 33 ) );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix33f >( gmtl::Vec2f( 32, 33 ) ) == new_mat );
      }
      // 3D rot/trans
      {
         gmtl::Matrix34f mat34, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat34[x] = a;
         expected_result34.set( 32, a, a, a,
                                a, 33, a, a,
                                a, a, 34, a );
         gmtl::setScale( mat34, gmtl::Vec3f( 32, 33, 34 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat34, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setScale( new_mat, gmtl::Vec3f( 32, 33, 34 ) );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix34f >( gmtl::Vec3f( 32, 33, 34 ) ) == new_mat );
      }
      // 3D rot/trans/skew
      {
         gmtl::Matrix44f mat44, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat44[x] = a;
         expected_result44.set( 32, a, a, a,
                                a, 33, a, a,
                                a, a, 34, a,
                                a, a, a, a  );
         gmtl::setScale( mat44, gmtl::Vec3f( 32, 33, 34 ) );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setScale( new_mat, gmtl::Vec3f( 32, 33, 34 ) );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix44f >( gmtl::Vec3f( 32, 33, 34 ) ) == new_mat );
      }



      // 2D rot/trans
      {
         gmtl::Matrix<float, 2, 3> mat23, expected_result23;
         for (int x = 0; x < 6; ++x)
            mat23[x] = a;
         expected_result23.set( 32, a, a,
                                a, 32, a );
         gmtl::setScale( mat23, 32.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result23, mat23, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix23f new_mat;
         gmtl::setScale( new_mat, 32.0f );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix23f >( 32.0f ) == new_mat );
      }
      // 2D rot/trans/skew
      {
         gmtl::Matrix33f mat33, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat33[x] = a;
         expected_result33.set( 32, a, a,
                                a, 32, a,
                                a, a, a );
         gmtl::setScale( mat33, 32.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat33, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix33f new_mat;
         gmtl::setScale( new_mat, 32.0f );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix33f >( 32.0f ) == new_mat );
      }
      // 3D rot/trans
      {
         gmtl::Matrix34f mat34, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat34[x] = a;
         expected_result34.set( 32, a, a, a,
                                a, 32, a, a,
                                a, a, 32, a );
         gmtl::setScale( mat34, 32.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat34, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setScale( new_mat, 32.0f );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix34f >( 32.0f ) == new_mat );
      }
      // 3D rot/trans/skew
      {
         gmtl::Matrix44f mat44, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat44[x] = a;
         expected_result44.set( 32, a, a, a,
                                a, 32, a, a,
                                a, a, 32, a,
                                a, a, a, a  );
         gmtl::setScale( mat44, 32.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat44, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setScale( new_mat, 32.0f );
         CPPUNIT_ASSERT( gmtl::makeScale<gmtl::Matrix44f >( 32.0f ) == new_mat );
      }
      {
         // make sure this compiles, and runs without internal assert.
         gmtl::Matrix<float, 4, 8> mat48;
         gmtl::setScale( mat48, 32.0f );

         gmtl::Matrix<float, 8, 4> mat84;
         gmtl::setScale( mat84, 32.0f );
      }
   }

   void MatrixGenTest::testMatrixsetRot()
   {
      const float eps = 0.01f;
      const float a = 98234576.0f;
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 1, 0, 0,
                                0, 0, -1,
                                0, 1, 0 );
         gmtl::Vec3f vec( 1.0f, 0.0f, 0.0f );
         gmtl::normalize( vec );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ), vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure that the other version works the same...
         gmtl::Matrix33f mat2;
         gmtl::setRot( mat2, gmtl::Math::deg2Rad( 90.0f ), 1.0f, 0.0f, 0.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( mat2, mat, eps ) );

         // make sure set and make are the same...
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 90.0f ), 1.0f, 0.0f, 0.0f ) == mat2 );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 90.0f ), vec ) == mat2 );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 1, 0, 0,
                                0, 1, 0,
                                0, 0, 1 );
         gmtl::Vec3f vec( -1.0f, 1.0f, -1.0f );
         gmtl::normalize( vec );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( -360.0f ), vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure that the other version works the same...
         gmtl::Matrix33f mat2;
         gmtl::setRot( mat2, gmtl::Math::deg2Rad( -360.0f ), -1.0f, 1.0f, -1.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( mat2, mat, eps ) );

         // make sure set and make are the same...
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( -360.0f ), -1.0f, 1.0f, -1.0f ) == mat2 );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( -360.0f ), vec ) == mat2 );
      }

      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 1, 0, 0, a,
                                0, 0, 1, a,
                                0, -1, 0, a );
         gmtl::Vec3f vec( 1.0f, 0.0f, 0.0f );
         gmtl::normalize( vec );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( -90.0f ), vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );

         // make sure that the other version works the same...
         gmtl::Matrix34f mat2;
         for (int x = 0; x < 12; ++x)
            mat2[x] = a;
         gmtl::setRot( mat2, gmtl::Math::deg2Rad( -90.0f ), 1.0f, 0.0f, 0.0f );
         CPPUNIT_ASSERT( gmtl::isEqual( mat2, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( -90.0f ), 1.0f, 0.0f, 0.0f );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( -90.0f ), 1.0f, 0.0f, 0.0f ) == new_mat );
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( -90.0f ), vec );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( -90.0f ), vec ) == new_mat );
      }
      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 0.804738f, 0.310617f, -0.505879f, a,
                                -0.505879f, 0.804738f, -0.310617f, a,
                                0.310617f, 0.505879f, 0.804738f, a  );
         gmtl::Vec3f vec( 0.7f, -0.7f, -0.7f );
         gmtl::normalize( vec );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 45.0f ), vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );

         // make sure that the other version works the same...
         gmtl::Matrix34f mat2;
         for (int x = 0; x < 12; ++x)
            mat2[x] = a;
         gmtl::setRot( mat2, gmtl::Math::deg2Rad( 45.0f ), 0.7f, -0.7f, -0.7f );
         CPPUNIT_ASSERT( gmtl::isEqual( mat2, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 45.0f ), 0.7f, -0.7f, -0.7f );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( 45.0f ), 0.7f, -0.7f, -0.7f ) == new_mat );
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 45.0f ), vec );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( 45.0f ), vec ) == new_mat );
      }
      // test that unnormalized vec works...
      {
         gmtl::Matrix44f mat, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat[x] = a;
         expected_result44.set( 0.804738f, -0.310617f, 0.505879f, a,
                                0.505879f, 0.804738f, -0.310617f, a,
                                -0.310617f, 0.505879f, 0.804738f, a,
                                a, a, a, a );
         gmtl::Vec3f vec( 1.7f, 1.7f, 1.7f );
         gmtl::normalize( vec );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 45.0f ), vec );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat, eps ) );

         // make sure that the other version works the same...
         gmtl::Matrix44f mat2;
         for (int x = 0; x < 16; ++x)
            mat2[x] = a;
         gmtl::setRot( mat2, gmtl::Math::deg2Rad( 45.0f ), 1.7f, 1.7f, 1.7f );
         CPPUNIT_ASSERT( gmtl::isEqual( mat2, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 45.0f ), 1.7f, 1.7f, 1.7f );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix44f>( gmtl::Math::deg2Rad( 45.0f ), 1.7f, 1.7f, 1.7f ) == new_mat );
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 45.0f ), vec );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix44f>( gmtl::Math::deg2Rad( 45.0f ), vec ) == new_mat );
      }

      // ---- Test standalone one ---- //
      {
         gmtl::Matrix44f mat, expected_mat;
         gmtl::Vec3f rot_axis(1.0f, 2.0f, 3.0f);
         gmtl::normalize(rot_axis);
         gmtl::setRot(expected_mat, 1.1f, rot_axis);
         mat = gmtl::makeRot<gmtl::Matrix44f>(1.1f, rot_axis);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeRot<gmtl::Matrix44f>(1.1f, rot_axis), expected_mat, eps ) );
      }

      {
         gmtl::Matrix34f mat, expected_mat;
         gmtl::Vec3f rot_axis(1.0f, 2.0f, 3.0f);
         gmtl::normalize(rot_axis);
         gmtl::setRot(expected_mat, 1.1f, rot_axis);
         mat = gmtl::makeRot<gmtl::Matrix34f>(1.1f, rot_axis);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeRot<gmtl::Matrix34f>(1.1f, rot_axis), expected_mat, eps ) );
      }

   }

   void MatrixGenTest::testMatrixsetRotEuler()
   {
      const float eps = 0.001f;
      const float a = 98234576.0f;
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0.683013f, -0.183013f, 0.707107f,
                                0.683013f, -0.183013f, -0.707107f,
                                0.258819f, 0.965926f, 0.0f );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 45.0f ),
                             gmtl::Math::deg2Rad( 15.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 1, 0,  0,
                                0, 0, -1,
                                0, 1,  0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ ) == mat );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0, 0, 1,
                                0, 1, 0,
                                -1, 0, 0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ ) == mat );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0, -1, 0,
                                1, 0, 0,
                                0, 0, 1  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::XYZ ) == mat );
      }

      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 0.683013f, 0.183013f, -0.707107f, a,
                               -0.0413633f, -0.956855f, -0.287606f, a,
                               -0.729234f, 0.225687f, -0.645974f, a   );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 156.0f ), gmtl::Math::deg2Rad( -45.0f ), gmtl::Math::deg2Rad( -15.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 156.0f ), gmtl::Math::deg2Rad( -45.0f ), gmtl::Math::deg2Rad( -15.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( 156.0f ), gmtl::Math::deg2Rad( -45.0f ), gmtl::Math::deg2Rad( -15.0f ), gmtl::XYZ ) == new_mat );
      }
      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 0, 0, 1, a,
                                0, 1, 0, a,
                                -1, 0, 0, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix34f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix34f>( gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::XYZ ) == new_mat );
      }

      {
         gmtl::Matrix44f mat, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat[x] = a;
         expected_result44.set( 0.697193f, 0.0121696f, 0.71678f, a,
                               -0.275553f, -0.918494f, 0.283617f, a,
                                0.66181f, -0.395247f, -0.637014f, a,
                                a, a, a, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( -156.0f ), gmtl::Math::deg2Rad( 45.7892892f ), gmtl::Math::deg2Rad( -361.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix44f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( -156.0f ), gmtl::Math::deg2Rad( 45.7892892f ), gmtl::Math::deg2Rad( -361.0f ), gmtl::XYZ );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix44f>( gmtl::Math::deg2Rad( -156.0f ), gmtl::Math::deg2Rad( 45.7892892f ), gmtl::Math::deg2Rad( -361.0f ), gmtl::XYZ ) == new_mat );
      }


      // ZYX
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0.0f, -0.965926f, 0.258819f,
                                0.707107f, 0.183013f, 0.683013f,
                                -0.707107f, 0.183013f, 0.683013f );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 45.0f ),
                             gmtl::Math::deg2Rad( 15.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix33f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 45.0f ),
                             gmtl::Math::deg2Rad( 15.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 45.0f ),
                             gmtl::Math::deg2Rad( 15.0f ), gmtl::ZYX ) == new_mat );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0, -1, 0,
                                1, 0, 0,
                                0, 0, 1  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix33f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX ) == new_mat );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0, 0, 1,
                                0, 1, 0,
                                -1, 0, 0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );

         // make sure set and make are the same...
         gmtl::Matrix33f new_mat;
         gmtl::setRot( new_mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::makeRot<gmtl::Matrix33f>( gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX ) == new_mat );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 1, 0, 0,
                                0, 0, -1,
                                0, 1, 0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }

      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( -0.645974f, -0.560068f, 0.518692f, a,
                                 0.287606f, -0.807979f, -0.514249f, a,
                                 0.707107f, -0.183013f, 0.683013f, a  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 156.0f ), gmtl::Math::deg2Rad( -45.0f ), gmtl::Math::deg2Rad( -15.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );
      }
      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 0, 0, 1, a,
                                0, 1, 0, a,
                                -1, 0, 0, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ), gmtl::Math::deg2Rad( 90.0f ), gmtl::Math::deg2Rad( 0.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );
      }

      {
         gmtl::Matrix44f mat, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat[x] = a;
         expected_result44.set( -0.637014f, 0.418103f, -0.647613f, a,
                                -0.283617f, -0.908318f, -0.30744f, a,
                                -0.71678f, -0.0121696f, 0.697193f, a,
                                 a, a, a, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( -156.0f ), gmtl::Math::deg2Rad( 45.7892892f ), gmtl::Math::deg2Rad( -361.0f ), gmtl::ZYX );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat, eps ) );
      }


      // ZXY
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( -0.183013f, -0.707107f, 0.683013f,
                                 0.965926f, 0.0f,       0.258819f,
                                -0.183013f, 0.707107f,  0.683013f );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 45.0f ),
                             gmtl::Math::deg2Rad( 15.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 0, -1, 0,
                                1, 0, 0,
                                0, 0, 1  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set( 1, 0,  0,
                                0, 0, -1,
                                0, 1,  0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }
      {
         gmtl::Matrix33f mat, expected_result33;
         for (int x = 0; x < 9; ++x)
            mat[x] = a;
         expected_result33.set(  0, 0, 1,
                                 0, 1, 0,
                                -1, 0, 0  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result33, mat, eps ) );
      }

      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( -0.956855f, -0.287606f, -0.0413633f, a,
                                 0.225687f, -0.645974f, -0.729234f,  a,
                                 0.183013f, -0.707107f,  0.683013f,  a  );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 156.0f ),
                             gmtl::Math::deg2Rad( -45.0f ),
                             gmtl::Math::deg2Rad( -15.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );
      }
      {
         gmtl::Matrix34f mat, expected_result34;
         for (int x = 0; x < 12; ++x)
            mat[x] = a;
         expected_result34.set( 1, 0,  0, a,
                                0, 0, -1, a,
                                0, 1,  0, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( 0.0f ),
                             gmtl::Math::deg2Rad( 90.0f ),
                             gmtl::Math::deg2Rad( 0.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result34, mat, eps ) );
      }

      {
         gmtl::Matrix44f mat, expected_result44;
         for (int x = 0; x < 16; ++x)
            mat[x] = a;
         expected_result44.set( -0.918494f, 0.283617f, -0.275553f, a,
                                -0.395247f, -0.637014f, 0.66181f, a,
                                 0.0121696f, 0.71678f, 0.697193f, a,
                                 a, a, a, a );
         gmtl::setRot( mat, gmtl::Math::deg2Rad( -156.0f ),
                             gmtl::Math::deg2Rad( 45.7892892f ),
                             gmtl::Math::deg2Rad( -361.0f ), gmtl::ZXY );
         CPPUNIT_ASSERT( gmtl::isEqual( expected_result44, mat, eps ) );
      }


      // --- Test standalone setRot(val,val,val) against setRot(mat,val,val,val) -- //
      {
         gmtl::Matrix44f mat, expected_mat;
         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::XYZ);
         mat = gmtl::makeRot<gmtl::Matrix44f>(0.1f, 2.3f, -2.1f, gmtl::XYZ);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZXY );
         mat = gmtl::makeRot<gmtl::Matrix44f>(0.1f, 2.3f, -2.1f, gmtl::ZXY);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZYX);
         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeRot<gmtl::Matrix44f>(0.1f, 2.3f, -2.1f, gmtl::ZYX),
                                        expected_mat, eps ) );
      }

      {
         gmtl::Matrix33f mat, expected_mat;
         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::XYZ);
         mat = gmtl::makeRot<gmtl::Matrix33f>(0.1f, 2.3f, -2.1f, gmtl::XYZ);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZXY );
         mat = gmtl::makeRot<gmtl::Matrix33f>(0.1f, 2.3f, -2.1f, gmtl::ZXY);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZYX);
         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeRot<gmtl::Matrix33f>(0.1f, 2.3f, -2.1f, gmtl::ZYX),
                                        expected_mat, eps ) );
      }

      {
         gmtl::Matrix34f mat, expected_mat;
         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::XYZ);
         mat = gmtl::makeRot<gmtl::Matrix34f>(0.1f, 2.3f, -2.1f, gmtl::XYZ);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZXY );
         mat = gmtl::makeRot<gmtl::Matrix34f>(0.1f, 2.3f, -2.1f, gmtl::ZXY);
         CPPUNIT_ASSERT( gmtl::isEqual( mat, expected_mat, eps ) );

         gmtl::setRot(expected_mat, 0.1f, 2.3f, -2.1f, gmtl::ZYX);
         CPPUNIT_ASSERT( gmtl::isEqual( gmtl::makeRot<gmtl::Matrix34f>(0.1f, 2.3f, -2.1f, gmtl::ZYX),
                                        expected_mat, eps ) );
      }

   }

   void MatrixGenTest::testTimingsetTrans()
   {
      gmtl::Matrix33f mat33;
      gmtl::Matrix34f mat34;
      gmtl::Matrix44f mat44;
      float a = 1.0f;

      const long iters(25000);

      // 2D translation
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setTrans( mat33, gmtl::Vec2f( a, 2 ) );
         a += mat33[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setTrans(mat33f,vec2f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat33[3] != 1234.0456f && a != 987654.321f  );


      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setTrans( mat33, gmtl::Vec3f( 1, a, 1.0f ) ); // homogeneous
         a += mat33[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setTrans(mat33f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat33[3] != 1234.0456f && a != 987654.321f  );


      // 3D translation
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setTrans( mat34, gmtl::Vec3f( a, 32, 121 ) );
         a += mat34[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setTrans(mat34f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat34[3] != 1234.0456f && a != 987654.321f  );


      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setTrans( mat44, gmtl::Vec3f( 30, a, 121 ) );
         a += mat44[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setTrans(mat44f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat44[3] != 1234.0456f && a != 987654.321f  );


      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setTrans( mat44, gmtl::Vec4f( 30, 32, a, 1.0f ) ); // homogeneous
         a += mat44[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setTrans(mat44f,vec4f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat44[3] != 1234.0456f && a != 987654.321f  );
   }
   /*
   void MatrixGenTest::testTimingMakeTransStatic()
   {
      gmtl::Matrix22f mat22;
      gmtl::Matrix33f mat33;
      gmtl::Matrix34f mat34;
      gmtl::Matrix44f mat44;
      gmtl::Matrix43f mat43;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::makeTrans( mat22, Vec2f( 1, 2 ) );
         gmtl::makeTrans( mat33, Vec3f( 30, 32, 121 ) );
         gmtl::makeTrans( mat34, Vec3f( 30, 32, 121 ) );
         gmtl::makeTrans( mat43, Vec3f( 30, 32, 121 ) );
         gmtl::makeTrans( mat44, Vec3f( 30, 32, 121 ) );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeScale", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */

   void MatrixGenTest::testTimingsetScale()
   {
      float a = 2.1f;
      gmtl::Matrix33f mat33;
      gmtl::Matrix34f mat34;
      gmtl::Matrix44f mat44;
      gmtl::Matrix<float, 4, 3> mat43;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat33, gmtl::Vec2f( a, 2 ) );
         a += mat33[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat33f,vec2f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat33[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat34, gmtl::Vec3f( 30, 32, a ) );
         a += mat34[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat34f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat34[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat43, gmtl::Vec3f( 30, 32, a ) );
         a += mat43[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat43f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat43[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat44, gmtl::Vec3f( 30, 32, a ) );
         a += mat44[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat44f,vec3f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat44[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat33, a );
         a += mat33[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat33f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat33[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat34, a );
         a += mat34[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat34f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat34[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat43, a );
         a += mat43[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat43f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat43[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setScale( mat44, a );
         a += mat44[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setScale(mat44f,f)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat44[3] != 1234.0456f && a != 987654.321f  );
   }

   /*
   void MatrixGenTest::testTimingMakeScaleStatic()
   {
      gmtl::Matrix22f mat22;
      gmtl::Matrix33f mat33;
      gmtl::Matrix34f mat34;
      gmtl::Matrix44f mat44;
      gmtl::Matrix43f mat43;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::makeScale( mat22, Vec2f( 1, 2 ) );
         gmtl::makeScale( mat33, Vec3f( 30, 32, 121 ) );
         gmtl::makeScale( mat34, Vec3f( 30, 32, 121 ) );
         gmtl::makeScale( mat43, Vec3f( 30, 32, 121 ) );
         gmtl::makeScale( mat44, Vec3f( 30, 32, 121 ) );
         gmtl::makeScale( mat33, 2.0f );
         gmtl::makeScale( mat34, 3.0f );
         gmtl::makeScale( mat43, 4.0f );
         gmtl::makeScale( mat44, 5.0f );
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeScale", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */

   void MatrixGenTest::testTimingsetRot33()
   {
      gmtl::Matrix33f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, gmtl::Math::deg2Rad( a ), gmtl::Vec3f( 1.0f, 0.0f, 0.0f ) );
         a += mat[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRot33f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetRot34()
   {
      gmtl::Matrix34f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, gmtl::Math::deg2Rad( a ), gmtl::Vec3f( 1.0f, 0.0f, 0.0f ) );
         a += mat[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRot34f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetRot44()
   {
      gmtl::Matrix44f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, gmtl::Math::deg2Rad( a ), gmtl::Vec3f( 1.0f, 0.0f, 0.0f ) );
         a += mat[3];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRot44f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   /*
   void MatrixGenTest::testTimingMakeRot33Static()
   {
      gmtl::bok<gmtl::Matrix33f>( (float)1.0f );
      gmtl::Matrix<float, 3, 3> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix33f>( 90.0f, 1.0f, 0.0f, 0.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRot33Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeRot34Static()
   {
      gmtl::Matrix<float, 3, 4> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix34f>( 90.0f, 1.0f, 0.0f, 0.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRot34Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeRot44Static()
   {
      gmtl::Matrix<float, 4, 4> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix44f>( 90.0f, 1.0f, 0.0f, 0.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRot44Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */


   void MatrixGenTest::testTimingGetRot()
   {
      /// @todo ... write a getRot( mat, rad, axis ) test here....
   }


   // makeRot Euler tests...

   void MatrixGenTest::testTimingsetRotEuler33()
   {
      gmtl::Matrix33f mat;
      float a = 0;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZXY );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat33f,ZXY)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZYX );
         a += mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat33f,ZYX)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::XYZ );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat33f,XYZ)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetRotEuler34()
   {
      gmtl::Matrix34f mat;
      float a = 0;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZXY );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat34f,ZXY)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZYX );
         a += mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat34f,ZYX)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::XYZ );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat34f,XYZ)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetRotEuler44()
   {
      gmtl::Matrix44f mat;
      float a = 0;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZXY );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat44f,ZXY)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::ZYX );
         a += mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat44f,ZYX)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );

      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setRot( mat, a, 45.0f, 35.0f, gmtl::XYZ );
         a -= mat[4];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setRotEuler(mat44f,XYZ)", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }
   /*
   void MatrixGenTest::testTimingMakeRotEuler33Static()
   {
      gmtl::Matrix<float, 3, 3> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix33f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRotEuler33Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeRotEuler34Static()
   {
      gmtl::Matrix<float, 3, 4> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix34f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRotEuler34Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeRotEuler44Static()
   {
      gmtl::Matrix44f mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix44f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeRotEuler44Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */

   void MatrixGenTest::testTimingsetDirCos33()
   {
      gmtl::Matrix33f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setDirCos( mat, gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( a,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setDirCos33f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetDirCos34()
   {
      gmtl::Matrix34f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setDirCos( mat, gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( a,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setDirCos34f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f  );
   }

   void MatrixGenTest::testTimingsetDirCos44()
   {
      gmtl::Matrix44f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setDirCos( mat, gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( a,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setDirCos44f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f );
   }
   /*
   void MatrixGenTest::testTimingMakeDirCos33Static()
   {
      gmtl::Matrix<float, 3, 3> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix33f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeDirCos33Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeDirCos34Static()
   {
      gmtl::Matrix<float, 3, 4> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix34f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeDirCos34Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeDirCos44Static()
   {
      gmtl::Matrix44f mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeRot<gmtl::Matrix44f>( 90.0f, 45.0f, 35.0f );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeDirCos44Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */

   void MatrixGenTest::testTimingsetAxes33()
   {
      gmtl::Matrix33f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setAxes( mat, gmtl::Vec3f( 1,a,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setAxes33f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f );
   }

   void MatrixGenTest::testTimingsetAxes34()
   {
      gmtl::Matrix34f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setAxes( mat, gmtl::Vec3f( 1,a,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setAxes34f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f );
   }

   void MatrixGenTest::testTimingsetAxes44()
   {
      gmtl::Matrix44f mat;
      float a = 0.0f;
      const long iters(25000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
      {
         gmtl::setAxes( mat, gmtl::Vec3f( 1,a,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
         a += mat[1];
      }
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/setAxes44f", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
      CPPUNIT_ASSERT( mat[3] != 1234.0456f && a != 987654.321f );
   }
   /*
   void MatrixGenTest::testTimingMakeAxes33Static()
   {
      gmtl::Matrix<float, 3, 3> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeAxes<gmtl::Matrix33f>( gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeAxes33Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeAxes34Static()
   {
      gmtl::Matrix<float, 3, 4> mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeAxes<gmtl::Matrix34f>( gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeAxes34Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }

   void MatrixGenTest::testTimingMakeAxes44Static()
   {
      gmtl::Matrix44f mat;
      const long iters(100000);
      CPPUNIT_METRIC_START_TIMING();
      for (long iter = 0; iter < iters; ++iter)
         mat = gmtl::makeAxes<gmtl::Matrix44f>( gmtl::Vec3f( 1,0,0 ), gmtl::Vec3f( 0,1,0 ), gmtl::Vec3f( 0,0,1 ) );
      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("MatrixGenTest/MakeAxes44Static", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%
   }
   */

   // is this a convert test?
   void MatrixGenTest::testTimingsetAxes()
   {
//      gmtl::Matrix44f mat1, mat2;
//      gmtl::Vec3f xAxis1,yAxis1,zAxis1;
//      gmtl::Vec3f xAxis2,yAxis2,zAxis2;



      /*
      // Simple rotation around X axis
      mat1.makeRot(90,gmtl::XUnitVec3);
      mat1.getAxes(xAxis1,yAxis1,zAxis1);
      mat2.makeAxes(xAxis1,yAxis1,zAxis1);
      mat2.getAxes(xAxis2,yAxis2,zAxis2);

      CPPUNIT_ASSERT(xAxis1.equal(xAxis2,0.01));
      CPPUNIT_ASSERT(yAxis1.equal(yAxis2,0.01));
      CPPUNIT_ASSERT(zAxis1.equal(zAxis2,0.01));

      // More complex Euler rotation
      mat1.makeXYZEuler(45.0f, -35.0f, 13.0f);
      mat1.getAxes(xAxis1,yAxis1,zAxis1);
      mat2.makeAxes(xAxis1,yAxis1,zAxis1);
      mat2.getAxes(xAxis2,yAxis2,zAxis2);

      CPPUNIT_ASSERT(xAxis1.equal(xAxis2,0.01));
      CPPUNIT_ASSERT(yAxis1.equal(yAxis2,0.01));
      CPPUNIT_ASSERT(zAxis1.equal(zAxis2,0.01));

      // Use orthonormal axis
      xAxis1.set(7, 11, 21);     xAxis1.normalize();
      yAxis1.set(12, 21, 75);    yAxis1.normalize();
      zAxis1 = xAxis1.cross(yAxis1);   zAxis1.normalize();

      mat2.makeAxes(xAxis1,yAxis1,zAxis1);
      mat2.getAxes(xAxis2,yAxis2,zAxis2);

      CPPUNIT_ASSERT(xAxis1.equal(xAxis2,0.01));
      CPPUNIT_ASSERT(yAxis1.equal(yAxis2,0.01));
      CPPUNIT_ASSERT(zAxis1.equal(zAxis2,0.01));
      */
   }
}