#include <iostream>
#include <functional>
#include <cmath>

int main() {
  // Just a simple function
  std::function<void()> worker = [] {
    std::cout << "Hello from lambda!" << std::endl;
  };
  worker();

  // Now we return some useful value
  std::function<double()> generator = []() -> double {
    return M_PI * 2;
  };
  std::cout << "generated value = " << generator() << std::endl;

  int value = 666;
  // Closure with integer value
  std::function<int()> closure = [value]() -> int {
    return value / 3;
  };
  std::cout << "closure value = " << closure() << std::endl;

  return 0;
}
