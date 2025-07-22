#include <iostream>

void BubleSort(int* arr, int size){
    do{
        bool is_change = false;
        for(int i = 0; i < size -1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                is_change = true;
            }
        }
        if(!is_change){
            break;
        }
    }
    while(true);
}

void SelectionSort(int* arr, int size){
    for(int j = 0; j < size; j++){
        int min = j;
        for(int i = j+1; i < size; i++){
            if(arr[min] > arr[i]){
                min = i;
            }
        } 
        if(min != j){
            int temp = arr[j];
            arr[j] = arr[min];
            arr[min] = temp; 
        }
    }        
}

void InsertionSort(int* arr, int size){
    int key = 0;
    int i = 1;
    while(i < size){
        key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        i++;
    }
}

void PrintArrey(int* arr, int size){
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<'\n';
}

//Sort model Lomuto.
int Partition(int* arr, int left, int right){
    int pivot = arr[right];
    int i = (left - 1); 
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return (i + 1);
}

void QuickSort(int* arr, int left, int right){
    if(left < right){
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot + 1, right);
    }   
}


//Sort model Hoare.
int Partition2(int* arr, int left, int right){
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do{
            i++;
        } 
        while (arr[i] < pivot);

        do{
            j--;
        } 
        while (arr[j] > pivot);
        
        if(i >= j){
            return j;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void QuickSort2(int* arr, int left, int right){
    if(left < right){
        int pivot = Partition2(arr, left, right);
        QuickSort(arr, left, pivot);
        QuickSort(arr, pivot + 1, right);
    }   
}

void BubleSortMax(int* arr, int size){
    do{
        int i = 0;
        bool is_merge = false;
        while(i + 1< size){
            if(arr[i] > arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                is_merge = true;
            }
            i++;
        }
        size --;
        if(!is_merge){
            break;
        }
    }
    while(size > 0);
}

int main(){
    int arr[] = {4,3,8,0,5,2,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    PrintArrey(arr, n);
    PrintArrey(arr, n);
    return 0;
}