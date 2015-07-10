// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/protect.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(protect<std::true_type>{}, "");
static_assert(std::is_same<protect<void>::type, protect<void>>{}, "");
static_assert(std::is_same<call_t<call_t<quote<protect>, placeholders::_1>, void>, void>{}, "");

static_assert(is_function<protect<test::wrapper>>{}, "");
static_assert(is_callable<protect<test::wrapper>>{}, "");
static_assert(std::is_same<call_t<protect<test::wrapper>>, call_t<test::wrapper>>{}, "");

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

static_assert(std::is_same<call_t<protect<bound>, void>, void*>{}, "");
static_assert(std::is_same<call_t<protect<protect<bound>>, void>, void*>{}, "");

static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, protect<bound>>, void>, protect<bound>*>{}, "");
static_assert(std::is_same<call_t<bind<quote<std::add_pointer>, protect<protect<bound>>>, void>, protect<protect<bound>>*>{}, "");

using lexpr = std::add_pointer<placeholders::_1>;

static_assert(std::is_same<call_t<protect<lambda<lexpr>>, void>, void*>{}, "");
static_assert(std::is_same<call_t<protect<protect<lambda<lexpr>>>, void>, void*>{}, "");

static_assert(std::is_same<call_t<lambda<protect<lexpr>>, void>, protect<lexpr>>{}, "");
static_assert(std::is_same<call_t<lambda<protect<protect<lexpr>>>, void>, protect<protect<lexpr>>>{}, "");