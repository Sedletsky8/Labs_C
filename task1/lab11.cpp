#include <functions.h>

int main() {
    std::ofstream results_for_graphics("lab14(O0).csv", std::ios::out);
    results_for_graphics << "Size,Bubble\n";

    for (int current_size = 10; current_size <= 5000; current_size += 50) {
      std::vector<int> for_sorting(current_size);
      auto array_Bubble = for_sorting;
    for (int i = 0; i < current_size; i++) {
      for_sorting[i] = RandUns(1, constants::supremum);
    }

    double bubble_time = Say_No_To_Copypaste(BubbleSort, for_sorting);

    results_for_graphics << current_size << "," << bubble_time << "\n";
    long long sum = 0;
    for ( int i = 0; i < current_size; i++ ) {
      sum += array_Bubble[i];
      }
    }

    results_for_graphics.close();
        
    return 0;
}