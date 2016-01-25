#include "symbolnotfounderror.hpp"

#include <ostream>

namespace AEC {
    SymbolNotFoundError::SymbolNotFoundError(std::string const& tokenAttempt) :
        std::runtime_error("SymbolNotFoundError! Couldn't find a symbol or match token:\n" + tokenAttempt)
    {

    }
}
