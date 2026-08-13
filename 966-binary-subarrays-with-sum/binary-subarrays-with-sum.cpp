class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> m;
        
        int prefixSum = 0;
        int total = 0;
        
        m[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            
            prefixSum += nums[i];
            
            if (m.count(prefixSum - goal)) {
                total += m[prefixSum-goal];
               
            }
            
            // Always update current prefix sum
            m[prefixSum]++;
        }
        
        return total;
    }
};