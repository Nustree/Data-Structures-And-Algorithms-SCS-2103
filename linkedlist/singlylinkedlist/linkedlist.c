// This is the C implementation of a singly linked list with nodes of integer values.
#include <stdio.h>
#include <stdlib.h>

// We declare as typedef struct so that we use the struct as if it is a primitive type.
typedef struct node {
    int value;
    struct node* next; // Pointer to the next node in the linked list.
} node;

// Prototype function so that we may use functions declared after the main function.
void initialize_list();
void print_list();
void insert_at_beginning(int value);
void insert_at_index(int value, int pos);


// Declare the head pointer as a global variable so that every function can access it.
node *head;

int main() {
    // Set the linked list to be empty initially by the head pointing to nothing.
    head = NULL;

    // Initialize the linked list and populate with nodes.
    initialize_list();

    print_list();

    return 0;
}


// Inserts all the dummy nodes into the linked list.
void initialize_list() {
    // Insert 10 nodes into the linked list.
    for (int i = 0; i < 10; i++)
        insert_at_beginning((i + 1) * 15);
}

// Print all the nodes in a linked list
void print_list() {

    int i = 0;

    printf("\nData in the linked list:\n");

    // 'temp' is initialized with pointer to the head,
    // 'temp' will traverse through the linked list as long as it's not pointing to NULL.
    // And when it is done with printing the node, 'temp' will pointer to the next node in the linked list.
    for (node *temp = head; temp != NULL; temp = temp->next) {
        printf("Node #%d: %d\n", i, temp->value);
        i++;
    }
}


// Insert a node at the beginning of the linked list.
void insert_at_beginning(int value) {

    // We want a pointer to memory allocation big enough to fit a node.
    // In simpler terms, we are asking the system for space beig enough for one node.
    node *new_node = (node*) malloc(sizeof(node));

    // Insert the value.
    new_node->value = value;

    // The next node of the new node should be the head.
    new_node->next = head;

    // The head should point to the new node.
    head = new_node;
}