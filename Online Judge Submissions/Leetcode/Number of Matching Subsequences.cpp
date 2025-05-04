class FileSystem {
private:
    unordered_map<string, string> fileLocationContentMap;
    class TrieNode {
        public:
            bool isEnd;
            unordered_map<string, TrieNode*> next;
            TrieNode() {
                isEnd = false;
            }
            ~TrieNode() {
                for(auto& u: next) {
                    delete u.second;
                }
            }
    };
    TrieNode* root;
public:
    FileSystem() {
        fileLocationContentMap.clear();
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {

        pair<string, TrieNode*> directoryLastNodePair = findLastDirectory(path);

        if(fileLocationContentMap.count(path)) return vector<string>(1, directoryLastNodePair.first);
        if(directoryLastNodePair.second -> next.size() == 0) return vector<string>(0);

        vector<string> fileFolderList;
        for(auto& x: directoryLastNodePair.second -> next) {
            fileFolderList.push_back(x.first);
        }
        
        sort(fileFolderList.begin(), fileFolderList.end());
        return fileFolderList;
    }
    
    void mkdir(string path) {
        findLastDirectory(path);
    }

    pair<string, TrieNode*> findLastDirectory(string path) {
        auto currentNode = root;
        string directory;
        for(char ch: path) {
            if(ch != '/') {
                directory += ch;
                continue;
            }

            if(currentNode -> next[directory] == NULL) currentNode -> next[directory] = new TrieNode();
            currentNode = currentNode -> next[directory];
            directory.clear();
        }

        if(directory != "") {
            if(currentNode -> next[directory] == NULL) currentNode -> next[directory] = new TrieNode();
            currentNode = currentNode -> next[directory];
        }
        return {directory, currentNode};
    }
    
    void addContentToFile(string filePath, string content) {
        mkdir(filePath);
        fileLocationContentMap[filePath] += content;
    }
    
    string readContentFromFile(string filePath) {
        if(!fileLocationContentMap.count(filePath)) return "";
        return fileLocationContentMap[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
