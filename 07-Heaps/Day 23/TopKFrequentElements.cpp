// T.C: O(n log k), each heap operation takes log k.
// S.C: O(n + k), frequency map + heap.
// Question Link: https://takeuforward.org/plus/dsa/problems/top-k-frequent-elements?source=strivers-sde-sheet


class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {

        // Step 1: Count frequency of each number
        // freq[num] = how many times 'num' appears in nums
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        // Step 2: Min-heap of size k
        // stores pairs of {frequency, number}
        // 'greater<>' makes it a MIN-heap (smallest freq at top)
        // so we can easily evict the least frequent element
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        for (auto& it : freq) {
            // Push {frequency, number} into the heap
            minHeap.push({it.second, it.first});

            // If heap exceeds size k, remove the element
            // with the SMALLEST frequency (the heap top)
            // This keeps only the k most frequent elements alive
            if (minHeap.size() > k)
                minHeap.pop();
        }

        // Step 3: Collect results
        // Whatever remains in the heap = top k frequent elements
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // grab the number (not freq)
            minHeap.pop();
        }

        return result;
    }
};