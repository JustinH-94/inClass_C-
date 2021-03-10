#include <iostream>

struct Node{
    int value;
    struct Node* next;
};

void Insert(Node **head, int new_data){
    Node* new_node = new Node();
    new_node->value = new_data;
    new_node->next = (*head);

    (*head) = new_node;
}

Node* EstablishList(Node* List){
    for(int i = 5; i >=1 ; i--){
        Insert(&List, i);
    }
    return List;
}

void DisplayList(Node* node){
    while(node != NULL){
        std:: cout << node -> value << " ";
        node = node-> next;
    }
    std::cout << std::endl;
}

int GetNthNode(){
    int nth;
    std::cout << "Enter the place from the list of which you want to get rid of." << std::endl;
    std::cin >> nth;
    return nth;
}

Node* RemoveFromList(Node* List, int n){
    Node* newList = new Node();
    int length = 0;
    newList->next = List;
    Node* head = List;

    while( head != NULL){
        length++;
        head = head->next;
    }

    length -= n;
    head = newList;
    while(length > 0){
        length--;
        head = head->next;
    }
    head->next = head->next->next;

    return newList->next;
}

int main(){
    Node* List = NULL;
    int nth;

    List = EstablishList(List);
    DisplayList(List);

    nth = GetNthNode();

    List = RemoveFromList(List, nth);

    DisplayList(List);
    
}