#ifndef PLUS_HPP_PDIGUZYT
#define PLUS_HPP_PDIGUZYT

#include "binaryoperator.hpp"
#include <ostream>

namespace AEC {
    template<typename NumberType>
    class Plus : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::ostream& outputString(std::ostream& os) const {
            return os << "+";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return left + right;
        }
    };
}

#endif /* end of include guard: PLUS_HPP_PDIGUZYT */
