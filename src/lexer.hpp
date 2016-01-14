#ifndef LEXER_HPP_0FXLKTQB
#define LEXER_HPP_0FXLKTQB

#include <istream>

namespace AEC {
    class Lexer {
    private:
        std::istream& is;
    
    public:
        Lexer(std::istream& is);
        ~Lexer();
    };
}

#endif /* end of include guard: LEXER_HPP_0FXLKTQB */
