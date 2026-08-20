class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        // Not enough flowers to make m bouquets
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            int boq = 0;

            for (int i = 0; i < bloomDay.size(); i++) {

                if (bloomDay[i] <= mid) {
                    count++;

                    if (count == k) {
                        boq++;
                        count = 0;
                    }
                }
                else {
                    count = 0;
                }
            }

            if (boq >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};