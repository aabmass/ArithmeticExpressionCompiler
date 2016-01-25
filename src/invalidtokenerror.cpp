#include "invalidtokenerror.hpp"

#include <ostream>

namespace AEC {
    InvalidTokenError::InvalidTokenError(std::string const& tokenAttempt) :
        std::runtime_error("InvalidTokenError! Couldn't find a symbol or match token:\n" + tokenAttempt)
    {

    }
}
