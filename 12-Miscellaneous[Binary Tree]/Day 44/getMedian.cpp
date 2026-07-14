// T.C: O(n log n)
// S.C: O(n)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-median-in-a-stream?source=strivers-sde-sheet


class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> left; // max-heap
        priority_queue<int, vector<int>, greater<int>> right; // min-heap
        vector<double> medians;

        for (int num : arr) {
            // Step 1: Add to one heap
            if (left.empty() || num <= left.top())
                left.push(num);
            else
                right.push(num);

            // Step 2: Balance heaps
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            // Step 3: Compute median
            if (left.size() == right.size())
                medians.push_back((left.top() + right.top()) / 2.0);
            else
                medians.push_back(left.top());
        }
        return medians;
    }
};