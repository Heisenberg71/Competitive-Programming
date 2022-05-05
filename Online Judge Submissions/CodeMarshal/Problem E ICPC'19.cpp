#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define LIM 20005
using namespace std;
struct abc{
    ll xx, yy, weight;
}edges[LIM];
ll vis[LIM], visited[LIM];
vector <ll> v[LIM], w[LIM];
vector <pair<ll,ll> > freq_val;
bool cmp(pair <ll,ll> x, pair<ll,ll> y)
{
    if(x.ff == y.ff) return x.ss > y.ss;
    return x.ff > y.ff;
}
ll dfs(ll node)
{
    ll cnt = 0; visited[node] = 1;
    for(ll i = 0; i < v[node].size(); i++){
        if(!visited[v[node][i]]){
            cnt += dfs(v[node][i]);
        }
    }
    return vis[node] = cnt + 1;
}
int main()
{
    ll t, n, i, j, cas = 1, x, y, wei;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n-1; i++){
            cin >> x >> y >> wei;
            edges[i] = {x,y,wei};
            v[x].pb(y), w[x].pb(wei);
            v[y].pb(x), w[y].pb(wei);
        }
        x = dfs(1);
//        for(i = 1; i <= n; i++)
//            cout << vis[i] << " ";
//        cout << endl;
        ll sum = 0, value;
        for(i = 0; i < n-1; i++){
            if(vis[edges[i].xx] < vis[edges[i].yy]){
                sum += edges[i].weight*vis[edges[i].xx]*(n-vis[edges[i].xx]);
                if(edges[i].weight < 0) freq_val.pb({vis[edges[i].xx]*(n-vis[edges[i].xx]),-edges[i].weight});
                //mx_fre = max(mx_fre,vis[edges[i].xx]*(n-vis[edges[i].xx]));
            }
            else{
                sum += edges[i].weight*vis[edges[i].yy]*(n-vis[edges[i].yy]);
                if(edges[i].weight < 0) freq_val.pb({vis[edges[i].yy]*(n-vis[edges[i].yy]),-edges[i].weight});
                    //mx_fre = max(mx_fre,vis[edges[i].yy]*(n-vis[edges[i].yy]));
            }
        }
        //cout << sum << " " << mx_fre << endl;
        printf("Case %lld: ", cas++);
        if(sum >= 0) cout << 0 << endl;
        else{
           // cout << (abs(sum)+mx_fre-1)/mx_fre <<endl;
           sum = -sum;
           sort(freq_val.begin(),freq_val.end(), cmp);
           ll ans = 0;
           for(i = 0; i < freq_val.size(); i++){
               ll freq = freq_val[i].ff;
               ll val = freq_val[i].ss;
                //cout << freq << " " << val << endl;
               if(val < (sum+freq-1)/freq) ans += val, sum -= val*freq;
               else{
                    ans += (sum+freq-1)/freq;
                    break;
               }
           }
           cout << ans << endl;
        }
        for(i = 1; i <= n; i++){
            vis[i] = visited[i] = 0;
            v[i].clear(), w[i].clear();
        }
        freq_val.clear();
    }
    return 0;
}
