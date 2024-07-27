class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut;

        for(int i = 0; i < n + 1; i++){
            cut.push_back(i - 1);
        }

        for(int i = 0; i < n; i++){
            for(int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; j--, k++){
                cut[k + 1] = min(cut[k + 1], 1 + cut[j]);
            }
            for(int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; j--, k++){
                cut[k + 1] = min(cut[k + 1], 1 + cut[j]);
            }
        }

        return cut[n];
    }
};
