/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: testSuite.cpp,v $
 * Date modified: $Date: 2002-02-10 04:38:06 $
 * Version:       $Revision: 1.5 $
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

//------------------------------------------------------
// Test suite for GMTL
//
// This is designed to test EVERY capability of GMTL
//
//------------------------------------------------------

#include <cppunit/TestSuite.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/MetricRegistry.h>

// GMTL tests
#include <gmtl/gmtlConfig.h>
#include <TestCases/Vec3Test.h>
#include <TestCases/MatrixTest.h>
#include <TestCases/Point3Test.h>
#include <TestCases/XformTest.h>
#include <TestCases/OOBoxTest.h>
#include <TestCases/PlaneTest.h>
#include <TestCases/ContainmentTest.h>
#include <TestCases/IntersectionTest.h>
#include <TestCases/QuatTest.h>
#include <TestCases/TriTest.h>
#include <TestCases/InfoTests/OptTest.h>

int main (int ac, char **av)
{
   CppUnit::TextTestRunner runner;
	
   //------------------------------------
   //  GMTL Tests
   //------------------------------------
   // Create the tests
   CppUnit::TestSuite* gmtl_suite = new CppUnit::TestSuite("gmtl_suite");
	
   gmtl_suite->addTest(gmtlTest::Vec3Test::suite());
   gmtl_suite->addTest(gmtlTest::MatrixTest::suite());
   gmtl_suite->addTest(gmtlTest::Point3Test::suite());
   gmtl_suite->addTest(gmtlTest::XformTest::suite());
   gmtl_suite->addTest(gmtlTest::OOBoxTest::suite());
   gmtl_suite->addTest(gmtlTest::PlaneTest::suite());
   gmtl_suite->addTest(gmtlTest::ContainmentTest::suite());
   gmtl_suite->addTest(gmtlTest::IntersectionTest::suite());
   gmtl_suite->addTest(gmtlTest::QuatTest::suite());
   gmtl_suite->addTest(gmtlTest::TriTest::suite());
   gmtl_suite->addTest(gmtlTest::OptTest::suite());

   // Add the tests
   runner.addTest(gmtl_suite);

   // --- RUN THEM --- //
   //runner.run( ac, av );
   runner.run("gmtl_suite");

   return 0;
}
