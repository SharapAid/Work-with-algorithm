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
    Node* new_node = new Node(value);
    if(head == nullptr){
        head = new_node;
    }
    else{
        Node* temp = head;
        head = new_node;
        head->next = temp;
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
    if(head == nullptr || head->next == nullptr){
        return;
    }
    do{
        Node* current_node = head;
        Node* next_node = current_node->next;
        Node* pred_node = nullptr;
        bool is_change = false;
        while(next_node != nullptr){
            if(current_node->m_data < current_node->next->m_data){
                if(current_node == head){
                    Node* temp = head;
                    Node* temp2 = next_node;
                    Node* temp3 = next_node->next;
                    head = temp2;
                    head->next = temp;
                    temp->next = temp3;
                    is_change = true;
                }
                else{
                    Node* temp = next_node;
                    Node* temp2 = pred_node->next;
                    Node* temp3 = next_node->next;
                    pred_node->next = temp;
                    temp->next = temp2;
                    temp2->next = temp3;
                    is_change = true;
                }
                pred_node = next_node;
            }
            else{
                pred_node = current_node;
                current_node = next_node;
            }
            if(current_node == nullptr){
                break;
            }
            next_node = current_node->next;
        }
        if(!is_change){
            break;
        }
    }
    while(true);
}

int main(){
    LinkedList list;
    list.push_front(21);
    list.push_front(3);
    list.push_front(4);
    list.push_front(1);
    list.push_front(14);
    list.push_front(2);
    list.sort();
    return 0;
}