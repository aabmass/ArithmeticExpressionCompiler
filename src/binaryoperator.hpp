#ifndef BINARYOPERATOR_HPP_PP1ZJYK0
#define BINARYOPERATOR_HPP_PP1ZJYK0

#include "node.hpp"
#include "visitor.hpp"
#include "nochildnodeerror.hpp"

namespace AEC {
    template<typename NumberType>
    class BinaryOperator : public Node<NumberType> {
    private:
        std::shared_ptr<Node<NumberType>> left;
        std::shared_ptr<Node<NumberType>> right;
    public:
        static const std::size_t LEFT = 0;
        static const std::size_t RIGHT = 1;

        BinaryOperator(std::shared_ptr<Node<NumberType>> left,
                       std::shared_ptr<Node<NumberType>> right) :
            left(left),
            right(right)
        { }

        virtual ~BinaryOperator() {

        }

        virtual std::shared_ptr<Node<NumberType>> getChild(std::size_t i) const {
            if (i > 1) {
                throw NoChildNodeError("BinaryNodes have only 2 children, can not access "
                        + std::to_string(i) + "th child");
            }

            return i == 0 ? left : right;
        }

        virtual void setChild(std::shared_ptr<Node<NumberType>> node, std::size_t i) {
            if (i > 1) {
                throw NoChildNodeError("BinaryNodes have only 2 children, can not access "
                        + std::to_string(i) + "th child");
            }

            (i == 0 ? left : right) = node;
        }

        /* accept a visitor */
        virtual void accept(Visitor<NumberType>& v) {
            v.visitBinaryOperator(*this);
        }

        virtual NumberType perform(NumberType left, NumberType right) const = 0;
    };
}

#endif /* end of include guard: BINARYOPERATOR_HPP_PP1ZJYK0 */
