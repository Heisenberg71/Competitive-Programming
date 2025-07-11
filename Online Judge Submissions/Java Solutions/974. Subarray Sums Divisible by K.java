class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int prefixSum = 0;
        Map<Integer, Integer> prefixReminder = new HashMap<>();
        prefixReminder.put(0, 1);
        int subArraySum = 0;
        for(int num: nums) {
            prefixSum = ((prefixSum + num)%k + k) %k;
            if(prefixReminder.containsKey(prefixSum) == false) {
                prefixReminder.put(prefixSum, 0);
            }
            int value = prefixReminder.get(prefixSum);
            subArraySum += value;
            prefixReminder.put(prefixSum, 1 + value);
        }
        return subArraySum;
    }
}
