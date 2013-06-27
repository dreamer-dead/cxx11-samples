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
  auto closure = [value]() -> int {
    return value / 3;
  };
  std::cout << "closure value = " << closure() << std::endl;

  float fvalue = 0.5f;
  // Closure with float value by reference
  auto accumulator = [&fvalue](float multiplayer) {
    fvalue *= multiplayer;
  };
  accumulator(100.0f);
  std::cout << "accumulated value = " << fvalue << std::endl;

  return 0;
}
