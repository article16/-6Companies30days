class Solution {
public:
	bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
		vis[node] = 1;
		dfsVis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				if (checkCycle(it, adj, vis, dfsVis)) return true;
			} else if (dfsVis[it]) {
				return true;
			}
		}
		dfsVis[node] = 0;
		return false;
	}
	bool isCyclic(int N, vector<int> adj[]) {
		int vis[N], dfsVis[N];
		memset(vis, 0, sizeof vis);
		memset(dfsVis, 0, sizeof dfsVis);

		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				// cout << i << endl;
				if (checkCycle(i, adj, vis, dfsVis)) {
					return true;
				}
			}
		}
		return false;
	}
	void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
		vis[node] = 1;

		for (auto it : adj[node]) {
			if (!vis[it]) {
				findTopoSort(it, vis, st, adj);
			}
		}
		st.push(node);
	}
	vector<int> topoSort(int N, vector<int> adj[]) {
		stack<int> st;
		vector<int> vis(N, 0);
		for (int i = 0; i < N; i++) {
			if (vis[i] == 0) {
				findTopoSort(i, vis, st, adj);
			}
		}
		vector<int> topo;
		while (!st.empty()) {
			topo.push_back(st.top());
			st.pop();
		}
		return topo;

	}
	vector<int> findOrder(int num, vector<vector<int>>& preq) {
		vector<int>adj[num];
		vector <int> res;
		int i, n = preq.size();

		for (i = 0; i < n; i++) {
			adj[preq[i][1]].push_back(preq[i][0]);
		}

		if (!isCyclic(num, adj))res = topoSort(num, adj);
		return res;
	}
};