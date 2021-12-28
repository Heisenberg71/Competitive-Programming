#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 100005
using namespace std;

struct abc{
    int left, right, idx;
};

int arr[LIM], cnt[LIM], ans[LIM], distinct, blockSize;
vector <abc> query;

bool cmp(abc x, abc y)
{
    int blockX = x.left/blockSize;
    int blockY = y.left/blockSize;
    if(blockX == blockY) return x.right < y.right;
    return blockX < blockY;
}

void add(int idx)
{
    cnt[ arr[idx] ]++;
    if(cnt[ arr[idx] ] == 1) distinct++;
}

void remov(int idx)
{
    cnt[ arr[idx] ]--;
    if(cnt[ arr[idx] ] == 0) distinct--;
}

void reset(int n)
{
    query.clear();
    for(int i = 0; i < n; i++)
        cnt[ arr[i] ] = 0;
}

int main()
{
    int t, cas = 1, n, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &q);
        blockSize = sqrt(n) + 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < q; i++){
            int L, R;
            scanf("%d %d", &L, &R);
            L--, R--;
            query.pb({L, R, i});
        }
        sort(query.begin(), query.end(), cmp);
      
        int L = 0, R = -1;
        distinct = 0;
        for(int i = 0; i < q; i++){
            while(query[i].left < L) add(--L);
            while(query[i].left > L) remov(L++);
            while(query[i].right < R) remov(R--);
            while(query[i].right > R) add(++R);
            ans[ query[i].idx ] = distinct;
        }

        printf("Case %d:\n", cas++);
        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);

        reset(n);
    }

    return 0;
}
