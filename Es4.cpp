#include <iostream>
#include <string>

void EnterString(std::string& text){
    std::cout<<"Enter string: ";
    std::getline(std::cin, text);
    while(text.empty()){
        std::cerr<<"String not be empty!"<<'\n';
        std::cin.clear();
        std::cout<<"Enter string: ";
        std::getline(std::cin, text);
    }
}

char CheckLetterMoreCommon(const std::string& text){
    int max_cout = 0;
    char letter = ' ';
    for(int i = 0; i < text.length(); i++){
        int cout_letter = 0;
        for(int j = i+1; j < text.length(); j++){
            if(text[i] == text[j]){
                cout_letter ++;
            }
        }
        if(cout_letter > max_cout){
            max_cout = cout_letter;
            letter = text[i];
        }
    }
    return max_cout > 0? letter : ' ';
}

int main(){
    std::string text;
    EnterString(text);
    char result = CheckLetterMoreCommon(text);
    result == ' '? std::cout<<"There are no identical letters in the text"<<'\n' : std::cout<<"Letter more common is: "<<result<<'\n';
    return 0;
}