#include <iostream>
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

static_assert(
  sizeof(varidic_inheritance<int_holder, float_array_holder>)
    >= sizeof(int_holder) + sizeof(float_array_holder),
  "Invalid size!");

int main() {
  return 0;
}
