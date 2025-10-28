// circular linked list

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }

        cout<< "memory is free for node with data: "<< value << endl;
    }

};



// insertion

void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        Node * temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else{
        // non-empty List
        // assuming that element is present in the list
        Node * curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        // element is found  -> curr is representing element wala node
        Node * temp = new Node(d);
        temp -> next = curr -> next; 
        curr -> next = temp;
    }

}


// How we will taverse the list?
void print(Node* tail){
    Node* temp= tail;

    // empty list
    if(tail == NULL){
        cout<< "List is Empty "<< endl;
        return;
    }

    do{
        cout << tail -> data << " ";
        tail = tail -> next;

    }
    while(tail != temp);
    cout << endl;
}




// delete node
void deleteNode(Node* &tail,int value){
    // empty List
    if(tail == NULL){
        cout<<" List is Empty: "<< endl;
        return;
    }

    else{
        // non-empty
        // assuming that "value" is present in Linked List
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != value){
            prev=curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // to delete one single node in linked list
        if(curr == prev){
            tail = NULL;
        }

        // to delete >=2 nodes in Linked List
        if(tail == curr){
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}





int main(){
       
    Node* tail = NULL;
    // Insert in empty list
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    insertNode(tail,9,10);
    print(tail);

    insertNode(tail,3,4);
    print(tail);

    deleteNode(tail,3);
    print(tail);

    deleteNode(tail,7);
    print(tail);


    deleteNode(tail,10);
    print(tail);




 return 0;
}