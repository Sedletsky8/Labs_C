#include <iostream>
#include <cstdint>
#include <string>

namespace {
  uint32_t kIntSize = 32;
}

std::string ToBinary(uint32_t number) {
  std::string answer(kIntSize, '0');
  for (int32_t i = kIntSize; i > 0; --i) {
    if (number & (1 << (i - 1))) {
      answer[kIntSize - i] = '1';
    }
  }
  return answer;
}
