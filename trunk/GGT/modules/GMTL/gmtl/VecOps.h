/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: VecOps.h,v $
 * Date modified: $Date: 2002-07-02 03:09:21 $
 * Version:       $Revision: 1.19 $
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
#ifndef _GMTL_VEC_OPS_H_
#define _GMTL_VEC_OPS_H_

#include "gmtl/Defines.h"
#include "gmtl/Math.h"
#include "gmtl/Vec.h"

namespace gmtl
{

/** @ingroup Ops
 * @name Vector/Point Operations
 * @{
 */
   
// --- Basic VEC types operations -- //
  
/**
 * Negates v1.  The result = -v1.
 *
 * @param v1   the vector.
 *
 * @return  the result of negating v1.
 */
template<typename DATA_TYPE, unsigned SIZE>
Vec<DATA_TYPE, SIZE> operator- (const VecBase<DATA_TYPE, SIZE>& v1)
{
   Vec<DATA_TYPE, SIZE> ret_val;
   for ( unsigned i=0; i < SIZE; ++i )
   {
      ret_val[i] = -v1[i];
   }
   return ret_val;
}

/**
 * Adds v2 to v1 and stores the result in v1. This is equivalent to the
 * expression v1 = v1 + v2.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  v1 after v2 has been added to it
 */
template<class DATA_TYPE, unsigned SIZE>
VecBase<DATA_TYPE, SIZE>& operator +=(VecBase<DATA_TYPE, SIZE>& v1,
                                      const VecBase<DATA_TYPE, SIZE>& v2)
{
   for(unsigned i=0;i<SIZE;++i)
   {
      v1[i] += v2[i];
   }

   return v1;
}

/**
 * Adds v2 to v1 and returns the result. Thus result = v1 + v2.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  the result of adding v2 to v1
 */
template<class DATA_TYPE, unsigned SIZE>
VecBase<DATA_TYPE, SIZE> operator +(const VecBase<DATA_TYPE, SIZE>& v1,
                                    const VecBase<DATA_TYPE, SIZE>& v2)
{
   VecBase<DATA_TYPE, SIZE> ret_val(v1);
   ret_val += v2;
   return ret_val;
}

/**
 * Subtracts v2 from v1 and stores the result in v1. This is equivalent to the
 * expression v1 = v1 - v2.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  v1 after v2 has been subtracted from it
 */
template<class DATA_TYPE, unsigned SIZE>
VecBase<DATA_TYPE, SIZE>& operator -=(VecBase<DATA_TYPE, SIZE>& v1,
                                      const VecBase<DATA_TYPE, SIZE>& v2)
{
   for(unsigned i=0;i<SIZE;++i)
   {
      v1[i] -= v2[i];
   }

   return v1;
}

/**
 * Subtracts v2 from v1 and returns the result. Thus result = v1 - v2.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  the result of subtracting v2 from v1
 */
template < class DATA_TYPE, unsigned SIZE>
Vec<DATA_TYPE, SIZE> operator -(const VecBase<DATA_TYPE, SIZE>& v1,
                                const VecBase<DATA_TYPE, SIZE>& v2)
{
   Vec<DATA_TYPE, SIZE> ret_val(v1);
   ret_val -= v2;
   return ret_val;
}

/**
 * Multiplies v1 by a scalar value and stores the result in v1. This is
 * equivalent to the expression v1 = v1 * scalar.
 *
 * @param v1      the vector to scale
 * @param scalar  the amount by which to scale v1
 *
 * @return  v1 after it has been mutiplied by scalar
 */
template<class DATA_TYPE, unsigned SIZE, class SCALAR_TYPE>
VecBase<DATA_TYPE, SIZE>& operator *=(VecBase<DATA_TYPE, SIZE>& v1,
                                      const SCALAR_TYPE& scalar)
{
   for(unsigned i=0;i<SIZE;++i)
   {
      v1[i] *= (DATA_TYPE)scalar;
   }

   return v1;
}

/**
 * Multiplies v1 by a scalar value and returns the result. Thus result = v1 *
 * scalar.
 *
 * @param v1      the vector to scale
 * @param scalar  the amount by which to scale v1
 *
 * @return  the result of multiplying v1 by scalar
 */
template<class DATA_TYPE, unsigned SIZE, class SCALAR_TYPE>
VecBase<DATA_TYPE, SIZE> operator *(const VecBase<DATA_TYPE, SIZE>& v1,
                                    const SCALAR_TYPE& scalar)
{
   VecBase<DATA_TYPE, SIZE> ret_val(v1);
   ret_val *= scalar;
   return ret_val;

   //return VecBase<DATA_TYPE, SIZE>(v1) *= scalar;
}

/**
 * Multiplies v1 by a scalar value and returns the result. Thus result = scalar
 * * v1. This is equivalent to result = v1 * scalar.
 *
 * @param scalar  the amount by which to scale v1
 * @param v1      the vector to scale
 *
 * @return  the result of multiplying v1 by scalar
 */
template<class DATA_TYPE, unsigned SIZE, class SCALAR_TYPE>
VecBase<DATA_TYPE, SIZE> operator *(const SCALAR_TYPE& scalar,
                                    const VecBase<DATA_TYPE, SIZE>& v1)
{
   VecBase<DATA_TYPE, SIZE> ret_val(v1);
   ret_val *= scalar;
   return ret_val;

   //return VecBase<DATA_TYPE, SIZE>(v1) *= scalar;
}

/**
 * Divides v1 by a scalar value and stores the result in v1. This is
 * equivalent to the expression v1 = v1 / scalar.
 *
 * @param v1      the vector to scale
 * @param scalar  the amount by which to scale v1
 *
 * @return  v1 after it has been divided by scalar
 */
template<class DATA_TYPE, unsigned SIZE, class SCALAR_TYPE>
VecBase<DATA_TYPE, SIZE>& operator /=(VecBase<DATA_TYPE, SIZE>& v1,
                                      const SCALAR_TYPE& scalar)
{
   for(unsigned i=0;i<SIZE;++i)
   {
      v1[i] /= scalar;
   }

   return v1;
}

/**
 * Divides v1 by a scalar value and returns the result. Thus result = v1 /
 * scalar.
 *
 * @param v1      the vector to scale
 * @param scalar  the amount by which to scale v1
 *
 * @return  the result of dividing v1 by scalar
 */
template<class DATA_TYPE, unsigned SIZE, class SCALAR_TYPE>
VecBase<DATA_TYPE, SIZE> operator /(const VecBase<DATA_TYPE, SIZE>& v1,
                                    const SCALAR_TYPE& scalar)
{
   VecBase<DATA_TYPE, SIZE> ret_val(v1);
   ret_val /= scalar;
   return ret_val;
   // return VecBase<DATA_TYPE, SIZE>(v1)( /= scalar;
}

/** @} */

/** @ingroup Ops
 *  @name Vector Operations
 * @{ 
 */

/**
 * Computes dot product of v1 and v2 and returns the result.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return the dotproduct of v1 and v2
 */
template<class DATA_TYPE, unsigned SIZE>
DATA_TYPE dot(const Vec<DATA_TYPE, SIZE>& v1, const Vec<DATA_TYPE, SIZE>& v2)
{
   DATA_TYPE ret_val(0);
   for(unsigned i=0;i<SIZE;++i)
   {
      ret_val += (v1[i] * v2[i]);
   }
   return ret_val;
}

/**
 * Computes the length of the given vector.
 *
 * @param v1   the vector with which to compute the length
 *
 * @return  the length of v1
 */
template<class DATA_TYPE, unsigned SIZE>
DATA_TYPE length(const Vec<DATA_TYPE, SIZE>& v1)
{
   DATA_TYPE ret_val = lengthSquared(v1);
   if (ret_val == 0.0f)
      return 0.0f;
   else
      return Math::sqrt(ret_val);
}

/**
 * Computes the square of the length of the given vector. This can be used in
 * many calculations instead of length to increase speed by saving you an
 * expensive sqrt call.
 *
 * @param v1   the vector with which to compute the squared length
 *
 * @return  the square of the length of v1
 */
template<class DATA_TYPE, unsigned SIZE>
DATA_TYPE lengthSquared(const Vec<DATA_TYPE, SIZE>& v1)
{
   DATA_TYPE ret_val(0);
   for(unsigned i=0;i<SIZE;++i)
   {
      ret_val += (v1[i] * v1[i]);
   }

   return ret_val;
}

/**
 * Normalizes the given vector in place causing it to be of unit length. If the
 * vector is already of length 1.0, nothing is done. For convenience, the
 * original length of the vector is returned.
 *
 * @post length(v1) == 1.0
 *
 * @param v1   the vector to normalize
 *
 * @return  the length of v1 before it was normalized
 */
template<class DATA_TYPE, unsigned SIZE>
DATA_TYPE normalize(Vec<DATA_TYPE, SIZE>& v1)
{
   DATA_TYPE len = length(v1);

   if(len != 0.0f)
   {
      for(unsigned i=0;i<SIZE;++i)
      {
         v1[i] /= len;
      }
   }

   return len;
}

/**
 * Determines if the given vector is normalized within the given tolerance. The
 * vector is normalized if its lengthSquared is 1.
 *
 * @param v1      the vector to test
 * @param eps     the epsilon tolerance
 *
 * @return  true if the vector is normalized, false otherwise
 */
template< class DATA_TYPE, unsigned SIZE >
bool isNormalized( const Vec<DATA_TYPE, SIZE>& v1,
                   const DATA_TYPE eps = (DATA_TYPE)0.0001 )
{
   return Math::isEqual( lengthSquared( v1 ), (DATA_TYPE)1.0, eps );
}

/**
 * Computes the cross product between v1 and v2 and returns the result. Note
 * that this only applies to 3-dimensional vectors.
 *
 * @post result = v1 x v2
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  the result of the cross product between v1 and v2
 */
template<class DATA_TYPE>
Vec<DATA_TYPE,3> cross(const Vec<DATA_TYPE, 3>& v1, const Vec<DATA_TYPE, 3>& v2)
{
   return Vec<DATA_TYPE,3>( ((v1[Yelt]*v2[Zelt]) - (v1[Zelt]*v2[Yelt])),
                            ((v1[Zelt]*v2[Xelt]) - (v1[Xelt]*v2[Zelt])),
                            ((v1[Xelt]*v2[Yelt]) - (v1[Yelt]*v2[Xelt])) );
}

/**
 * Computes the cross product between v1 and v2 and stores the result in result.
 * The result is also returned by reference. Use this when you want to reuse an
 * existing Vec to store the result. Note that this only applies to
 * 3-dimensional vectors.
 *
 * @post result = v1 x v2
 *
 * @param result  filled with the result of the cross product between v1 and v2
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  a reference to result for convenience
 */
template<class DATA_TYPE>
Vec<DATA_TYPE,3>& cross( Vec<DATA_TYPE,3>& result, const Vec<DATA_TYPE, 3>& v1,
                         const Vec<DATA_TYPE, 3>& v2 )
{
   result.set( (v1[Yelt]*v2[Zelt]) - (v1[Zelt]*v2[Yelt]),
               (v1[Zelt]*v2[Xelt]) - (v1[Xelt]*v2[Zelt]),
               (v1[Xelt]*v2[Yelt]) - (v1[Yelt]*v2[Xelt]) );
   return result;
}

/** @} */

/** @ingroup Interp
 * @name Vector Interpolation
 * @{
 */

/**
 * Linearly interpolates between to vectors.
 * 
 * @pre  lerpVal is a value between 0 and 1 that interpolates between from and to.
 * @post undefined if lerpVal < 0 or lerpVal > 1
 *
 * @param result     the result of the linear interpolation
 * @param lerpVal    the value to interpolate between from and to
 * @param from       the vector at lerpVal 0
 * @param to         the vector at lerpVal 1
 *
 * @return  a reference to result for convenience
 */
template <typename DATA_TYPE, unsigned SIZE>
VecBase<DATA_TYPE, SIZE>& lerp( VecBase<DATA_TYPE, SIZE>& result,
                                const DATA_TYPE& lerpVal,
                                const VecBase<DATA_TYPE, SIZE>& from, 
                                const VecBase<DATA_TYPE, SIZE>& to )
{
   /// @todo metaprogramming...
   for (unsigned int x = 0; x < SIZE; ++x)
   {
      Math::lerp( result[x], lerpVal, from[x], to[x] );
   }
   return result;
}
/** @} */

/** @ingroup Compare
 * @name Vector Comparitors
 * @{
 */

       
// --- VEC comparisons -- //

/**
 * Compares v1 and v2 to see if they are exactly the same with zero tolerance.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  true if v1 equals v2; false if they differ
 */
template<class DATA_TYPE, unsigned SIZE>
inline bool operator==(const VecBase<DATA_TYPE, SIZE>& v1,
                       const VecBase<DATA_TYPE, SIZE>& v2)
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

/**
 * Compares v1 and v2 to see if they are NOT exactly the same with zero
 * tolerance.
 *
 * @param v1   the first vector
 * @param v2   the second vector
 *
 * @return  true if v1 does not equal v2; false if they are equal
 */
template<class DATA_TYPE, unsigned SIZE>
inline bool operator!=(const VecBase<DATA_TYPE, SIZE>& v1,
                       const VecBase<DATA_TYPE, SIZE>& v2)
{
   return(! (v1 == v2));
}

/**
 * Compares v1 and v2 to see if they are the same within the given epsilon
 * tolerance.
 *
 * @pre eps must be >= 0
 *
 * @param v1   the first vector
 * @param v2   the second vector
 * @param eps  the epsilon tolerance value
 *
 * @return  true if v1 equals v2; false if they differ
 */
template<class DATA_TYPE, unsigned SIZE>
inline bool isEqual(const VecBase<DATA_TYPE, SIZE>& v1,
                    const VecBase<DATA_TYPE, SIZE>& v2, const DATA_TYPE& eps)
{
   gmtlASSERT(eps >= 0);

   for(unsigned i=0;i<SIZE;++i)
   {
      if (fabs(v1[i] - v2[i]) > eps)
      {
         return false;
      }
   }
   return true;
}

/** @} */

}

#endif
