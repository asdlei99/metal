// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_INTEGER_HPP
#define BOOST_MPL2_CORE_INTEGRAL_INTEGER_HPP

#include <boost/mpl2/core/integral.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<short constant>
        struct short_ :
                integral<short, constant>
        {};

        template<unsigned short constant>
        struct ushort_ :
                integral<unsigned short, constant>
        {};

        template<int constant>
        struct int_ :
                integral<int, constant>
        {};

        template<unsigned int constant>
        struct uint_ :
                integral<unsigned int, constant>
        {};

        template<long constant>
        struct long_ :
                integral<long, constant>
        {};

        template<unsigned long constant>
        struct ulong_ :
                integral<unsigned long, constant>
        {};

#if defined(BOOST_HAS_LONG_LONG)
        template<long_long_type constant>
        struct long_long_ :
                integral<long_long_type, constant>
        {};

        template<ulong_long_type constant>
        struct ulong_long_ :
                integral<ulong_long_type, constant>
        {};
#endif
    }
}

#endif