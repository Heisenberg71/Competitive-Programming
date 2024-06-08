class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int totalSum = 0;
        map<int, vector<int>> firstIdx;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            firstIdx[totalSum].push_back(i);
        }

        int sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            if (!firstIdx.count(sum))
                continue;

            for (int m = 0; m < firstIdx[sum].size(); m++) {

                int a = firstIdx[sum][m] + 1;
                int b = i - 1;

                cout << a << " " << b << '\n';

                if (a + 3 >= b)
                    continue;

                int currSum = 0;
                for (int j = a + 1; j < b - 2; j++) {

                    currSum += nums[j];
                    if (sum == currSum && sum == totalSum - 3 * sum - nums[a] -
                                                     nums[b] - nums[j + 1]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
