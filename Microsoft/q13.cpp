class Solution
{
public:
   int dfs(int i, int vis[], vector<int> adj[], int c, int d)
   {
      vis[i] = 1;
      for (auto x : adj[i])
      {
         if (i == c && x == d) continue;
         if (!vis[x]) dfs(x, vis, adj, c, d);
      }
      return 0;
   }
   int isBridge(int V, vector<int> adj[], int c, int d)
   {
      int vis[V] = {0};
      dfs(c, vis, adj, c, d);
      return (!vis[d]);
   }
};