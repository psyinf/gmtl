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
 * File:          $RCSfile: _Tri_double.cpp,v $
 * Date modified: $Date: 2005-07-14 02:48:22 $
 * Version:       $Revision: 1.6 $
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
void _Export_Tri_double()
{
    class_< gmtl::Tri<double> >("Trid", init<  >())
        .def(init< const gmtl::Point<double,3> &, const gmtl::Point<double,3> &, const gmtl::Point<double,3> & >())
        .def(init< const gmtl::Tri<double> & >())
        .def("edge", (gmtl::Vec<double, 3> (gmtl::Tri<double>::*)(int) const) &gmtl::Tri<double>::edge)
        .def("edge", (gmtl::Vec<double, 3> (gmtl::Tri<double>::*)(int, int) const) &gmtl::Tri<double>::edge)
        .def("set", &gmtl::Tri<double>::set)
        .def("set",
             (gmtl::Tri<double>& (gmtl::Tri<double>::*)(const gmtl::Tri<double>&)) &gmtl::Tri<double>::operator=,
             return_internal_reference<1>())
        .def("__getitem__", (gmtl::Point<double, 3>& (gmtl::Tri<double>::*)(const unsigned)) &gmtl::Tri<double>::operator[], return_internal_reference< 1 >())
        .def("__setitem__", (void (*)(gmtl::Tri<double>*, const unsigned, const gmtl::Point<double, 3>&)) gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::Tri_pickle<double>())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    ;

}
