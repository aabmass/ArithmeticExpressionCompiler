#include <iostream>

#include <memory>
#include "number.hpp"
#include "operators.hpp"
#include "evalvisitor.hpp"

int main(int argc, char *argv[]) { 
    using namespace AEC;

    auto n1 = std::make_shared<Number<double>>(2);
    auto n2 = std::make_shared<Number<double>>(3);

    auto p1 = std::make_shared<Plus<double>>(n1, n2);

    EvalVisitor<double> eval;

    try {
        n1->getChild(1);
    }
    catch(NoChildNodeError const& e) {
        std::cout << "Caught expected error!!: " << e.what() << std::endl;
    }

    p1->accept(eval);

    std::cout << "result is " << eval.getResult() << std::endl;

    return 0;
}
