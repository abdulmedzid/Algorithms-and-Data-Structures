#pragma once
#include <functional>

template <class T, class F>
class Compare {
    bool operator()(T& a, T& b, F comp) {
        return comp(a, b);
    }
};