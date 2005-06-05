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
 * File:          $RCSfile: _Tri_float.cpp,v $
 * Date modified: $Date: 2005-06-05 22:19:45 $
 * Version:       $Revision: 1.5 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Tri.h>
#include <gmtl/TriOps.h>
#include <gmtl/Output.h>
#include <gmtl-wrappers.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Tri_float()
{
    class_< gmtl::Tri<float> >("Trif", init<  >())
        .def(init< const gmtl::Point<float,3> &, const gmtl::Point<float,3> &, const gmtl::Point<float,3> & >())
        .def(init< const gmtl::Tri<float> & >())
        .def("edge", (gmtl::Vec<float, 3> (gmtl::Tri<float>::*)(int) const) &gmtl::Tri<float>::edge)
        .def("edge", (gmtl::Vec<float, 3> (gmtl::Tri<float>::*)(int, int) const) &gmtl::Tri<float>::edge)
        .def("set", &gmtl::Tri<float>::set)
        .def("__getitem__", (gmtl::Point<float, 3>& (gmtl::Tri<float>::*)(const unsigned)) &gmtl::Tri<float>::operator[], return_internal_reference< 1 >())
        .def("__setitem__", (void (*)(gmtl::Tri<float>*, const unsigned, const gmtl::Point<float, 3>&)) gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::Tri_pickle<float>())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    ;

}
