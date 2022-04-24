#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl "\n"
using namespace std;
 
ll prefSum[LIM];
 
int main()
{
    int n, q;
 
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefSum[i] = prefSum[i - 1] + x;
    }
 
    while(q--){
        int L, R;
        cin >> L >> R;
        cout << prefSum[R] - prefSum[L - 1] << nl;
    }
 
    return 0;
}
