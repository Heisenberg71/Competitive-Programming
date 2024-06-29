Problem Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int kth_smallest;
        int lo = 1, hi = m*n;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int smallerCount = 0;
            for(int i = 1; i <= m; i++){
                smallerCount += min(n, mid/i);
            }
            if(smallerCount >= k){
                kth_smallest = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return kth_smallest;
    }
};
