#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define LIM 100005
#define MOD 1000000007
using namespace std;

vector <pll> graph[LIM];
ll n, m;
ll vis[LIM], min_price[LIM], routes[LIM], min_flight[LIM], max_flight[LIM], can_reachn[LIM];

int main()
{
   int i,j,x;
   cin>>n>>m;
   int a,b,c;
   for(int i = 0; i < m; i++){
       cin>>a>>b>>c;
       graph[a].pb({b,c});
   }

   memset(vis, -1, sizeof vis);
   memset(min_price, -1, sizeof min_price);
   memset(routes, 0, sizeof routes);
   memset(min_flight, -1, sizeof min_flight);
   memset(max_flight, -1, sizeof max_flight);
   memset(can_reachn, -1, sizeof can_reachn);


   min_price[1]=0;
   routes[1]=1;
   min_flight[1]=0;
   max_flight[1]=0;
   priority_queue<pll,vector <pll>,greater<pll>> q;

   q.push({0,1});
   while(!q.empty()){
   	int x=q.top().ss;
   	q.pop();
   	if(vis[x]!=-1)continue;
   	vis[x]=1;
   	for(int i = 0; i < graph[x].size(); i++){
        pll aa = graph[x][i];
   		if(vis[aa.ff]==1)continue;
   		if(min_price[aa.ff]==-1||min_price[aa.ff]>min_price[x]+aa.ss){
   				min_price[aa.ff]=min_price[x]+aa.ss;
				routes[aa.ff]=routes[x];
				min_flight[aa.ff]=min_flight[x]+1;
				max_flight[aa.ff]=max_flight[x]+1;
				q.push({min_price[aa.ff],aa.ff});
   		}
   		else if(min_price[aa.ff]==min_price[x]+aa.ss){
   				routes[aa.ff]+=routes[x];
				routes[aa.ff]%=MOD;
				min_flight[aa.ff]=min(min_flight[aa.ff],min_flight[x]+1);
				max_flight[aa.ff]=max(max_flight[aa.ff],max_flight[x]+1);
				q.push({min_price[aa.ff],aa.ff});
   		}

   	}

   }

   cout<<min_price[n]<<" "<<routes[n]<<" "<<min_flight[n]<<" "<<max_flight[n]<<endl;

    return 0;
}
