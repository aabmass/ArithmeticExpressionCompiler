#include <iostream>

#include <memory>
#include "number.hpp"

int main(int argc, char *argv[]) { 
    using namespace AEC;

    Number<double> n(2);

    try {
        n.getChild(1);
    }
    catch(NoChildNodeError const& e) {
        std::cout << "Caught expected error!!: " << e.what() << std::endl;
    }

    std::cout << "Here is a number: " << n << std::endl;

    return 0;
}
