class Solution {
    int index = 0;
    public boolean verifyPreorder(int[] preorder) {
        return verify(preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean verify(int[] preorder, int minValue, int maxValue) {
        if(index == preorder.length) {
            return true;
        }
        int value = preorder[index];
        if(value < minValue || maxValue < value) {
            return false;
        }
        index++;
        return verify(preorder, minValue, value) || verify(preorder, value, maxValue);
    }
}
