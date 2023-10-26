/*

Problem Link: https://leetcode.com/problems/meeting-rooms-iii/
Time Complexity: O(Number_of_meeting_rooms + number_of_meetings*log(number_of_meetings))
Space Complexity: O(Number_of_meeting_rooms + number_of_meetings)

*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        sort(meetings.begin(), meetings.end());
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
            greater<pair<long long, int>>> emptyRooms, filledRooms;
        
        for(int i = 0; i < n; i++)
            emptyRooms.push({-1, i}); /// (out-time, meetingRoomNumber)
        
        long long currentTime = 0;
        for(int i = 0; i < meetings.size(); i++){
            while(!filledRooms.empty() && filledRooms.top().first <= meetings[i][0]){
                emptyRooms.push({-1, filledRooms.top().second});
                filledRooms.pop();
            }
            if(emptyRooms.empty()){
                currentTime = filledRooms.top().first;
                meetingCount[ filledRooms.top().second ]++;
                auto topVal = filledRooms.top(); filledRooms.pop();
                topVal.first = currentTime + meetings[i][1] - meetings[i][0];
                filledRooms.push(topVal);
            }
            else{
                currentTime = meetings[i][1];
                filledRooms.push({currentTime, emptyRooms.top().second});
                meetingCount[ emptyRooms.top().second ]++;
                emptyRooms.pop();
            }
        }
        
        int maxMeetingOnARoom = 0, lowestNumberRoomWithMaxMeeting;
        for(int i = 0; i < n; i++){
            if(maxMeetingOnARoom < meetingCount[i]){
                maxMeetingOnARoom = meetingCount[i];
                lowestNumberRoomWithMaxMeeting = i;
            }
        }
        
        return lowestNumberRoomWithMaxMeeting;
    }
};
