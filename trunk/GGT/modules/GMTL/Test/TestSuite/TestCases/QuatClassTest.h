/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: QuatClassTest.h,v $
 * Date modified: $Date: 2003-02-06 01:12:27 $
 * Version:       $Revision: 1.10 $
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
#ifndef _GMTL_QUAT_CLASS_TEST_H_
#define _GMTL_QUAT_CLASS_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

namespace gmtlTest
{
   class QuatClassTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(QuatClassTest);

      CPPUNIT_TEST(testQuatClassTestCreation);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testQuatClassTestCreation();
   };

   class QuatClassMetricTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(QuatClassMetricTest);

      CPPUNIT_TEST(testQuatTimingDefaultConstructor);
      CPPUNIT_TEST(testQuatTimingElementConstructor);
      CPPUNIT_TEST(testQuatTimingCopyConstructor);
      CPPUNIT_TEST(testQuatTimingGet);
      CPPUNIT_TEST(testQuatTimingSet);
      CPPUNIT_TEST(testQuatTimingOpBracket);
      CPPUNIT_TEST(testQuatTimingGetData);
      CPPUNIT_TEST(testQuatTimingOpEqual);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testQuatTimingDefaultConstructor();
      void testQuatTimingElementConstructor();
      void testQuatTimingCopyConstructor();
      void testQuatTimingGet();
      void testQuatTimingSet();
      void testQuatTimingOpBracket();
      void testQuatTimingGetData();
      void testQuatTimingOpEqual();
   };
}

#endif
