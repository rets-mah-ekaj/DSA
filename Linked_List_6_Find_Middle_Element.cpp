#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;
Node *head = NULL;

void createNode(); // for the explanation of this function, refer to "Linked_List_Creation.cpp" file
Node * findMiddle(Node *); // prototype for the findMiddle() function to find the 1st middle element in Linked List

int main() {
  int n;
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i)
    createNode();
  cout << "Middle element is: ";
  cout << findMiddle(head) -> data << '\n';
  /*
  calling findMiddle() and passing head pointer to it this function will return the address of the Node which is the
  1st middle of Linked List and from that Node we are pulling data segment of the Node
  */
  return 0;
}

void createNode() {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL)
    exit(0);
  cout << "Enter the data: ";
  cin >> temp -> data;
  temp -> next = NULL;

  if (head == NULL)
    head = temp;
  else {
    Node *p = head;
    while (p -> next != NULL)
      p = p -> next;
    p -> next = temp;
    p = NULL;
  }
  temp = NULL;
  cout << "Node Created!\n";
}

Node * findMiddle(Node *head) { // definition of findMiddle() function
  Node *slow = head; // slow pointer that will move forward by 1 Node
  Node *fast = head; // fast pointer that will move forward by 2 Node
  while (fast != NULL && fast -> next != NULL && fast -> next -> next != NULL) {
    // 'fast != NULL' is to check whether our current Node address if not NULL, if it is, exit the loop
    // 'fast -> next != NULL' is to check whether next segment of current Node is NULL or not, if it is, exit the loop
    // 'fast -> next -> next != NULL' is to check whether the next segment of next Node is NULL or not, if it is, exit the loop
    slow = slow -> next; // move the slow pointer to point the next Node
    fast = fast -> next -> next; // move the fast pointer to point the second Node from current Node
  }
  // when we are out of the loop that means the slow pointer is pointing to 1st middle Node
  return slow; // return the address slow pointer is holding
}
