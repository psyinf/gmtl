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
 * File:          $RCSfile: _gmtl_Defines_h.cpp,v $
 * Date modified: $Date: 2003-05-20 18:57:15 $
 * Version:       $Revision: 1.1.1.1 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Defines.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_gmtl_Defines_h()
{
    enum_< gmtl::PlaneSide >("PlaneSide")
        .value("NEG_SIDE", gmtl::NEG_SIDE)
        .value("POS_SIDE", gmtl::POS_SIDE)
        .value("ON_PLANE", gmtl::ON_PLANE)
    ;

    enum_< gmtl::VectorIndex >("VectorIndex")
        .value("Xelt", gmtl::Xelt)
        .value("Yelt", gmtl::Yelt)
        .value("Welt", gmtl::Welt)
        .value("Zelt", gmtl::Zelt)
    ;

}
