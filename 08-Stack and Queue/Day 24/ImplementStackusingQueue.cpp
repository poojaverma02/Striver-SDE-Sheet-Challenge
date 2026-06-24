// T.C: 
// Push operation: O(n) 
// Pop operation: O(1) 
// Top operation: O(1) 
// IsEmpty operation: O(1) 

// S.C: O(n) — only the queue itself, holding at most n elements. No auxiliary structure used.
// Question Link: https://takeuforward.org/plus/dsa/problems/implement-stack-using-queue?source=strivers-sde-sheet

// Stack implemented using a single queue
// Key idea: on every push, rotate all pre-existing elements to the back,
// so the newest element always sits at the front (LIFO order maintained)
class QueueStack {
    queue<int> q;   // Underlying queue; front always holds the stack's top

public:
    QueueStack() {}

    // Push: inserts x and rotates all older elements behind it
    // After push, x is at the front — making it the new top of the stack
    void push(int x) {
        int s = q.size();       // Number of elements before inserting x
        q.push(x);              // x goes to the back initially

        // Rotate the s old elements to the back, so x ends up at the front
        for (int i = 0; i < s; i++) {
            q.push(q.front());  // Move front element to the back
            q.pop();            // Remove it from the front
        }
    }

    // Pop: removes and returns the top of the stack (always at the front)
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    // Top: peeks at the stack's top without removing it (front of the queue)
    int top() {
        return q.front();
    }

    // isEmpty: returns true if the stack has no elements
    bool isEmpty() {
        return q.empty();
    }
};