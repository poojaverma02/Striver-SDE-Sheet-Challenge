// T.C: 
// addNum: O(log n)
// findMedian: O(1)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-median-from-data-stream?source=strivers-sde-sheet

class MedianFinder {
    priority_queue<int> maxH;                        // left half  (max-heap)
    priority_queue<int, vector<int>, greater<int>> minH; // right half (min-heap)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: always push to left first
        maxH.push(num);

        // Step 2: ensure left.top <= right.top (cross-heap ordering)
        if (!minH.empty() && maxH.top() > minH.top()) {
            minH.push(maxH.top());
            maxH.pop();
        }

        // Step 3: rebalance sizes (left can exceed right by at most 1)
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } else if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    double findMedian() {
        if (maxH.size() > minH.size())
            return maxH.top();            // odd count → left top is median
        return (maxH.top() + minH.top()) / 2.0;  // even → average of both tops
    }
};