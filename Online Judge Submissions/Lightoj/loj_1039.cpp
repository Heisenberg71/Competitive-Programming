#include <bits/stdc++.h>
#define ll long long
using namespace std;
string st, ed;
ll n, forbidden[30][30][30];
ll updown[] = {1, -1};
struct trio{
    ll ff, ss, tt;
};
queue <trio> q;
void bfs()
{
    if(forbidden[st[0]-'a'][st[1]-'a'][st[2]-'a'] == -1){
        q.push({st[0]-'a',st[1]-'a',st[2]-'a'});
        forbidden[st[0]-'a'][st[1]-'a'][st[2]-'a'] = 0;
    }
    while(!q.empty()){
        ll a = q.front().ff;
        ll b = q.front().ss;
        ll c = q.front().tt; q.pop();
        for(ll i = 0; i < 3; i++){
            for(ll j = 0; j < 2; j++){
                ll aa = a, bb = b, cc = c;
                if(i == 0){
                    aa = (aa + updown[j]+26)%26;
                }
                else if(i == 1){
                    bb = (bb + updown[j]+26)%26;
                }
                else{
                    cc = (cc + updown[j]+26)%26;
                }
                if(forbidden[aa][bb][cc] == -1){
                    q.push({aa,bb,cc});
                    forbidden[aa][bb][cc] = 1 + forbidden[a][b][c];
                }
            }
        }
    }
}
int main()
{
    ll t, cas = 1, i, j, k;
    string s, s2, s3;
    cin >> t;
    while(t--){
        cin >> st >> ed;
        cin >> n;
        memset(forbidden,-1,sizeof(forbidden));
        while(n--){
            cin >> s >> s2 >> s3;
            for(i = 0; i < s.size(); i++){
                for(j = 0; j < s2.size(); j++){
                    for(k = 0; k < s3.size(); k++){
                        ll a = s[i]-'a', b = s2[j]-'a', c = s3[k]-'a';
                        forbidden[a][b][c] = -2;
                    }
                }
            }
        }
        bfs();
        if(forbidden[ed[0]-'a'][ed[1]-'a'][ed[2]-'a'] < 0) printf("Case %lld: -1\n", cas++);
        else printf("Case %lld: %lld\n", cas++, forbidden[ed[0]-'a'][ed[1]-'a'][ed[2]-'a']);
    }
    return 0;
}
