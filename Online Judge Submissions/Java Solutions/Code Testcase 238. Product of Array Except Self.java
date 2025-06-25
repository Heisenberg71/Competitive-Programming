class Solution {
    public int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        int[] suffixProductArray = new int[length];
        int suffixProduct = 1;
        for(int i = nums.length - 1; i >= 0; i--) {
            suffixProductArray[i] = suffixProduct;
            suffixProduct *= nums[i];
        }

        int[] productArray = new int[length];
        int forwardMult = 1;
        for(int i = 0; i < length; i++) {
            productArray[i] = forwardMult*suffixProductArray[i];
            forwardMult *= nums[i];
        }
        return productArray;
    }
}
