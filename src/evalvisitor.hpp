#ifndef EVALVISITOR_HPP_NRJLQWWP
#define EVALVISITOR_HPP_NRJLQWWP

#include "visitor.hpp"

namespace AEC {
    template<typename NumberType>
    class EvalVisitor : public Visitor<NumberType> {
    private:
        NumberType result;

    public:
        EvalVisitor() :
            result(0)
        { }

        NumberType getResult() const {
            return result;
        }

        virtual void visitNumber(Number<NumberType> const& num) {
            result = num.getNumber();   
        }

        virtual void visitBinaryOperator(BinaryOperator<NumberType> const& o) {
            o.getChild(BinaryOperator<NumberType>::LEFT)->accept(*this);
            NumberType leftResult = result;
            o.getChild(BinaryOperator<NumberType>::RIGHT)->accept(*this);
            NumberType rightResult = result;

            result = o.perform(leftResult, rightResult);
        }
    };
}

#endif /* end of include guard: EVALVISITOR_HPP_NRJLQWWP */
