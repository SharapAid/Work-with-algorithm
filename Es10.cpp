#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>

class Solution {
private: 
    static char char_change[126];

    struct Initializer{
        Initializer(){
            char_change['}'] = '{';
            char_change[']'] = '[';
            char_change[')'] = '(';
        }
    };
    static Initializer initializer;

public:
    bool isValid(std::string& s){
        std::stack<char> temp;
        for(auto& letter : s){
            if(char_change[letter]){
                if(temp.empty() || temp.top() != char_change[letter]) {
                    return false;
                }
                temp.pop();
            }
            else{
                temp.push(letter);
            }
        }
        return temp.empty();
    }
};
char Solution::char_change[126] = {0};
Solution::Initializer Solution::initializer;

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