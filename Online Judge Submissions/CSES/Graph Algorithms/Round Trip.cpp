#include<bits/stdc++.h>
#define ll long long
#define infinity 1e15;
using namespace std;

vector<ll>edge[100005], cost[100005];
//map< pair<ll,ll>, ll >cost;
ll dis[100005];

priority_queue < pair <ll, ll>, vector < pair<ll, ll> >, greater< pair<ll, ll> > > pq;

void dijkstra(ll source,ll num_node)
{
    for(ll i=1LL; i<=num_node; i++)
    {
        dis[i]=infinity;
    }

    dis[source]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
        pair< ll, ll> p=pq.top();
        pq.pop();

        ll d=p.first;
        ll u=p.second;

        if(dis[u] < d) continue;

        for(ll i=0LL; i<edge[u].size(); i++)
        {
            ll v=edge[u][i];
            ll c=d + cost[u][i];

            if(c<dis[v])
            {
                dis[v]=c;
                pq.push({c,v});
            }
        }
    }
}

int main()
{
    ll num_node,num_edge,source;

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

//    cin>>num_node>>num_edge;
    scanf("%lld %lld", &num_node, &num_edge);

    for(ll i=0LL; i<num_edge; i++)
    {
        ll u,v,w;
//        cin>>u>>v>>w;
        scanf("%lld %lld %lld", &u, &v, &w);

        edge[u].push_back(v);
        cost[u].push_back(w);
    }


    source=1LL;
    dijkstra(source,num_node);

    for(ll i=1LL; i<=num_node; i++)
    {
//        cout<<dis[i]<<" ";
        printf("%lld ", dis[i]);
    }
    cout<< '\n';

    return 0;
}
