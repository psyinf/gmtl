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
 * File:          $RCSfile: _VecBase_float_4.cpp,v $
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
void _Export_VecBase_float_4()
{
    scope* gmtl_VecBase_float_4_scope = new scope(
    class_< gmtl::VecBase<float,4> >("VecBase4f", init<  >())
        .def(init< const gmtl::VecBase<float,4> & >())
        .def(init< const float &, const float &, const float &, const float & >())
        .def("set", (void (gmtl::VecBase<float,4>::*)(const float &, const float &, const float &, const float &) )&gmtl::VecBase<float,4>::set)
        .def("set", (void (*)(gmtl::VecBase<float,4>*, list))&gmtlWrappers::VecBase_set)
        .def("getData", (tuple (*)(gmtl::VecBase<float,4>*)) &gmtlWrappers::VecBase_4_getData)
        .add_property("data", (tuple (*)(gmtl::VecBase<float,4>*)) &gmtlWrappers::VecBase_4_getData)
        .def("__getitem__", (float& (gmtl::VecBase<float,4>::*)(const unsigned) ) &gmtl::VecBase<float,4>::operator[], return_value_policy<copy_non_const_reference>())
        .def("__setitem__", (void (*)(gmtl::VecBase<float,4>*, const unsigned, float)) &gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::VecBase4_pickle<float>())
        .def(-self)
        .def(self += self)
        .def(self + self)
        .def(self -= self)
        .def(self - self)
        .def(self *= float())
        .def(self * float())
        .def(float() * self)
        .def(self /= float())
        .def(self / float())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    );

    enum_< gmtl::VecBase<float,4>::Params >("Params")
        .value("Size", gmtl::VecBase<float,4>::Size)
    ;

    delete gmtl_VecBase_float_4_scope;

}
