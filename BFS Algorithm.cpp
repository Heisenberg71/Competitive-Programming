vector <int> v[105], seq;
int vis[1005];
void bfs(int st)
{
    queue <int> q;
    memset(vis,127,sizeof vis);
    vis[st] = 0;
    q.push(st);
    while(!q.empty()){
            int u = q.front(); q.pop(); seq.pb(u);
            for(int i = 0; i < v[u].size(); i++){
                if(vis[u]+1 < vis[v[u][i]]){
                    vis[v[u][i]] = vis[u]+1;
                    q.push(v[u][i]);
                }
          }
    }
}
