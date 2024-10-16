#include <stdio.h>
#define SIZE 5 // Max size of the queue

int queue[SIZE];  // Array to store queue elements
int front = -1;   // Points to the front of the queue
int rear = -1;    // Points to the rear of the queue

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow! Cannot add more elements.\n");
    } else {
        if (front == -1) { // If the queue is initially empty
            front = 0;
        }
        rear = (rear + 1) % SIZE;  // Move rear circularly
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! No elements to remove.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            // Queue is empty after the dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Move front circularly
        }
    }
}

// Function to view the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Main function with a menu-driven system
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2: // Dequeue
                dequeue();
                break;
            case 3: // Peek
                peek();
                break;
            case 4: // Check if Empty
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5: // Exit
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
