class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        int last = Integer.MIN_VALUE;
        int overlapMeetingCount = intervals.length;
        for(int[] interval: intervals) {
            if(last <= interval[0]) {
                last = interval[1];
                overlapMeetingCount--;
            }       
        }
        return overlapMeetingCount;
    }
}
