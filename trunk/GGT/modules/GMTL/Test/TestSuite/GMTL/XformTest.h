/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: XformTest.h,v $
 * Date modified: $Date: 2002-01-18 20:43:11 $
 * Version:       $Revision: 1.1.1.1 $
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
#include <gfxConfig.h>
#include <iostream>

#include <TestCase.h>
#include <TestSuite.h>
#include <TestCaller.h>

#include <GMTL/Vec3.h>
#include <GMTL/Point3.h>
#include <GMTL/Matrix.h>
#include <GMTL/Vec4.h>
#include <GMTL/Xforms.h>
#include <GMTL/gmtlOutput.h>

namespace gmtlTest
{

class XformTest : public TestCase
{
public:
   XformTest( std::string name )
   : TestCase (name)
   {;}

   virtual ~XformTest()
   {}

   virtual void setUp()
   {;}

   virtual void tearDown()
   {
   }

   void testVec4_Mat_Xform()
   {
      gmtl::Vec4  v1, v1_trans, v1_trans_ans;
      v1.set(1.1,-2.2,3.3,1.0);
      gmtl::Matrix rot_mat;
      rot_mat.makeXYZEuler(20.0f, -30.0f, 40.0f);
      v1_trans_ans.set(0.30443, -2.28262, 3.41130, 1.0);
      v1_trans = rot_mat * v1;

      assertTest(v1_trans.equal(v1_trans_ans,0.0001));

   }

   void testVec3_Mat_Xform()
   {
      // Vector, so translation should not affect it

      gmtl::Vec3  v1, v1_xform, v1_xform_ans;
      v1.set(1.1,-2.2,3.3);
      gmtl::Matrix xform_mat;
      xform_mat.makeXYZEuler(20.0f, -30.0f, 40.0f);
      xform_mat.setTrans(10.0, 1.0, -13.0f);
      //std::cout << "xform_mat: " << xform_mat << std::endl;

      v1_xform_ans.set(0.30443, -2.28262, 3.41130);
      v1_xform = xform_mat * v1;

      assertTest(v1_xform.equal(v1_xform_ans,0.0001));
   }

   void testPoint3_Mat_Xform()
   {
      // Vector, so translation should not affect it

      gmtl::Point3  p1, p1_xform, p1_xform_ans;
      p1.set(1.1,-2.2,3.3);
      gmtl::Matrix xform_mat;
      xform_mat.makeXYZEuler(20.0f, -30.0f, 40.0f);
      xform_mat.setTrans(10.0, 1.0, -13.0f);
      //std::cout << "p1: " << p1 << std::endl;
      //std::cout << "xform_mat: " << xform_mat << std::endl;

      p1_xform_ans.set(10.30443, -1.28262, -9.5887);
      p1_xform = xform_mat * p1;
      //std::cout << "point_p1_xform: " << p1_xform << std::endl;

      assertTest(p1_xform.equal(p1_xform_ans,0.0001));
   }

   static Test* suite()
   {
      TestSuite* test_suite = new TestSuite ("Vec3Test");
      test_suite->addTest( new TestCaller<XformTest>("testVec4_Mat_Xform", &XformTest::testVec4_Mat_Xform));
      test_suite->addTest( new TestCaller<XformTest>("testVec3_Mat_Xform", &XformTest::testVec3_Mat_Xform));
      test_suite->addTest( new TestCaller<XformTest>("testPoint3_Mat_Xform", &XformTest::testPoint3_Mat_Xform));

      return test_suite;
   }

   static Test* interactiveSuite()
   {
      TestSuite* test_suite = new TestSuite ("InteractiveThreadTest");
      //test_suite->addTest( new TestCaller<ThreadTest>("interactiveCPUGrind", &ThreadTest::interactiveTestCPUGrind));
      return test_suite;
   }

protected:

};

};
