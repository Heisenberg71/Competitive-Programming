class WordFilter {
private:
    class TrieNode{
        public:
        bool hasEnd = false;
        int maxWordLength = 0;
        TrieNode* next[27][27];
    };

    TrieNode* root;
    void insert(string& word, TrieNode* root, int index) {
        auto currNode = root;
        for(int i = 0; i < word.size(); i++){
            int prefWord = word[i] - 'a';
            int sufWord = word[ word.size() - i - 1 ] - 'a';

           // cout << prefix[i] << " " << suffix[i] << '\n';
        //    cout <<  word[i] << " " << word[ word.size() - i - 1 ] << '\n';
            // cout << (currNode -> next[prefWord][sufWord] == NULL) << '\n';

            if(currNode -> next[prefWord][sufWord] == NULL)
                currNode -> next[prefWord][sufWord] = new TrieNode();
            currNode = currNode -> next[prefWord][sufWord];

            currNode -> maxWordLength = index;
        }
        currNode -> hasEnd = true;
    }

    int search(string& prefix, string& suffix) {
        auto currNode = root;
        for(int i = 0; i < max(prefix.size(), suffix.size()); i++) {

            int prefWord = (i < prefix.size()) ? prefix[i] - 'a' : 26;
            int sufWord =  (suffix.size() - 1 - i >= 0) ? suffix[suffix.size() - 1 - i] - 'a' : 26;
            // cout << prefix[i] << " " << suffix[suffix.size() - 1 - i] << '\n';
            // cout << (currNode -> next[prefWord][sufWord] == NULL) << '\n';
            if(currNode -> next[prefWord][sufWord] == NULL) return -1;
            currNode = currNode -> next[prefWord][sufWord];
        }
        return currNode -> maxWordLength;
    }

public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        int index = 0;
        for(auto& word: words){
            insert(word, root, index++);
        }
    }
    
    int f(string pref, string suff) {
        return search(pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
