#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node *prev, *next;
};

// Front and rear pointers
struct Node *front = NULL, *rear = NULL;

// Insert at front
void insertFront(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL)
        rear = newNode;
    else
        front->prev = newNode;

    front = newNode;
    printf("%d inserted at front\n", x);
}

// Insert at rear
void insertRear(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;

    rear = newNode;
    printf("%d inserted at rear\n", x);
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("%d deleted from front\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node *temp = rear;
    printf("%d deleted from rear\n", rear->data);
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

// Display deque
void display() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteRear();
    display();

    deleteFront();
    display();

    return 0;
}
