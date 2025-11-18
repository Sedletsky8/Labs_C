#include <functions.h>

int main() {
    std::ofstream results_for_graphics("lab3.csv", std::ios::out);
    for (int current_size = 50; current_size <= 10000; current_size += 50) {
      std::vector<int> for_sorting(current_size);

    for (int i = 0; i < current_size; i++) {
      for_sorting[i] = RandUns(1, constants::supremum);
    }

    double time_of_sorting_Gnome = Say_No_To_Copypaste(GnomeSort, for_sorting);
    double time_of_sorting_Bubble = Say_No_To_Copypaste(BubbleSort, for_sorting);
    double time_of_sorting_Insertion = Say_No_To_Copypaste(InsertionSort, for_sorting);
    double time_of_sorting_Merge = Say_No_To_Copypaste(MergeSortWrapper, for_sorting);
    double time_of_sorting_Quick = Say_No_To_Copypaste(QuickSortWrapper, for_sorting);
    double time_of_sorting_Heap = Say_No_To_Copypaste(HeapSort, for_sorting);

    results_for_graphics << current_size << "," << time_of_sorting_Gnome << "," << time_of_sorting_Bubble << "," 
    << time_of_sorting_Insertion << "," << time_of_sorting_Merge << "," << time_of_sorting_Quick << "," << time_of_sorting_Heap << "\n";
    }

    results_for_graphics.close();

    return 0;
}