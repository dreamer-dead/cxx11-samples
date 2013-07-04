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

// Ignore all params and do nothing
template<typename ... T>
void ignore(const T& ...) {;}

// Recursion tail
void out() { std::cout << std::endl; }

template <typename Head, typename ... TailList>
void out(const Head& head, TailList ... tail) {
  std::cout << head << ' ';
  out(tail...);
}

template <typename ... TypesList>
void process_args(TypesList ... args) {
  //out(args...);
  //std::cout << args ...;
  ignore(std::cout << args << ' ' ...);
  std::cout << std::endl;
}

// Here we can get sum of all elements
template<typename ... T>
int calculate_sum(T ... nums)
{
     int ret_val = 0;

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsequenced"
#endif
     // This expands to ignore(ret_val += nums1, ret_val += nums2, ...)
     // This line should generate warning in clang - [-Wunsequenced]
     ignore(ret_val += nums ...);
#if defined __clang__
#pragma clang diagnostic pop
#endif

     return ret_val;
}

// Right angle brackets
typedef varidic_inheritance<varidic_inheritance<int_holder>> complex_type;

int main() {
  std::string str("hello");
  int i = 10;
  double d = 0.65541;
  process_args(str, i, d);

  std::cout << "sum of 10 + 5 + 46 + 9 = " << calculate_sum(10, 5, 46, 9) << std::endl;
  return 0;
}
