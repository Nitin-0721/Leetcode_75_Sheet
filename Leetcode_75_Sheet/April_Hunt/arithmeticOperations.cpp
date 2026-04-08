class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int n = nums.length;
        int count = 0;
        int j = 1;
        int k = 2;

        for (int i = 0; i < n - 2; i++) {
            while (j < n - 1 && nums[j] - nums[i] < diff) {
                j++;
            }

            if (j < n - 1 && nums[j] - nums[i] == diff) {
                if (k <= j) {
                    k = j + 1;
                }

                while (k < n && nums[k] - nums[j] < diff) {
                    k++;
                }

                if (k < n && nums[k] - nums[j] == diff) {
                    count++;
                }
            }
        }
        return count;
    }
}