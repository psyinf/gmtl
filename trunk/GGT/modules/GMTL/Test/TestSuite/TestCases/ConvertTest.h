/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: ConvertTest.h,v $
 * Date modified: $Date: 2003-02-05 22:02:48 $
 * Version:       $Revision: 1.13 $
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
#ifndef _GMTL_CONVERT_TEST_H_
#define _GMTL_CONVERT_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

/// @todo test convert( vec, matrix ), convert( matrix, vec )

namespace gmtlTest
{
   class ConvertTest : public CppUnit::TestFixture
   {
      CPPUNIT_TEST_SUITE(ConvertTest);

      CPPUNIT_TEST(testConvertVecToPureQuat);
      CPPUNIT_TEST(testConvertQuatMat_MatQuat);

      CPPUNIT_TEST_SUITE_END();

   public:
      void testConvertVecToPureQuat();
      void testConvertQuatMat_MatQuat();
   };
}

#endif
