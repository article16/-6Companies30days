int main()
{

	priority_queue<int, vector<int>, greater<int> > pq;

	int n, t = 10;

	while (cin >> n) {
		if (t > 0)pq.push(n);
		else {
			if (n > st.top()) {
				pq.pop();
				pq.push(n);
			}
		}
		t--;
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}