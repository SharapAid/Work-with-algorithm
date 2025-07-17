#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs){
        int cout_similar_letter = 0;
        std::string result;
        if(!strs.empty()){
            std::size_t size_word = strs[0].size();
            for(int i = 1; i < strs.size(); i++){
                if(size_word > strs[i].size()){
                    size_word = strs[i].size();
                }
            }
            for(int j = 0; j < size_word; j++){
                for(int i = 0; i < strs.size(); i ++){
                    if(strs[0][j] == strs[i][j]){
                        cout_similar_letter ++;
                    }
                }
                if(cout_similar_letter  == strs.size()){
                    result += strs[0][j];
                    cout_similar_letter = 0;
                }
                else{
                    return result;
                }
            }
        }
        return result;
    }
};


int main(){
    std::vector<std::string> vector_word = 
        {"flower","flower","flower","flower"};
    std::vector<std::string> vector_word4 = 
        {"flower","flow","flight"};
    std::vector<std::string> vector_word2 = 
        {"dog","racecar","car"};
    std::vector<std::string> vector_word3 = 
        {"ab","a"};
    std::vector<std::string> vector_word5 = 
        {"a"};
        Solution solv;
        std::string result = solv.longestCommonPrefix(vector_word4);
        std::cout<<result<<'\n';
    return 0;
}