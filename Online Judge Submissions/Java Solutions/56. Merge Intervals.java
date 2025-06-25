class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        LinkedList<int[]> merged = new LinkedList<>();
        int R = -1;
        for(int[] interval: intervals) {
            if(R < interval[0]) {
                merged.add(interval);
                R = interval[1];
            }
            else {
                R = Math.max(R, interval[1]);
                merged.getLast()[1] = R;
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }
}
