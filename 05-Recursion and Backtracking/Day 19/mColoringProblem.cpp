// T.C: O(M^N)
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/m-coloring-problem?source=strivers-sde-sheet

class Solution {
   public:
    // Function to check if it's safe to color the node with a given color
    bool isSafe(int col, int node, vector<int>& colors, vector<int> adj[]) {
        // Check adjacent nodes
        for (int i = 0; i < adj[node].size(); i++) {
            // If an adjacent node has the same color
            if (colors[adj[node][i]] == col) return false;
        }
        return true;  // Safe to color
    }

    // Recursive function to solve graph coloring problem
    bool solve(int node, int m, int n, vector<int>& colors, vector<int> adj[]) {
        // If all nodes are colored
        if (n == node) return true;
        // Try all colors from 1 to m
        for (int i = 1; i <= m; i++) {
            // Check if it is safe to color the node with color i
            if (isSafe(i, node, colors, adj)) {
                // Assign color i to node
                colors[node] = i;
                // Recursively try to color the next node
                if (solve(node + 1, m, n, colors, adj)) return true;
                // Reset color if it doesn't lead to a solution
                colors[node] = 0;
            }
        }
        // No color can be assigned
        return false;
    }

    // Function to check if the graph can be colored with m colors
    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        // Adjacency list representation of the graph
        vector<int> adj[n];

        // Build the graph from edges
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // Initialize all colors to 0 (uncolored)
        vector<int> colors(n, 0);
        // Start solving from the first node
        return solve(0, m, n, colors, adj);
    }
};