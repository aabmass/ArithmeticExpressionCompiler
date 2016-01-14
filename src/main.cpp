#include <iostream>
#include <limits>

#include <memory>
#include "number.hpp"
#include "operators.hpp"
#include "evalvisitor.hpp"
#include "infixprintvisitor.hpp"

int main(int argc, char *argv[]) { 
    using namespace AEC;

    using NumberType = double;

    // set precision of cout
    std::cout.precision(std::numeric_limits<NumberType>::max_digits10);

    auto n1 = std::make_shared<Number<NumberType>>(2);
    auto n2 = std::make_shared<Number<NumberType>>(3);
    auto n3 = std::make_shared<Number<NumberType>>(1.213);
    auto n4 = std::make_shared<Number<NumberType>>(1.2);

    auto p1 = std::make_shared<Plus<NumberType>>(n1, n2);
    auto t1 = std::make_shared<Times<NumberType>>(n3, n4);
    auto e1 = std::make_shared<Exponentiate<NumberType>>(p1, t1);

    auto eval = std::make_shared<EvalVisitor<NumberType>>();
    auto print = std::make_shared<InfixPrintVisitor<NumberType>>();

    try {
        n1->getChild(1);
    }
    catch(NoChildNodeError const& e) {
        std::cout << "Caught expected error!!: " << e.what() << std::endl;
    }

    e1->accept(*eval);
    e1->accept(*print);

    std::cout << print->getResult() << std::endl;
    std::cout << "result is " << eval->getResult() << std::endl;

    return 0;
}
