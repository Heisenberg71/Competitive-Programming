#include <bits/stdc++.h>
#define ll long long
#define LIM 10005
#define mod 100000007
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, m, zero;

bool status[LIM]; /// NEED A GLOBAL ARRAY
vector <int> prime;
vector <pair<int,int> > prime_pow;

void make_prime(int N)
{
    int i, j, sqrtN;
    status[0] = 1, status[1] = 1;
    sqrtN = int( sqrt((double) N )) + 1; /// have to check primes up to (sqrt(N))
    for(i = 4; i <= N; i+=2) status[i] = 1;
    for(i = 3; i <= sqrtN; i+= 2){  /// so, i is a prime, so, discard all the multiples
        if(status[i] == 0){
            for(j = i*i; j <= N; j+=i+i) /// j = i * i, because it's the first number to be colored
                status[j] = 1;
        }
    }
    for(i = 0; i < LIM; i++) if(status[i] == 0) prime.pb(i);
    //for(i = 0; i < 10000005; i++) cout << v[i] << endl;
}

void factor(int n)
{
    for(int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++){
        int cnt = 0;
        while(n%prime[i] == 0){
            n /= prime[i];
            cnt++;
        }
        if(cnt) prime_pow.pb({prime[i], cnt*m});
    }
    if(n != 1) prime_pow.pb({n, 1*m});
}

int main()
{
    make_prime(LIM);

    int i, j, cas = 1;
    while(cin >> n >> m >> zero){
        if(!n) break;
        factor(n);
        ll ans = 0;
        for(i = 0; i < prime_pow.size(); i++){
            ll tem = prime_pow[i].ss/zero - prime_pow[i].ss/(zero+1);
            //cout << tem << " 1 " << endl;
            for(j = i+1; j < prime_pow.size(); j++){
                tem *= (prime_pow[j].ss/zero + 1);
                tem %= mod;
            }

            for(j = i-1; j >= 0; j--){
                tem *= ((prime_pow[j].ss/(zero+1))+1) % mod;
                tem %= mod;
            }
            //cout << tem << " 2" << endl;
            ans += tem;
            ans %= mod;
        }
        printf("Case %d: %lld\n", cas++, ans);
        prime_pow.clear();
    }
    return 0;
}
