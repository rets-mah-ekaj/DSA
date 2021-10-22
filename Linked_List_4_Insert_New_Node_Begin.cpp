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
void insertNodeBegin(); // prototype of insertNodeBegin() function that adds an element at the beginning of the Linked List

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
  if (more) { // to check whether user wants to insert more Nodes at beginning
    cout << "How many more Nodes you want to insert at the beginning: ";
    cin >> how_many_more;
  }
  for (int i = 0; i < how_many_more; ++i)
    insertNodeBegin(); // calling insertNodeBegin() function to insert more Nodes at the beginning of Linked List
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


void insertNodeBegin() { // definition of insertNodeBegin()
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
  temp -> next = NULL; // store NULL in 'temp -> next' as of now

  if (head == NULL) { // if head is NULL, that means if there is no Node in Linked List
    head = temp; // store the value present in temp into head (both are pointers that will hold address)
    cout << "Node added.\n";
  }
  // if head was NULL earlier, it will now point to 1st Node of Linked List

  else { // coming into else means there are already some Nodes in Linked List
    temp -> next = head; // store the address of 1st Node of Linked List to 'temp -> next'
    head = temp; // replace the old address of head with new address that is stored in temp
    // Now, new node is inserted at the beginning of Linked List and its address if held in head
    cout << "Node added.\n";
  }
  temp = NULL; // (optional) this will remove the address of Node from our temporay pointer 'temp'

  // 'temp' was a pointer to help us out in the process and it will get destroyed after the scope of their blocks
  // automatically.

  // head pointer was global so it is still pointing the 1st Node of Linked List, hence no need to return anything as well!
}
