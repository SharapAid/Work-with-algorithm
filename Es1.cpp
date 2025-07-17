#include <iostream>

int FindMaxNumber(const int arr[], const int& size){
    int max_number = *arr;
    for(int i = 1; i < size; i++){
        if(max_number < arr[i]){
            max_number = arr[i];
        }
    }
    return max_number;
}

int main(){
    const int size = 8;
    int arr[size] = {3, 1, 4, 1, 5, 9, 2, 6};
    std::cout<<"MAX number: "<<FindMaxNumber(arr, size)<<'\n';
    return 0;
}