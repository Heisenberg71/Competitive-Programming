#include <bits/stdc++.h>
#define ll long long
#define LIM 1000000
#define pb push_back
using namespace std;
bool status[LIM+5]; /// NEED A GLOBAL ARRAY
vector <ll> v;
void make_primes(ll N)
{
    ll i, j, sqrtN;
    status[0] = 1, status[1] = 1;
    sqrtN = sqrt(N); /// have to check primes up to (sqrt(N))
    for(i = 4; i <= N; i+=2) status[i] = 1;
    for(i = 3; i <= sqrtN; i+= 2){  /// so, i is a prime, so, discard all the multiples
        if(status[i] == 0){
            for(j = i*i; j <= N; j+=i+i) /// j = i * i, because it's the first number to be colored
                status[j] = 1;
        }
    }
    for(i = 0; i <= LIM; i++) if(status[i] == 0) v.pb(i);
    //for(i = 0; i < 10000005; i++) cout << v[i] << endl;
}

int main()
{
    make_primes(LIM);
    ll t, a, b, cas = 1, i, div, sq, cnt;
    cin >> t;
    while(t--){
        scanf("%lld %lld", &a, &b);
        printf("Case %lld: ", cas++);
        if(a <= b*b){
            printf("0\n");
        }
        else{
            div = 1, sq = sqrt(a);
            for(i = 0; v[i] <= sq; i++){
                cnt = 0;
                if(a%v[i] == 0){
                    while(a%v[i] == 0){
                        cnt++;
                        a /= v[i];
                    }
                    div *= (cnt+1);
                }
            }
            if(a != 1) div *= 2;
            if(div%2==1) div--;
            for(i = 1; i < b; i++)
                if(a%i == 0) div -= 2;
            printf("%lld\n", div/2);
        }
    }
    return 0;
}
