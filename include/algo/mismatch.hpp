#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

#include "algo.hpp"

namespace algobench
{
    namespace algo
    {
        template <typename T, size_t size>
        struct mismatch: public algo
        {
            std::vector<T> data;
            mismatch(): data(size)
            {
                init();

            }

            void init() override
            {
                static bool once = ([this](){
                    std::iota(std::begin(data), data.begin()+size/2,0);
                    std::iota(std::rbegin(data), data.rbegin()+size/2,0);
                }(),true);
            }

            bool algorithm() override
            {
                return std::mismatch(std::begin(data), std::end(data), std::rbegin(data)).first == std::end(data);
            }

            bool home_impl() override
            {
                auto it = data.begin();
                auto rit = data.rbegin();
                auto end = data.end();
                while(it!=end && *(it++) == *(rit++))
                    ;
                return it == end;
            }
        };
    }
}