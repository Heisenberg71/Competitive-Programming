/*

  Problem Link: https://leetcode.com/problems/employee-free-time/description/
  Time Complexity: O(NlogN)
  Space Complexity: O(N)

  Here, N = size of all intervals

/*

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
private:
    static bool asendingOrder(Interval& a, Interval& b){
        if(a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int furthestEndTime = -1;
        vector<Interval> freeTimes, allIntervals;
        for(auto& u: schedule){
            for(auto&v: u)
                allIntervals.push_back(v);
        }
        sort(allIntervals.begin(), allIntervals.end(), asendingOrder);
        for(auto& u: allIntervals){
            if(furthestEndTime != -1 && furthestEndTime < u.start)
                freeTimes.push_back(Interval(furthestEndTime, u.start));
            furthestEndTime = max(furthestEndTime, u.end);
        }
        return freeTimes;
    }
};
