class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int hoursNeeded = 0;

            for (int pile : piles) {
                hoursNeeded += (pile + mid - 1) / mid;
            }

            if (hoursNeeded <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};