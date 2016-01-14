#ifndef EXPONENTIATE_HPP_UK24TBWI
#define EXPONENTIATE_HPP_UK24TBWI

#include "binaryoperator.hpp"
#include <cmath>
#include <ostream>

namespace AEC {
    template<typename NumberType>
    class Exponentiate : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::ostream& outputString(std::ostream& os) const {
            return os << "^";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return std::pow(left, right);
        }
    };
}

#endif /* end of include guard: EXPONENTIATE_HPP_UK24TBWI */
