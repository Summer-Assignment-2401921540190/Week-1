class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0, ans, mid;
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());

        for (int i = 0; i < n; i++) {
            high += weights[i];
        }

        while (low <= high) {
            mid = low + (high - low) / 2;

            int current_load = 0;
            int total_days = 1;

            for (int i = 0; i < n; i++) {
                if (current_load + weights[i] > mid) {
                    total_days++;
                    current_load = weights[i];
                }
                else {
                    current_load += weights[i];
                }
            }

            if (total_days > days) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};