#include <functions.h>


int main() {
  std::ofstream results_for_graphics("lab0.csv", std::ios::out);
  results_for_graphics << "Size,Gnome,Bubble,Insertion\n";

  for (int current_size = 50; current_size <= 5000; current_size += 50) {
    std::vector<int> data(current_size);

    for (int i = 0; i < current_size; i++) {
      data[i] = RandUns(1, constants::supremum);
    }

    double gnome_time = Say_No_To_Copypaste(GnomeSort, data);
    double bubble_time = Say_No_To_Copypaste(BubbleSort, data);
    double insertion_time = Say_No_To_Copypaste(InsertionSort, data);

    results_for_graphics << current_size << "," << gnome_time << "," 
    << bubble_time << "," << insertion_time << "\n";
  }
    results_for_graphics.close();
    return 0;
}