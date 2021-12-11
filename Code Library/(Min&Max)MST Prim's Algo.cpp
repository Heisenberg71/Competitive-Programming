#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define INF 1e9
#define pll pair<ll, ll>
using namespace std;
vector <pll> V[105];
ll n; /// num of total nodes
struct Node{
    ll u, cost;
    Node() {}  /// default constructor
    Node(ll _u, ll _cost){
        u = _u;
        cost = _cost;
    }
};

bool operator < (Node A, Node B){
    /// priority_queue is a max heap.
    /// so we need to compare the cost
    /// in reverse order to get minimum
    /// cost vertex at top.
    return A.cost > B.cost;
}


ll min_prim(ll s) /// the starting node
{
    /// weighted adjacency list
    /// first element neighboring node
    /// second element weight of the edge
    priority_queue<Node> pq;

    ll cost[105]; /// minimum cost so far for a node.
    ll  taken[105]; /// if the node is already taken.
    /// n = number of nodes.
    /// INF = infinite, something like 10^9.
    for(ll i = 0; i < n; i++) /// considering all Nodes are 0 to n-1
        cost[i] = INF, taken[i] = 0;
    cost[s] = 0;
    pq.push(Node(s,0));
    ll ans = 0; /// cost of MST
    while(!pq.empty()){
        Node x = pq.top();
        pq.pop();

        if(taken[x.u]){
            /// already visited.
            continue;
        }
        taken[x.u] = 1;
        ans += x.cost;
        for(ll i = 0; i < V[x.u].size(); i++){
            pll v = V[x.u][i];
            if(taken[v.ff]) continue; /// if the edge leads to previously visited node
            if(v.second < cost[v.ff]){
                /// cost of current edge to v.first
                /// is less than whatever we saw
                /// so far.
                pq.push(Node(v.ff,v.ss));
                cost[v.ff] = v.ss;
            }
        }
    }
    return ans;
}
};

struct Node2{
    ll u, cost;
    Node2() {}  /// default constructor
    Node2(ll _u, ll _cost){
        u = _u;
        cost = _cost;
    }
};

bool operator < (Node2 A, Node2 B){
    /// priority_queue is a max heap.
    /// so we need to compare the cost
    /// in reverse order to get minimum
    /// cost vertex at top.
    return A.cost < B.cost;
}

ll max_prim(ll s) /// the starting node
{
    /// weighted adjacency list
    /// first element neighboring node
    /// second element weight of the edge
    priority_queue<Node2> pq;

    ll cost[105]; /// minimum cost so far for a node.
    ll  taken[105]; /// if the node is already taken.
    /// n = number of nodes.
    /// INF = infinite, something like 10^9.
    for(ll i = 0; i < n; i++) /// considering all Nodes are 0 to n-1
        cost[i] = -INF, taken[i] = 0;
    cost[s] = 0;
    pq.push(Node2(s,0));
    ll ans = 0; /// cost of MST
    while(!pq.empty()){
        Node2 x = pq.top();
        pq.pop();

        if(taken[x.u]){
            /// already visited.
            continue;
        }
        taken[x.u] = 1;
        ans += x.cost;
//        ll xx = x.u, yy;
        for(ll i = 0; i < V[x.u].size(); i++){
            pll v = V[x.u][i];
            if(taken[v.ff]) continue; /// if the edge leads to previously visited node
            if(v.second > cost[v.ff]){
                /// cost of current edge to v.first
                /// is less than whatever we saw
                /// so far.
                pq.push(Node2(v.ff,v.ss));
                cost[v.ff] = v.ss;
            }
        }
    }
    return ans;
}
