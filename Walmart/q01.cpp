class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int source, int end) {

		vector<pair<int, double> > g[n];

		int a, b;
		double wt;
		int m = edges.size();
		for (int i = 0; i < m ; i++) {
			//cin >> a >> b >> wt;
			wt = succProb[i];
			a = edges[i][0]; b = edges[i][1];
			g[a].push_back(make_pair(b, wt));
			g[b].push_back(make_pair(a, wt));
		}


		// Dijkstra's algorithm begins from here
		priority_queue<pair<double, int> > pq; // max-heap ; In pair => (prob,from)
		vector<double> distTo(n, 0); 	;

		distTo[source] = 1;
		pq.push(make_pair(1, source));

		while ( !pq.empty() ) {
			double dist = pq.top().first;
			int prev = pq.top().second;
			pq.pop();

			vector<pair<int, double> >::iterator it;
			for ( it = g[prev].begin() ; it != g[prev].end() ; it++) {
				int next = it->first;
				double nextDist = it->second;
				if ( distTo[next] < distTo[prev] * nextDist) {
					distTo[next] = distTo[prev] * nextDist;
					pq.push(make_pair(distTo[next], next));
				}
			}

		}

		return distTo[end];

	}
};