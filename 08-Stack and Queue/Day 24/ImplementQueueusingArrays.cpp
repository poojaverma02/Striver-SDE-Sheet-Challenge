// T.C: O(1) for push, pop and top operations.
// S.C: O(n) where n = maxSize (hardcoded to 10 here).
// Question Link: https://takeuforward.org/plus/dsa/problems/implement-queue-using-arrays?source=strivers-sde-sheet

class ArrayQueue {
    int* arr;           // Dynamically allocated circular array to store queue elements
    int start, end;     // Indices tracking the front and rear of the queue
    int currSize;       // Current number of elements in the queue
    int maxSize;        // Maximum capacity of the queue

public:
    // Constructor: initializes a circular queue with a fixed capacity of 10
    ArrayQueue() {
        arr = new int[10];
        start = -1;     // -1 indicates the queue is empty
        end = -1;
        currSize = 0;
        maxSize = 10;
    }

    // Push: adds an element to the rear of the queue
    void push(int x) {
        if (currSize == maxSize) {          // Guard against overflow
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }

        if (end == -1) {                    // First element being inserted
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % maxSize;      // Wrap around using modulo (circular behavior)
        }

        arr[end] = x;
        currSize++;
    }

    // Pop: removes and returns the front element of the queue (FIFO order)
    int pop() {
        if (start == -1) {                  // Guard against underflow
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];

        if (currSize == 1) {                // Last element being removed; reset the queue
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % maxSize;  // Wrap around using modulo (circular behavior)
        }

        currSize--;
        return popped;
    }

    // Peek: returns the front element without removing it
    int peek() {
        if (start == -1) {                  // Guard against empty queue
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    // isEmpty: returns true if the queue has no elements
    bool isEmpty() {
        return (currSize == 0);
    }
};
