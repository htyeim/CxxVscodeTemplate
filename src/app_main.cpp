#include "hello.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

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
  auto start = std::chrono::steady_clock::now();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elpse = end - start;
  std::cout << start.time_since_epoch().count() << " "
            << end.time_since_epoch().count() << " " << elpse.count()
            << std::endl;

  say_hello();

  return EXIT_SUCCESS;
}
