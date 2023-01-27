#include <cstdlib>
#include <iostream>

#include "hello.hpp"

int main(int argc, char *argv[]) {
    std::cout << "argc == " << argc << '\n';

    for (int ndx{}; ndx != argc; ++ndx) {
        std::cout << "argv[" << ndx << "] == " << argv[ndx] << '\n';
    }
    std::cout << "argv[" << argc << "] == " << static_cast<void *>(argv[argc])
              << '\n';

    if (const char *env_p = std::getenv("PATH")) {
        std::cout << "Your PATH is: " << env_p << '\n';
    }

    say_hello();

    return EXIT_SUCCESS;
}