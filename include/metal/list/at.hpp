// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

#include <metal/list/list.hpp>
#include <metal/list/zip.hpp>
#include <metal/list/enumerate.hpp>
#include <metal/list/size.hpp>
#include <metal/map/at_key.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq, typename val>
    struct at
    {};

    /// \ingroup sequece
    /// \brief Eager adaptor for \ref at.
    template<typename seq, typename val>
    using at_t = extract<at<seq, val>>;

    template<
        template<typename...> class list,
        typename... vals,
        typename t, t v
    >
    struct at<list<vals...>, number<t, v>> :
            at_key<
                zip_t<
                    enumerate_t<size_t<list<vals...>>>,
                    metal::list<vals...>
                >,
                number<std::size_t, static_cast<std::size_t>(v%sizeof...(vals))>
            >
    {};

    template<template<typename...> class list, typename t, t v>
    struct at<list<>, number<t, v>>
    {};
}

#endif