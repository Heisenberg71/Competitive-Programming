#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll dp[55][2][55];
ll eval(ll pos, ll isvowel, ll cnt){
    if(isvowel == 1 and cnt == 3) return 0;
    if(isvowel == 0 and cnt == 5) return 0;
    if(pos == s.size()) return 1;
    return dp[pos][isvowel][cnt];
}
ll f()
{
    //cout << pos << " " << isvowel << " " << cnt << endl;
    //if(isvowel == 1 and cnt == 3) return 0;
    //if(isvowel == 0 and cnt == 5) return 0;
    //if(pos == s.size()) return 1;
    //if(dp[pos][isvowel][cnt] != -1) return dp[pos][isvowel][cnt];
    for(ll pos = s.size()-1; pos >= 0; pos--){
        for(ll isvowel = 0; isvowel < 2; isvowel++){
            for(ll cnt = 0; cnt < 55; cnt++){
                ll a, b;
                if(s[pos] == 'A'){
                    if(isvowel)
                        a = eval(pos+1, 1, cnt+1);
                    else
                        a = eval(pos+1, 1, 1);
                    dp[pos][isvowel][cnt] = a;
                }
                else if(s[pos] == 'B'){
                    if(isvowel)
                        a = eval(pos+1, 0, 1);
                    else
                        a = eval(pos+1, 0, cnt+1);
                    dp[pos][isvowel][cnt] = a;
                }
                else{
                    if(isvowel)
                        a = eval(pos+1, 1, cnt+1);
                    else
                        a = eval(pos+1, 1, 1);
                    if(isvowel)
                        b = eval(pos+1, 0, 1);
                    else
                        b = eval(pos+1, 0, cnt+1);
                    if(a == 2 or b == 2)
                        dp[pos][isvowel][cnt] = 2;
                    else if((a == 0 and b == 1) or (a == 1 and b == 0))
                        dp[pos][isvowel][cnt] = 2;
                    else dp[pos][isvowel][cnt] = a;
                }
            }
        }
    }
    return dp[0][0][0];
}
int main()
{
    ll t, i, cas = 1;
    cin >> t;
    while(t--){
        cin >> s;
        for(i = 0; i < s.size(); i++){
            if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
                s[i] = 'A';
            else if(s[i] == '?');
            else s[i] = 'B';
        }
        memset(dp,0,sizeof(dp));
        ll val = f();
        printf("Case %lld: ", cas++);
        //cout << val << endl;
        if(val == 0) cout << "BAD" << endl;
        else if(val == 1) cout << "GOOD" << endl;
        else cout << "MIXED" << endl;
    }
    return 0;
}
