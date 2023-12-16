/*
    Problem Link: https://leetcode.com/problems/substring-with-largest-variance/description/
    T.C: O(size of string)
    S.C: O(1)
*/
class Solution {
public:
    int largestVariance(string s) {
        vector<int> freq(26, 0);
        for(auto& ch: s){
            freq[ch - 'a']++;
        }

        int globalMax = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){

                if(i == j || !freq[i] || !freq[j]) continue;

                int major = 0, minor = 0;
                int restMinor = freq[j];
                for(auto& ch: s){
                    if(ch - 'a' == i) major++;
                    if(ch - 'a' == j){
                        minor++;
                        restMinor--;
                    }

                    if(minor > 0){
                        globalMax = max(globalMax, major - minor);
                    }

                    if(major < minor && restMinor){
                        major = minor = 0;
                    }
                }

            }
        }

        return globalMax;
    }
};
