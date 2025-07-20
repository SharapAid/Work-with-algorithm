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
    
}

int main(){
    int arr[] = {1, 18, 6, 3, 8, 4, 32, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int number : arr){
        std::cout<<number<<'\t';
    }
    std::cout<<'\n';
    SelectionSort(arr, n);
    for(int number : arr){
        std::cout<<number<<'\t';
    }
    std::cout<<'\n';
    return 0;
}