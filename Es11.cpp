#include <iostream>

class LinkedList{
private:
    struct Node{
        int m_data;
        Node* next;
        Node():m_data(0), next(nullptr){}
        Node(int data):m_data(data), next(nullptr){}
    };
    Node* head;
public:
    LinkedList(): head(nullptr){}

    ~LinkedList(){
        if(head != nullptr){
            while(head->next != nullptr){
                Node* current_node = head->next;
                delete head;
                head = current_node;     
            }
            delete head;
            head = nullptr;
        }
    }

    void push_front(int value);
    void pop_front();
    Node* find(int value);
    void sort();
};

void LinkedList::push_front(int value){
    Node* current_node = head;
    if(head == nullptr){
        Node* new_node = new Node(value);
        head = new_node;
    }
    else{
        while(current_node->next != nullptr){
            current_node = current_node->next;
        }
        Node* new_node = new Node(value);
        current_node->next = new_node;
    }
}

void LinkedList::pop_front(){
    if(head != nullptr){
        if(head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node* current_node = head->next;
            delete head;
            head = current_node;  
        }
    }
}

LinkedList::Node* LinkedList::find(int value){
    Node* current_node = head;
    while(current_node != nullptr){
        if(current_node->m_data == value){
            return current_node;
        }
        current_node = current_node->next;
    }
    return nullptr;
}

void LinkedList::sort(){
    Node* current_node = head;
    while(current_node->next != nullptr){
    }
}

int main(){
    LinkedList list;
    list.push_front(21);
    list.push_front(3);
    list.push_front(4);
    list.push_front(1);
    return 0;
}