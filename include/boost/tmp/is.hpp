#ifndef BOOST_TMP_IS_HPP_INCLUDED
#define BOOST_TMP_IS_HPP_INCLUDED

//  Copyright 2018 Odin Holmes.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include "vocabulary.hpp"
#include <type_traits>

namespace boost{
    namespace tmp {
        template<typename P, typename C = identity_>
        struct is_{};

        namespace detail{
            template<typename P, typename C>
            struct dispatch<1,is_<P,C>>{
                template<typename T>
                using f = typename dispatch<1,C>::template f<bool_<std::is_same<P,T>::value>>;
            };
        }
    }
}
#endif
