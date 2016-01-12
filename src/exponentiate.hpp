#ifndef PLUS_HPP_PDIGUZYT
#define PLUS_HPP_PDIGUZYT

#include "binaryoperator.hpp"

namespace AEC {
    template<typename NumberType>
    class Exponentiate : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::string asString() const {
            return "^";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return left ^ right;
        }
    };
}

#endif /* end of include guard: PLUS_HPP_PDIGUZYT */
