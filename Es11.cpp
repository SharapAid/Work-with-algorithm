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
    bool is_empty(){
        if(this->head == nullptr){
            return true;
        }
        return false;
    }

    void sort();
    LinkedList merge(LinkedList& list1, LinkedList& list2);
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
LinkedList LinkedList::merge(LinkedList& list1, LinkedList& list2){
    LinkedList new_list;
    Node* dumpe_node = new Node(0);
    Node* current_node_list1 = list1.head;
    Node* current_node_list2 = list2.head;
    Node* current_node_new_list = dumpe_node;
    
    while(current_node_list1 != nullptr){
        Node* new_node= new Node(current_node_list1->m_data);
        current_node_new_list->next = new_node;
        current_node_list1 = current_node_list1->next;
        current_node_new_list = current_node_new_list->next;
    }

    while(current_node_list2 != nullptr){
        Node* new_node= new Node(current_node_list2->m_data);
        current_node_new_list->next = new_node;
        current_node_list2 = current_node_list2->next;
        current_node_new_list = current_node_new_list->next;
    }


    if(dumpe_node->next != nullptr){
        Node* temp = dumpe_node->next;
        delete dumpe_node;
        dumpe_node = nullptr;
        new_list.head = temp;
    }
    else{
        delete dumpe_node;
        dumpe_node = nullptr;
    }
    return new_list;
}

int main(){
    LinkedList list;
    LinkedList list2;
    LinkedList list3 = list.merge(list, list2);
    return 0;
}