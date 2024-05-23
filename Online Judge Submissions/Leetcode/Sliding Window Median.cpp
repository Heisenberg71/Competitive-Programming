/*
Problem Link: https://leetcode.com/problems/sliding-window-median/description/
*/

class Solution {
private:
    multiset<int> firstHalfSet, secondHalfSet;
    
    void arrangeOrder() {
        while (firstHalfSet.size() > secondHalfSet.size()) {
            secondHalfSet.insert(*(--firstHalfSet.end()));
            firstHalfSet.erase((--firstHalfSet.end()));
        }

        while(!firstHalfSet.empty() && *(--firstHalfSet.end()) > *secondHalfSet.begin()){
            int lastValueOfFirstHalfSet = *(--firstHalfSet.end()), firstValueOfSecondHalfSet = *secondHalfSet.begin();
            firstHalfSet.erase((--firstHalfSet.end()));
            secondHalfSet.erase(secondHalfSet.begin());
            
            firstHalfSet.insert(firstValueOfSecondHalfSet);
            secondHalfSet.insert(lastValueOfFirstHalfSet);
        }
    }

    void populateMedianWindows(int k, vector<double>& medianOfWindows){
        (k & 1) ? medianOfWindows.push_back(*secondHalfSet.begin()) : 
                medianOfWindows.push_back(*(--firstHalfSet.end()) / 2.0 + (*secondHalfSet.begin()) / 2.0);
    }

    void modifyAccordingToRange(int L, int R, vector<int>& nums){
        (firstHalfSet.count(nums[L])) ? firstHalfSet.erase(firstHalfSet.find(nums[L])) : secondHalfSet.erase(secondHalfSet.find(nums[L]));
            firstHalfSet.insert(nums[R]); 
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        for (int i = 0; i < k; i++) {
            firstHalfSet.insert(nums[i]);
        }
        
        vector<double> medianOfWindows;
        for (int L = 0, R = k; R < nums.size(); L++, R++) {
            arrangeOrder();
            populateMedianWindows(k, medianOfWindows);
            modifyAccordingToRange(L, R, nums);
        }

        arrangeOrder();
        populateMedianWindows(k, medianOfWindows);

        return medianOfWindows;
    }
};
