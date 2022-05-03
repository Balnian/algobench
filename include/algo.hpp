#pragma once

namespace algobench
{
    namespace algo
    {

        struct algo
        {
            virtual void init() = 0;
            virtual bool algorithm() = 0;
            virtual bool home_impl() = 0;
        };
    }
}