#ifndef NODE_CPP_NY056JSI
#define NODE_CPP_NY056JSI

#include <memory>

#include "visitor.hpp"

namespace AEC {
    template<typename NumberType>
    class Node {
    public:
        virtual ~Node() {

        }

        virtual std::shared_ptr<Node> getChild() = 0;
        virtual void setChild(std::shared_ptr<Node> node, std::size_t n) = 0;
        virtual std::string asString() const = 0;

        /* accept a visitor */
        virtual void accept(Visitor<NumberType>& v) = 0;
    };

    /* not sure if this is the best place for this... */
    template<typename NumberType>
    std::ostream& operator<<(std::ostream& os, Node<NumberType> const& node) {
        os << node.asString();
        return os;
    }

};

#endif /* end of include guard: NODE_CPP_NY056JSI */
