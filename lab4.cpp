#include <algorithm>
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
    while ( degree > 0) {
        if(degree & 1){
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

void MergeSort ( std::vector<int>& nums, int left, int right ) {

    if ( left >= right ){
        return;
    }

    int mid = (right + left) / 2;
    MergeSort ( nums, left, mid );
    MergeSort ( nums, mid + 1, right );
    
    std::vector<int> temp ( right - left + 1 );
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while ( i <= mid && j <= right ) {
        if ( nums[i] <= nums[j] ) {
            temp[k] = nums[i];
            k++;
            i++;
        } 
        else {
            temp[k] = nums[j];
            k++;
            j++;
        }
    }
    
    while ( i <= mid ) {
        temp[k] = nums[i];
        k++;
        i++;
    }
    
    while ( j <= right ) {
        temp[k] = nums[j];
        k++;
        j++;
    }
    for ( int idx = 0; idx < k; idx++ ) {
        nums[left + idx] = temp[idx];
    }
    return;
}

int Partition ( std::vector<int>& arr, int left, int right ) {

    int l = left;
    int r = right; 
    int pivot = arr[(left + right) / 2];
    while ( true ) {
        while ( arr[l] < pivot ) {
            l++;
        }
        while ( arr[r] > pivot ) {
            r--;
        }
        
        if (l >= r) {
            return r;
        }
        std::swap(arr[l++], arr[r--]);
}
}
void QuickSort ( std::vector<int>& arr, int left, int right ) {
    if ( left < right ) {
        int part = Partition ( arr, left, right);
        QuickSort ( arr, left, part);
        QuickSort ( arr, part + 1, right );
    }
    return;
}

void Heapify ( std::vector<int>& arr, int i, int size ) {

    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ( left < size && arr[left] > arr[parent] ) {
        parent = left;
        }
    if ( right < size && arr[right] > arr[parent] ) {
        parent = right;
    }
    if ( parent != i ) {
        std::swap( arr[i], arr[parent] );
        Heapify ( arr, parent, size );
    }
    return;
}

void HeapSort ( std::vector<int>& arr ) {

    int size = arr.size();

    for ( int  i = size / 2 - 1; i >= 0; i-- ) {
        Heapify ( arr, i, size );
    }

    for ( int i = size - 1; i > 0; i--) {
        std::swap ( arr[i], arr[0] );
        Heapify ( arr, 0, i );
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::ofstream results_for_graphics("lab4.csv", std::ios::out);
    int size_of_array = 10000;
    for ( int current_size = 100; current_size <= size_of_array; current_size += 100 ) {
        std::vector <int> for_sorting(current_size);
        int supremum = pow(2, 30);

        for ( int i = 0; i < current_size; i++ ) {
            for_sorting[i] = RandUns(1, supremum);
        }

        std::vector <int> sorted_array = for_sorting;
        HeapSort(sorted_array);
        std::vector <int> sorted_reversed_array = sorted_array;
        std::reverse(sorted_reversed_array.begin(), sorted_reversed_array.end());

        auto array_Gnome = for_sorting;
        auto start = std::chrono::high_resolution_clock::now();
        GnomeSort(array_Gnome);
        auto end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Gnome_Random = std::chrono::duration<double>(end - start).count();

        array_Gnome = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        GnomeSort(array_Gnome);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Gnome_Best = std::chrono::duration<double>(end - start).count();

        array_Gnome = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        GnomeSort(array_Gnome);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Gnome_Worst = std::chrono::duration<double>(end - start).count();

        auto array_Bubble = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        BubbleSort(array_Bubble);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Bubble_Random = std::chrono::duration<double>(end - start).count();

        array_Bubble = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        BubbleSort(array_Bubble);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Bubble_Best = std::chrono::duration<double>(end - start).count();

        array_Bubble = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        BubbleSort(array_Bubble);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Bubble_Worst = std::chrono::duration<double>(end - start).count();

        auto array_Insertion = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        InsertionSort(array_Insertion);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Insertion_Random = std::chrono::duration<double>(end - start).count();

        array_Insertion = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        InsertionSort(array_Insertion);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Insertion_Best = std::chrono::duration<double>(end - start).count();

        array_Insertion = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        InsertionSort(array_Insertion);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Insertion_Worst = std::chrono::duration<double>(end - start).count();

        auto array_Merge = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        MergeSort(array_Merge, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Merge_Random = std::chrono::duration<double>(end - start).count();

        array_Merge = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        MergeSort(array_Merge, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Merge_Best = std::chrono::duration<double>(end - start).count();

        array_Merge = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        MergeSort(array_Merge, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Merge_Worst = std::chrono::duration<double>(end - start).count();

        auto array_Quick = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        QuickSort(array_Quick, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Quick_Random = std::chrono::duration<double>(end - start).count();

        array_Quick = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        QuickSort(array_Quick, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Quick_Best = std::chrono::duration<double>(end - start).count();

        array_Quick = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        QuickSort(array_Quick, 0, current_size - 1);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Quick_Worst = std::chrono::duration<double>(end - start).count();

        auto array_Heap = for_sorting;
        start = std::chrono::high_resolution_clock::now();
        HeapSort(array_Heap);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Heap_Random = std::chrono::duration<double>(end - start).count();

        array_Heap = sorted_array;
        start = std::chrono::high_resolution_clock::now();
        HeapSort(array_Heap);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Heap_Best = std::chrono::duration<double>(end - start).count();

        array_Heap = sorted_reversed_array;
        start = std::chrono::high_resolution_clock::now();
        HeapSort(array_Heap);
        end = std::chrono::high_resolution_clock::now();
        double time_of_sorting_Heap_Worst = std::chrono::duration<double>(end - start).count();

        results_for_graphics << current_size << "," << time_of_sorting_Gnome_Random << "," << time_of_sorting_Gnome_Best << "," << time_of_sorting_Gnome_Worst << ","
        << time_of_sorting_Bubble_Random << "," << time_of_sorting_Bubble_Best << "," << time_of_sorting_Bubble_Worst << "," 
        << time_of_sorting_Insertion_Random << "," << time_of_sorting_Insertion_Best << "," << time_of_sorting_Insertion_Worst << ","
        << time_of_sorting_Merge_Random << "," << time_of_sorting_Merge_Best << "," << time_of_sorting_Merge_Worst << ","
        << time_of_sorting_Quick_Random << "," << time_of_sorting_Quick_Best << "," << time_of_sorting_Quick_Worst << "," 
        << time_of_sorting_Heap_Random << "," << time_of_sorting_Heap_Best << "," << time_of_sorting_Heap_Worst << "\n";
    }

    results_for_graphics.close();

    return 0;
}