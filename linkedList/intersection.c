#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find the intersection of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* intersectionHead = NULL;

    struct Node* temp1 = head1;
    while (temp1 != NULL) {
        struct Node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                insertEnd(&intersectionHead, temp1->data);
                break;  // Avoid duplicates in the intersection
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return intersectionHead;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);
    insertEnd(&list1, 4);
    insertEnd(&list1, 5);

    // Create second linked list: 3 -> 4 -> 5 -> 6 -> 7
    insertEnd(&list2, 3);
    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);
    insertEnd(&list2, 7);

    // Display the linked lists
    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Find and display the intersection
    struct Node* intersection = findIntersection(list1, list2);
    printf("Intersection: ");
    displayList(intersection);

    return 0;
}
