#include "lexer.hpp"
#include "token.hpp"
#include "tokenpattern.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>

namespace AEC {
    Lexer::Lexer(std::istream& is) :
        is(is)
    {
    }

    Lexer::~Lexer() {

    }

    Token Lexer::nextToken() {
        std::vector<std::unique_ptr<TokenPattern>> possibleTokens(getPatterns());
        std::unique_ptr<TokenPattern> const& bestMatch = possibleTokens.front();

        char nextChar;
        std::ostringstream buf;

        this->is >> nextChar;
        
        if (!nextChar) {
            return EOFToken;
        }
        else {
            buf << nextChar;
            checkAndEliminatePatterns(possibleTokens, buf.str());

            if (possibleTokens.empty())
                throw SyntaxError();
        }

        while (this->is >> nextChar && !possibleTokens.empty()) {
            // append this char to the buffer stream
            buf << nextChar;
            checkAndEliminatePatterns(possibleTokens, buf.str());
        }

        return bestMatch->generateToken(buf.str());
    }

    void Lexer::checkAndEliminatePatterns(std::vector<std::unique_ptr<TokenPattern>>& patterns, std::string const& input) {
        patterns.erase(std::remove_if(
                    patterns.begin(),
                    patterns.end(),
                    [&](std::unique_ptr<TokenPattern> const& pattern) {
                        return pattern->matches(input);
                    }),
                    patterns.end());
    }
      
}
