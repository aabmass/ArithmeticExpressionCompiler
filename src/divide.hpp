#ifndef DIVIDE_HPP_BMQPC4VO
#define DIVIDE_HPP_BMQPC4VO

#include "binaryoperator.hpp"
#include <ostream>

namespace AEC {
    template<typename NumberType>
    class Divide : public BinaryOperator<NumberType> {
    public:
        using BinaryOperator<NumberType>::BinaryOperator;

        virtual std::ostream& outputString(std::ostream& os) const {
            return os << "/";
        }

        virtual NumberType perform(NumberType left, NumberType right) const {
            return left / right;
        }
    };
}

#endif /* end of include guard: DIVIDE_HPP_BMQPC4VO */
