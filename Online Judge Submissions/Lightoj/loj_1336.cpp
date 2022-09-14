#include <bits/stdc++.h>
#define ll long long
#define LIM 1000000000000 //(10^12)
#define eps 1e-9
#define pb push_back
using namespace std;
/*
ll arr[4000000+5], brr[4000000+5], l;
bool overflow(ll a, ll b)
{
    ll res = a*b;
    if(b == res/a) return 1;
    return 0;
}
void make_div()
{
    ll i, j, k = 0;
    for(i  = 1; i <= LIM; i *= 2){
        for(j = 1; j*j <= LIM; j++){
            ll tem = j*j;
            if(overflow(i,tem) and i*tem <= LIM) arr[k] = tem*i, k++;
        }
    }
    sort(arr,arr+k);
    arr[k] = -1;
    for(i = l = 0; i < k; i++)
        if(arr[i] != arr[i+1]) brr[l] = arr[i], l++;
}
ll lb(ll x)
{
    ll lo = 0, hi = l, md;
    while(lo<hi){
        md = (lo+hi)/2;
        if(x <= brr[md]) hi = md;
        else lo = md+1;
    }
    if(lo < l and brr[lo] == x) return lo;
    return lo-1;
}
*/
int main()
{
    ll t, cas = 1, n, i, tem;
//    make_div();
    cin >> t;
    while(t--){
        cin >> n;
//        printf("Case %lld: %lld\n", cas++, n-lb(n)-1);
        //tem = (sqrt(n*1.0)+sqrt(n/2.0)+eps);
        //tem += ;
        ll tem = sqrt(n*1.0);
        tem += sqrt(n/2.0);
        printf("Case %lld: %lld\n", cas++, n-tem);
    }
    return 0;
}
