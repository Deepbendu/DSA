class Solution {
  public:
  vector<int> result;
  void traversal(int u, vector<vector<int>>& adj, vector<bool>& visited){
      if(visited[u]) return;
      
      result.push_back(u);
      visited[u] = true;
      
      for(int &v: adj[u]){
          if(!visited[v]){
              traversal(v, adj, visited);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        // u ---> v
        traversal(0,adj, visited);
        return result;
    }
};