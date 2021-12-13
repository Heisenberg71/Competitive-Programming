#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int mat[55][55], n, pr[55];
set <int> s;

struct abc{
    int w, x, y;
};

vector <abc> edg;

int findP(int u)
{
    if(pr[u] == u) return u;
    return pr[u] = findP(pr[u]);
}

void connect(int u, int v)
{
    u = findP(u);
    v = findP(v);
    if(u != v)
        pr[u] = v;
}

bool cmp(abc x, abc y)
{
    return x.w < y.w;
}

int MST()
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i+1;  j < n; j++){
            if(mat[i][j])
                edg.pb({mat[i][j], i, j});
        }
        pr[i] = i;
    }
    sort(edg.begin(), edg.end(), cmp);
    int cost = 0;
    for(i = 0; i < edg.size(); i++){
        int u = findP(edg[i].x);
        int v = findP(edg[i].y);
        if(u != v){
            connect(u, v);
            cost += edg[i].w;
        }
    }
    for(i = 0; i < n; i++){
        findP(i);
        s.insert(pr[i]);
    }

    edg.clear();

    if(s.size() == 1){
        s.clear();
        return cost;
    }
    else{
        s.clear();
        return -1;
    }
}

int main()
{
    int t, cas = 1, i, j;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                cin >> mat[i][j];
                ans += mat[i][j];
            }
        }


        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(mat[i][j] && mat[j][i]){
                    if(mat[i][j] < mat[j][i])
                        mat[j][i] = mat[i][j];
                    else
                        mat[i][j] = mat[j][i];
                }
                else if(mat[i][j] || mat[j][i]){
                    mat[i][j] = max(mat[i][j], mat[j][i]);
                    mat[j][i] = max(mat[i][j], mat[j][i]);
                }
            }
        }

        int mst = MST();
        printf("Case %d: ", cas++);
        if(mst == -1) printf("-1\n");
        else printf("%d\n", ans - mst);
    }
    return 0;
}
