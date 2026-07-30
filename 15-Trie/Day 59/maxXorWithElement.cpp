// T.C: O(32N + Q(logQ) + 32Q)
// S.C: O(32N + Q)
// Question Link: https://takeuforward.org/plus/dsa/problems/maximum-xor-with-an-element-from-an-array?source=strivers-sde-sheet


struct Node {
    Node *links[2];

  
    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }

  
    Node* get(int ind) {
        return links[ind];
    }

    void put(int ind, Node* node) {
        links[ind] = node;
    }
};

// Definition for Trie data
class Trie {
private:
    Node* root;

public:
    // Constructor 
    Trie() {
        root = new Node();
    }

    // Function to insert 
    void insert(int num) {
        // Start traversal
        Node* node = root;

       /* Traverse each bit of the number 
       from the most significant bit to the 
       least significant bit*/
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            /*If the current node doesn't have 
            a child node at the current bit, 
            create one*/
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

           /* Move to the child node
            corresponding to the 
            current bit*/
            node = node->get(bit);
        }
    }

    // Function to find maximum XOR
    int findMax(int num) {
        Node* node = root;

        int maxNum = 0;

        /*Traverse each bit of the number from 
        the most significant bit to the least 
        significant bit extract the i-th 
        bit of the number.
        If there exists a different bit 
        in the trie at the current 
        position, choose it to maximize XOR*/
        for (int i = 31; i >= 0; i--) {
            
            int bit = (num >> i) & 1;

            
            if (node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }

        // Return maximum XOR value
        return maxNum;
    }
};
class Solution {
public:
    // Function to handle the maximize XOR queries
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Initialize vector to store results of queries
        vector<int> ans(queries.size(), 0);

        // Vector to store offline queries
        vector<pair<int, pair<int, int>>> offlineQueries;

        // Sort the array of numbers
        sort(nums.begin(), nums.end());

        // Convert queries to offline queries and store them in a vector
        int index = 0;
        for (auto &it : queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort queries based on their end points
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        int n = nums.size();

        Trie trie;

        // Process each query
        for (auto &it : offlineQueries) {
            // Insert numbers 
            while (i < n && nums[i] <= it.first) {
                trie.insert(nums[i]);
                i++;
            }

            /*If there are numbers inserted into the trie, 
            find the maximum XOR value for the query range*/
            if (i != 0)
                ans[it.second.second] = trie.findMax(it.second.first);
            else
                ans[it.second.second] = -1;
        }

        // Return results
        return ans;
    }
};