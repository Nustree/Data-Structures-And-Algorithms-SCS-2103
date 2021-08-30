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
void delete(int pos);
int size_of_list();
void free_list();


// Declare the head pointer as a global variable so that every function can access it.
node *head;

int main() {
    // Set the linked list to be empty initially by the head pointing to nothing.
    head = NULL;

    // Initialize the linked list and populate with nodes.
    initialize_list();

    // Insert the value at the head of the list.
    insert_at_index(25, 5);

    // Print the entire list.
    print_list();

    // Delete the value we just inserted.
    delete(5);

    print_list();
    
    // This just frees all the memory allocations for the nodes we created when are we done with the program.
    free_list();
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

    int i = 1;

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

// Inserts a node at a specific position 'pos' in the linked list.
void insert_at_index(int value, int pos) {
    if (pos <= size_of_list()) {

        node *temp = head;

        // Create the node with its value.
        node *new_node = (node*) malloc(sizeof(node));
        new_node->value = value;

        // Traverse to the node before the position we want to insert the node.
        for (int i = 0; i < (pos - 2); i++) temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Delete a node from the linked list at a specific index 'pos'.
void delete(int pos) {
    if (pos < size_of_list()) {

        node *temp = head;

        // If the node to be removed is at the head of the linked list.
        if (pos == 0) {
            head = temp->next;

            // Release the memory allocated for the node.
            free(temp);

            return;
        } else {
            // Traverse the node before the one you want to delete.
            for (int i = 0; i < (pos - 2); i++) temp = temp->next;

            // Get the node that you want to remove.
            node *removed_node = temp->next;

            // Switch the next node of temp to the next node of removed_node.
            // This is done to unlink removed_node from the linked list.
            temp->next = removed_node->next;

            free(removed_node);
        }
    }
}


// Get the number of nodes in the linked list.
int size_of_list() {
    int size = 0;
    for (node *temp = head; temp != NULL; temp = temp->next) size++;
    return size;
}

// This function frees all the nodes memory allocations.
// More like a delete-all function.
void free_list() {
    node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}