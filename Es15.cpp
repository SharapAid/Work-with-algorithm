#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums);

int main(){
    std::vector<int> test = {1,1,1,1,2,2,3,4,4,4,5};
    int result = removeDuplicates(test);
    std::cout<<result<<'\n';
    return 0;
}

int removeDuplicates(std::vector<int>& nums){
    if(nums.empty() || nums.size() == 1){
        return nums.size();
    }
    int insertIndex = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[insertIndex - 1]){
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    return insertIndex;
}