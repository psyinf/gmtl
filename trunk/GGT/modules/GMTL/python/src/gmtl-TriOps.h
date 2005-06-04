/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: gmtl-TriOps.h,v $
 * Date modified: $Date: 2005-06-04 20:13:09 $
 * Version:       $Revision: 1.3 $
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

#ifndef _PYGMTL_TRI_OPS_H_
#define _PYGMTL_TRI_OPS_H_

// This file makes declarations of the templated function instantiations
// needed for Boost.Python to do its thing.

#include <gmtl/Tri.h>
#include <gmtl/TriOps.h>


#if ! defined(__APPLE__)
namespace gmtl
{
   template gmtl::Point3f center(const gmtl::Trif&);
   template gmtl::Point3d center(const gmtl::Trid&);
   template gmtl::Point3i center(const gmtl::Trii&);

   template gmtl::Vec3f normal(const gmtl::Trif&);
   template gmtl::Vec3d normal(const gmtl::Trid&);
//   template gmtl::Vec3i normal(const gmtl::Trii&);

   template bool isEqual(const gmtl::Trif&, const gmtl::Trif&, const float&);
   template bool isEqual(const gmtl::Trid&, const gmtl::Trid&, const double&);
}
#endif


#endif /* _PYGMTL_TRI_OPS_H_ */
