#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Add two lists
struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;

    while (l1 != NULL && l2 != NULL) {
        int sum = l1->data + l2->data;

        struct Node* newNode = createNode(sum);

        if (result == NULL) {
            result = newNode;
            temp = result;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    return result;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create lists
    insert(&list1, 2);
    insert(&list1, 4);
    insert(&list1, 3);

    insert(&list2, 5);
    insert(&list2, 6);
    insert(&list2, 4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* result = addLists(list1, list2);

    printf("Result: ");
    printList(result);

    return 0;
}