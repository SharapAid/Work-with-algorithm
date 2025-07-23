#include <iostream>
void merge(int* arr, int left,int mid, int right);
void MergeSort(int* arr, int left, int right);
void Print(int* arr, int size);

int main(){
    int size = 10;
    int arr[size] = {24,45,6,2,65,12,2,3,3,7};
    Print(arr, size);
    MergeSort(arr, 0, size -1);
    Print(arr, size);
    return 0;
}



void MergeSort(int* arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left,int mid, int right){
    int arr_left[mid - left + 1];
    int arr_right[right - mid];

    int size_left = mid - left +1;
    int size_right = right - mid;

    for(int i = 0; i < size_left; i++){
        arr_left[i] = arr[left + i];
    }

    for(int i = 0; i < size_right; i++){
        arr_right[i] = arr[mid + 1 + i];
    }

    int j = 0;
    int h = 0;
    int k = left;
    while(j < size_left && h < size_right){
        if(arr_left[j] <= arr_right[h]){
            arr[k] = arr_left[j];
            j++;
        }
        else{
            arr[k] = arr_right[h];
            h++;
        }
        k++; 
    }

    while(j < size_left){
        arr[k] = arr_left[j];
        j++;
        k++;
    }

    while(h < size_right){
        arr[k] = arr_right[h];
        h++;
        k++;
    }
}


void Print(int* arr, int size){
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<'\n';
}