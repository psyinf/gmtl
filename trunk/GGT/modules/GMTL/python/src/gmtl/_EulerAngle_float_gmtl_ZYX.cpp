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
 * File:          $RCSfile: _EulerAngle_float_gmtl_ZYX.cpp,v $
 * Date modified: $Date: 2004-10-27 19:01:33 $
 * Version:       $Revision: 1.4 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/EulerAngle.h>
#include <gmtl/EulerAngleOps.h>
#include <gmtl/Output.h>
#include <gmtl-wrappers.h>
#include <gmtl-getData-wrappers.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_EulerAngle_float_gmtl_ZYX()
{
    scope* gmtl_EulerAngle_float_gmtl_ZYX_scope = new scope(
    class_< gmtl::EulerAngle<float,gmtl::ZYX> >("EulerAngleZYXf", init<  >())
        .def(init< const gmtl::EulerAngle<float,gmtl::ZYX> & >())
        .def(init< float, float, float >())
        .def("set", &gmtl::EulerAngle<float,gmtl::ZYX>::set)
        .def("getData", (tuple (*)(gmtl::EulerAngle<float,gmtl::ZYX>*)) &gmtlWrappers::EulerAngle_getData)
        .add_property("data", (tuple (*)(gmtl::EulerAngle<float,gmtl::ZYX>*)) &gmtlWrappers::EulerAngle_getData)
        .def("__getitem__", (float& (gmtl::EulerAngle<float,gmtl::ZYX>::*)(const unsigned) ) &gmtl::EulerAngle<float,gmtl::ZYX>::operator[], return_value_policy<copy_non_const_reference>())
        .def("__setitem__", (void (*)(gmtl::EulerAngle<float,gmtl::ZYX>*, const unsigned, float)) &gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::EulerAngle_pickle<float, gmtl::ZYX>())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    );

    enum_< gmtl::EulerAngle<float,gmtl::ZYX>::Params >("Params")
        .value("Order", gmtl::EulerAngle<float,gmtl::ZYX>::Order)
        .value("Size", gmtl::EulerAngle<float,gmtl::ZYX>::Size)
    ;

    delete gmtl_EulerAngle_float_gmtl_ZYX_scope;

}
