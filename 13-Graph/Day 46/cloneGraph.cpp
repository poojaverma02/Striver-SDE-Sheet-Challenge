// T.C: O(V + E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/clone-graph?source=strivers-sde-sheet

class Solution {
public:
    // Map original node -> cloned node
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node) {
        // If already cloned, return it
        if (visited.count(node))
            return visited[node];

        // Create clone
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};