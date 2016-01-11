#ifndef NOCHILDNODEERROR_HPP_GMVEHMAE
#define NOCHILDNODEERROR_HPP_GMVEHMAE

#include <stdexcept>

namespace AEC {
    class NoChildNodeError : public std::runtime_error {
        // use the what constructor from before
        using std::runtime_error::runtime_error;
    };
}

#endif /* end of include guard: NOCHILDNODEERROR_HPP_GMVEHMAE */
