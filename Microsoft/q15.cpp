class Solution {
public:
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
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            for (int j = 0; j < min(s1.length(), s2.length()); j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int>ans = topoSort(K, adj);
        string s;
        for (auto x : ans) {
            s += ('a' + x);
        }
        return s;
    }
};