#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;


    Node(int data){
        this -> data = data;
        this -> next = NULL;
    } 
// Counstructor
    Node(){
        this->next = NULL;
    }  
// Destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data : "<<value<<endl;
    }

};

void printlist(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int Peek(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

void InsertAtHead(Node* &head,Node* &tail,int data){

    // Creating a new node
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }

}
void InsertAtTail(Node* &head,Node* &tail,int data){
    
     // Creating a new node
    Node* newNode = new Node(data);

    if(tail == NULL){
        head = newNode;
        tail = newNode;
    }else{
         tail->next = newNode;
         tail = newNode;
    }
}

void InsertAtPosition(Node* &head,Node* &tail,int data,int pos){

        if(pos == 1){
            InsertAtHead(head,tail,data);
            return;
        }

        // Creating a node
        Node* newNode = new Node(data);

        Node* temp = head;
        int cnt = 1;

        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }

        // inserting at tail
        if(temp->next == NULL){
            InsertAtTail(head,tail,data);
            return;
        }

        newNode -> next = temp->next;
        temp->next = newNode;
}


void deleteNode(Node* &head,Node* &tail,int pos){



    if(pos == 1){
     Node* temp = head;
     head = head->next;
         // Free up the memory of the garbage node
        temp->next = NULL;
        delete temp;    
    }else{
    
    int cnt = 1;
    Node* temp = head;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }


   if(pos == Peek(head)){
       tail = temp;
   }
   Node* curr = temp->next;

   temp->next = curr->next;
    curr->next = NULL;
    delete curr;
}
}


int main(){
    // Node* node1 = new Node(1);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    
    // Node* node2 = new Node(2);
    // cout<<node2->data<<endl;
    // cout<<node2->next<<endl;

    // node1->next = node2;
    Node* head = NULL;
    Node* tail = NULL;
    printlist(head);
    InsertAtHead(head,tail,1);
    InsertAtHead(head,tail,0);
    InsertAtHead(head,tail,-1);
    InsertAtTail(head,tail,-8);
    InsertAtTail(head,tail,-99);
    InsertAtPosition(head,tail,69,2);
    InsertAtPosition(head,tail,689,7);
    printlist(head);
    deleteNode(head,tail,2);
    printlist(head);

    deleteNode(head,tail,1);
    printlist(head);
    int p = Peek(head);
    deleteNode(head,tail,p);
     p = Peek(head);
    deleteNode(head,tail,p);
     printlist(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl; 
    cout<<"Peek : "<<Peek(head)<<endl; 

}