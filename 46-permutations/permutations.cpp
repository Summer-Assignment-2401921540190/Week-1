class Solution {
public:

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& temp,
               vector<bool>& visited)
    {
        // Base case
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Try every element
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == false)
            {
                // Choose
                visited[i] = true;
                temp.push_back(nums[i]);

                // Recursion
                solve(nums, ans, temp, visited);

                // Backtracking
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        solve(nums, ans, temp, visited);

        return ans;
    }
};