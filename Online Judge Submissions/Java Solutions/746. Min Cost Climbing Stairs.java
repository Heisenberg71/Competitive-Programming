class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int stairSize = cost.length;
        int[] minCost = new int[stairSize + 1];
        for(int i = 2; i < stairSize + 1; i++) {
            minCost[i] = Math.min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }
        return minCost[stairSize];
    }
}
