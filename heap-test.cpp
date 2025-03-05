#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <string>
#include "heap.h"

using namespace std;

void testMinHeapIntBinary() {
    cout << "Test 1: Binary Min-Heap with ints (default comparator)" << endl;
    Heap<int> h(2);
    if (!h.empty())
        cout << "Error: Heap should be empty initially." << endl;
    h.push(10);
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(15);
    h.push(1);
    cout << "Size after pushes: " << h.size() << endl;
    vector<int> expected = {1, 3, 5, 7, 10, 15};
    bool success = true;
    for (int val : expected) {
        int topVal = h.top();
        if (topVal != val) {
            cout << "Error: Expected top " << val << ", got " << topVal << endl;
            success = false;
        }
        h.pop();
    }
    if (success && h.empty())
        cout << "Test 1 passed." << endl;
    else
        cout << "Test 1 failed." << endl;
}

void testMaxHeapIntBinary() {
    cout << "\nTest 2: Binary Max-Heap with ints using std::greater" << endl;
    Heap<int, std::greater<int>> h(2, std::greater<int>());
    if (!h.empty())
        cout << "Error: Heap should be empty initially." << endl;
    h.push(10);
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(15);
    h.push(1);
    cout << "Size after pushes: " << h.size() << endl;
    vector<int> expected = {15, 10, 7, 5, 3, 1};
    bool success = true;
    for (int val : expected) {
        int topVal = h.top();
        if (topVal != val) {
            cout << "Error: Expected top " << val << ", got " << topVal << endl;
            success = false;
        }
        h.pop();
    }
    if (success && h.empty())
        cout << "Test 2 passed." << endl;
    else
        cout << "Test 2 failed." << endl;
}

void testTernaryMinHeapInt() {
    cout << "\nTest 3: Ternary Min-Heap with ints" << endl;
    Heap<int> h(3);
    h.push(20);
    h.push(10);
    h.push(30);
    h.push(5);
    h.push(15);
    h.push(25);
    h.push(2);
    vector<int> expected = {2, 5, 10, 15, 20, 25, 30};
    bool success = true;
    for (int val : expected) {
        int topVal = h.top();
        if (topVal != val) {
            cout << "Error: Expected top " << val << ", got " << topVal << endl;
            success = false;
        }
        h.pop();
    }
    if (success && h.empty())
        cout << "Test 3 passed." << endl;
    else
        cout << "Test 3 failed." << endl;
}

void testExceptions() {
    cout << "\nTest 4: Exception handling on empty heap" << endl;
    Heap<int> h(2);
    bool topExceptionCaught = false;
    try {
        h.top();
    } catch (const std::underflow_error &e) {
        topExceptionCaught = true;
        cout << "Caught exception on top(): " << e.what() << endl;
    }
    bool popExceptionCaught = false;
    try {
        h.pop();
    } catch (const std::underflow_error &e) {
        popExceptionCaught = true;
        cout << "Caught exception on pop(): " << e.what() << endl;
    }
    if (topExceptionCaught && popExceptionCaught)
        cout << "Test 4 passed." << endl;
    else
        cout << "Test 4 failed." << endl;
}

void testStringMinHeap() {
    cout << "\nTest 5: Binary Min-Heap with strings" << endl;
    Heap<string> h(2);
    h.push("delta");
    h.push("alpha");
    h.push("charlie");
    h.push("bravo");
    vector<string> expected = {"alpha", "bravo", "charlie", "delta"};
    bool success = true;
    for (const string &s : expected) {
        string topVal = h.top();
        if (topVal != s) {
            cout << "Error: Expected top \"" << s << "\", got \"" << topVal << "\"" << endl;
            success = false;
        }
        h.pop();
    }
    if (success && h.empty())
        cout << "Test 5 passed." << endl;
    else
        cout << "Test 5 failed." << endl;
}

int main() {
    testMinHeapIntBinary();
    testMaxHeapIntBinary();
    testTernaryMinHeapInt();
    testExceptions();
    testStringMinHeap();
    return 0;
}
