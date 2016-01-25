#ifndef LEXER_HPP_0FXLKTQB
#define LEXER_HPP_0FXLKTQB

#include <istream>
#include <memory>
#include <vector>

namespace AEC {
    /* forward declarations */
    class Token;
    class TokenPattern;

    class Lexer {
    private:
        std::istream& is;

        /* private methods */
        /**
         * @brief Puts matched patterns on input into matches 
         *
         * @param patterns matches to test on and elimante. If empty, tests on getPatterns()
         * @param input the string to test patterns on
         */
        void checkAndEliminatePatterns(std::vector<std::unique_ptr<TokenPattern>>& patterns, std::string const& input);

    public:
        Lexer(std::istream& is);
        virtual ~Lexer();
        
        Token nextToken();

        virtual std::vector<std::unique_ptr<TokenPattern>>& getPatterns() = 0;
    };
}

#endif /* end of include guard: LEXER_HPP_0FXLKTQB */
