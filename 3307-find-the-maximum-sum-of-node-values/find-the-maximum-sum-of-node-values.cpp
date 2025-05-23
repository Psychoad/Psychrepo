class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0, minLoss = LLONG_MAX;
        int cnt = 0;
        for (int x : nums) {
            long long d = (x ^ k) - x;
            if (d > 0) {
                total += x ^ k;
                cnt++;
                minLoss = min(minLoss, d);
            } else {
                total += x;
                minLoss = min(minLoss, -d);
            }
        }
        // If number of flips is odd, remove the smallest gain
        if (cnt % 2) total -= minLoss;
        return total;
    }
};