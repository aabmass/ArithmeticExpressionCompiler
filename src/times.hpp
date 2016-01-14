#ifndef TIMES_HPP_VZQLE0SP
#define TIMES_HPP_VZQLE0SP

#include "binaryoperator.hpp"
#include <ostream>

namespace AEC {
    template<typename NumberType>
    class Times : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::ostream& outputString(std::ostream& os) const {
            return os << "*";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return left * right;
        }
    };
}

#endif /* end of include guard: TIMES_HPP_VZQLE0SP */
