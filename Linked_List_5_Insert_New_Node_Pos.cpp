#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;
Node *head = NULL;

void createNode(); // for the explanation of this function, refer to "Linked_List_1_Creation.cpp" file
int lengthCount(Node *); // for the explanation of this function, refer to "Linked_List_2_Length.cpp" file
void insertAtBegin(Node *); // for the explanation of this function, refer to "Linked_List_3_Insert_New_Node_Begin.cpp" file
void insertAtEnd(Node *); // for the explanation of this function, refer to "Linked_List_4_Insert_New_Node_End.cpp" file
void insertNodePos(Node *, int); // prototype of insertNodePos() function that adds an element at given position in the Linked List

int main() {
  int n, more = 0, how_many_more = 0, pos;
  cout << "Enter the number of nodes you want: ";
  cin >> n;
  for (int i = 0; i < n; ++i)
    createNode();
  if (n)
    cout << "Linked List created.\n";
  else
    cout << "Linked List not created, 0 Nodes\n";

  cout << "Want to add more Nodes (0 for NO / 1 for YES): ";
  cin >> more;
  if (more) { // to check whether user wants to insert more Nodes at beginning
    cout << "How many more Nodes you want to insert at the beginning: ";
    cin >> how_many_more;
  }
  for (int i = 0; i < how_many_more; ++i) {
    cout << "Enter position at which you want the node to be inserted: ";
    cin >> pos;
    insertNodePos(head, pos);
  }
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

void insertNodeBegin(Node *head) {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    cout << "Error: Memory Full!\n";
    exit(0);
  }
  cout << "Enter the data: ";
  cin >> temp -> data;
  temp -> next = NULL;
  if (head == NULL) {
    head = temp;
    cout << "Node added.\n";
  }
  else {
    temp -> next = head;
    head = temp;
    cout << "Node added.\n";
  }
  temp = NULL;
}

void insertNodeEnd(Node *head) {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    cout << "Error: Memory Full!\n";
    exit(0);
  }
  cout << "Enter the data: ";
  cin >> temp -> data;
  temp -> next = NULL;
  if (head == NULL) {
    head = temp;
    cout << "Node added.\n";
  }
  else {
    Node *p = head;
    while (p -> next != NULL)
      p = p -> next;
    p -> next = temp;
    cout << "Node added.\n";
    p = NULL;
  }
  temp = NULL;
}

void insertNodePos(Node *head, int pos) { // definition of insertNodePos
  int length = lengthCount(head); // calling lengthCount() to find the length of Linked List and store it in length variable
  if (pos <= 0 || pos > length + 1) // this conditions check whether the position given by user is valid or not
    cout << "Invalid position!\n";
  else if (pos == 1) // if position given by user is 1
    insertAtBegin(head); // call insertAtBegin() function to add a Node at the beginning of the Linked List
  else if (pos == length + 1) // if position given by user is next of the last Node of Linked List
    insertAtEnd(head); // call insertAtEnd() function to add a Node at the end of the Linked List

  else {
    int k = 0; // a variable 'k' to store the current position of pointer.
    Node *temp; // a pointer 'temp' that will store the address of the new Node we create
    Node *p = head; // pointer 'p' will store address stored in head and will help in traversing to desired position in Linked List
    temp = (Node *)malloc(sizeof(Node)); // dynamically allocating memory for a Node and storing the address of this Node in temp
    // In case if memory is full, malloc() will return NULL which will be stored in temp

    if (temp == NULL) { // if this is true, that means memory is full, hence exit the program
      cout << "Error: Memory Full!\n"; // Display error message on screen
      exit(0);
    }

    // get the data from the user and store it in 'temp -> data'
    cout << "Enter the data: ";
    cin >> temp -> data;

    while (k < pos - 1) { // traversing through the Linked List till we reach Node at position 'pos - 1'
      p = p -> next; // storing address of next Node in p
      ++k; // incrementing the current position by 1
    }
    // After this while loop, we reach at Node which is just before the desired position in Linked List

    temp -> next = p -> next; // storing address of next Node of Linked List in next segment of 'temp'
    p -> next = temp; // now store the address of 'temp' Node in next segment of 'p'
    p = NULL; // (optional) this will remove the address of Node from our temporay pointer 'p'
    temp = NULL; // (optional) this will remove the address of Node from our temporay pointer 'temp'
  }
  
  // both 'p' and 'temp' were pointers to help us out in the process and they will get destroyed after the scope of their blocks
  // automatically, respectively.

  // head pointer was global so it is still pointing the 1st Node of Linked List, hence no need to return anything as well!
}
