#include <fstream>
#include "ToBinary.h"

namespace {
  uint32_t kConst = 1000000000;
}

double anal_solution() {
  return 0.5;
}

float LeftRectangleFloat(float a, float b, int n) {
  float h = (b - a) / n;
  float sum = 0.0f;

  for (uint32_t i = 0; i < n; ++i) {
    float y = a + i * h;
    sum += y;
  }
  return sum * h;
}

double LeftRectangleDouble(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0.0;

  for (uint32_t i = 0; i < n; ++i) {
    double y = a + i * h;
    sum += y;
  }
  return sum * h;
}

int main() {
  std::ofstream output_file("integrate_result.csv");
  output_file << std::fixed;
  output_file.precision(10);
  output_file << "size, float_error, double_error" << '\n';
  double analytical = anal_solution();

  for (int size = 10; size < kConst; size *= 10) {
    float floated = LeftRectangleFloat(0.0f, 1.0f, size);
    double doubled = LeftRectangleDouble(0.0, 1.0, size);
    float float_error = std::abs(floated - analytical);
    double double_error = std::abs(doubled - analytical);
    output_file << size << " " << float_error <<  " " << double_error << '\n';
  }
  output_file.close();
  return 0;
}