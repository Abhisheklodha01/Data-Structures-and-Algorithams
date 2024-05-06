#include <iostream>
using namespace std;

class Node {

public: 
    int data;
    Node* head;
    Node* next;
    Node(int data) {
       this->data = data;
       this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // inserting a first position
      Node* temp = new Node(d);
      temp->next = head;
      head = temp;
}

void insertAtTail(Node* &tail, int d) {
    // inserting at last position
      Node* temp = new Node(d);
      tail->next = temp;
      tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int pos) {
   // inserting at first position
    if(pos == 1) {
        insertAtHead(head, d);
        return;
    }

    // inserting at given position or in middle
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos -1) {
        temp = temp->next;
        cnt++;
    }
   
   // inserting at last position
    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
  // creating node for inserting at given position
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting node according to position
void deleteNode(Node* &head, int position) {
     // assuming the given position within the range
     
}

void PrintLL(Node* &head) {
     Node* temp = head;
     while (temp != NULL)
     {
       cout<<temp->data<< " ";
       temp = temp->next;
     }
     cout<<endl;
}

int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 9);
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(head, tail, 13, 4);
    insertAtPosition(head, tail, 14, 5);
    insertAtPosition(head, tail, 8, 1);
    PrintLL(head);

    return 0;
}