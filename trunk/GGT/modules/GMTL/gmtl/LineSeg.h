/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: LineSeg.h,v $
 * Date modified: $Date: 2002-02-24 22:47:02 $
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
#ifndef _GMTL_LINESEG_H_
#define _GMTL_LINESEG_H_

#include <gmtl/gmtlConfig.h>
#include <gmtl/Point.h>
#include <gmtl/Vec.h>
#include <gmtl/VecOps.h>

namespace gmtl {

/**
 * Describes a line segment. This is represented by a point origin O and a
 * vector spanning the length of the line segement originating at O. Thus any
 * point on the line segment can be described as
 *
 * P(s) = O + Vs
 *
 * where 0 <= s <= 1
 *
 * @param DATA_TYPE     the internal type used for the point and vector
 */
template< class DATA_TYPE >
class LineSeg
{
public:
   /**
    * Constructs a line segment at the origin with a zero vector.
    */
   LineSeg()
   {}

   /**
    * Constructs a line segment with the given origin and vector.
    *
    * @param origin     the point at which the line segment starts
    * @param dir        the vector describing the direction and length of the
    *                   line segment starting at origin
    */
   LineSeg( const Point<DATA_TYPE, 3>& origin, const Vec<DATA_TYPE, 3>& dir )
      : mOrigin( origin ), mDir( dir )
   {}

   /**
    * Constructs a line segment with the given beginning and ending points.
    *
    * @param beg     the point at the beginning of the line segment
    * @param end     the point at the end of the line segment
    */
   LineSeg( const Point<DATA_TYPE, 3>& beg, const Point<DATA_TYPE, 3>& end )
      : mOrigin( beg )
   {
      mDir = end - beg;
   }

   /**
    * Constructs an exact duplicate of the given line segment.
    *
    * @param lineseg    the line segment to copy
    */
   LineSeg( const LineSeg& lineseg )
   {
      mOrigin = lineseg.mOrigin;
      mDir = lineseg.mDir;
   }

   /**
    * Gets the origin of the line segment.
    *
    * @return  the point at the beginning of the line
    */
   const Point<DATA_TYPE, 3>& getOrigin() const
   {
      return mOrigin;
   }

   /**
    * Sets the origin point for this line segment.
    *
    * @param origin     the point at which the line segment starts
    */
   void setOrigin( const Point<DATA_TYPE, 3>& origin )
   {
      mOrigin = origin;
   }

   /**
    * Gets the vector describing the direction and length of the line segment.
    *
    * @return  the line segment's vector
    */
   const Vec<DATA_TYPE, 3>& getDir() const
   {
      return mDir;
   }

   /**
    * Sets the vector describing the direction and length of the line segment.
    *
    * @param dir     the line segment's vector
    */
   void setDir( const Vec<DATA_TYPE, 3>& dir )
   {
      mDir = dir;
   }

   /**
    * Gets the length of this line segment.
    */
   const DATA_TYPE& getLength() const
   {
      return length( dir );
   }

public:
   /**
    * The origin of the line segment.
    */
   Point<DATA_TYPE, 3> mOrigin;

   /**
    * The vector along which the line segment lies.
    */
   Vec<DATA_TYPE, 3> mDir;
};

// --- helper types --- //
typedef LineSeg<float>  LineSegf;
typedef LineSeg<double> LineSegd;

}

#endif
