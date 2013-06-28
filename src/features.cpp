#include <iostream>
#include <string>
#include <type_traits>

// Common part
struct int_holder {
  int value;
};

struct float_array_holder {
  float values[10];
};

// Variadic templates

template <typename ... TypesList>
struct varidic_inheritance : public TypesList ... {
};

// Static assert
static_assert(
  sizeof(varidic_inheritance<int_holder, float_array_holder>)
    >= sizeof(int_holder) + sizeof(float_array_holder),
  "Invalid size!");

// Recursion tail
void out() { std::cout << std::endl; }

template <typename Head, typename ... TailList>
void out(const Head& head, TailList ... tail) {
  std::cout << head << ' ';
  out(tail...);
}

template <typename ... TypesList>
void process_args(TypesList ... args) {
  out(args...);
}

int main() {
  std::string str("hello");
  int i = 10;
  double d = 0.65541;
  process_args(str, i, d);

  return 0;
}
