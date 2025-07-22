#include <iostream>

template<class T>
class DoublyLinkedList{
private:
    struct Node{
        T m_value;
        Node* next;
        Node* pred;
        Node(): m_value(T), next(nullptr), pred(nullptr){}
        Node(T value): m_value(value), next(nullptr), pred(nullptr){}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr){}

    ~DoublyLinkedList(){
        if(head != nullptr){
            while(head != nullptr){
                Node* temp = head->next;
                delete head;
                head = temp;
            }
            head = nullptr;
        }
    }

    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
};

template<class T>
void DoublyLinkedList<T>::push_back(T value){
    Node* new_node = new Node(value);
    if(head == nullptr){
        head = new_node;
        tail = head;
    }
    else{
        tail->next = new_node;
        new_node->pred = tail;
        tail = new_node; 
    }
}

template<class T>
void DoublyLinkedList<T>::push_front(T value){
    Node* new_node = new Node(value);
    if(head == nullptr){
        head = new_node;
        tail = head;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;  
    }
}

template<class T>
void DoublyLinkedList<T>::pop_front(){
    if(head != nullptr){
        
        Node* temp = head;

        if(head == tail){
            delete temp;
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
}

template<class T>
void DoublyLinkedList<T>::pop_back(){
    if(tail != nullptr){
        if(tail == head){
            delete tail;
            tail = nullptr;
            head = nullptr;
        }
        else{
            Node* temp = tail->pred;
            delete tail;
            tail = temp;
            tail->next = nullptr;  
        }
    }
}

int main(){
    return 0;
}