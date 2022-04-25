#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl "\n"
using namespace std;

int arr[LIM], logArray[LIM], table[LIM][20];

void build(int n)
{
    for(int i = 0; i < n; i++)
        table[i][0] = arr[i];

    logArray[1] = 0;
    for(int i = 2; i <= n; i++)
        logArray[i] = 1 + logArray[i/2];

    for(int j = 1; j < logArray[n] + 1; j++){
        for(int i = 0; i + (1 << (j - 1)) < n; i++){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R)
{
    int len = R - L + 1;
    int lg = logArray[len];
    return min(table[L][lg], table[R - (1 << lg) + 1][lg]);
}

int main()
{
    int n, q;

    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(n);

    while(q--){
        int L, R;
        cin >> L >> R;
        cout << query(L - 1, R - 1) << nl;
    }

    return 0;
}
