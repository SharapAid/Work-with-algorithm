#include <iostream>
#include <string>
#include <iomanip>

void EnterString(std::string& text){
    std::cout<<"Enter string: ";
    std::getline(std::cin, text);
    while(text.empty()){
        std::cerr<<"Not be empty!"<<'\n';
        std::cin.clear();
        std::cout<<"Enter string: ";
        std::getline(std::cin, text);
    }
}

bool ChecTheSameLetter(std::string& text){
    for(int i = 0; i < text.length(); i++){
        for(int j = i+1; j < text.length(); j++){
            if(text[i] == text[j]){
                return true;
            }
        }
    }
    return false;
}


int main(){
    std::cout<<std::boolalpha;
    const int size = 100;
    std::string text;
    EnterString(text);
    std::cout<<'\n'<<"Word is: "<<text<<'\n';
    bool result = ChecTheSameLetter(text);
    std::cout<<result<<'\n';
    return 0;
}