#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll div(ll num)
{
    ll i, cnt = 0;
    for(i = 2; i*i <= num; i++){
        if(num%i == 0){
            if(num/i == i) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
int main()
{
    ll x;
    cin >> x;
    cout << div(x) << endl;
}
