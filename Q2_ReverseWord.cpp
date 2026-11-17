#include <iostream>
using namespace std;

const int MAX = 100;
char stackData[MAX];
int top = -1;

bool push(char letter) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!\n";
        return false;
    }

    stackData[++top] = letter;
    return true;
}

bool pop(char &letter) {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return false;
    }

    letter = stackData[top--];
    return true;
}

int main() {
    char word[MAX + 1];
    char letter;

    cout << "Enter a word: ";
    cin.getline(word, MAX + 1);

    if (cin.fail()) {
        cout << "Input error! Maximum length is 100 characters.\n";
        return 0;
    }

    if (word[0] == '\0') {
        cout << "Input cannot be empty.\n";
        return 0;
    }

   
    for (int i = 0; word[i] != '\0'; i++) {
        if (!push(word[i])) {
            return 0;
        }
    }

    cout << "\nOriginal word: " << word << '\n';
    cout << "Reversed word: ";

    
    while (top != -1) {
        if (pop(letter)) {
            cout << letter;
        }
    }

    cout << '\n';
    return 0;
}