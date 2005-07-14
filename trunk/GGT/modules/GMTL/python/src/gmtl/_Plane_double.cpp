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
 * File:          $RCSfile: _Plane_double.cpp,v $
 * Date modified: $Date: 2005-07-14 02:48:22 $
 * Version:       $Revision: 1.4 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Plane.h>
#include <gmtl/PlaneOps.h>
#include <gmtl/Output.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Plane_double()
{
    class_< gmtl::Plane<double> >("Planed", init<  >())
        .def(init< const gmtl::Point<double,3> &, const gmtl::Point<double,3> &, const gmtl::Point<double,3> & >())
        .def(init< const gmtl::Vec<double,3> &, const gmtl::Point<double,3> & >())
        .def(init< const gmtl::Vec<double,3> &, const double & >())
        .def(init< const gmtl::Plane<double> & >())
        .def_readwrite("norm", &gmtl::Plane<double>::mNorm)
        .def_readwrite("offset", &gmtl::Plane<double>::mOffset)
        .def("getNormal", &gmtl::Plane<double>::getNormal, return_value_policy< copy_const_reference >())
        .def("setNormal", &gmtl::Plane<double>::setNormal)
        .def("getOffset", &gmtl::Plane<double>::getOffset, return_value_policy< copy_const_reference >())
        .def("setOffset", &gmtl::Plane<double>::setOffset)
        .def("set",
             (gmtl::Plane<double>& (gmtl::Plane<double>::*)(const gmtl::Plane<double>&)) &gmtl::Plane<double>::operator=,
             return_internal_reference<1>())
        .def_pickle(gmtlPickle::Plane_pickle<double>())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    ;

}
