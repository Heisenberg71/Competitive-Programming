class Solution {
private:
    long long BASE = 26141059, MOD = 100000000007;
    long long BASE2 = 100007, MOD2 = 1000000009;
    int isContainDuplicateSubString(int len, string& s){

        long long hashValue = s[0] - 'a' + 1, baseLen = BASE;
        long long hashValue2 = s[0] - 'a' + 1, baseLen2 = BASE2;
        for(int i = 1; i < len; i++){
            hashValue = (hashValue*BASE + s[i] - 'a' + 1) %MOD;
            hashValue2 = (hashValue2*BASE2 + s[i] - 'a' + 1) %MOD2;
            baseLen = (baseLen*BASE) %MOD;
            baseLen2 = (baseLen2*BASE2) %MOD2;
        }
        
        int startIdx = -1;
        unordered_map<int, bool> isExist;
        unordered_map<int, bool> isExist2;
        isExist[hashValue] = true;
        isExist2[hashValue2] = true;
        for(int i = len; i < s.size(); i++){
            
            hashValue = (hashValue*BASE + s[i] - 'a' + 1) %MOD;
            hashValue = (hashValue - (baseLen*(s[i - len] - 'a' + 1)) %MOD + MOD) %MOD;

            hashValue2 = (hashValue2*BASE2 + s[i] - 'a' + 1) %MOD2;
            hashValue2 = (hashValue2 - (baseLen2*(s[i - len] - 'a' + 1)) %MOD2 + MOD2) %MOD2;

            if(isExist.count(hashValue) && isExist2.count(hashValue2)) startIdx = i - len + 1;
            
            isExist[hashValue] = true;
            isExist2[hashValue2] = true;
        }

        return startIdx;
    }
public:
    string longestDupSubstring(string s) {

        int lo = 1, hi = s.size();
        int length = 0, startIndexForLargestString = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int startIndex = isContainDuplicateSubString(mid, s);
            if(startIndex != -1){
                length = mid;
                startIndexForLargestString = startIndex;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return (startIndexForLargestString == -1) ? "" : s.substr(startIndexForLargestString, length);
    }
};
