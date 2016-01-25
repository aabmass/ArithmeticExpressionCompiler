#ifndef SYMBOLNOTFOUNDERROR_HPP_NOFC016T
#define SYMBOLNOTFOUNDERROR_HPP_NOFC016T

#include <stdexcept>

namespace AEC {
    class SymbolNotFoundError : public std::runtime_error {
    public:
        explicit SymbolNotFoundError(std::string const& tokenAttempt);
    };
}

#endif /* end of include guard: SYMBOLNOTFOUNDERROR_HPP_NOFC016T */
