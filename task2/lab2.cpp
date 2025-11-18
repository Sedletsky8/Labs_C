#include <functions.h>

int main() {
    std::ofstream results_for_graphics("lab2.csv", std::ios::out);
    results_for_graphics << "Size,Merge,Quick,Heap\n";
    
    for (int current_size = 1000; current_size <= 500000; current_size += 5000) {
      std::vector<int> for_sorting(current_size);

      for (int i = 0; i < current_size; i++) {
        for_sorting[i] = RandUns(1, constants::supremum);
      }

    double time_of_sorting_Merge = Say_No_To_Copypaste(MergeSortWrapper, for_sorting);
    double time_of_sorting_Quick = Say_No_To_Copypaste(QuickSortWrapper, for_sorting);
    double time_of_sorting_Heap = Say_No_To_Copypaste(HeapSort, for_sorting);

        
    results_for_graphics << current_size << "," << time_of_sorting_Merge << ","
    << time_of_sorting_Quick << "," << time_of_sorting_Heap << "\n";
    }

    results_for_graphics.close();

    return 0;
}