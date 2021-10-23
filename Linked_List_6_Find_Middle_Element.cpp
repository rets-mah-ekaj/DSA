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
Node * findMiddleListLength(Node *); // prototype for finding the 1st middle element in the Linked List using listLength function

int main() {
  int n;
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i)
    createNode();
  cout << "Middle element is without using length function: " << findMiddle(head) -> data << '\n';
  cout << "Middle element is without using length function: " << findMiddleListLength(head) -> data << '\n';
  /*
  calling findMiddle() and findMiddleListLength() and passing head pointer to it these function will return the address of the
  Node which is the 1st middle and 2nd middle of Linked List, repectively and from that Node we are pulling data segment
  of the Node.
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

int lengthCount(Node *head) {
  int count = 0;
  if (head != NULL) {
    Node *p = head;
    ++count;
    while (p -> next != NULL) {
      ++count;
      p = p -> next;
    }
  }
  return count;
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

Node * findMiddleListLength(Node *head) { // definition of findMiddleListLength() function
  int length = lengthCount(head); // we call lengthCount() function and pass the head pointer to it get length of Linked List
  int k = 0, mid = length / 2; // 'k' will be current position and 'mid' will be the 2nd middle position of Linked List
  Node *p = head; // 'p' is a pointer of type Node that will hold the address stored in head
  while (k < mid) { // now, we will loop till we reach middle Node
    p = p -> next; // move pointer 'p' one Node ahead
    ++k; // increment the current postion by 1
  }
  return p; // return the 2nd middle Node address
}
