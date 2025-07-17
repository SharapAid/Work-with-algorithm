#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
private:
    static int char_to_int_map[91];

    struct Initializer{
        Initializer(){
            char_to_int_map['I'] = 1;
            char_to_int_map['V'] = 5;
            char_to_int_map['X'] = 10;
            char_to_int_map['L'] = 50;
            char_to_int_map['C'] = 100;
            char_to_int_map['D'] = 500;
            char_to_int_map['M'] = 1000;
        }
    };
    static Initializer initializer;

public:
    
    int romanToInt(std::string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            int current_number = char_to_int_map[s[i]];
            if(i + 1 < s.length() && char_to_int_map[s[i+1]] > current_number){
                result -= current_number;
            }
            else{
                result += current_number;
            } 
        }
        return result;
    }
};

int Solution::char_to_int_map[91] = {0};
Solution::Initializer Solution::initializer;

int main(){
    std::string num_roman = "XIV";
    Solution roman;
    int result = roman.romanToInt(num_roman);
    std::cout<<result<<'\n';
    return 0;
}