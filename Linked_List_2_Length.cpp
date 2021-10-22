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
int lengthCount(Node *); // prototype of lengthCount() function that counts the number of Nodes

int main() {
  int n;
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i)
    createNode();
  cout << "Number of nodes: " << lengthCount(head) << '\n'; // calling lengthCount()
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


int lengthCount(Node *head) { // definition of lengthCount()
  int count = 0; // declaring a count variable and initializing it with 0
  if (head != NULL) { // if head is not containing NULL, that means, Linked List already has some Nodes
    Node *p = head; // create a new pointer 'p' to Node and store head value (address of 1st Node) in it
    // p is pointing to the 1st Node now
    ++count; // p is pointing to 1st Node, hence, Linked List at least has length of 1, so increment the value of count by 1
    while (p -> next != NULL) { // condition will check whether p is pointing to the last Node or not, if not, then loop breaks
      // we are inside the loop that means the pointer 'p' is not pointing to the last Node
      ++count; // since 'p' is not at last Node, increment the value of count by 1
      p = p -> next; // after this, 'p' will point to the next Node of the Linked List
    }
  }
  return count; // return value of count which will be length of Linked List
}
