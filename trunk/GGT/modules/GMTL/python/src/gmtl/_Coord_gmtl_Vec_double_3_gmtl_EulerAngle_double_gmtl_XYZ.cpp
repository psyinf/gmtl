/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * PyJuggler is (C) Copyright 2002, 2003 by Patrick Hartling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: _Coord_gmtl_Vec_double_3_gmtl_EulerAngle_double_gmtl_XYZ.cpp,v $
 * Date modified: $Date: 2004-10-27 19:01:33 $
 * Version:       $Revision: 1.2 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Coord.h>
#include <gmtl/EulerAngleOps.h>
#include <gmtl/CoordOps.h>
#include <gmtl/Output.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Coord_gmtl_Vec_double_3_gmtl_EulerAngle_double_gmtl_XYZ()
{
    scope* gmtl_Coord_gmtl_Vec_double_3_gmtl_EulerAngle_double_gmtl_XYZ_scope = new scope(
    class_< gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> > >("Coord3dXYZ", init<  >())
        .def(init< const gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> > & >())
        .def(init< const gmtl::Vec<double,3> &, const gmtl::EulerAngle<double,gmtl::XYZ> & >())
        .def_readwrite("mPos", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::mPos)
        .def_readwrite("mRot", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::mRot)
        .def("getPos", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::getPos, return_internal_reference< 1 >())
        .def("getRot", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::getRot, return_internal_reference< 1 >())
        .def("pos", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::pos, return_internal_reference< 1 >())
        .def("rot", &gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::rot, return_internal_reference< 1 >())
        .def_pickle(gmtlPickle::Coord_pickle< gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >())
        .def(self == self)
        .def(self != self)
    );

    enum_< gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::Params >("Params")
        .value("RotSize", gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::RotSize)
        .value("PosSize", gmtl::Coord<gmtl::Vec<double, 3>,gmtl::EulerAngle<double, gmtl::XYZ> >::PosSize)
    ;

    delete gmtl_Coord_gmtl_Vec_double_3_gmtl_EulerAngle_double_gmtl_XYZ_scope;

}
