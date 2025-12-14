#include <ToBinary.h>
#include <cmath>

int32_t main() {
  std::cout << std::fixed;
  std::cout.precision(2);
  for (uint32_t i = 1; i < 30; ++i) {
    std::cout << std::pow(10, i) << "\n";
  }
  return 0;
}