//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/make.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  namespace br = brigand;

  BOOST_DISPATCH_OVERLOAD ( deinterleave_first_
                          , (typename T, typename X)
                          , bd::cpu_
                          , bs::pack_< bd::unspecified_<T>, X >
                          , bs::pack_< bd::unspecified_<T>, X >
                          )
  {
    template<typename K, typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, K const&, br::list<N...> const&) BOOST_NOEXCEPT
    {
      return make<T>( bs::extract<N::value*2>(x)..., bs::extract<N::value*2>(y)... );
    }

    template<typename... N> static BOOST_FORCEINLINE
    typename T::storage_type
    do_( T const& x, T const& y, aggregate_storage const&, br::list<N...> const&) BOOST_NOEXCEPT
    {
      return  { { deinterleave_first(x.storage()[0],x.storage()[1])
                , deinterleave_first(y.storage()[0],y.storage()[1])
              } };
    }

    BOOST_FORCEINLINE T operator()(T const& x, T const& y) const BOOST_NOEXCEPT
    {
      return do_(x,y, typename T::traits::storage_kind{}
                    , br::range<std::size_t, 0, T::static_size/2>{}
                );
    }
  };
} } }

#endif