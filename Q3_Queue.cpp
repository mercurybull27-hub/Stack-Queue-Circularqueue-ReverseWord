#include <iostream>
using namespace std;

const int MAX = 5;
int queueData[MAX];
int frontIndex = -1;
int rearIndex = -1;

void enqueue(int value) {
    if (rearIndex == MAX - 1) {
        cout << "Queue Overflow! Rear has reached the last index.\n";
        return;
    }

    if (frontIndex == -1) {
        frontIndex = 0;
    }

    queueData[++rearIndex] = value;
    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (frontIndex == -1) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    cout << queueData[frontIndex] << " removed successfully.\n";

    if (frontIndex == rearIndex) {
       
        frontIndex = -1;
        rearIndex = -1;
    } else {
        frontIndex++;
    }
}

void front() {
    if (frontIndex == -1) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front element: " << queueData[frontIndex] << '\n';
}

void display() {
    if (frontIndex == -1) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue: ";
    for (int i = frontIndex; i <= rearIndex; i++) {
        cout << queueData[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Choose operation: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            return 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (!(cin >> value)) {
                    cout << "Invalid integer.\n";
                    return 0;
                }
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                front();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program finished.\n";
                break;

            default:
                cout << "Invalid choice. Choose 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}