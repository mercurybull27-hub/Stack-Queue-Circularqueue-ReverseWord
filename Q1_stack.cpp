#include <iostream>
using namespace std;

const int MAX = 5;
int stackData[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Stack is full.\n";
        return;
    }

    stackData[++top] = value;
    cout << value << " inserted successfully.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    cout << stackData[top--] << " removed successfully.\n";
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << stackData[top] << '\n';
}

void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackData[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
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
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
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