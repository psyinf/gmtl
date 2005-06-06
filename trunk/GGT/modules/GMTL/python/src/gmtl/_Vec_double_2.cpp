/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: _Vec_double_2.cpp,v $
 * Date modified: $Date: 2005-06-06 03:57:41 $
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
#include <gmtl/Vec.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Vec_double_2()
{
    scope* gmtl_Vec_double_2_scope = new scope(
    class_< gmtl::Vec<double,2>, bases< gmtl::VecBase<double,2> >  >("Vec2d", init<  >())
        .def(init< const gmtl::Vec<double,2> & >())
        .def(init< const gmtl::VecBase<double,2> & >())
        .def(init< const double &, const double & >())
        .def_pickle(gmtlPickle::Vec2_pickle<double>())
    );

    enum_< gmtl::Vec<double,2>::Params >("Params")
        .value("Size", gmtl::Vec<double,2>::Size)
    ;

    delete gmtl_Vec_double_2_scope;

}
