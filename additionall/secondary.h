#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

namespace  constants {
    constexpr int supremum = 1 << 30;
}

int RandUns(int min, int max) {
  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  static std::default_random_engine e(seed);
  std::uniform_int_distribution<int> d(min, max);
  return d(e);
}