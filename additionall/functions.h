#include <secondary.h>


void GnomeSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size();) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            ++i;
        }
        else {
            std::swap(arr[i], arr[i - 1]);
            --i;
        }
    }
}

void BubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void MergeSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (right + left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    
    std::vector<int> temp(right - left + 1);
    int left_index = left;
    int right_index = mid + 1;
    int temp_index = 0;
    
    while (left_index <= mid && right_index <= right) {
        if (nums[left_index] <= nums[right_index]) {
            temp[temp_index++] = nums[left_index++];
        } else {
            temp[temp_index++] = nums[right_index++];
        }
    }
    
    while (left_index <= mid) {
        temp[temp_index++] = nums[left_index++];
    }
    
    while (right_index <= right) {
        temp[temp_index++] = nums[right_index++];
    }
    
    for (int copy_index = 0; copy_index < temp_index; ++copy_index) {
        nums[left + copy_index] = temp[copy_index];
    }
}

int Partition(std::vector<int>& arr, int left, int right) {
    int l = left;
    int r = right; 
    int pivot = arr[(left + right) / 2];
    
    while (true) {
        while (arr[l] < pivot) {
            ++l;
        }
        while (arr[r] > pivot) {
            --r;
        }
        
        if (l >= r) {
            return r;
        }
        std::swap(arr[l++], arr[r--]);
    }
}

void QuickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int part = Partition(arr, left, right);
        QuickSort(arr, left, part);
        QuickSort(arr, part + 1, right);
    }
}

void Heapify(std::vector<int>& arr, int i, int size) {
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[parent]) {
        parent = left;
    }
    if (right < size && arr[right] > arr[parent]) {
        parent = right;
    }
    if (parent != i) {
        std::swap(arr[i], arr[parent]);
        Heapify(arr, parent, size);
    }
}

void HeapSort(std::vector<int>& arr) {
    int size = arr.size();

    for (int i = size / 2 - 1; i >= 0; --i) {
        Heapify(arr, i, size);
    }

    for (int i = size - 1; i > 0; --i) {
        std::swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}

void MergeSortWrapper(std::vector<int>& arr) {
    MergeSort(arr, 0, arr.size() - 1);
}

void QuickSortWrapper(std::vector<int>& arr) {
    QuickSort(arr, 0, arr.size() - 1);
}

double Say_No_To_Copypaste(void (*sortFunc)(std::vector<int>&), std::vector<int> data) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}