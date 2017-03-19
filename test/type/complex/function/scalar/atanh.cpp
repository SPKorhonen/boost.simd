//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/atanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex atanh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::atanh(c1), bs::complex<T>(0, 1.1071487177940905030170654601785), 0.5);
  STF_ULP_EQUAL( bs::atanh(c2), bs::complex<T>(- 0.11750090731143388841273425778709, 1.4099210495965755225306193844604), 0.5);
  STF_ULP_EQUAL( bs::atanh(c3), bs::complex<T>(0.40235947810852509365018983330655,  1.0172219678978513677227889615505), 0.5);
}
