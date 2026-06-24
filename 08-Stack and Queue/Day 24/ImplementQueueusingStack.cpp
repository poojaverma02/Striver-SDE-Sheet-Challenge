// T.C: O(1) The average time complexity for each operation is O(1)
// S.C: O(2N) because, in the worst case, both the input and output stacks can each hold up to N elements
// Question Link: https://takeuforward.org/plus/dsa/problems/implement-queue-using-stack?source=strivers-sde-sheet

// Queue implemented using two stacks
// Key idea: 'input' accepts new elements (push end),
// 'output' serves old elements (pop end).
// Elements are lazily transferred from input → output only when output runs dry,
// which reverses their order and restores FIFO behavior.
class StackQueue {
public:
    stack<int> input;   // Holds newly pushed elements (most recent on top)
    stack<int> output;  // Holds elements ready to be dequeued (oldest on top)

    StackQueue() {}

    // Push: always goes onto the input stack — O(1)
    void push(int x) {
        input.push(x);
    }

    // Pop: removes and returns the oldest element (front of the queue)
    int pop() {
        // Lazy transfer: pour input into output only when output is empty.
        // Reversing the order makes the oldest element land on top of output.
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());   // Move top of input to output
                input.pop();
            }
        }

        // Both stacks empty means the queue itself is empty
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();   // Oldest element is now on top of output
        output.pop();
        return x;
    }

    // Peek: returns the oldest element without removing it
    int peek() {
        // Same lazy transfer as pop — ensure output has elements
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());   // Move top of input to output
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();    // Oldest element sits on top of output
    }

    // isEmpty: queue is empty only when both stacks hold no elements
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

