#include <iostream>

template<typename T>
class DoublyLinkedList;

template<typename T>
void Print(DoublyLinkedList<T>& list);

template<typename T>
class DoublyLinkedList{
private:
    struct Node{
        T m_value;
        Node* next;
        Node* pred;
        Node(): m_value(T()), next(nullptr), pred(nullptr){}
        Node(T value): m_value(value), next(nullptr), pred(nullptr){}
    };
    Node* head;
    Node* tail;

    Node* merge(Node* first_half, Node* second_half);
    Node* split(Node* head_ref);

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
    Node* GetHead(){
        return head;
    }

    friend void Print<T>(DoublyLinkedList<T>& list);

    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    Node* find(T value);
    void sort();
    bool is_empty(){
        return head == nullptr;
    }
    Node* merge_sort(Node* head);
};

template<typename T>
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

template<typename T>
void DoublyLinkedList<T>::push_front(T value){
    Node* new_node = new Node(value);
    if(head == nullptr){
        head = new_node;
        tail = head;
    }
    else{
        new_node->next = head;
        head->pred = new_node;
        head = new_node;  
    }
}

template<typename T>
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
            head->pred = nullptr;
            delete temp;
        }
    }
}

template<typename T>
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

template<typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::find(T value){
    Node* current_node = head;
    while(current_node != nullptr && current_node->m_value != value){
        current_node = current_node->next;
    }
    return current_node;
}

template<typename T>
void DoublyLinkedList<T>::sort(){
    if(head != nullptr){
        do{
            bool is_merge = false;
            Node* current_node = head;
            Node* next_node = current_node->next;
            while(current_node->next != nullptr){
                if(current_node->m_value > next_node->m_value){
                    T temp = current_node->m_value;
                    current_node->m_value = next_node->m_value;
                    next_node->m_value = temp;
                    is_merge = true;
                    
                }
                current_node = current_node->next;
                next_node = current_node -> next;
            }
            if(!is_merge){
                break;
            }
        }
        while(true);
    }
}

template<typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::split(Node* head_ref){
    if(head_ref != nullptr && head_ref->next != nullptr){
        Node* slow = head_ref;
        Node* fast = head_ref;
        Node* prev_slow = nullptr;
        while(fast && fast->next != nullptr){
            prev_slow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* second_half_head = slow;
        prev_slow->next = nullptr;
        second_half_head->pred = nullptr; 
        return second_half_head;
    }
    return head_ref;
}

template<typename T>
typename DoublyLinkedList<T>::Node*  DoublyLinkedList<T>::merge(Node* first_half, Node* second_half){
    if(first_half == nullptr){
        return second_half;
    }

    if(second_half == nullptr){
        return first_half;
    }

    Node* first = first_half;
    Node* second = second_half;
    Node* dummy = new Node(T());
    Node* current = dummy;
    while(first != nullptr && second != nullptr){
        if(first->m_value < second->m_value){
            current->next = first;
            first->pred = current;
            first = first->next;
        }
        else{
            current->next = second;
            second->pred = current;
            second = second->next;
        }
        current = current->next;
    }

    if(first != nullptr){
        current->next = first;
        first->pred = current;
    } 

    else if(second != nullptr){
        current->next = second;
        second->pred = current;
    } 
    
    Node* new_head = dummy->next;
    new_head->pred = nullptr;
    delete dummy;
    dummy = nullptr;
    second = nullptr;
    first = nullptr;
    current = nullptr;
    return new_head;
}

template<typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::merge_sort(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* first_half_head = head;
    Node* second_half_head = split(head);
    Node* first_half_sorted = merge_sort(first_half_head);
    Node* second_half_sorted = merge_sort(second_half_head);
    return merge(first_half_sorted, second_half_sorted);
}

template<typename T>
void Print(DoublyLinkedList<T>& list){
    typename DoublyLinkedList<T>::Node* current_node = list.GetHead();
    while(current_node != nullptr){
        std::cout<<current_node->m_value<<'\t';
        current_node = current_node->next;
    }
    std::cout<<'\n';
}

int main(){
    DoublyLinkedList<int> list;
    list.push_front(3);
    list.push_front(12);
    list.push_front(7);
    list.push_front(35);
    list.push_front(17);
    list.push_front(1);
    Print(list);
    list.merge_sort(list.GetHead());
    Print(list);
    return 0;
}