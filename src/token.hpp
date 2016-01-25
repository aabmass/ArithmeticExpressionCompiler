#ifndef TOKEN_HPP_DDF1MEPC
#define TOKEN_HPP_DDF1MEPC

#include <string>

namespace AEC {
    class Token {
    private:
        std::string value;
        std::string classification;

    public:
        Token(std::string const& value, std::string const& classification);
    };
}

#endif /* end of include guard: TOKEN_HPP_DDF1MEPC */
