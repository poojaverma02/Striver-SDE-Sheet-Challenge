// T.C: O((V+E)*logV)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/dijkstra's-algorithm?source=strivers-sde-sheet

class Solution {
public:
    /* Function to find the shortest distance of all 
    the vertices from the source vertex S. */
    vector<int> dijkstra(int V, vector<vector<int>> edges, 
                         int S) {
                             
        // Create adjacency list from edges
        vector<vector<vector<int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // assuming undirected graph
        }
        
        // Set to store {dist, node}
        set <pair<int,int>> st;
        
        // Distance array 
        vector<int> dist(V, 1e9);
        
        // Distance of source node from itself is 0
        dist[S] = 0;
        
        // Adding the source node to set
        st.insert({0, S});
        
        // Until the set is empty
        while(!st.empty()) {
            
            // Get the distance
            int dis = st.begin()->first;
            
            // Get the node
            int node = st.begin()->second;
            st.erase(st.begin());
            
            // Traverse all its neighbors
            for(auto it : adj[node]) {
                int adjNode = it[0]; // node
                int edgeWt = it[1]; // edge weight
                
                /* If the tentative distance to 
                reach adjacent node is smaller 
                than the known distance */
                if(dis + edgeWt < dist[adjNode]) {
                    
                    /* If another longer known distance 
                    is found, erase it from the set */
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode] , adjNode});
                    
                    // Update the known distance
                    dist[adjNode] = dis + edgeWt;
                    
                    // Add the new pair to the set
                    st.insert({dist[adjNode] , adjNode});
                }
            }
        }
        
        // Return the result
        return dist;
    }
};