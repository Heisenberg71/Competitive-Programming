class Solution {
    public int maxSubArray(int[] nums) {
        int minPrefixSum = 0;
        int prefixSum = 0;
        int maxSum = Integer.MIN_VALUE;
        for(int num: nums) {
            prefixSum += num;
            maxSum = Math.max(maxSum, prefixSum  - minPrefixSum);
            minPrefixSum = Math.min(minPrefixSum, prefixSum);
        }
        return maxSum;
    }
}
