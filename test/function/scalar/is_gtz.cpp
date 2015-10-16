//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/is_gtz.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_gtz real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_gtz;
  using r_t = decltype(is_gtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(is_gtz(bs::Inf<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_gtz(bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_gtz(-bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_gtz(bs::Half<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_gtz(bs::One<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Quarter<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" is_gtz signed_int",  STF_SIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_gtz;
  using r_t = decltype(is_gtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_gtz(bs::Mone<T>()), r_t(false));
  STF_EQUAL(is_gtz(bs::One<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Zero<T>()), r_t(false));
}

STF_CASE_TPL (" is_gtz unsigned_int",  STF_UNSIGNED_ALL_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_gtz;
  using r_t = decltype(is_gtz(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_gtz(bs::One<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_gtz(bs::Zero<T>()), r_t(false));
}

STF_CASE ( "is_gtz bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_gtz;
  using r_t = decltype(is_gtz(bool()));

  // return type conformity test
   STF_TYPE_IS(r_t, bool);


  // specific values tests
  STF_EQUAL(is_gtz(true), true);
  STF_EQUAL(is_gtz(false), false);
}

