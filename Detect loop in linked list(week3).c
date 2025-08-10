#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }
    return 0;
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

    if (detectLoop(head)) {
        printf("Loop detected\n");
    } else {
        printf("No loop found\n");
    }

    return 0;
}
