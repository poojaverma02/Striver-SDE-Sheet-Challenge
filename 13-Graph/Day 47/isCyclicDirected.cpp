// T.C: O(V + E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-a-directed-graph?source=strivers-sde-sheet

class Solution {
private:

    // Function to perform DFS traversal
    bool dfs(int node, vector<int> adj[], 
             vector<bool> &visited, 
             vector<bool> &pathVisited) {
                 
        // Mark the node as path visited
        visited[node] = true;
        
        // Mark the node as path visited
        pathVisited[node] = true;
        
        // Traverse all the neighbors
        for(auto it : adj[node]) {
            
            /* If the neighbor is already visited 
            in the path, a cycle is detected */
            if(pathVisited[it]) 
                return true;
            
            /* Else if the node is unvisited, 
            perform DFS recursively from this node */
            else if(!visited[it]) {
                
                // If cycle is detected, return true
                if(dfs(it, adj, visited, pathVisited)) 
                    return true;
            }
        }
        
        // Remove the node from path 
        pathVisited[node] = false;
        
        // Return false if no cycle is detected
        return false;
    }
    
public:

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // Visited array
        vector<bool> visited(V, false);
        
        /* Array to mark nodes that are 
        visited in a particular path */
        vector<bool> pathVisited(V, false);
        
        // Traverse the graph
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                
                // If a cycle is found, return true
                if(dfs(i, adj, visited, pathVisited)) 
                    return true;
            }
        }
        
        /* Return false if no cycle is 
        detected in any component */
        return false;
    }
};


