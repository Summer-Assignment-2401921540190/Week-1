class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long total = 0;

        int low = 1;
        int high = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            total += candies[i];
            high = max(high, candies[i]);
        }

        if (total < k) return 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long children = 0;

            for (int i = 0; i < n; i++) {
                children += candies[i] / mid;
            }

            if (children >= k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};