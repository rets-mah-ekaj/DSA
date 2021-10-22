#include<iostream> // contains standard input-output functions
#include<stdlib.h> // contains malloc(), free() and other Dynamic Memory Allocation functions
using namespace std;


struct node { // structure of node that contains data and address of next node
  int data; // data (type = integer)
  struct node *next; // pointer to address of next node of Linked List
};

typedef struct node Node; // typedef to use "Node" instead of "struct node"

Node *head = NULL; // creating a pointer to Node that shall always store address of 1st Node of existing Linked List
// If there is no existing Linked List, head will store NULL instead of address


void createNode(); // prototype of a createNode() function that creates a Node


int main() { // main function
  int n; // 'n' will store the number of Nodes given by user
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i) // loop from 0 to n - 1
    createNode(); // calling createNode()
  return 0;
}


void createNode() { // definition of createNode()
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
    p = NULL; // (optional) this will remove the address of Node from our temporay pointer 'p'
  }
  temp = NULL; // (optional) this will remove the address of Node from our temporay pointer 'temp'
  cout << "Node Created!\n";

  // both 'p' and 'temp' were pointers to help us out in the process and they will get destroyed after the scope of their blocks
  // automatically, respectively.

  // head pointer was global so it is still pointing the 1st Node of Linked List, hence no need to return anything as well!
}
