vector <int> calculateSpan(int price[], int n)
{
    vector<int>ans(n);
    stack<int>st;
    for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            if (price[st.top()] > price[i])break;
            st.pop();
        }
        ans[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return ans;
}