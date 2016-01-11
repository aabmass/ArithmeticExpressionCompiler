#ifndef NUMBER_HPP_6HCA1OB7
#define NUMBER_HPP_6HCA1OB7

#include "node.hpp"
#include "visitor.hpp"
#include "nochildnodeerror.hpp"

namespace AEC {
    template<typename NumberType>
    class Number : public Node<NumberType> {
    private:
        NumberType num;

    public:
        Number(NumberType num) :
            num(num)
        { }

        virtual std::shared_ptr<Node<NumberType>> getChild(std::size_t) {
            // return a nullptr, no children
            throw NoChildNodeError("Number node's do not have any children to get or set");
        }

        virtual void setChild(std::shared_ptr<Node<NumberType>>, std::size_t) {
            throw NoChildNodeError("Number node's do not have any children to get or set");
        }

        virtual std::string asString() const {
            return std::to_string(num);
        }

        /* accept a visitor */
        virtual void accept(Visitor<NumberType>& v) {
            v.visitNumber(*this);
        }
    };
}

#endif /* end of include guard: NUMBER_HPP_6HCA1OB7 */  
