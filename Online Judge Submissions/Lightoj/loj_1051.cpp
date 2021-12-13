#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll dp[55][2][55];
ll f(ll pos, ll isvowel, ll cnt)
{
    //cout << pos << " " << isvowel << " " << cnt << endl;
    if(isvowel == 1 and cnt == 3) return 0;
    if(isvowel == 0 and cnt == 5) return 0;
    if(pos == s.size()) return 1;
    if(dp[pos][isvowel][cnt] != -1) return dp[pos][isvowel][cnt];

    ll a, b;
    if(s[pos] == 'A'){
        if(isvowel)
            a = f(pos+1, 1, cnt+1);
        else
            a = f(pos+1, 1, 1);
        return dp[pos][isvowel][cnt] = a;
    }
    else if(s[pos] == 'B'){
        if(isvowel)
            a = f(pos+1, 0, 1);
        else
            a = f(pos+1, 0, cnt+1);
        return dp[pos][isvowel][cnt] = a;
    }
    else{
        if(isvowel)
            a = f(pos+1, 1, cnt+1);
        else
            a = f(pos+1, 1, 1);
        if(isvowel)
            b = f(pos+1, 0, 1);
        else
            b = f(pos+1, 0, cnt+1);
        if(a == 2 or b == 2)
            return dp[pos][isvowel][cnt] = 2;
        if((a == 0 and b == 1) or (a == 1 and b == 0))
            return dp[pos][isvowel][cnt] = 2;
        return dp[pos][isvowel][cnt] = a;
    }
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
        memset(dp,-1,sizeof(dp));
        ll val = f(0,0,0);
        printf("Case %lld: ", cas++);
        //cout << val << endl;
        if(val == 0) cout << "BAD" << endl;
        else if(val == 1) cout << "GOOD" << endl;
        else cout << "MIXED" << endl;
    }
    return 0;
}
