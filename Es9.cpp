#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>

class Solution {
public:
    bool isValid(std::string& s){
        std::unordered_map<char, char> simbol={
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        std::stack<char> temp;
        for(auto& letter : s){
            if(simbol.count(letter)){
                if (temp.empty() || temp.top() != simbol[letter]) {
                    return false;
                }
                temp.pop();
            }
            else {
                temp.push(letter);
            }
        }
        return temp.empty();
    }
};

int main(){
    std::string test1 = "{}[]()";
    std::string test2 = "{[()]}";
    std::string test3 = "{[)]}";
    std::string test4 = "{([)]}";
    std::string test5 = "{]";
    Solution sol;
    std::cout<<std::boolalpha<<sol.isValid(test5)<<'\n';
    return 0;
}