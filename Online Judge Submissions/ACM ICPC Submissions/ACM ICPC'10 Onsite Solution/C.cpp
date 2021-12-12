#include <bits/stdc++.h>
#define ll long long
#define MAXX 2000000009
using namespace std;

vector <ll> fib;

void makeFib()
{
    fib.push_back(1);
    fib.push_back(2);

    while(fib[fib.size() - 1] + fib[fib.size() - 2] <= MAXX){
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    reverse(fib.begin(), fib.end());
}

int main()
{
    makeFib();

    int t, cas = 1, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll ans = 1;
        while(n--){
            int val, cnt = 0;
            scanf("%d", &val);
            while(val){
                for(int i = 0; i < fib.size(); i++){
                    if(fib[i] <= val){
                        val -= fib[i];
                        break;
                    }
                }
                cnt++;
            }
            ans *= cnt;
        }
        printf("Case %d: %lld\n",cas++, ans);
    }

    return 0;
}
