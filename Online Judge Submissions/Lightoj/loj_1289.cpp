#include <bits/stdc++.h>
#define ll unsigned int
#define LIM 100000000
#define mod 4294967295
#define pb push_back
#define ff first
#define ss second
using namespace std;
ll status[LIM/32+2], it;
//vector <pair<ll,ll> > pos_val;
struct ab{
    ll a, b;
};
ab pos_value[5762859+5];
bool check(ll n, ll pos){ return (bool)(n & (1<<pos));}
ll mark(ll n, ll pos){ return n = (n | (1<<pos));}
bool overflow(ll a, ll b)
{
    ll res = a*b;
    if(res/a == b) return 0;
    return 1;
}
bool cmp(ab x, ab y)
{
    return x.a < y.a;
}
void make_prime()
{
    ll i, j, sq, pre;
    ll tem;
    sq = sqrt(LIM);
    for(i = 3; i <= sq; i+=2){
        if(check(status[i/32],i%32) == 0){
            for(j = i*i; j <= LIM; j += i+i){
                status[j/32] = mark(status[j/32],j%32);
            }
        }
    }
    i = tem = 2;
    while(tem <= LIM){
        //pos_val.pb({tem,i});
        pos_value[it].a = tem;
        pos_value[it].b = i;
        it++;
        if(overflow(i,tem)) break;
        tem *= i;
    }
    for(i = 3; i <=LIM; i+=2){
        if(check(status[i/32],i%32) == 0){
            tem = i;
            while(tem <= LIM){
                //pos_val.pb({tem,i});
                pos_value[it].a = tem;
                pos_value[it].b = i;
                it++;
                if(overflow(i,tem)) break;
                tem *= i;
            }
        }
    }

    sort(pos_value,pos_value+it,cmp);
    for(i = 1; i < it; i++){
        //ll tem = ((pos_val[i-1].ss%mod)*(pos_val[i].ss%mod))%mod;
        ll tem = pos_value[i-1].b*pos_value[i].b;
        pos_value[i].b = tem;
       // cout << i << " " << tem << endl;
    }
}
ll lb(ll n)
{
    ll lo = 0, hi = it, md;
    while(lo<hi){
        md = (lo+hi)/2;
        if(n < pos_value[md].a) hi = md;
        else lo = md+1;
    }
    return pos_value[lo-1].b;
}
int main()
{
    make_prime();
    ll t, n, cas = 1;
    scanf("%u", &t);
    while(t--){
        scanf("%u", &n);
        printf("Case %u: %u\n", cas++, lb(n));
    }
    return 0;
}
