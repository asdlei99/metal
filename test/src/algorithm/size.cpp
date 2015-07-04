/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algorithm/size.hpp>
#include <metal/functional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace metal;

namespace test
{
    struct sized
    {
        using size = test::three;
    };

    struct not_sized
    {
        using size = void;
    };

    struct size
    {};
}

METAL_ASSERT((is_evaluable<size, test::sized>));
METAL_ASSERT((not_<is_evaluable<size, test::not_sized>>));
METAL_ASSERT((not_<is_evaluable<size, test::size>>));

METAL_ASSERT((equal_to<size<test::sized>, test::three>));