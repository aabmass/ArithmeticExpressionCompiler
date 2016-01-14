#ifndef MINUS_HPP_XTQS0HIC
#define MINUS_HPP_XTQS0HIC

#include "binaryoperator.hpp"
#include <ostream>

namespace AEC {
    template<typename NumberType>
    class Minus : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::ostream& outputString(std::ostream& os) const {
            return os << "-";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return left - right;
        }
    };
}

#endif /* end of include guard: MINUS_HPP_XTQS0HIC */
