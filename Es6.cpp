#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

bool foonk(int x){
    if(x < 0){
        return false;
    }
    if(x % 10 == 0 && x != 0){
        return false;
    }
    int reversed_num = 0;
    while(x >= reversed_num){
        reversed_num = reversed_num * 10 + x % 10;
        x /= 10; 
    }
    return x == reversed_num || x == reversed_num / 10;
}

int main(){
    int num = 121;
    bool is_polindrome = foonk(num);
    std::cout<<num<<'\n';
    std::cout<<std::boolalpha<<is_polindrome<<'\n';
    return 0;
}