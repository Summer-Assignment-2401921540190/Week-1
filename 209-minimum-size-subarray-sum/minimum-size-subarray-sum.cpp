class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = INT_MAX;
        int st = 0;
        int end = 0;
        int sum = 0;
        int n = nums.size();

        while (end < n) {
            sum += nums[end];

            while (sum >= target) {
                total = min(total, end - st + 1);

                sum -= nums[st];
                st++;
            }

            end++;
        }

        return total == INT_MAX ? 0 : total;
    }
};