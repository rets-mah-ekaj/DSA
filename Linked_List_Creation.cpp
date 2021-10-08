#include<iostream> // contains standard input-output functions
#include<stdlib.h> // contains malloc(), free() and other Dynamic Memory Allocation functions
using namespace std;


struct node { // structure of node that contains data and address of next node
  int data; // data (type = integer)
  struct node *next; // pointer to address of next node of Linked List
};

typedef struct node Node; // typedef to use "Node" instead of "struct node"

Node *head = NULL; // creating a pointer to Node that shall always store address of 1st node of existing Linked List
// If there is no existing Linked List, head will store NULL instead of address


void createNode(); // prototype of a createNode() function that creates a Node


int main() { // main function
  int n; // 'n' will store the number of nodes given by user
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i) // loop from 0 to n - 1
    createNode(); // calling createNode()
  return 0;
}


void createNode() { // definition of createNode()
  Node *temp; // creating a pointer temp of type Node that will hold the address of node we create
  temp = (Node *)malloc(sizeof(Node)); // dynamically allocating memory for a node and storing the address of this node in temp
  // In case if memory is full, malloc() will return NULL which will be stored in temp

  if (temp == NULL) // if this is true, that means memory is full, hence exit the program
    exit(0);

  // get the data from the user and store it in 'temp -> data'
  cout << "Enter the data: ";
  cin >> temp -> data;
  temp -> next = NULL; // store NULL to indicate that it is last node of Linked List

  if (head == NULL) // if head is NULL, that means if there is no node in Linked List
    head = temp; // store the value present in temp into head (both are pointers that will hold address)
    // if head was NULL earlier, it will now point to 1st node of Linked List

  else { // coming into else means there are already some nodes in Linked List
    Node *p = head; // create a new pointer 'p' to Node and store head value (address of 1st node) in it
    // p is pointing to first node of Linked List now
    while (p -> next != NULL) // condition will check whether p is pointing to last node or not, if not, then loop will end
      // if above condition is true, that means p is not pointing to last node, hence, move forward
      p = p -> next; // storing the address of next node in p
    // now p is pointing to the last node of Linked List
    p -> next = temp; // now address of temp node will store in 'p -> next'
    p = NULL; // (optional) this will remove the address of node from our temporay pointer 'p'
  }
  temp = NULL; // (optional) this will remove the address of node from our temporay pointer 'temp'
  cout << "Node Created!\n";

  // both 'p' and 'temp' were pointers to help us out in the process and they will get destroyed after the scope of their blocks
  // automatically, respectively.

  // head pointer was global so it is still pointing the 1st node of Linked List, hence no need to return anything as well!
}
