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
 * File:          $RCSfile: _Vec_double_4.cpp,v $
 * Date modified: $Date: 2003-05-20 18:57:15 $
 * Version:       $Revision: 1.1.1.1 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Vec.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Vec_double_4()
{
    scope* gmtl_Vec_double_4_scope = new scope(
    class_< gmtl::Vec<double,4>, bases< gmtl::VecBase<double,4> >  >("Vec4d", init<  >())
        .def(init< const gmtl::Vec<double,4> & >())
        .def(init< const gmtl::VecBase<double,4> & >())
        .def(init< const double &, const double & >())
        .def(init< const double &, const double &, const double & >())
        .def(init< const double &, const double &, const double &, const double & >())
    );

    enum_< gmtl::Vec<double,4>::Params >("Params")
        .value("Size", gmtl::Vec<double,4>::Size)
    ;

    delete gmtl_Vec_double_4_scope;

}
