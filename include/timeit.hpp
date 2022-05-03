#pragma once

#include <string>
#include <chrono>
#include <iostream>

#include "algo.hpp"
namespace algobench
{
    namespace util
    {

        // template <typename T>
        void time_it(algobench::algo::algo &inst, std::string name, size_t iteration = 1)
        {
            using std::chrono::duration;
            using std::chrono::duration_cast;
            using std::chrono::high_resolution_clock;
            using std::chrono::seconds;

            // warmup
            volatile auto x = inst.algorithm();

            auto t1 = high_resolution_clock::now();
            for (size_t i = 0; i < iteration; i++)
            {
                x = inst.algorithm();
            }
            auto t2 = high_resolution_clock::now();

            // warmup
            x = inst.home_impl();

            auto t3 = high_resolution_clock::now();
            for (size_t i = 0; i < iteration; i++)
            {
                x = inst.home_impl();
            }
            auto t4 = high_resolution_clock::now();

            duration<double, std::milli> ms_algo = t2 - t1;
            duration<double, std::milli> ms_loop = t4 - t3;

            // print times
            std::cout << name << ": " << ms_algo.count() << ", " << ms_loop.count() << std::endl;
        }
    }

}