/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: LineSegOps.h,v $
 * Date modified: $Date: 2002-02-24 23:37:03 $
 * Version:       $Revision: 1.1 $
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
#ifndef _GMTL_LINESEGOPS_H_
#define _GMTL_LINESEGOPS_H_

namespace gmtl {

/**
 * Compare two line segments to see if they are EXACTLY the same. In other
 * words, this comparison is done with zero tolerance.
 *
 * @param ls1     the first lineseg to compare
 * @param ls2     the second lineseg to compare
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator==( const LineSeg<DATA_TYPE>& ls1, const LineSeg<DATA_TYPE>& ls2 )
{
   return ( (ls1.mOrigin == ls2.mOrigin) && (ls1.mDir == ls1.mDir) );
}

/**
 * Compare two line segments to see if they are not EXACTLY the same. In other
 * words, this comparison is done with zero tolerance.
 *
 * @param ls1     the first lineseg to compare
 * @param ls2     the second lineseg to compare
 *
 * @return  true if they are not equal, false otherwise
 */
template< class DATA_TYPE >
inline bool operator!=( const LineSeg<DATA_TYPE>& ls1,
                        const LineSeg<DATA_TYPE>& ls2 )
{
   return ( ! (ls1 == ls2) );
}

/**
 * Compare two line segments to see if the are the same within the given
 * tolerance.
 *
 * @param ls1     the first lineseg to compare
 * @param ls2     the second lineseg to compare
 * @param pre     the tolerance value to use
 *
 * @pre eps must be >= 0
 *
 * @return  true if they are equal, false otherwise
 */
template< class DATA_TYPE >
inline bool isEqual( const LineSeg<DATA_TYPE>& ls1,
                     const LineSeg<DATA_TYPE>& ls2,
                     const DATA_TYPE& eps )
{
   ggtASSERT( eps >= 0 );
   return ( (isEqual(ls1.mOrigin, ls2.mOrigin, eps)) &&
            (isEqual(ls1.mDir, ls2.mDir, eps)) );
}

} // namespace gmtl
#endif
