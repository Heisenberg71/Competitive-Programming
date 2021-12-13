#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 10000000
using namespace std;
bool status[LIM+5];
vector <ll> v;
void make_prime()
{
    ll i, j;

    status[0] = 1, status[1] = 1;
    for(i = 4; i <= LIM; i+=2)
        status[i] = 1;

    for(i = 3; i*i <= LIM; i+=2){
        if(status[i] == 0){
            for(j = i*i; j <= LIM; j += i+i)
                status[j] = 1;
        }
    }

    for(i = 0; i <= LIM; i++)
        if(status[i] == 0) v.pb(i);

//    for(i = 0; i < v.size(); i++)
//        cout << v[i] << endl;

}
int main()
{
    make_prime();
    ll t, a, b, n, cas = 1, cnt, i;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        for(i = 0; v[i] <= n/2 and i < v.size(); i++){
            if(status[n-v[i]] == 0) cnt++;
        }
        printf("Case %lld: %lld\n", cas++, cnt);
    }
    return 0;
}

