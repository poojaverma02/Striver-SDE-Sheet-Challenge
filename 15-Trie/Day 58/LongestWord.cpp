// T.C: O(N*M)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/longest-word-with-all-prefixes?source=strivers-sde-sheet


class Node {
public:
    // To store references to child nodes
    Node* links[26];  
    // Flag to indicate end of a word
    bool flag = false;  

    // Checks if the current character link exists
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Returns the next node corresponding to the character
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Creates a link to the next node for the current character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Marks the end of a word
    void setEnd() {
        flag = true;
    }

    // Checks if the current node is the end of a word
    bool isEnd() {
        return flag;
    }
};
class Trie {
public:
    // Root node of the Trie
    Node* root;  

    // Initializes the Trie
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        // Marks the end of the inserted word
        node->setEnd();  
    }

    // Checks if all prefixes of the given word exist in the Trie
    bool checkIfAllPrefixExists(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                if (!node->isEnd()) {
                     // Prefix is incomplete, return false
                    return false; 
                }
            } else {
                // Return false if a character link is missing
                return false;  
            }
        }
        // All prefixes exist
        return true;  
    }
};
class Solution {
public:
    string completeString(vector<string>& nums) {
        // Create a new Trie
        Trie* obj = new Trie();  

        // Insert all words into the Trie
        for (int i = 0; i < nums.size(); i++) {
            obj->insert(nums[i]);
        }
         // Stores the longest valid word
        string longest = ""; 

        // Check each word to find the longest one where all prefixes exist
        for (int i = 0; i < nums.size(); i++) {
            if (obj->checkIfAllPrefixExists(nums[i])) {
                if (nums[i].size() > longest.size()) {
                    longest = nums[i];
                } else if (nums[i].size() == longest.size() && nums[i] < longest) {
                    // Lexicographically smaller word
                    longest = nums[i];  
                }
            }
        }
        // Return result or "None"

        return longest.empty() ? "None" : longest;  
    }
};