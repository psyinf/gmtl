/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: _gmtl_MatrixOps_h.cpp,v $
 * Date modified: $Date: 2004-05-25 17:00:23 $
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

// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl-MatrixOps.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {


BOOST_PYTHON_FUNCTION_OVERLOADS(isEqual_overloads_2_3, gmtl::isEqual, 2, 3)


}// namespace 

// Module ======================================================================
void _Export_gmtl_MatrixOps_h()
{
    def("add", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::add, return_internal_reference< 1 >());
    def("add", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::add, return_internal_reference< 1 >());
    def("identity", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &))&gmtl::identity, return_internal_reference< 1 >());
    def("identity", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &))&gmtl::identity, return_internal_reference< 1 >());
    def("invert", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::invert, return_internal_reference< 1 >());
    def("invert", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::invert, return_internal_reference< 1 >());
    def("invert", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &))&gmtl::invert, return_internal_reference< 1 >());
    def("invert", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &))&gmtl::invert, return_internal_reference< 1 >());
    def("invertFull", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::invertFull, return_internal_reference< 1 >());
    def("invertFull", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::invertFull, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::mult, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &, const float &))&gmtl::mult, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &, const float &))&gmtl::mult, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, float))&gmtl::mult, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::mult, return_internal_reference< 1 >());
    def("mult", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, float))&gmtl::mult, return_internal_reference< 1 >());
    def("postMult", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::postMult, return_internal_reference< 1 >());
    def("postMult", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::postMult, return_internal_reference< 1 >());
    def("preMult", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::preMult, return_internal_reference< 1 >());
    def("preMult", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::preMult, return_internal_reference< 1 >());
    def("sub", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::sub, return_internal_reference< 1 >());
    def("sub", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::sub, return_internal_reference< 1 >());
    def("transpose", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &))&gmtl::transpose, return_internal_reference< 1 >());
    def("transpose", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &))&gmtl::transpose, return_internal_reference< 1 >());
    def("transpose", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &))&gmtl::transpose, return_internal_reference< 1 >());
    def("transpose", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &))&gmtl::transpose, return_internal_reference< 1 >());
    def("zero", (gmtl::Matrix<float,3,3> & (*)(gmtl::Matrix<float,3,3> &))&gmtl::zero, return_internal_reference< 1 >());
    def("zero", (gmtl::Matrix<float,4,4> & (*)(gmtl::Matrix<float,4,4> &))&gmtl::zero, return_internal_reference< 1 >());
    def("isEqual", (bool (*)(const gmtl::Matrix<float,4,4> &, const gmtl::Matrix<float,4,4> &, const float))&gmtl::isEqual, isEqual_overloads_2_3());
    def("isEqual", (bool (*)(const gmtl::Matrix<float,3,3> &, const gmtl::Matrix<float,3,3> &, const float))&gmtl::isEqual, isEqual_overloads_2_3());
}
