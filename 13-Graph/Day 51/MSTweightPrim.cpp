// T.C: O(E log E)
// S.C: O(V + E)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-the-mst-weight?source=strivers-sde-sheet

#include <bits/stdc++.h>
using namespace std;

/* Define P as a shorthand for
the pair<int, pair<int,int>> type */
#define P pair<int,int>

class Solution{
public:

    // Function to get the sum of weights of edges in MST
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Min-Heap to store pair of {edgeWt, node}
        priority_queue <P, vector<P>, greater<P>> pq;
        
        // Visited array
        vector<int> visited(V, 0);
        
        // Push any arbitrary initial node
        pq.push({0,0});
        
        // To store the weight of MST
        int sum = 0;
        
        // Until the priority queue is not empty
        while(!pq.empty()) {
            
            // Get the pair with minimum edge
            auto p = pq.top();
            pq.pop();
            
            int node = p.second; // Get the node
            int wt = p.first; // Get the edge weight
            
            /* If the node is already visited, 
            skip the iteration */
            if(visited[node] == 1) continue;
            
            // Otherwise, mark the node as visited
            visited[node] = 1;
            
            // Update the weight of MST
            sum += wt;
            
            // Traverse all the edges of the node
            for(auto it : adj[node]) {
                
                // Get the adjacent node
                int adjNode = it[0]; 
                
                // Get the edge weight
                int edgeWt = it[1];
                
                /* Add the pair to min-heap if 
                the node is not visited already */
                if(visited[adjNode] == 0) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        
        // Return the weight of MST
        return sum;
    }
};