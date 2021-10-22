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
void insertNodeEnd(Node *); // prototype of insertNodeEnd() function that adds an element at the end of the Linked List

int main() {
  int n, more = 0, how_many_more = 0;
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i)
    createNode();
  if (n) // check whether user inserted 0 or non-0 number of Nodes
    cout << "Linked List created.\n";
  else
    cout << "Linked List not create, 0 Nodes\n";

  cout << "Want to add more Nodes (0 for NO / 1 for YES): ";
  cin >> more;
  if (more) { // to check whether user wants to insert more Nodes at end
    cout << "How many more Nodes you want to insert at the end: ";
    cin >> how_many_more;
  }
  for (int i = 0; i < how_many_more; ++i)
    insertNodeEnd(head); // calling insertNodeEnd() function to insert more Nodes at the end of Linked List
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


void insertNodeEnd(Node *head) { // definition of insertNodeEnd()
  Node *temp; // creating a pointer temp of type Node that will hold the address of Node we create
  temp = (Node *)malloc(sizeof(Node)); // dynamically allocating memory for a Node and storing the address of this Node in temp
  // In case if memory is full, malloc() will return NULL which will be stored in temp

  if (temp == NULL) { // if this is true, that means memory is full, hence exit the program
    cout << "Error: Memory Full!\n"; // Display error message on screen
    exit(0);
  }

  // get the data from the user and store it in 'temp -> data'
  cout << "Enter the data: ";
  cin >> temp -> data;
  temp -> next = NULL; // store NULL to indicate that it is last Node of Linked List

  if (head == NULL) { // if head is NULL, that means if there is no Node in Linked List
    head = temp; // store the value present in temp into head (both are pointers that will hold address)
    cout << "Node added.\n";
  }
  // if head was NULL earlier, it will now point to 1st Node of Linked List

  else { // coming into else means there are already some Nodes in Linked List
    Node *p = head; // create a new pointer 'p' to Node and store head value (address of 1st Node) in it
    // p is pointing to 1st Node of Linked List now
    while (p -> next != NULL) // condition will check whether p is pointing to last Node or not, if not, then loop will end
      // if above condition is true, that means p is not pointing to last Node, hence, move forward
      p = p -> next; // storing the address of next Node in p
    // now p is pointing to the last Node of Linked List
    p -> next = temp; // now address of temp Node will store in 'p -> next'
    cout << "Node added.\n";
    p = NULL; // (optional) this will remove the address of Node from our temporay pointer 'p'
  }
  temp = NULL; // (optional) this will remove the address of Node from our temporay pointer 'temp'

  // both 'p' and 'temp' were pointers to help us out in the process and they will get destroyed after the scope of their blocks
  // automatically, respectively.

  // head pointer was global so it is still pointing the 1st Node of Linked List, hence no need to return anything as well!
}
