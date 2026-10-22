class Solution {
public:
    static int getDgtSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [](int num1, int num2) {
            int num1DgtSum = getDgtSum(num1);
            int num2DgtSum = getDgtSum(num2);
            if (num1DgtSum != num2DgtSum) {
                return num1DgtSum < num2DgtSum;
            }
            return num1 < num2;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        // Map each value to its current index in `nums`
        unordered_map<int, int> valtoidx;
        for (int i = 0; i < n; i++) {
            valtoidx[nums[i]] = i;
        }

        int swapcnt = 0;
        for (int i = 0; i < n; i++) {
            int expVal = afterSorted[i];
            int currVal = nums[i];

            if (expVal == currVal) continue;

            int idx = valtoidx[expVal];

            // Perform the swap in `nums`
            nums[i] = expVal;
            nums[idx] = currVal;

            // Update indices in the map
            valtoidx[expVal] = i;
            valtoidx[currVal] = idx;

            swapcnt++;
        }

        return swapcnt;
    }
};