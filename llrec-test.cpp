#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
struct IsOdd{
    bool operator()(int value) const{
        return (value %2) != 0;
    }
};
// Functor that filters nothing (keeps all nodes).
struct FilterNothing {
    bool operator()(int value) const {
        return false;
    }
};

// Functor that filters everything (removes all nodes).
struct FilterEverything {
    bool operator()(int value) const {
        return true;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Testing llpivot:
    // -----------------------------------------------
    Node* headPivot = readList(argv[1]);
    cout << "=== Testing llpivot ===" << endl;
    cout << "Original list: ";
    print(headPivot);

    Node* smaller = NULL;
    Node* larger = NULL;
    int pivot = 5; // You can change the pivot value as needed
    llpivot(headPivot, smaller, larger, pivot);
    
    cout << "After calling llpivot with pivot = " << pivot << ":" << endl;
    cout << "smaller list (<= " << pivot << "): ";
    print(smaller);
    cout << "larger list (> " << pivot << "): ";
    print(larger);
    if (headPivot == NULL)
        cout << "Original list is now empty as expected." << endl;

    // Clean up pivot test lists.
    dealloc(smaller);
    dealloc(larger);

    // -----------------------------------------------
    // Testing llfilter:
    // -----------------------------------------------
    // Read a new list for filtering.
    Node* headFilter = readList(argv[1]);
    cout << "\n=== Testing llfilter (filter out odd numbers) ===" << endl;
    cout << "Original list: ";
    print(headFilter);
    
    // Filter out nodes with odd values.
    IsOdd isOdd;
    Node* filteredList = llfilter(headFilter, isOdd);
    cout << "Filtered list (only even numbers remain): ";
    print(filteredList);
    dealloc(filteredList);

    // Additional tests for llfilter:
    // 1. A predicate that filters nothing (should return the same list)
    Node* headFilter2 = readList(argv[1]);
    cout << "\n=== Testing llfilter with predicate that filters nothing ===" << endl;
    FilterNothing filterNothing;
    Node* filteredList2 = llfilter(headFilter2, filterNothing);
    cout << "Filtered list (should be the same as original): ";
    print(filteredList2);
    dealloc(filteredList2);

    // 2. A predicate that filters everything (should return an empty list)
    Node* headFilter3 = readList(argv[1]);
    cout << "\n=== Testing llfilter with predicate that filters everything ===" << endl;
    FilterEverything filterEverything;
    Node* filteredList3 = llfilter(headFilter3, filterEverything);
    cout << "Filtered list (should be empty): ";
    print(filteredList3);
    // No need to deallocate filteredList3 because it is NULL.

    return 0;



    
    return 0;

}
