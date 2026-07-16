// T.C: O(V + E)
// S.C: O(V)
// Question Link: https://takeuforward.org/plus/dsa/problems/traversal-techniques?source=strivers-sde-sheet

class Solution {
private:

	/* Helper function to perform BFS
	traversal from the node */
	void bfs(int node, vector<vector<int>>& adj, int vis[],
	         vector<int> &ans) {

		// Queue data structure
		queue<int> q;

		// Push the starting node
		q.push(node);

		// Until the queue is empty
		while(!q.empty()) {

			// Get the node
			int node = q.front();
			q.pop();

			// Add the node to answer
			ans.push_back(node);

			// Traverse for all its neighbours
			for(auto it : adj[node]) {

				/* If the neighbour has previously not been
				visited, store in Q and mark as visited */
				if(!vis[it]) {
					vis[it] = 1;
					q.push(it);
				}
			}
		}

		// Return
		return;
	}


	/* Helper function to recursively
	perform DFS from the node */
	void dfs(int node, vector<vector<int>>& adj, int vis[],
	         vector<int> &ans) {

		// Mark the node as visited
		vis[node] = 1;

		// Add the node to the result
		ans.push_back(node);

		// Traverse all its neighbours
		for(auto it : adj[node]) {

			// If the neighbour is not visited
			if(!vis[it]) {

				// Perform DFS recursively
				dfs(it, adj, vis, ans);
			}
		}
	}

public:

	/* Function to return a list containing
	the DFS traversal of the graph */
	vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
		// Visited array
		int vis[V] = {0};

		// Create a list to store DFS
		vector<int> ans;

		// Create adjacency list from edges
		vector<vector<int>> adj(V);
		for(auto& edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]); // Assuming undirected graph
		}

		// Traverse all the nodes
		for(int i=0; i < V; i++) {

			// If the node is unvisited
			if(vis[i] == 0) {

				// Call DFS from that node
				dfs(i, adj, vis, ans);
			}
		}

		// Return the result
		return ans;
	}

	/* Function to return a list containing
	the BFS traversal of the graph */
	vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {

		// Visited array
		int vis[V] = {0};

		// To store the result
		vector<int> ans;

		// Create adjacency list from edges
		vector<vector<int>> adj(V);
		for(auto& edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]); // Assuming undirected graph
		}

		// Traverse all the nodes
		for(int i=0; i < V; i++) {

			// If the node is unvisited
			if(vis[i] == 0) {
			    
			    // Mark the node as visited
                vis[i] = 1;
                
				// Call BFS from that node
				bfs(i, adj, vis, ans);
			}
		}

		return ans;
	}
};
