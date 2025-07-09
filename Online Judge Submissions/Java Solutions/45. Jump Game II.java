class Solution {
    public int jump(int[] nums) {
        int jumpCount = 0;
        int currEnd = 0, currFar = 0;
        for(int i = 0; i + 1 < nums.length; i++) {
            currFar = Math.max(currFar, i + nums[i]);

            if(i == currEnd) {
                jumpCount++;
                currEnd = currFar;
            }
        }

        return jumpCount;
    }
}
