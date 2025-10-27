class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int i;
        int n = nums.size();
        for (i = 0; i < n; i++)
            sum += nums[i];

        int j;
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        bool siam[n + 1][sum + 1];
        for (i = 0; i <= sum; i++)
            siam[0][i] = false;
        for (i = 0; i <= n; i++)
            siam[i][0] = true;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= sum; j++) {
                if (nums[i-1] <= j) {
                    siam[i][j] = siam[i - 1][j] || siam[i - 1][j - nums[i-1]];
                } else
                    siam[i][j] = siam[i - 1][j];
            }
        }
        return siam[n][sum];
    }
};
