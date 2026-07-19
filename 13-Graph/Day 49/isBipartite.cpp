// T.C:  O(V+E) 
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/bipartite-graph?source=strivers-sde-sheet

class Solution {
private:
    /* Function to perform BFS traversal and color
    the nodes with alternate colors in a component */
    bool bfs(int start, int V, vector<int> adj[], int color[]) {
        // Queue for BFS traversal
        queue <int> q;
        
        // Add initial node to queue
        q.push(start);
        color[start] = 0; // Mark it with a color
        
        // While queue is not empty
        while(!q.empty()) {
            // Get the node
            int node = q.front();
            q.pop();
            
            // Traverse all its neighbors
            for(auto it : adj[node]) {
                
                // If not already colored
                if(color[it] == -1) {
                    
                    // Color it with opposite color.
                    color[it] = !color[node];
                    
                    // Push the node in queue
                    q.push(it);
                }
                
                // Else if the neighbor has same color as node
                else if(color[it] == color[node]) {
                    
                    /* Return false, as the 
                    component is not bipartite */
                    return false;
                }
            }
        }
        
        // Return true is the component is bipartite
        return true;
    }
    
public:
    /* Function to check if the 
    given graph is bipartite */
    bool isBipartite(int V, vector<vector<int>> edges) {
        
        /* To store the color of nodes, where 
        each node is uncolored initially */
        int color[V];
        for(int i=0; i < V; i++) color[i] = -1;
        
        // Create adjacency list
        vector<int> adj[V];
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        // Traverse all the nodes 
        for(int i=0; i < V; i++) {
            
            // If not colored, start the traversal
            if(color[i] == -1) {
                // Return false if graph is not bipartite
                if(!bfs(i, V, adj, color))
                    return false;
            }
        }
        
        /* Return true if each 
        component is bipartite */
        return true;
    }
};
