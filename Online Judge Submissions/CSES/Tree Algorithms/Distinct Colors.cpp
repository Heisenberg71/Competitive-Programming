#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LIM 200005
#define nl '\n'
using namespace std;

int color[LIM], subTree[LIM], posSeq[LIM], ans[LIM], cnt[LIM], pos[LIM], distinct, blockSize;
vector <int> edge[LIM], seq, v;
map <int, int> ump;

struct abc{
    int Left, Right, idx;
};

bool cmp(abc x, abc y)
{
    //cout << blockSize << nl;
    int blockX = x.Left/blockSize;
    int blockY = y.Left/blockSize;
    if(blockX == blockY) return x.Right < y.Right;
    return blockX < blockY;
}

vector <abc> query;

void add(int idx)
{
    cnt[ color[ seq[ idx] ] ]++;
    if( cnt[ color[ seq[ idx] ] ] == 1) distinct++;
}

void remov(int idx)
{
     cnt[ color[ seq[ idx] ] ]--;
    if( cnt[ color[ seq[ idx] ] ] == 0) distinct--;
}

void dfs(int u, int pr)
{
//    cout << color[u] << " ";
    seq.pb(u);
    subTree[u] = 1;
    for(int i = 0; i < edge[u].size(); i++){
        int v = edge[u][i];
        if(v != pr){
            dfs(v, u);
            subTree[u] += subTree[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> color[i];
        v.pb(color[i]);
    }

    int coun = 1;
    for(int i = 0; i < n; i++)
        ump[ v[i] ] = coun++;

    for(int i = 1; i <= n; i++)
        color[i] = ump[ color[i] ];

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

//    for(int i = 1; i <= n; i++)
//        cout << color[i] << " ";
//    cout << nl;

    blockSize = sqrt(n) + 1;
    dfs(1, -1);// cout << nl;
    for(int i = 0; i < seq.size(); i++)
        posSeq[ seq[i] ] = i;

    for(int i = 1; i <= n; i++){
        query.pb({posSeq[i], posSeq[i] + subTree[i] - 1, i});
    }
    sort(query.begin(), query.end(), cmp);

    int L = 0, R = -1;
    for(int i = 0; i < n; i++){
        while(query[i].Left < L) add(--L);
        while(query[i].Left > L) remov(L++);
        while(query[i].Right < R) remov(R--);
        while(query[i].Right > R) add(++R);
        ans[ query[i].idx ] = distinct;
//        cout << L << " " << R << " " << distinct << nl;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;

    return 0;
}
