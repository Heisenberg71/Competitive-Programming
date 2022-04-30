#include <bits/stdc++.h>
#define ll long long
#define LIM 200005
#define nl "\n"
using namespace std;

ll arr[LIM], sum[4*LIM], maxPrefSum[4*LIM], maxSuffSum[4*LIM], maxSubArrSum[4*LIM];

void update(int st, int ed, int nd, int pos, int val)
{
    if(pos < st || ed < pos) return;

    if(st == ed){
        sum[nd] = val;
        maxPrefSum[nd] = val;
        maxSuffSum[nd] = val;
        maxSubArrSum[nd] = val;
        return;
    }

    int md = st + (ed - st)/2;
    update(st, md, nd + nd, pos, val);
    update(md + 1, ed, nd + nd + 1, pos, val);

    sum[nd] = sum[nd + nd] + sum[nd + nd + 1];
    maxPrefSum[nd] = max(maxPrefSum[nd + nd], sum[nd + nd] + maxPrefSum[nd + nd + 1]);
    maxSuffSum[nd] = max(maxSuffSum[nd + nd + 1], sum[nd + nd + 1] + maxSuffSum[nd + nd]);
    maxSubArrSum[nd] = max(maxSubArrSum[nd + nd], max(maxSubArrSum[nd + nd + 1], maxSuffSum[nd + nd] + maxPrefSum[nd + nd + 1]));
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        update(0, n - 1, 1, i, arr[i]);
    }

    while(m--){
        int k, x;
        cin >> k >> x;
        update(0, n - 1, 1, k - 1, x);
        cout << max(0LL, maxSubArrSum[1]) << nl;
    }

    return 0;
}
