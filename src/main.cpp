#include <iostream>

#include <memory>
#include "number.hpp"

int main(int argc, char *argv[]) { 
    using namespace AEC;

    Number<double> n(2);

    n.getChild(1);

    std::cout << "Here is a number: " << n << std::endl;

    return 0;
}
