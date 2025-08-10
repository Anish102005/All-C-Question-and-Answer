#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverseList(first);
    second = reverseList(second);
    
    struct Node* result = NULL;
    struct Node* temp = NULL;
    struct Node* prev = NULL;
    int carry = 0, sum;
    
    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        
        temp = createNode(sum);
        
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        
        prev = temp;
        
        if (first) first = first->next;
        if (second) second = second->next;
    }
    
    if (carry > 0) {
        temp->next = createNode(carry);
    }
    
    result = reverseList(result);
    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtEnd(struct Node** head, int data) {
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

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* result = NULL;
    
    insertAtEnd(&first, 5);
    insertAtEnd(&first, 6);
    insertAtEnd(&first, 3);
    
    insertAtEnd(&second, 8);
    insertAtEnd(&second, 4);
    insertAtEnd(&second, 2);
    
    printf("First List: ");
    printList(first);
    printf("Second List: ");
    printList(second);
    
    result = addTwoLists(first, second);
    printf("Result List: ");
    printList(result);
    
    return 0;
}
