#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000012
#define LIM 50005
using namespace std;

ll trie[LIM*32][2], power[35], ver = 2;

string conv(ll n)
{
    string s;
    for(int i = 0; i < 32; i++){
        s += n%2 + '0';
        n /= 2;
    }
    //reverse(s.begin(), s.end());
    //cout << s << endl;
    return s;
}

ll MIN(string &s)
{
    int u = 1, ans = 0;
    for(int i = 31; i >= 0; i--){
        int dig = s[i] - '0';
        if(trie[u][0] == 0 && trie[u][1] == 0) return inf;
        else if(dig == 0 && trie[u][0]){
            u = trie[u][0];
        }
        else if(dig == 0 && trie[u][1]){
            ans += power[i];
            u = trie[u][1];
        }
        else if(dig == 1 && trie[u][1]){
            u = trie[u][1];
        }
        else{
            ans += power[i];
            u = trie[u][0];
        }
    }

    return ans;
}

ll MAX(string &s)
{
    int u = 1, ans = 0;
    for(int i = 31; i >= 0; i--){
        int dig = s[i] - '0';
        //cout << dig;
        if(trie[u][0] == 0 && trie[u][1] == 0) return -inf;
        else if(dig == 0 && trie[u][1]){
            ans += power[i];
            u = trie[u][1];
        }
        else if(dig == 0 && trie[u][0]){
            u = trie[u][0];
        }
        else if(dig == 1 && trie[u][0]){
            ans += power[i];
            u = trie[u][0];
        }
        else{
            u = trie[u][1];
        }
    }
    //cout << endl << endl;
    //cout << ans << endl;
    return ans;
}

void add(string &s)
{
    int u = 1;
    for(int i = 31; i >= 0; i--){
        int edg = s[i] - '0';
        if(!trie[u][edg]){
            trie[u][edg] = ver++;
        }
        u = trie[u][edg];
    }
}

void reset(int u)
{
    for(int i = 0; i < 2; i++){
        if(trie[u][i]) reset(trie[u][i]);
        trie[u][i] = 0;
    }
}

void printTrie()
{
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 2; j++){
            cout << trie[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    power[0] = 1;
    for(int i = 1; i < 32; i++)
        power[i] = power[i - 1] * 2;

    ll t, cas = 1, arr[LIM], n, i;
    string s;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        arr[0] = 0;
        for(i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        ll mn = inf, mx = -inf, ans = 0;
        ver = 2;
        for(i = 0; i <= n; i++){
            ans ^= arr[i];
            s = conv(ans);
            //cout << MIN(s) << " std " << MAX(s) << endl;
            ll Min = MIN(s), Max = MAX(s);
            if(i) mn = min(mn, min(arr[i], Min));
            if(i) mx = max(mx, max(arr[i], Max));
            //cout << mx << " " << mn << endl;
            //printTrie();
            add(s);
        }
        printf("Case %lld: %lld %lld\n", cas++, mx, mn);

        reset(1);
    }
    return 0;
}
