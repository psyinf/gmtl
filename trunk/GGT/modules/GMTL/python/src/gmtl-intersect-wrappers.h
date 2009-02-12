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
 * File:          $RCSfile: gmtl-intersect-wrappers.h,v $
 * Date modified: $Date: 2009-02-12 23:35:29 $
 * Version:       $Revision: 1.7 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

#ifndef _PYJUGGLER_GMTL_INTERSECT_WRAPPERS_H_
#define _PYJUGGLER_GMTL_INTERSECT_WRAPPERS_H_

// This file makes declarations of the templated function instantiations
// needed for Boost.Python to do its thing.  More specifically, the functions
// defined here wrap instantiations of gmtl::intersect() and change the return
// type to be a Python tuple.

#include <boost/python/tuple.hpp>

#include <gmtl/Intersection.h>


namespace gmtlWrappers
{
   using namespace boost::python;

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b1, const gmtl::AABox<T>& b2)
   {
      return make_tuple(gmtl::intersect(b1, b2));
   }

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b, const gmtl::Point<T, 3>& p)
   {
      return make_tuple(gmtl::intersect(b, p));
   }

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b, const gmtl::LineSeg<T>& l)
   {
      unsigned int c;
      T val1, val2;
      bool result = gmtl::intersect(b, l, c, val1, val2);
      return make_tuple(result, c, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::LineSeg<T>& p, const gmtl::AABox<T>& b)
   {
      return intersect(b, p);
   }

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b, const gmtl::Ray<T>& r)
   {
      unsigned int c;
      T val1, val2;
      bool result = gmtl::intersect(b, r, c, val1, val2);
      return make_tuple(result, c, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::Ray<T>& r, const gmtl::AABox<T>& b)
   {
      return intersect(b, r);
   }

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b1, const gmtl::Vec<T, 3>& v1,
                   const gmtl::AABox<T>& b2, const gmtl::Vec<T, 3>& v2)
   {
      T val1, val2;
      bool result = gmtl::intersect(b1, v1, b2, v2, val1, val2);
      return make_tuple(result, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::Sphere<T>& s1, const gmtl::Vec<T, 3>& v1,
                   const gmtl::Sphere<T>& s2, const gmtl::Vec<T, 3>& v2)
   {
      T val1, val2;
      bool result = gmtl::intersect(s1, v1, s2, v2, val1, val2);
      return make_tuple(result, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::AABox<T>& b, const gmtl::Sphere<T>& s)
   {
      return make_tuple(gmtl::intersect(b, s));
   }

   template<typename T>
   tuple intersect(const gmtl::Sphere<T>& s, const gmtl::AABox<T>& b)
   {
      return make_tuple(gmtl::intersect(s, b));
   }

   template<typename T>
   tuple intersect(const gmtl::Sphere<T>& s, const gmtl::Point<T, 3>& p)
   {
      return make_tuple(gmtl::intersect(s, p));
   }

   template<typename T>
   tuple intersect(const gmtl::Sphere<T>& s, const gmtl::Ray<T>& r)
   {
      int c;
      T val1, val2;
      bool result = gmtl::intersect(s, r, c, val1, val2);
      return make_tuple(result, c, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::Sphere<T>& s, const gmtl::LineSeg<T>& l)
   {
      int c;
      T val1, val2;
      bool result = gmtl::intersect(s, l, c, val1, val2);
      return make_tuple(result, c, val1, val2);
   }

   template<typename T>
   tuple intersect(const gmtl::Plane<T>& p, const gmtl::Ray<T>& r)
   {
      T val;
      bool result = gmtl::intersect(p, r, val);
      return make_tuple(result, val);
   }

   template<typename T>
   tuple intersect(const gmtl::Plane<T>& p, const gmtl::LineSeg<T>& r)
   {
      T val;
      bool result = gmtl::intersect(p, r, val);
      return make_tuple(result, val);
   }

   template<typename T>
   tuple intersect(const gmtl::Tri<T>& t, const gmtl::Ray<T>& r)
   {
      float val1, val2, val3;
      bool result = gmtl::intersect(t, r, val1, val2, val3);
      return make_tuple(result, val1, val2, val3);
   }

   template<typename T>
   tuple intersectDoubleSided(const gmtl::Tri<T>& t, const gmtl::Ray<T>& r)
   {
      T val1, val2, val3;
      bool result = gmtl::intersectDoubleSided(t, r, val1, val2, val3);
      return make_tuple(result, val1, val2, val3);
   }

   template<typename T>
   tuple intersect(const gmtl::Tri<T>& t, const gmtl::LineSeg<T>& l)
   {
      float val1, val2, val3;
      bool result = gmtl::intersect(t, l, val1, val2, val3);
      return make_tuple(result, val1, val2, val3);
   }

   template<typename T>
   tuple intersectVolume(const gmtl::Sphere<T>& sphere,
                         const gmtl::LineSeg<T>& lineseg)
   {
      int num_hits;
      T t0, t1;
      bool result = gmtl::intersectVolume(sphere, lineseg, num_hits, t0, t1);
      return make_tuple(result, num_hits, t0, t1);
   }

   template<typename T>
   tuple intersectVolume(const gmtl::Sphere<T>& sphere,
                         const gmtl::Ray<T>& ray)
   {
      int num_hits;
      T t0, t1;
      bool result = gmtl::intersectVolume(sphere, ray, num_hits, t0, t1);
      return make_tuple(result, num_hits, t0, t1);
   }
}

#if ! defined(__APPLE__)
namespace gmtlWrappers
{
   template tuple intersect(const gmtl::AABoxf&, const gmtl::AABoxf&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::AABoxd&);

   template tuple intersect(const gmtl::AABoxf&, const gmtl::Point3f&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::Point3d&);

   template tuple intersect(const gmtl::AABoxf&, const gmtl::Vec3f&,
                            const gmtl::AABoxf&, const gmtl::Vec3f&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::Vec3d&,
                            const gmtl::AABoxd&, const gmtl::Vec3d&);

   template tuple intersect(const gmtl::AABoxf&, const gmtl::LineSegf&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::LineSegd&);
   template tuple intersect(const gmtl::LineSegf&, const gmtl::AABoxf&);
   template tuple intersect(const gmtl::LineSegd&, const gmtl::AABoxd&);

   template tuple intersect(const gmtl::AABoxf&, const gmtl::Rayf&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::Rayd&);
   template tuple intersect(const gmtl::Rayf&, const gmtl::AABoxf&);
   template tuple intersect(const gmtl::Rayd&, const gmtl::AABoxd&);

   template tuple intersect(const gmtl::Spheref&, const gmtl::Vec3f&,
                            const gmtl::Spheref&, const gmtl::Vec3f&);
   template tuple intersect(const gmtl::Sphered&, const gmtl::Vec3d&,
                            const gmtl::Sphered&, const gmtl::Vec3d&);

   template tuple intersect(const gmtl::AABoxf&, const gmtl::Spheref&);
   template tuple intersect(const gmtl::AABoxd&, const gmtl::Sphered&);

   template tuple intersect(const gmtl::Spheref&, const gmtl::AABoxf&);
   template tuple intersect(const gmtl::Sphered&, const gmtl::AABoxd&);

   template tuple intersect(const gmtl::Spheref&, const gmtl::Point3f&);
   template tuple intersect(const gmtl::Sphered&, const gmtl::Point3d&);

   template tuple intersect(const gmtl::Spheref&, const gmtl::Rayf&);
   template tuple intersect(const gmtl::Sphered&, const gmtl::Rayd&);

   template tuple intersect(const gmtl::Spheref&, const gmtl::LineSegf&);
   template tuple intersect(const gmtl::Sphered&, const gmtl::LineSegd&);

   template tuple intersect(const gmtl::Planef&, const gmtl::Rayf&);
   template tuple intersect(const gmtl::Planed&, const gmtl::Rayd&);

   template tuple intersect(const gmtl::Planef&, const gmtl::LineSegf&);
   template tuple intersect(const gmtl::Planed&, const gmtl::LineSegd&);

   template tuple intersect(const gmtl::Trif&, const gmtl::Rayf&);
   template tuple intersect(const gmtl::Trid&, const gmtl::Rayd&);

   template tuple intersectDoubleSided(const gmtl::Trif&, const gmtl::Rayf&);
   template tuple intersectDoubleSided(const gmtl::Trid&, const gmtl::Rayd&);

   template tuple intersect(const gmtl::Trif&, const gmtl::LineSegf&);
   template tuple intersect(const gmtl::Trid&, const gmtl::LineSegd&);

   template tuple intersectVolume(const gmtl::Spheref&, const gmtl::LineSegf&);
   template tuple intersectVolume(const gmtl::Sphered&, const gmtl::LineSegd&);
}
#endif


#endif /* _PYJUGGLER_GMTL_INTERSECT_WRAPPERS_H_ */
