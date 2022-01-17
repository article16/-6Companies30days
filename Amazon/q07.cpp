string FirstNonRepeating(string A) {
	string ans = "";
	unordered_map<char, int>mp;
	queue<char>q;
	for (char c : A) {
		mp[c]++;
		if (mp[c] <= 1)q.push(c);
		while (!q.empty() && mp[q.front()] > 1)q.pop();
		if (!q.empty())ans += q.front();
		else ans += "#";
	}
	return ans;
}