string printMinNumberForPattern(string s) {
    // code here
    stack<int>st;
    int num = 1;
    for (char c : s) {
        st.push(num++);
        if (c == 'I') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
    }
    st.push(num);
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}