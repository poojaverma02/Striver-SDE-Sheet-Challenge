// T.C: O(V + E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/topological-sort-or-kahns-algorithm?source=strivers-sde-sheet

class Solution {
private:

    // Function to perform DFS traversal
    void dfs(int node, vector<int> adj[], 
            vector<int> &vis, 
            stack <int> &st) {
                
        // Mark the node as visited
        vis[node] = 1;
        
        // Traverse all the neighbors
        for(auto it : adj[node]) {
            
            // If not visited, recursively perform DFS.
            if(vis[it] == 0) dfs(it, adj, vis, st);
        }
        
        /* Add the current node to stack 
        once all the nodes connected to it 
        have been processed */
        st.push(node);
    }
    
public:

	/* Function to return list containing 
	vertices in Topological order */
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // To store the result
	    vector <int> ans;
	    
	    /* Stack to store processed 
	    nodes in reverse order */
	    stack <int> st;
	    
	    // Visited array
	    vector<int> vis(V, 0);
	    
	    // Traverse the graph
	    for(int i=0; i<V; i++) {
	        
	        // Start DFS traversal for unvisited node
	        if(!vis[i]) {
	            dfs(i, adj, vis, st);
	        }
	    }
	    
	    // Until the stack is empty
	    while(!st.empty()) {
	        
	        // Add the top of stack to result
	        ans.push_back(st.top());
	        
	        // Pop the top node
	        st.pop();
	    }
	    
	    // Return the result
        return ans;
	}
};