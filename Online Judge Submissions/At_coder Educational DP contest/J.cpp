#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, cnt[5];
double dp[305][305][305];
double prob(ll ck, ll one, ll two, ll three)
{
    if(ck == 0) return (1.0*(n-one-two-three))/n;
    else if(ck == 1) return (1.0*one)/n;
    else if(ck == 2) return (1.0*two)/n;
    else return (1.0*three)/n;
}
double f(ll one, ll two, ll three)
{
    if(!one and !two and !three) return 0;
    if(dp[one][two][three] != -1) return dp[one][two][three];

    return dp[one][two][three] = (1.0/(1-prob(0,one,two,three)))*
                                 (prob(0,one,two,three)+
                                  prob(1,one,two,three)*(1+f(one-1,two,three))+
                                  prob(2,one,two,three)*(1+f(one+1,two-1,three))+
                                  prob(3,one,two,three)*(1+f(one,two+1,three-1)));

}
int main()
{
    ll i, j, k, x;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        cnt[x]++;
    }
    for(i = 0; i < 305; i++)
        for(j = 0; j < 305; j++)
            for(k = 0; k < 305; k++)
                dp[i][j][k] = -1;
    printf("%0.12lf\n", f(cnt[1],cnt[2],cnt[3]));
    return 0;
}
