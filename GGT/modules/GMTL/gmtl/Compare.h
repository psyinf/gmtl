/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: Compare.h,v $
 * Date modified: $Date: 2002-02-18 22:59:57 $
 * Version:       $Revision: 1.6 $
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
#ifndef _GMTL_COMPARE_H_
#define _GMTL_COMPARE_H_

#include <gmtl/gmtlConfig.h>

// Core types
#include <gmtl/Vec.h>
#include <gmtl/Point.h>
#include <gmtl/Sphere.h>
#include <gmtl/Tri.h>
#include <gmtl/Matrix.h>
#include <gmtl/Plane.h>

namespace gmtl
{
// --- MATRIX comparisons -- //

/** Compare two mats */
template <typename DATA_TYPE, unsigned ROWS, unsigned COLS>
inline bool operator==( const Matrix<DATA_TYPE, ROWS, COLS>& lhs, const Matrix<DATA_TYPE, ROWS, COLS>& rhs )
{
   for (unsigned int i = 0; i < ROWS*COLS; ++i)
   {
      if (lhs[i] != rhs[i])
      {
         return false;
      }
   }

   return true;

   /*  Would like this
   return( lhs[0] == rhs[0] &&
           lhs[1] == rhs[1] &&
           lhs[2] == rhs[2] );
   */
}

template <typename DATA_TYPE, unsigned ROWS, unsigned COLS>
inline bool operator!=( const Matrix<DATA_TYPE, ROWS, COLS>& lhs, const Matrix<DATA_TYPE, ROWS, COLS>& rhs )
{
   return bool( !(lhs == rhs) );
}

/** Compare two vectors with a tolerance
* @pre eps must be >= 0
*/
template <typename DATA_TYPE, unsigned ROWS, unsigned COLS>
inline bool isEqual( const Matrix<DATA_TYPE, ROWS, COLS>& lhs, const Matrix<DATA_TYPE, ROWS, COLS>& rhs, const DATA_TYPE& eps = (DATA_TYPE)0 )
{
   ggtASSERT( eps >= (DATA_TYPE)0 );

   for (unsigned int i = 0; i < ROWS*COLS; ++i)
   {
      if (!Math::isEqual( lhs[i], rhs[i], eps ))
         return false;
   }
   return true;
}


// --- VEC comparisons -- //


/** Compare two vecs */
template<class DATA_TYPE, unsigned SIZE>
inline bool operator ==(const VecBase<DATA_TYPE, SIZE>& v1, const VecBase<DATA_TYPE, SIZE>& v2)
{
   for(unsigned i=0;i<SIZE;++i)
   {
      if(v1[i] != v2[i])
      {
         return false;
      }
   }

   return true;

   /*  Would like this
   return(vec[0] == _v[0] &&
          vec[1] == _v[1] &&
          vec[2] == _v[2]);
          */
}

template<class DATA_TYPE, unsigned SIZE>
inline bool operator !=(const VecBase<DATA_TYPE, SIZE>& v1, const VecBase<DATA_TYPE, SIZE>& v2)
{
   return(! (v1 == v2));
}

/** Compare two vectors with a tolerance
* @pre eps must be >= 0
*/
template<class DATA_TYPE, unsigned SIZE>
inline bool isEqual(const VecBase<DATA_TYPE, SIZE>& v1, const VecBase<DATA_TYPE, SIZE>& v2, const DATA_TYPE& eps)
{
   ggtASSERT(eps >= 0);

  for(int i=0;i<SIZE;++i)
  {
     if (fabs(v1[i] - v2[i]) > eps)
        return false;
  }
  return true;
}

// --- Triangle comparisons -- //
/**
 * Compare two triangles to see if they are EXACTLY the same. In other words,
 * this comparison is done with zero tolerance.
 * 
 * @param tri1    the first triangle to compare
 * @param tri2    the second triangle to compare
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
bool operator==( const Tri<DATA_TYPE>& tri1, const Tri<DATA_TYPE>& tri2 )
{
   return ( (tri1[0] == tri2[0]) &&
            (tri1[1] == tri2[1]) &&
            (tri1[2] == tri2[2]) );
}

/**
 * Compare two triangle to see if they are not EXACTLY the same. In other words,
 * this comparison is done with zero tolerance.
 *
 * @param tri1    the first triangle to compare
 * @param tri2    the second triangle to compare
 *
 * @return  true if they are not equal, false otherwise
 */
template< class DATA_TYPE >
bool operator!=( const Tri<DATA_TYPE>& tri1, const Tri<DATA_TYPE>& tri2 )
{
   return (! (tri1 == tri2));
}

/**
 * Compare two triangles to see if they are the same within the given tolerance.
 *
 * @param tri1    the first triangle to compare
 * @param tri2    the second triangle to compare
 * @param eps     the tolerance value to use
 *
 * @pre  eps must be >= 0
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
bool isEqual( const Tri<DATA_TYPE>& tri1, const Tri<DATA_TYPE>& tri2,
              const DATA_TYPE& eps )
{
   ggtASSERT( eps >= 0 );
   return ( isEqual(tri1[0], tri2[0], eps) &&
            isEqual(tri1[1], tri2[1], eps) &&
            isEqual(tri1[2], tri2[2], eps) );
}

// --- Sphere comparisons -- //

/**
 * Compare two spheres to see if they are EXACTLY the same. In other words, this
 * comparison is done with zero tolerance.
 *
 * @param s1      the first sphere to compare
 * @param s2      the second sphere to compare
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator==( const Sphere<DATA_TYPE>& s1, const Sphere<DATA_TYPE>& s2 )
{
   return ( (s1.mCenter == s2.mCenter) && (s1.mRadius == s2.mRadius) );
}

/**
 * Compare two spheres to see if they are not EXACTLY the same. In other words,
 * this comparison is done with zero tolerance.
 *
 * @param s1      the first sphere to compare
 * @param s2      the second sphere to compare
 *
 * @return  true if they are not equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator!=( const Sphere<DATA_TYPE>& s1, const Sphere<DATA_TYPE>& s2 )
{
   return (! (s1 == s2));
}

/**
 * Compare two spheres to see if they are the same within the given tolerance.
 *
 * @param s1      the first sphere to compare
 * @param s2      the second sphere to compare
 * @param eps     the tolerance value to use
 *
 * @pre eps must be >= 0
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool isEqual( const Sphere<DATA_TYPE>& s1, const Sphere<DATA_TYPE>& s2, const DATA_TYPE& eps )
{
   ggtASSERT( eps >= 0 );
   return ( (isEqual(s1.mCenter, s2.mCenter, eps)) && (fabs(s1.mRadius - s2.mRadius) <= eps) );
}

//--- Plane Comparisons --//
/**
 * Compare two planes to see if they are EXACTLY the same. In other words, this
 * comparison is done with zero tolerance.
 *
 * @param p1      the first plane to compare
 * @param p2      the second plane to compare
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator==( const Plane<DATA_TYPE>& p1, const Plane<DATA_TYPE>& p2 )
{
   return ( (p1.mNorm == p2.mNorm) && (p1.mOffset == p2.mOffset) );
}

/**
 * Compare two planes to see if they are not EXACTLY the same. In other words,
 * this comparison is done with zero tolerance.
 *
 * @param p1      the first plane to compare
 * @param p2      the second plane to compare
 *
 * @return  true if they are not equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator!=( const Plane<DATA_TYPE>& p1, const Plane<DATA_TYPE>& p2 )
{
   return (! (p1 == p2));
}

/**
 * Compare two planes to see if they are the same within the given tolerance.
 *
 * @param p1      the first plane to compare
 * @param p2      the second plane to compare
 * @param eps     the tolerance value to use
 *
 * @pre eps must be >= 0
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool isEqual( const Plane<DATA_TYPE>& p1, const Plane<DATA_TYPE>& p2,
                     const DATA_TYPE& eps )
{
   ggtASSERT( eps >= 0 );
   return ( (isEqual(p1.mNorm, p2.mNorm, eps)) &&
            (Math::isEqual(p1.mOffset, p2.mOffset, eps)) );
}


};

#endif

