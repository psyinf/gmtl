/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: VecBaseTest.h,v $
 * Date modified: $Date: 2003-02-06 01:39:50 $
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
#ifndef _GMTL_VEC_BASE_TEST_H_
#define _GMTL_VEC_BASE_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

namespace gmtlTest
{
   /**
    * Functionality tests
    */
   class VecBaseTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(VecBaseTest);

      CPPUNIT_TEST(testVecBaseCreation);
      CPPUNIT_TEST(testCopyConstruct);
      CPPUNIT_TEST(testConstructors);
      CPPUNIT_TEST(testSet);
      CPPUNIT_TEST(testSetPtr);
      CPPUNIT_TEST(testGetData);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testVecBaseCreation();
      void testCopyConstruct();
      void testConstructors();

      void testSet();
      void testSetPtr();
      void testGetData();
   };

   /**
    * Metric tests.
    */
   class VecBaseMetricTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(VecBaseMetricTest);

      CPPUNIT_TEST(testTimingVecBaseCreation);
      CPPUNIT_TEST(testTimingCopyConstruct);
      CPPUNIT_TEST(testTimingConstructors);
      CPPUNIT_TEST(testTimingSet);
      CPPUNIT_TEST(testTimingSetPtr);
      CPPUNIT_TEST(testTimingGetData);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testTimingVecBaseCreation();
      void testTimingCopyConstruct();
      void testTimingConstructors();

      void testTimingSet();
      void testTimingSetPtr();
      void testTimingGetData();
   };
}

#endif
