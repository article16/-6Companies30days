vector<int> leaders(int a[], int n) {
    stack<int>st;
    vector<int>ans;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty()) {
            if (a[st.top()] > a[i])break;
            st.pop();
        }
        if (st.empty())ans.push_back(a[i]);
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}