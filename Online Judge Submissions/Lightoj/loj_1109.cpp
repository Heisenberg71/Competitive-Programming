#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define LIM 1000
using namespace std;
vector <pair<ll,ll> > v;
bool status[LIM+5];
ll nod[LIM+5];
void NOD()
{
    ll i, j, tem, cnt;
    for(i = 0; i <= LIM; i++)
        nod[i] = 1;
    for(i = 4; i <= LIM; i+=2){
        status[i] = 1;
        tem = i;
        cnt = 0;
        while(tem%2 == 0){
            tem /= 2;
            cnt++;
        }
        nod[i] *= (cnt+1);
    }
    for(i = 3; i <= LIM; i+=2){
        if(status[i] == 0){
            for(j = i+i; j <= LIM; j += i){
                status[j] = 1;
                tem = j;
                cnt = 0;
                while(tem%i == 0){
                    tem /= i;
                    cnt++;
                }
                nod[j] *= (cnt+1);
            }
        }
    }
    nod[0] = 0, nod[1] = 0;
}

bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    if(x.ss < y.ss) return 1;
    if(x.ss == y.ss and y.ff < x.ff) return 1;
    return 0;
}
int main()
{
    NOD();
    ll t, n, i, cas = 1;
    for(i = 1; i <= 1000; i++){
        v.pb({i,nod[i]});
    }
    sort(v.begin(),v.end(),cmp);
    cin >> t;
    while(t--){
        cin >> n;
        printf("Case %lld: %lld\n", cas++, v[n-1].ff);
    }
    return 0;
}
