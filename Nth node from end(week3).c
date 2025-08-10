#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void findNthFromEnd(struct Node* head, int n) {
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;

    while (count < n) {
        if (ref_ptr == NULL) {
            printf("%d exceeds list length\n", n);
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    printf("Node %d from end: %d\n", n, main_ptr->data);
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printList(head);

    findNthFromEnd(head, 2);
    findNthFromEnd(head, 4);
    findNthFromEnd(head, 6);

    return 0;
}
