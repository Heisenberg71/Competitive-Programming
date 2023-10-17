class manacher{
public:
    vector<int> p;

    void run_manacher(string& s){
        int len = s.size(), L = 1, R = 1;
        p.assign(len, 1);
        for(int i = 1; i < len; i++){
            if(L + R - i >= 0 && L + R - i < len) p[i] = max(0, min(R - i, p[L + R - i]));
            else p[i] = max(0, R - i);
            while(i - p[i] >= 0 && i + p[i] < len && s[ i - p[i] ] == s[ i + p[i] ])
                p[i]++;
            if(i + p[i] > R){
                L = i - p[i];
                R = i + p[i];
            }
        }
        for(int i = 0; i < p.size(); i++)
            cout << p[i] << " ";
        cout << '\n';
    }

    void build(string& s){
        string transformedStr;
        for(auto& ch: s)
            transformedStr += (string("x") + ch);
        transformedStr += "x";

        run_manacher(transformedStr);
    }

    int getLongest(int center, int isOdd){
        int pos = 2*center + 1 + (!isOdd);
        return p[pos] - 1;
    }

    bool checkPalindrome(int L, int R){
        return (R - L + 1 <= getLongest((L + R)/2, (L&1) == (R&1)));
    }
}m;
