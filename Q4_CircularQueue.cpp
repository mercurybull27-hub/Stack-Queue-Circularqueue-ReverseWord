#include <iostream>
using namespace std;

const int MAX = 5;
int queueData[MAX];
int frontIndex = -1;
int rearIndex = -1;

bool isEmpty() {
    return frontIndex == -1;
}

bool isFull() {
    return (rearIndex + 1) % MAX == frontIndex;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue is full.\n";
        return;
    }

    if (isEmpty()) {
        frontIndex = 0;
    }

   
    rearIndex = (rearIndex + 1) % MAX;
    queueData[rearIndex] = value;

    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    cout << queueData[frontIndex] << " removed successfully.\n";

    if (frontIndex == rearIndex) {
        frontIndex = -1;
        rearIndex = -1;
    } else {
       
        frontIndex = (frontIndex + 1) % MAX;
    }
}

void front() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front element: " << queueData[frontIndex] << '\n';
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue: ";
    int i = frontIndex;

    while (true) {
        cout << queueData[i];

        if (i == rearIndex) {
            break;
        }

        cout << ' ';
        i = (i + 1) % MAX;
    }

    cout << '\n';
}

int main() {
    cout << "===== CIRCULAR QUEUE TEST =====\n";

   
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    
    dequeue();
    dequeue();

   
    enqueue(60);
    enqueue(70);

    display();

    return 0;
}