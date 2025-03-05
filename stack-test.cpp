#include <iostream>
#include <stdexcept>
#include "stack.h"

using namespace std;

int main() {
    // Create an instance of Stack<int>
    Stack<int> s;

    // Test empty() and size() on a new stack.
    cout << "Initial state:" << endl;
    cout << "  Stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "  Stack size: " << s.size() << endl;

    // Push some elements onto the stack.
    cout << "\nPushing elements 10, 20, 30..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    // Test state after pushes.
    cout << "After pushing:" << endl;
    cout << "  Stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "  Stack size: " << s.size() << endl;
    cout << "  Top element: " << s.top() << endl;

    // Pop one element.
    cout << "\nPopping top element..." << endl;
    s.pop();
    cout << "After one pop:" << endl;
    cout << "  Top element: " << s.top() << endl;
    cout << "  Stack size: " << s.size() << endl;

    // Pop remaining elements.
    s.pop();
    s.pop();
    cout << "\nAfter popping all elements:" << endl;
    cout << "  Stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // Test pop() on an empty stack.
    cout << "\nAttempting to pop from an empty stack:" << endl;
    try {
        s.pop();
    } catch (const std::underflow_error& e) {
        cout << "  Caught exception: " << e.what() << endl;
    }

    // Test top() on an empty stack.
    cout << "\nAttempting to access top element on an empty stack:" << endl;
    try {
        int topVal = s.top();
        (void) topVal; // Suppress unused variable warning.
    } catch (const std::underflow_error& e) {
        cout << "  Caught exception: " << e.what() << endl;
    }

    return 0;
}