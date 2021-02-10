#include <iostream>

struct Node {
    int data;
    struct Node* next;
};

void insert(Node **head, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);

    (*head) = new_node;
}

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* TwoListAddition(Node* L1, Node* L2){
    Node* headNode = NULL;
    Node *temp;
    Node *last = NULL;
    int sum, carry = 0;

    while( L1 != NULL || L2 != NULL){
        sum = carry + (L1 ? L1->data : 0) + (L2 ? L2->data : 0);
        
        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        temp = newNode(sum);

        if(headNode == NULL){
            headNode = temp;
        }
        else{
            last->next = temp;
        }

        last = temp;

        if(L1){
            L1 = L1->next;
        }
        if(L2){
            L2 = L2 -> next;
        }
    }

    if(carry > 0){
        temp->next = newNode(carry);
    }

    return headNode;
}

void DisplayList(Node* node){
    while(node != NULL){
        std:: cout << node -> data << " ";
        node = node-> next;
    }
    std::cout << std::endl;
}

int main(){
    Node* result = NULL;
    Node* firstList = NULL;
    Node* secondList = NULL;

    insert(&firstList,2);
    insert(&firstList,4);
    insert(&firstList,3);

    insert(&secondList,5);
    insert(&secondList,6);
    insert(&secondList,4);
    
    DisplayList(firstList);
    DisplayList(secondList);

    result = TwoListAddition(firstList, secondList);
    std:: cout << "Result of the addition of the two Linked List is: ";
    DisplayList(result);

    return 0;
}

