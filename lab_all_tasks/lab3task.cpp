#include "ToBinary.h"

namespace {
  float kZeroErrorRate = 16777210.0f;
}

void InfiniteLoop() {
  float floated = kZeroErrorRate;
  int32_t counter = 0;
  while (floated < floated + 1.0f) {
    floated += 1.0f;
    counter++;
    std::cout << floated << " " << counter << "\n";
  }
}

int main() {
  InfiniteLoop();
}