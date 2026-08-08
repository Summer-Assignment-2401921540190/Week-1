#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        
        // 1. Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        // 2. Iterate through the array for the first element
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Two pointers initialization
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    // Found a valid triplet
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // Skip duplicate values for the third element
                    while (j < k && nums[k] == nums[k + 1]) k--;
                    
                } else if (sum < 0) {
                    // Sum is too small, move the left pointer rightward to increase sum
                    j++;
                } else {
                    // Sum is too large, move the right pointer leftward to decrease sum
                    k--;
                }
            }
        }
        
        // The missing fix from the image code
        return output; 
    }
};