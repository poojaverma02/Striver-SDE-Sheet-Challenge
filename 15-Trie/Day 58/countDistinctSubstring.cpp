// T.C: O(N^2)
// S.C: O(N^2)
// Question Link: https://takeuforward.org/plus/dsa/problems/number-of-distinct-substrings-in-a-string?source=strivers-sde-sheet


struct Node {

    Node* links[26];

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

 
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
public:
    // Count number of distinct substrings in string
    int countDistinctSubstring(string s) {
        int c = 0; 
         // Root node of the trie
        Node* root = new Node();

        // Iterate all starting positions of substrings
        for (int i = 0; i < s.size(); i++) {
            Node* node = root;

            // Iterate through characters 
            for (int j = i; j < s.size(); j++) {
                /*If the current character is not 
                a child of the current node, 
                insert it as a new child node*/
                if (!node->containsKey(s[j])) {
                    c++; 
                    // Insert new child node for character s[j]
                    node->put(s[j], new Node()); 
                }
                // Move to the child node 
                node = node->get(s[j]); 
            }
        }

        // Clean up the allocated memory
        deleteTrie(root);
        /*Return the total 
        count of distinct 
        substrings including 
        the empty string*/
        return c+1; 
    }

private:
    // Freeing up memory
    void deleteTrie(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                deleteTrie(node->links[i]);
            }
        }
        delete node;
    }
};
