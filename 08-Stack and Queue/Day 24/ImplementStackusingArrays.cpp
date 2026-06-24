// T.C: O(1) for push, pop and top operations.
// S.C: O(N) for using a stack which is equivalent to the size of the array.
// Question Link: https://takeuforward.org/plus/dsa/problems/implement-stack-using-arrays?source=strivers-sde-sheet

class ArrayStack {
private:
    int* stackArray;  // Dynamically allocated array to store stack elements
    int capacity;     // Maximum number of elements the stack can hold
    int topIndex;     // Index of the current top element (-1 means empty)

public:
    // Constructor: initializes the stack with a given size (default 1000)
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;  // Empty stack starts with topIndex at -1
    }

    // Destructor: frees the dynamically allocated array to prevent memory leaks
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Push: adds an element to the top of the stack
    void push(int x) {
        if (topIndex >= capacity - 1) {  // Check for overflow before inserting
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;  // Increment topIndex first, then insert
    }

    // Pop: removes and returns the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Sentinel value indicating failure
        }
        return stackArray[topIndex--];  // Return top element, then decrement topIndex
    }

    // Top: returns the top element without removing it (peek)
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Sentinel value indicating failure
        }
        return stackArray[topIndex];
    }

    // isEmpty: returns true if the stack has no elements
    bool isEmpty() {
        return topIndex == -1;
    }
};
