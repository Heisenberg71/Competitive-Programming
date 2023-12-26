/**

Problem Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

*/

class Solution {
    int MAX_CHAR_LIM = 26;
    bool isPossible(int shift, string& str1, string& str2){
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()){
            int a = (str1[i] - 'a' + shift) %MAX_CHAR_LIM;
            int b = str2[j] - 'a';
            if(str1[i] == str2[j] || a == b) j++;
            i++;
        }
        return (j == str2.size());
    }
public:
    bool canMakeSubsequence(string str1, string str2) {
        bool canMake = false;
        for(int shift = 0; shift < 2; shift++){
            canMake |= isPossible(shift, str1, str2);
        }
        return canMake;
    }
};
