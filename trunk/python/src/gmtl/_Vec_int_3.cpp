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
 * File:          $RCSfile: _Vec_int_3.cpp,v $
 * Date modified: $Date: 2005-06-06 03:57:41 $
 * Version:       $Revision: 1.5 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Vec.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Vec_int_3()
{
    scope* gmtl_Vec_int_3_scope = new scope(
    class_< gmtl::Vec<int,3>, bases< gmtl::VecBase<int,3> >  >("Vec3i", init<  >())
        .def(init< const gmtl::Vec<int,3> & >())
        .def(init< const gmtl::VecBase<int,3> & >())
        .def(init< const int &, const int &, const int & >())
        .def_pickle(gmtlPickle::Vec3_pickle<int>())
    );

    enum_< gmtl::Vec<int,3>::Params >("Params")
        .value("Size", gmtl::Vec<int,3>::Size)
    ;

    delete gmtl_Vec_int_3_scope;

}
