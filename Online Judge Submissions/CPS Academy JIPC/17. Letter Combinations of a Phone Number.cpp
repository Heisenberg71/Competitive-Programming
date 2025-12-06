class Solution {
private:
    vector<string> allLetterCombinations;
    unordered_map<char, string> number_alphabetsMap = {
                   {'2', "abc"}, {'3', "def"}, 
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void findAllCombinations(int position, string digits, string prefixWord) {
        if(position == digits.size()) {
            allLetterCombinations.push_back(prefixWord);
            return;
        }

        int currentDigit = digits[position];
        string alphabets = number_alphabetsMap[currentDigit];
        for(int i = 0; i < alphabets.size(); i++) {
            findAllCombinations(position + 1, digits, prefixWord + alphabets[i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        findAllCombinations(0, digits, "");
        return allLetterCombinations;
    }
};
