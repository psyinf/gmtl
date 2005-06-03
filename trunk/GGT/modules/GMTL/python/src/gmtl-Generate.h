/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: gmtl-Generate.h,v $
 * Date modified: $Date: 2005-06-03 22:51:39 $
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

#ifndef _PYGMTL_GENERATE_H_
#define _PYGMTL_GENERATE_H_

// This file makes declarations of the templated function instantiations
// needed for Boost.Python to do its thing.

#include <gmtl/Generate.h>


namespace gmtl
{
   // See gmtl-wrappers.h for GMTL functions that use the Type2Type idiom.

   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&, const Vec3f&,
                                    const Vec3f&);
   template gmtl::Quatf& setRot(gmtl::Quatf&, const Vec3f&, const Vec3f&);

   template gmtl::Vec3f makeVec(const gmtl::Quatf&);
   template gmtl::Vec3d makeVec(const gmtl::Quatd&);

   template gmtl::Vec3f makeNormal(gmtl::Vec3f);
   template gmtl::Vec4f makeNormal(gmtl::Vec4f);

   template gmtl::Vec3i makeCross(const gmtl::Vec3i&, const gmtl::Vec3i&);
   template gmtl::Vec3d makeCross(const gmtl::Vec3d&, const gmtl::Vec3d&);
   template gmtl::Vec3f makeCross(const gmtl::Vec3f&, const gmtl::Vec3f&);

   template gmtl::Vec3f& setTrans(gmtl::Vec3f&, const gmtl::Matrix44f&);
   template gmtl::Vec3d& setTrans(gmtl::Vec3d&, const gmtl::Matrix44d&);

   template gmtl::Vec2f& setTrans(gmtl::Vec2f&, const gmtl::Matrix33f&);
   template gmtl::Vec2d& setTrans(gmtl::Vec2d&, const gmtl::Matrix33d&);

   template gmtl::Quatf& setPure(gmtl::Quatf&, const gmtl::Vec3f&);
   template gmtl::Quatd& setPure(gmtl::Quatd&, const gmtl::Vec3d&);

   template gmtl::Quatf makePure(const gmtl::Vec3f&);
   template gmtl::Quatd makePure(const gmtl::Vec3d&);

   template gmtl::Quatf makeNormal(const gmtl::Quatf&);
   template gmtl::Quatd makeNormal(const gmtl::Quatd&);

   template gmtl::Quatf makeConj(const gmtl::Quatf&);
   template gmtl::Quatd makeConj(const gmtl::Quatd&);

   template gmtl::Quatf makeInvert(const gmtl::Quatf&);
   template gmtl::Quatd makeInvert(const gmtl::Quatd&);

   template gmtl::Quatf& set(gmtl::Quatf&, const gmtl::AxisAnglef&);
   template gmtl::Quatd& set(gmtl::Quatd&, const gmtl::AxisAngled&);

   template gmtl::Quatf& setRot(gmtl::Quatf&, const gmtl::EulerAngleXYZf&);
   template gmtl::Quatf& setRot(gmtl::Quatf&, const gmtl::EulerAngleZYXf&);
   template gmtl::Quatf& setRot(gmtl::Quatf&, const gmtl::EulerAngleZXYf&);

   template gmtl::Quatf& set(gmtl::Quatf&, const gmtl::Matrix44f&);
   template gmtl::Quatd& set(gmtl::Quatd&, const gmtl::Matrix44d&);

   template gmtl::Quatf& setRot(gmtl::Quatf&, const gmtl::Matrix44f&);
   template gmtl::Quatd& setRot(gmtl::Quatd&, const gmtl::Matrix44d&);

   template gmtl::AxisAnglef& set(gmtl::AxisAnglef&, gmtl::Quatf);
   template gmtl::AxisAngled& set(gmtl::AxisAngled&, gmtl::Quatd);

   template gmtl::AxisAnglef& setRot(gmtl::AxisAnglef&, gmtl::Quatf);
   template gmtl::AxisAngled& setRot(gmtl::AxisAngled&, gmtl::Quatd);

   template gmtl::AxisAnglef makeNormal(const gmtl::AxisAnglef&);
   template gmtl::AxisAngled makeNormal(const gmtl::AxisAngled&);

   template gmtl::EulerAngleXYZf& set(gmtl::EulerAngleXYZf&,
                                      const gmtl::Matrix44f&);
   template gmtl::EulerAngleZYXf& set(gmtl::EulerAngleZYXf&,
                                      const gmtl::Matrix44f&);
   template gmtl::EulerAngleZXYf& set(gmtl::EulerAngleZXYf&,
                                      const gmtl::Matrix44f&);

   template gmtl::EulerAngleXYZf& setRot(gmtl::EulerAngleXYZf&,
                                         const gmtl::Matrix44f&);
   template gmtl::EulerAngleZYXf& setRot(gmtl::EulerAngleZYXf&,
                                         const gmtl::Matrix44f&);
   template gmtl::EulerAngleZXYf& setRot(gmtl::EulerAngleZXYf&,
                                         const gmtl::Matrix44f&);

   template gmtl::Matrix44f& setFrustum(gmtl::Matrix44f&, float, float, float,
                                        float, float, float);
   template gmtl::Matrix44d& setFrustum(gmtl::Matrix44d&, double, double,
                                        double, double, double, double);

   template gmtl::Matrix44f& setPerspective(gmtl::Matrix44f&, float,
                                            float, float, float);
   template gmtl::Matrix44d& setPerspective(gmtl::Matrix44d&, double,
                                            double, double, double);

   template gmtl::Matrix33f& setTrans(gmtl::Matrix33f&,
                                      const gmtl::VecBase<float, 2>&);
   template gmtl::Matrix33d& setTrans(gmtl::Matrix33d&,
                                      const gmtl::VecBase<double, 2>&);
   template gmtl::Matrix44f& setTrans(gmtl::Matrix44f&,
                                      const gmtl::VecBase<float, 3>&);
   template gmtl::Matrix44d& setTrans(gmtl::Matrix44d&,
                                      const gmtl::VecBase<double, 3>&);

   template gmtl::Matrix33f& setScale(gmtl::Matrix33f&, const gmtl::Vec2f&);
   template gmtl::Matrix33d& setScale(gmtl::Matrix33d&, const gmtl::Vec2d&);
   template gmtl::Matrix44f& setScale(gmtl::Matrix44f&, const gmtl::Vec3f&);
   template gmtl::Matrix44d& setScale(gmtl::Matrix44d&, const gmtl::Vec3d&);

   template gmtl::Matrix33f& setScale(gmtl::Matrix33f&, const float);
   template gmtl::Matrix33d& setScale(gmtl::Matrix33d&, const double);
   template gmtl::Matrix44f& setScale(gmtl::Matrix44f&, const float);
   template gmtl::Matrix44d& setScale(gmtl::Matrix44d&, const double);

   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&, const gmtl::AxisAnglef&);
   template gmtl::Matrix44d& setRot(gmtl::Matrix44d&, const gmtl::AxisAngled&);

   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::AxisAnglef&);
   template gmtl::Matrix44d& set(gmtl::Matrix44d&, const gmtl::AxisAngled&);

   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&,
                                    const gmtl::EulerAngleXYZf&);
   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&,
                                    const gmtl::EulerAngleZYXf&);
   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&,
                                    const gmtl::EulerAngleZXYf&);
   template gmtl::Matrix44d& setRot(gmtl::Matrix44d&,
                                    const gmtl::EulerAngleXYZd&);
   template gmtl::Matrix44d& setRot(gmtl::Matrix44d&,
                                    const gmtl::EulerAngleZYXd&);
   template gmtl::Matrix44d& setRot(gmtl::Matrix44d&,
                                    const gmtl::EulerAngleZXYd&);

   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::EulerAngleXYZf&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::EulerAngleZYXf&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::EulerAngleZXYf&);
   template gmtl::Matrix44d& set(gmtl::Matrix44d&, const gmtl::EulerAngleXYZd&);
   template gmtl::Matrix44d& set(gmtl::Matrix44d&, const gmtl::EulerAngleZYXd&);
   template gmtl::Matrix44d& set(gmtl::Matrix44d&, const gmtl::EulerAngleZXYd&);

   template float makeYRot(const gmtl::Matrix33f&);
   template float makeYRot(const gmtl::Matrix44f&);
   template double makeYRot(const gmtl::Matrix33d&);
   template double makeYRot(const gmtl::Matrix44d&);

   template float makeXRot(const gmtl::Matrix33f&);
   template float makeXRot(const gmtl::Matrix44f&);
   template double makeXRot(const gmtl::Matrix33d&);
   template double makeXRot(const gmtl::Matrix44d&);

   template float makeZRot(const gmtl::Matrix33f&);
   template float makeZRot(const gmtl::Matrix44f&);
   template double makeZRot(const gmtl::Matrix33d&);
   template double makeZRot(const gmtl::Matrix44d&);

   template gmtl::Matrix33f& setAxes(gmtl::Matrix33f&, const gmtl::Vec3f&,
                                       const gmtl::Vec3f&, const gmtl::Vec3f&);
   template gmtl::Matrix33d& setAxes(gmtl::Matrix33d&, const gmtl::Vec3d&,
                                       const gmtl::Vec3d&, const gmtl::Vec3d&);
   template gmtl::Matrix44f& setAxes(gmtl::Matrix44f&, const gmtl::Vec3f&,
                                       const gmtl::Vec3f&, const gmtl::Vec3f&);
   template gmtl::Matrix44d& setAxes(gmtl::Matrix44d&, const gmtl::Vec3d&,
                                       const gmtl::Vec3d&, const gmtl::Vec3d&);

   template gmtl::Matrix33f makeTranspose(const gmtl::Matrix33f&);
   template gmtl::Matrix44f makeTranspose(const gmtl::Matrix44f&);
   template gmtl::Matrix33d makeTranspose(const gmtl::Matrix33d&);
   template gmtl::Matrix44d makeTranspose(const gmtl::Matrix44d&);

   template gmtl::Matrix33f makeInvert(const gmtl::Matrix33f&);
   template gmtl::Matrix44f makeInvert(const gmtl::Matrix44f&);
   template gmtl::Matrix33d makeInvert(const gmtl::Matrix33d&);
   template gmtl::Matrix44d makeInvert(const gmtl::Matrix44d&);

   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord3fXYZ&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord3fZYX&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord3fZXY&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord4fXYZ&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord4fZYX&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord4fZXY&);

   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord3fXYZ&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord3fZYX&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord3fZXY&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord4fXYZ&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord4fZYX&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord4fZXY&);

   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord3fQuat&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Coord4fQuat&);

   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord3fQuat&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Coord4fQuat&);

   template gmtl::Matrix33f& set(gmtl::Matrix33f&,
                                 const gmtl::Coord3fAxisAngle&);
   template gmtl::Matrix33f& set(gmtl::Matrix33f&,
                                 const gmtl::Coord4fAxisAngle&);

   template gmtl::Matrix44f& set(gmtl::Matrix44f&,
                                 const gmtl::Coord3fAxisAngle&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&,
                                 const gmtl::Coord4fAxisAngle&);

   template gmtl::Matrix33f& setRot(gmtl::Matrix33f&, const gmtl::Quatf&);
   template gmtl::Matrix44f& setRot(gmtl::Matrix44f&, const gmtl::Quatf&);
   template gmtl::Matrix33d& setRot(gmtl::Matrix33d&, const gmtl::Quatd&);
   template gmtl::Matrix44d& setRot(gmtl::Matrix44d&, const gmtl::Quatd&);

   template gmtl::Matrix33f& set(gmtl::Matrix33f&, const gmtl::Quatf&);
   template gmtl::Matrix44f& set(gmtl::Matrix44f&, const gmtl::Quatf&);
   template gmtl::Matrix33d& set(gmtl::Matrix33d&, const gmtl::Quatd&);
   template gmtl::Matrix44d& set(gmtl::Matrix44d&, const gmtl::Quatd&);

   template gmtl::Coord3fXYZ& set(gmtl::Coord3fXYZ&, const gmtl::Matrix33f&);
   template gmtl::Coord3fZYX& set(gmtl::Coord3fZYX&, const gmtl::Matrix33f&);
   template gmtl::Coord3fZXY& set(gmtl::Coord3fZXY&, const gmtl::Matrix33f&);
   template gmtl::Coord4fXYZ& set(gmtl::Coord4fXYZ&, const gmtl::Matrix33f&);
   template gmtl::Coord4fZYX& set(gmtl::Coord4fZYX&, const gmtl::Matrix33f&);
   template gmtl::Coord4fZXY& set(gmtl::Coord4fZXY&, const gmtl::Matrix33f&);

   template gmtl::Coord3fXYZ& set(gmtl::Coord3fXYZ&, const gmtl::Matrix44f&);
   template gmtl::Coord3fZYX& set(gmtl::Coord3fZYX&, const gmtl::Matrix44f&);
   template gmtl::Coord3fZXY& set(gmtl::Coord3fZXY&, const gmtl::Matrix44f&);
   template gmtl::Coord4fXYZ& set(gmtl::Coord4fXYZ&, const gmtl::Matrix44f&);
   template gmtl::Coord4fZYX& set(gmtl::Coord4fZYX&, const gmtl::Matrix44f&);
   template gmtl::Coord4fZXY& set(gmtl::Coord4fZXY&, const gmtl::Matrix44f&);

   template gmtl::Coord3fQuat& set(gmtl::Coord3fQuat&, const gmtl::Matrix33f&);
   template gmtl::Coord4fQuat& set(gmtl::Coord4fQuat&, const gmtl::Matrix33f&);

   template gmtl::Coord3fQuat& set(gmtl::Coord3fQuat&, const gmtl::Matrix44f&);
   template gmtl::Coord4fQuat& set(gmtl::Coord4fQuat&, const gmtl::Matrix44f&);

   template gmtl::Coord3fXYZ& setRot(gmtl::Coord3fXYZ&,
                                     const gmtl::Matrix33f&);
   template gmtl::Coord3fZYX& setRot(gmtl::Coord3fZYX&,
                                     const gmtl::Matrix33f&);
   template gmtl::Coord3fZXY& setRot(gmtl::Coord3fZXY&,
                                     const gmtl::Matrix33f&);
   template gmtl::Coord4fXYZ& setRot(gmtl::Coord4fXYZ&,
                                     const gmtl::Matrix33f&);
   template gmtl::Coord4fZYX& setRot(gmtl::Coord4fZYX&,
                                     const gmtl::Matrix33f&);
   template gmtl::Coord4fZXY& setRot(gmtl::Coord4fZXY&,
                                     const gmtl::Matrix33f&);

   template gmtl::Coord3fXYZ& setRot(gmtl::Coord3fXYZ&,
                                     const gmtl::Matrix44f&);
   template gmtl::Coord3fZYX& setRot(gmtl::Coord3fZYX&,
                                     const gmtl::Matrix44f&);
   template gmtl::Coord3fZXY& setRot(gmtl::Coord3fZXY&,
                                     const gmtl::Matrix44f&);
   template gmtl::Coord4fXYZ& setRot(gmtl::Coord4fXYZ&,
                                     const gmtl::Matrix44f&);
   template gmtl::Coord4fZYX& setRot(gmtl::Coord4fZYX&,
                                     const gmtl::Matrix44f&);
   template gmtl::Coord4fZXY& setRot(gmtl::Coord4fZXY&,
                                     const gmtl::Matrix44f&);

   template gmtl::Coord3fQuat& setRot(gmtl::Coord3fQuat&,
                                      const gmtl::Matrix33f&);
   template gmtl::Coord4fQuat& setRot(gmtl::Coord4fQuat&,
                                      const gmtl::Matrix33f&);

   template gmtl::Coord3fQuat& setRot(gmtl::Coord3fQuat&,
                                      const gmtl::Matrix44f&);
   template gmtl::Coord4fQuat& setRot(gmtl::Coord4fQuat&,
                                      const gmtl::Matrix44f&);

   template void setRow(gmtl::Vec3f&, const gmtl::Matrix33f&, unsigned);
   template void setRow(gmtl::Vec3d&, const gmtl::Matrix33d&, unsigned);
   template void setRow(gmtl::Vec4f&, const gmtl::Matrix44f&, unsigned);
   template void setRow(gmtl::Vec4d&, const gmtl::Matrix44d&, unsigned);

   template gmtl::Vec3f makeRow(const gmtl::Matrix33f&, unsigned);
   template gmtl::Vec3d makeRow(const gmtl::Matrix33d&, unsigned);
   template gmtl::Vec4f makeRow(const gmtl::Matrix44f&, unsigned);
   template gmtl::Vec4d makeRow(const gmtl::Matrix44d&, unsigned);

   template void setColumn(gmtl::Vec3f&, const gmtl::Matrix33f&, unsigned);
   template void setColumn(gmtl::Vec3d&, const gmtl::Matrix33d&, unsigned);
   template void setColumn(gmtl::Vec4f&, const gmtl::Matrix44f&, unsigned);
   template void setColumn(gmtl::Vec4d&, const gmtl::Matrix44d&, unsigned);

   template gmtl::Vec3f makeColumn(const gmtl::Matrix33f&, unsigned);
   template gmtl::Vec3d makeColumn(const gmtl::Matrix33d&, unsigned);
   template gmtl::Vec4f makeColumn(const gmtl::Matrix44f&, unsigned);
   template gmtl::Vec4d makeColumn(const gmtl::Matrix44d&, unsigned);
}

#endif /* _PYGMTL_GENERATE_H_ */
