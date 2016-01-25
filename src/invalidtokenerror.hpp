#ifndef INVALIDTOKENERROR_HPP_GUVWEYE0
#define INVALIDTOKENERROR_HPP_GUVWEYE0

#include <stdexcept>

namespace AEC {
    class InvalidTokenError : public std::runtime_error {
    public:
        explicit InvalidTokenError(std::string const& tokenAttempt);
    };
}

#endif /* end of include guard: INVALIDTOKENERROR_HPP_GUVWEYE0 */
