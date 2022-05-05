#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

stack <int> stk;
vector <int> rem;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                stk.push(i);
            }
            else{
                if(!stk.empty()) stk.pop();
                else rem.pb(i);
            }
        }
        while(!stk.empty()){
            rem.pb(stk.top());
            stk.pop();
        }
        int minLen = rem.size();
        rem.pb(0), rem.pb(str.size() - 1);
        sort(rem.begin(), rem.end());

        int minOperation = 0;
        for(int i = 1; i < rem.size(); i++){
            if(rem[i - 1] + 1 < rem[i]) minOperation++;
        }

        cout << minLen << " " << minOperation << "\n";
        rem.clear();
    }

    return 0;
}
