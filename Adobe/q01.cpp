class Solution
{
public:
	//Function to find a continuous sub-array which adds up to a given number.
#define ll long long
	vector<int> subarraySum(int a[], int n, long long target)
	{
		ll s = 0, e = 0, sum = a[0];
		while (s < n && e < n) {
			if (sum < target)sum += a[++e];
			else if (sum > target)sum -= a[s++];
			else return {s + 1, e + 1};
		}
		return { -1};
	}
};