/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/verbatim.hpp>
#include <metal/functional/quote.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/bind.hpp>
#include <metal/functional/lambda.hpp>
#include <metal/functional/call.hpp>

#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((std::is_same<verbatim<void>::type, verbatim<void>>));
METAL_ASSERT((std::is_same<call_t<quote<verbatim>, void>, verbatim<void>>));

METAL_ASSERT((call_t<bind<verbatim<placeholders::_1>, verbatim<std::true_type>>>));
METAL_ASSERT((call_t<lambda<verbatim<std::true_type>>>));

using bound = bind<quote<std::add_pointer>, placeholders::_1>;

METAL_ASSERT((std::is_same<call_t<bind<verbatim<quote<std::add_pointer>>, verbatim<bound>>, void>, bound*>));
METAL_ASSERT((std::is_same<call_t<bind<quote<std::add_pointer>, verbatim<verbatim<bound>>>, void>, verbatim<bound>*>));

using lexpr = std::add_pointer<placeholders::_1>;

METAL_ASSERT((std::is_same<call_t<lambda<verbatim<lexpr>>, void>, lexpr>));
METAL_ASSERT((std::is_same<call_t<lambda<verbatim<verbatim<lexpr>>>, void>, verbatim<lexpr>>));