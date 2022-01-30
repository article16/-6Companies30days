class Solution {
public:
#define ll long long
    const ll mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<ll, ll>>v(n);
        ll i, ans = INT_MIN, sum = 0;
        for (i = 0; i < n; i++) {
            v[i].first = efficiency[i];
            v[i].second = speed[i];
        }
        sort(v.begin(), v.end(), greater<pair<ll, ll>>());
        multiset<ll>st;
        for (i = 0; i < k; i++) {
            sum = (sum + v[i].second);
            ans = max(ans, (v[i].first * sum));
            st.insert(v[i].second);
            //cout<<sum<<endl;
        }
        i--;
        while (i < n - 1) {
            i++;
            auto it = st.begin(); ll sml = *it;
            if (v[i].second > sml) {
                sum -= sml; sum = (sum + v[i].second);
                st.erase(st.begin()); st.insert(v[i].second);
            }
            ans = max(ans, (v[i].first * sum));
            //cout<<sum<<endl;
        }
        return ans % mod;
    }
};