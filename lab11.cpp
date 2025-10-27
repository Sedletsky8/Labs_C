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

int main() {
    std::ofstream results_for_graphics("lab14(O0).csv", std::ios::out);
    results_for_graphics << "Size,Bubble\n";
    int size_of_array = 5000;
    for ( int current_size = 10; current_size <= size_of_array; current_size += 50 ) {
        std::vector <int> for_sorting(current_size);
        int supremum = pow(2, 30);

        for ( int i = 0; i < current_size; i++ ) {
            for_sorting[i] = RandUns(1, supremum);
        }

        auto array_Bubble = for_sorting;
        auto start = std::chrono::high_resolution_clock::now();
        BubbleSort(array_Bubble);
        auto end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Bubble = std::chrono::duration<double>(end - start).count();

        results_for_graphics << current_size << "," << time_of_sorting_Bubble << "\n"; 
        long long sum = 0;
        for ( int i = 0; i < current_size; i++ ) {
            sum += array_Bubble[i];
        }
    }

    results_for_graphics.close();
        
    return 0;
}
//прпопоая больной у меня болит лапка спаааситеее помогииитеееее люди добрые