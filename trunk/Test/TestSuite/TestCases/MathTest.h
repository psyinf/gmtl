/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: MathTest.h,v $
 * Date modified: $Date: 2004-08-19 16:50:22 $
 * Version:       $Revision: 1.10 $
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
#ifndef _GMTL_MATH_TEST_H_
#define _GMTL_MATH_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

namespace gmtlTest
{
   class MathTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(MathTest);

      CPPUNIT_TEST(testQuadraticFormula);
      CPPUNIT_TEST(testSigni);
      CPPUNIT_TEST(testSignf);
      CPPUNIT_TEST(testZeroClampf);
      CPPUNIT_TEST(testZeroClampd);
      CPPUNIT_TEST_SUITE_END();

   public:
      void testQuadraticFormula();
      void testSigni();
      void testSignf();
      void testZeroClampf();
      void testZeroClampd();

   };

   class MathMetricTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(MathMetricTest);

      CPPUNIT_TEST(testTimingZeroClampf);
      CPPUNIT_TEST(testTimingZeroClampd);
      CPPUNIT_TEST(testFastInvSqrt);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testTimingZeroClampf();
      void testTimingZeroClampd();
      void testFastInvSqrt();
   };
}

#endif
