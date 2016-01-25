#ifndef TOKENPATTERN_HPP_CHLAKW8N
#define TOKENPATTERN_HPP_CHLAKW8N

#include <regex>

#include "token.hpp"

namespace AEC {
    class TokenPattern {
    protected:
        virtual std::regex const& getRegex() = 0;

    public:
        virtual ~TokenPattern();

        bool matches(std::string const& str);
        virtual Token generateToken(std::string const& value) = 0;
    };
}

#endif /* end of include guard: TOKENPATTERN_HPP_CHLAKW8N */
