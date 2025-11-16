#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int RandUns ( int min, int max ) { 
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    static std::default_random_engine e(seed); 
    std::uniform_int_distribution<int> d(min, max); 
    return d(e); 
}

int pow ( int base, int degree ) {
    int result = 1;
    while ( degree > 0 ) {
        if ( degree & 1 ) {
            result *= base;
        }
        base *= base;
        degree >>= 1;
        
    }
    return result;
}

void GnomeSort ( std::vector<int>& arr ) {

    int vector_size = arr.size( );
    int idx = 0;

    while ( idx < vector_size ) {
        if ( !idx ) {
            idx++;
        }
        if ( arr[idx] >= arr[idx - 1] ) {
            idx++;
        }
        else {
            std::swap ( arr[idx], arr[idx - 1] );
            idx--;
        }
    }
    return;
}

void BubbleSort ( std::vector<int>& arr ) {   //Legend_Sort

    int vector_size = arr.size();

    for ( int  i = 0; i < vector_size - 1; i++ ) {
        for ( int  j = 0; j < vector_size - i - 1; j++ ) {
            if ( arr[j] > arr[j + 1] ) {
                std::swap( arr[j], arr[j + 1] );
            }
        }
    }
    return;
}

void InsertionSort ( std::vector<int>& arr ) {

    int vector_size = arr.size();

    for ( int i = 1; i < vector_size; i++ ) {

        int j = i - 1;
        int key = arr[i];

        while ( j >= 0 && arr[j] > key ) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

int main() {
    std::ofstream results_for_graphics("lab0.csv", std::ios::out);
    results_for_graphics << "Size,Gnome,Bubble,Insertion\n";
    int size_of_array = 5000;
    for ( int current_size = 50; current_size <= size_of_array; current_size += 50 ) {
        std::vector <int> for_sorting(current_size);
        int supremum = pow(2, 30);

        for ( int i = 0; i < current_size; i++ ) {
            for_sorting[i] = RandUns(1, supremum);
        }

        auto array_Gnome = for_sorting;
        auto start = std::chrono::high_resolution_clock::now();
        GnomeSort(array_Gnome);
        auto end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Gnome = std::chrono::duration<double>(end - start).count();

        auto array_Bubble = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        BubbleSort(array_Bubble);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Bubble = std::chrono::duration<double>(end - start).count();

        auto array_Insertion = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        InsertionSort(array_Insertion);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Insertion = std::chrono::duration<double>(end - start).count();

        results_for_graphics << current_size << "," << time_of_sorting_Gnome << "," << time_of_sorting_Bubble << "," 
        << time_of_sorting_Insertion << "\n";
    }
        results_for_graphics.close();
        
        return 0;
}