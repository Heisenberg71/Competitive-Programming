/*
  Problem Link: https://leetcode.com/problems/number-of-valid-clock-times/description/
  Time Complexity: O(N)
  Space Complexity: O(1)

  Here,
  N = number of possible times
*/
class Solution {
public:
    int countTime(string time) {
        int validTimes = 0;
        for(int currTime = 0; currTime <= 2359; currTime++){
            int minute = currTime%100;
            int hour = currTime/100;
            if(hour > 23 || minute > 59) continue;

            string timeStr = to_string(currTime);
            while(timeStr.size() < 4) timeStr = '0' + timeStr;
            timeStr.insert(2, ":");

            int matched = 0;
            for(int i = 0; i < time.size(); i++){
                if(time[i] == '?' || time[i] == ':' || timeStr[i] == time[i]) matched++;
            }
            if(matched == time.size()) validTimes++;
        }
        return validTimes;
    }
};
