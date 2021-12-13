#include <bits/stdc++.h>
#define ull unsigned long long
#define pb push_back
#define LIM 3000005
using namespace std;
ull phi[LIM], ans[LIM];
void divi()
{
    ull i, j;

    for(i = 2; i < LIM; i++){
        for(j = i; j < LIM; j += i){
            ans[j] += j*((i*phi[i])/2);
        }
    }
}
void ETF()
{
    ull i, j;

    for(i = 0; i < LIM; i++)
        phi[i] = i;

    for(i = 2; i < LIM; i++){
        if(phi[i] == i){
            for(j = i; j < LIM; j += i)
                phi[j] = (phi[j]/i)*(i-1);
        }
    }

//    for(i = 0; i < LIM; i++){
//        cout << i << ": " << phi[i] << endl;
//    }

}

void GCD()
{
    ull i;

    for(i = 1; i < LIM; i++)
        ans[i] += ans[i-1];

}
int main()
{
    ETF();
    divi();
    GCD();
    ull t, n, i, cas = 1;
    cin >> t;
    while(t--){
        scanf("%llu", &n);
        printf("Case %llu: %llu\n", cas++, ans[n]);
    }
    return 0;
}
