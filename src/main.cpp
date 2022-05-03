
#include "timeit.hpp"

#include <algo/all_of.hpp>
#include <algo/mismatch.hpp>

int main()
{
    auto all = algobench::algo::all_of<float, 10000000>();
    auto mis = algobench::algo::mismatch<float, 10000000>();
    // algobench::util::time_it(all, "all_of", 1000);
    algobench::util::time_it(mis, "mismatch", 1000);
}