// T.C: O(V + E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-a-directed-graph?source=strivers-sde-sheet&approach=bfs

class Solution {
private:
    /* Function to return the topological
     sorting of given graph */
    vector<int> topoSort(int V, vector<int> adj[]) {
        
        // To store the result
        vector<int> ans;
        
        // To store the In-degrees of nodes
	    vector<int> inDegree(V, 0);
	    
	    // Calculating the In-degree of the given graph
	    for(int i=0; i<V; i++) {
	        for(auto it : adj[i]) inDegree[it]++;
	    }
	    
	    // Queue to facilitate BFS
	    queue<int> q;
	    
	    // Add the nodes with no in-degree to queue
	    for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }
	    
	    // Until the queue is empty
	    while(!q.empty()) {
	        
	        // Get the node
	        int node = q.front();
	        
	        // Add it to the answer
	        ans.push_back(node);
	        q.pop();
	        
	        // Traverse the neighbours
	        for(auto it : adj[node]) {
	            
	            // Decrement the in-degree
	            inDegree[it]--;
	            
	            /* Add the node to queue if 
	            its in-degree becomes zero */
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    
	    // Return the result
	    return ans;
    }
    
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // To store the topological ordering
        vector<int> topo;
        
        // Get the topological sort of the graph
        topo = topoSort(V, adj);
        
        /* If topological sort doesn't include all
        nodes, the graph is cyclic in nature. */
        if(topo.size() < V) return true;
        
        // Else the graph is acyclic. 
        return false;
    }
};