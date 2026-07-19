// T.C:  O(V+E) 
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/bipartite-graph?source=strivers-sde-sheet

class Solution {
private:
    /* Function to perform DFS traversal and 
    color the nodes with alternate colors*/
    bool dfs(int node, int col, vector<int> &color, 
             vector<vector<int>>& adj) {
        
        // Color the current node
        color[node] = col; 
        
        // Traverse adjacent nodes
        for(auto it : adj[node]) {
            
            // if uncoloured
            if(color[it] == -1) {
                
                // Recursively color the nodes 
                if(dfs(it, !col, color, adj) == false) 
                    return false; 
            }
            
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                
                // Return false as it is not bipartite
                return false; 
            }
        }
        
        /* Return true if all the nodes can 
        be colored with alternate colors */
        return true; 
    }

public:
    /* Function to check if the 
    given graph is bipartite */
    bool isBipartite(int V, vector<vector<int>>& edges) {
        
        /* To store the color of nodes, where 
        each node is uncolored initially */
        vector<int> color(V, -1);
        
        // Create adjacency list from edges
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
        
        // Start Traversal of connected components
        for(int i = 0; i < V; i++) {
            
            /* if a node is not colored, 
            a new component is found */
            if(color[i] == -1) {
                
                /* Start DFS traversal 
                and color each node */
                if(dfs(i, 0, color, adj) == false) {
                    
                    /* Return false if component 
                    is found not to be bipartite */
                    return false;
                }
            }
        }
        
        /* Return true if each 
        component is bipartite */
        return true;
    }
};
