#ifndef VISITOR_HPP_DVSHTKKU
#define VISITOR_HPP_DVSHTKKU

#include <memory>

namespace AEC {
    /* forward declarations */
    template<typename NumberType>
    class Number;

    template<typename NumberType>
    class BinaryOperator;

    template<typename NumberType>
    class Visitor {
    public:
        virtual ~Visitor() {

        }

        virtual void visitNumber(Number<NumberType> const& num) = 0;
        virtual void visitBinaryOperator(BinaryOperator<NumberType> const& num) = 0;
    };

};

#endif /* end of include guard: VISITOR_HPP_DVSHTKKU */
