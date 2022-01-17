vector <int> max_of_subarrays(int *a, int n, int k)
{
    vector<int>right(n);
    vector<int>ans(n - k + 1);
    stack<int>st;
    int i, j, p;
    for (i = n - 1; i >= 0; i--) {
        while (!st.empty()) {
            if (a[st.top()] > a[i])break;
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    for (i = 0; i < n - k + 1; i++) {
        j = i;
        while (j < i + k) {
            p = j;
            j = right[j];
        }
        ans[i] = a[p];
    }
    return ans;
}