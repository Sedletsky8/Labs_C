#include <functions.h>


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::ofstream results_for_graphics("lab4.csv", std::ios::out);
  
  for (int current_size = 100; current_size <= 10000; current_size += 100) {
    std::vector<int> data(current_size);

    for (int i = 0; i < current_size; i++) {
      data[i] = RandUns(1, constants::supremum);
    }

    std::vector<int> sorted_data = data;
    HeapSort(sorted_data);
    std::vector<int> reversed_data = sorted_data;
    std::reverse(reversed_data.begin(), reversed_data.end());

    double gnome_random = Say_No_To_Copypaste(GnomeSort, data);
    double gnome_best = Say_No_To_Copypaste(GnomeSort, sorted_data);
    double gnome_worst = Say_No_To_Copypaste(GnomeSort, reversed_data);

    double bubble_random = Say_No_To_Copypaste(BubbleSort, data);
    double bubble_best = Say_No_To_Copypaste(BubbleSort, sorted_data);
    double bubble_worst = Say_No_To_Copypaste(BubbleSort, reversed_data);

    double insertion_random = Say_No_To_Copypaste(InsertionSort, data);
    double insertion_best = Say_No_To_Copypaste(InsertionSort, sorted_data);
    double insertion_worst = Say_No_To_Copypaste(InsertionSort, reversed_data);

    double merge_random = Say_No_To_Copypaste(MergeSortWrapper, data);
    double merge_best = Say_No_To_Copypaste(MergeSortWrapper, sorted_data);
    double merge_worst = Say_No_To_Copypaste(MergeSortWrapper, reversed_data);

    double quick_random = Say_No_To_Copypaste(QuickSortWrapper, data);
    double quick_best = Say_No_To_Copypaste(QuickSortWrapper, sorted_data);
    double quick_worst = Say_No_To_Copypaste(QuickSortWrapper, reversed_data);

    double heap_random = Say_No_To_Copypaste(HeapSort, data);
    double heap_best = Say_No_To_Copypaste(HeapSort, sorted_data);
    double heap_worst = Say_No_To_Copypaste(HeapSort, reversed_data);

    results_for_graphics << current_size << "," 
    << gnome_random << "," << gnome_best << "," << gnome_worst << ","
    << bubble_random << "," << bubble_best << "," << bubble_worst << "," 
    << insertion_random << "," << insertion_best << "," << insertion_worst << ","
    << merge_random << "," << merge_best << "," << merge_worst << ","
    << quick_random << "," << quick_best << "," << quick_worst << "," 
    << heap_random << "," << heap_best << "," << heap_worst << "\n";
  }

    results_for_graphics.close();

    return 0;
}