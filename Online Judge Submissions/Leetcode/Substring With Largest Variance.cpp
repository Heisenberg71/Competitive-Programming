/*
    Problem Link: https://leetcode.com/problems/substring-with-largest-variance/description/
    T.C: O(size of string)
    S.C: O(1)
*/

class Solution {
private:
    vector<int> freq;
    void findFrequencies(string& s){
        freq.assign(26, 0);
        for(auto& ch: s){
            freq[ch - 'a']++;
        }
    }
    
    int findVarianceWithFixedMajorAndMinor(string& s, int major, int minor){
        if(major == minor || !freq[major] || !freq[minor]) return 0;

        int majorCount = 0, minorCount = 0, mx = 0;
        int restMinorCount = freq[minor];
        for(auto& ch: s){
            if(ch - 'a' == major) majorCount++;
            if(ch - 'a' == minor){
                minorCount++;
                restMinorCount--;
            }

            if(minorCount > 0){
                mx = max(mx, majorCount - minorCount);
            }

            if(majorCount < minorCount && restMinorCount){
                majorCount = minorCount = 0;
            }
        }
        
        return mx;
    }
public:
    int largestVariance(string s) {
        
        findFrequencies(s);

        int globalMax = 0;
        for(int major = 0; major < 26; major++){
            for(int minor = 0; minor < 26; minor++){
                globalMax = max(globalMax, findVarianceWithFixedMajorAndMinor(s, major, minor));
            }
        }

        return globalMax;
    }
};
