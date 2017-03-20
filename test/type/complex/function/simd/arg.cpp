//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/arg.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;


STF_CASE_TPL( "Complex arg complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0 ,-2};

  bs::complex<p_t> r0{r,i};
  p_t ar{bs::Zero<T>(), bs::Pi<T>()/4, bs::Pi<T>(), -bs::Pi<T>()/2};

  STF_EQUAL(r0.argument(), ar);
  STF_EQUAL(bs::arg(r0) , ar);
}