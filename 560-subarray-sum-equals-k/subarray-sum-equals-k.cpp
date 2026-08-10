class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> m;

        int prefixSum = 0;
        int total = 0;

        // Prefix sum 0 has occurred once
        m[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            // Check if prefixSum - k exists
            if (m.count(prefixSum - k)) {
                total += m[prefixSum - k];
            }

            // Store current prefix sum
            m[prefixSum]++;
        }

        return total;
    }
};