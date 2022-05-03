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
            // template<typename T>
            // bool func (const T &value){return (value/10)<10000000;};


        template <typename T, size_t size>
        struct all_of : public algo
        {

            // bool (*func)(const T& ) = [](const T &value){return (value/10)<10000000;};

            std::vector<T> data;

            all_of():data(size)
            {
                init();
            }

            void init() override
            {
                static bool once = ([this](){
                    std::iota(std::begin(data), std::end(data),0);
                }(),true);

            }

            bool algorithm() override
            {
                init();
                return std::all_of(std::cbegin(data), std::cend(data), [](const T &value){return (value/10)<10000000;});
                
            }

            bool home_impl() override
            {
                init();
                for(int i =0; i<data.size(); ++i)
                    if((data[i]/10)>=10000000)
                        return false ;
                return true;
            }
        };
    }
}