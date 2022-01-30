bool cmp(string x, string y) {
    if (x.size() > y.size())return true;
    else if (x.size() < y.size())return false;
    else return x > y;
}
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k - 1];
    }
};