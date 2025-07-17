class Solution {
    int[][] profit;
    boolean[][] visited;
    int length;
    int findMaxProfit(int index, int remaining, int[] prices) {
        if(remaining < 0) {
            return Integer.MIN_VALUE/2;
        }
        if(index == length) {
            if((remaining&1) == 0) return 0;
            return Integer.MIN_VALUE/2;
        }
        if(visited[index][remaining]) {
            return profit[index][remaining];
        }
        int maxProfit;
        if((remaining&1) == 0) {
            maxProfit = Math.max(-prices[index] + findMaxProfit(index + 1, remaining - 1, prices), 
                        findMaxProfit(index + 1, remaining, prices));
        }
        else{
            maxProfit = Math.max(prices[index] + findMaxProfit(index + 1, remaining - 1, prices),
                        findMaxProfit(index + 1, remaining, prices));
        }
        visited[index][remaining] = true;
        return profit[index][remaining] = maxProfit;
    }
    public int maxProfit(int k, int[] prices) {
        length = prices.length;
        profit = new int[length][k*2 + 1];
        visited = new boolean[length][k*2 + 1];
        return findMaxProfit(0, k*2, prices);
    }
}
