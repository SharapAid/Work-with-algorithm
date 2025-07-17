#include <iostream>

class List{
private:
    struct Node{
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
public:
    List(): head(nullptr){}

    ~List(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; 
    }

    void PushBack(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        } 
        else{
            Node* current = head;
            while(current->next != nullptr){ 
                current = current->next;
            }
            current->next = newNode; 
        }
    }

    void Print(){
        Node* current = head;
        while(current != nullptr){
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    bool FindElement(int value){
        Node* current = head;
        while(current != nullptr){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main(){
    return 0;
}