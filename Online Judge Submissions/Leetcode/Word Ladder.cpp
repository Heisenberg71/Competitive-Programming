class Solution {
private:
    map<string, bool> wordListContains;
    map<string, int> cost;
    int findShortestTransform(string& beginWord, string& endWord, vector<string>& wordList){
        queue<string> Q;
        Q.push(beginWord); 
        cost[beginWord] = 1;
        wordListContains[beginWord] = true;
        while(!Q.empty()){
            string currentWord = Q.front(); Q.pop();
            if(currentWord == endWord) return cost[currentWord];

            for(int pos = 0; pos < currentWord.size(); pos++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string nextWord = currentWord;
                    nextWord[pos] = ch;

                    if(wordListContains.find(nextWord) != wordListContains.end() && 
                        cost.find(nextWord) == cost.end()){
                        cost[nextWord] = cost[currentWord] + 1;
                        Q.push(nextWord);
                    }
                }
            }
        }

        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto& s: wordList){
            wordListContains[s] = true;
        }
        return findShortestTransform(beginWord, endWord, wordList);
    }
};
