#include <ToBinary.h>

union ForBinaryFloat {
  float floatted;
  uint32_t uint;
};

int32_t main() {
  ForBinaryFloat Float;
  std::cin >> Float.floatted;
  std::cout << ToBinary(Float.uint);
  return 0;
}
