// T.C: O(V*E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/bellman-ford-algorithm?source=strivers-sde-sheet

class Solution {
public:

    /* Function to implement 
    Bellman Ford Algorithm */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, 
                             int S) {
                                 
        // To store the distance
        vector<int> dist(V, 1e9);
        
        // Distane of source from itself is zero
        dist[S] = 0;
        
        // Repeat for V-1 times
        for(int i=0; i<V-1; i++) {
            
            // Iterate on all the edges
            for(auto it : edges) {
                
                int u = it[0]; // node 1
                int v = it[1]; // node 2
                int wt = it[2]; // edge weight
                
                // Edge relaxation
                if(dist[u] != 1e9 && 
                   dist[u] + wt < dist[v]) {
                       
                    // Updating the known distance
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        /* An extra relaxation to check if the 
        graph consists of a negative cycle */
        for(auto it : edges) {
            
            int u = it[0]; // node 1
            int v = it[1]; // node 2
            int wt = it[2]; // edge weight
            
            /* If edge relaxation is possible, 
            negative cycle exists */
            if(dist[u] != 1e9 && 
               dist[u] + wt < dist[v]) {
                   
                // Return {-1}
                return {-1};
            }
        }
        
        // Return the computed result
        return dist;
    }
};