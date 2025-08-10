#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void detectAndRemoveLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            removeLoop(head, slow);
            return;
        }
    }
}

void removeLoop(struct Node* head, struct Node* loop_node) {
    struct Node *ptr1 = head;
    struct Node *ptr2;

    while (1) {
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }
        if (ptr2->next == ptr1) {
            break;
        }
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

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

void createLoop(struct Node* head, int k) {
    if (k == 0) return;
    
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;
    
    while (temp->next != NULL) {
        if (count == k) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    createLoop(head, 3);
    detectAndRemoveLoop(head);
    printList(head);

    return 0;
}
