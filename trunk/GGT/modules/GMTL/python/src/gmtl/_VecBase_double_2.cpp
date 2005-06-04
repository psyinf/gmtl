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
 * File:          $RCSfile: _VecBase_double_2.cpp,v $
 * Date modified: $Date: 2005-06-04 19:34:43 $
 * Version:       $Revision: 1.6 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/VecBase.h>
#include <gmtl/Output.h>
#include <gmtl-wrappers.h>
#include <gmtl-array-wrappers.h>
#include <gmtl-getData-wrappers.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_VecBase_double_2()
{
    scope* gmtl_VecBase_double_2_scope = new scope(
    class_< gmtl::VecBase<double,2> >("VecBase2d", init<  >())
        .def(init< const gmtl::VecBase<double,2> & >())
        .def(init< const double &, const double & >())
        .def("set", (void (gmtl::VecBase<double,2>::*)(const double &, const double &) )&gmtl::VecBase<double,2>::set)
        .def("set", (void (*)(gmtl::VecBase<double,2>*, list))&gmtlWrappers::VecBase_set)
        .def("getData", (tuple (*)(gmtl::VecBase<double,2>*)) &gmtlWrappers::VecBase_2_getData)
        .add_property("data", (tuple (*)(gmtl::VecBase<double,2>*)) &gmtlWrappers::VecBase_2_getData)
        .def("__getitem__", (double& (gmtl::VecBase<double,2>::*)(const unsigned) ) &gmtl::VecBase<double,2>::operator[], return_value_policy<copy_non_const_reference>())
        .def("__setitem__", (void (*)(gmtl::VecBase<double,2>*, const unsigned, double)) &gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::VecBase2_pickle<double>())
        .def(-self)
        .def(self += self)
        .def(self + self)
        .def(self -= self)
        .def(self - self)
        .def(self *= double())
        .def(self * double())
        .def(double() * self)
        .def(self /= double())
        .def(self / double())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    );

    enum_< gmtl::VecBase<double,2>::Params >("Params")
        .value("Size", gmtl::VecBase<double,2>::Size)
    ;

    delete gmtl_VecBase_double_2_scope;

}
