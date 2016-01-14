#ifndef INFIXPRINTVISITOR_HPP_F5V4VPYZ
#define INFIXPRINTVISITOR_HPP_F5V4VPYZ

#include "visitor.hpp"
#include <sstream>
#include <limits>

namespace AEC {
    template<typename NumberType>
    class InfixPrintVisitor : public Visitor<NumberType> {
    private:
        std::ostringstream result;

    public:
        InfixPrintVisitor() :
            result()
        {
            // set the precision on number outputted to the stream
            result.precision(std::numeric_limits<NumberType>::max_digits10);
        }

        std::string getResult() const {
            return result.str();
        }

        virtual void visitNumber(Number<NumberType> const& num) {
            result << num;   
        }

        virtual void visitBinaryOperator(BinaryOperator<NumberType> const& o) {
            result << "(";
            o.getChild(BinaryOperator<NumberType>::LEFT)->accept(*this);
            result << " " << o << " ";
            o.getChild(BinaryOperator<NumberType>::RIGHT)->accept(*this);
            result << ")";
        }
    };
}


#endif /* end of include guard: INFIXPRINTVISITOR_HPP_F5V4VPYZ */
