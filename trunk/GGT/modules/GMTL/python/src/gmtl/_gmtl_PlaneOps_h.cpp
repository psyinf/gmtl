/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: _gmtl_PlaneOps_h.cpp,v $
 * Date modified: $Date: 2003-08-30 17:22:10 $
 * Version:       $Revision: 1.2 $
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
#include <gmtl-PlaneOps.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_gmtl_PlaneOps_h()
{
    def("findNearestPt", (float (*)(const gmtl::Plane<float> &, const gmtl::Point<float,3> &, gmtl::Point<float,3> &))&gmtl::findNearestPt);
    def("findNearestPt", (double (*)(const gmtl::Plane<double> &, const gmtl::Point<double,3> &, gmtl::Point<double,3> &))&gmtl::findNearestPt);
    def("distance", (double (*)(const gmtl::Plane<double> &, const gmtl::Point<double,3> &))&gmtl::distance);
    def("distance", (float (*)(const gmtl::Plane<float> &, const gmtl::Point<float,3> &))&gmtl::distance);
    def("whichSide", (gmtl::PlaneSide (*)(const gmtl::Plane<double> &, const gmtl::Point<double,3> &))&gmtl::whichSide);
    def("whichSide", (gmtl::PlaneSide (*)(const gmtl::Plane<float> &, const gmtl::Point<float,3> &))&gmtl::whichSide);
    def("whichSide", (gmtl::PlaneSide (*)(const gmtl::Plane<double> &, const gmtl::Point<double,3> &, const double &))&gmtl::whichSide);
    def("whichSide", (gmtl::PlaneSide (*)(const gmtl::Plane<float> &, const gmtl::Point<float,3> &, const float &))&gmtl::whichSide);
    def("isEqual", (bool (*)(const gmtl::Plane<float> &, const gmtl::Plane<float> &, const float &))&gmtl::isEqual);
    def("isEqual", (bool (*)(const gmtl::Plane<double> &, const gmtl::Plane<double> &, const double &))&gmtl::isEqual);
}
