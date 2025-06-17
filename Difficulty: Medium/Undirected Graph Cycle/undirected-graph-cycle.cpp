class Solution {
  public:
    bool cycleDFS(vector<vector<int>>& adj, int u, int parent, vector<bool> &visited){

        visited[u] = true;
        
        for(int &v : adj[u]){
            if(v == parent) continue; 
            //UDG m parent pr to ja skta h
            //but usko cycle thodi manenge
            
            if(visited[v]) return true; //Already visited h -> Cycle hai
            
            if(cycleDFS(adj, v, u, visited)) return true;
            
        }
        
        return false;
        
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);  // Adjacency list

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && cycleDFS(adj, i, -1, visited)){
                return true;
            }
        }
        return false;
        
    }
};