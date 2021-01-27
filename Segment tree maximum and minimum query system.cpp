ll arr[200005], grid[300005], grid3[300005];
ll max_sg_tree(ll st,ll ed, ll now)
{
    ll md = (st+ed)/2;
    if(st == ed){
        return grid[now] = arr[st];
    }
    if(grid[2*now+1] and grid[2*now+2]){
        return grid[now] = max(grid[2*now+1],grid[2*now+2]);
    }
    return grid[now] = max(max_sg_tree(md+1,ed,2*now+2),max_sg_tree(st,md,2*now+1));
}
ll min_sg_tree(ll st, ll ed, ll now)
{
    ll md = (st+ed)/2;
    if(st == ed){
        return grid3[now] = arr[st];
    }
    if(grid[2*now+1] and grid3[2*now+2]){
        return grid3[now] = min(grid3[2*now+1],grid3[2*now+2]);
    }
    return grid3[now] = min(min_sg_tree(md+1,ed,2*now+2),min_sg_tree(st,md,2*now+1));
}
ll max_ask(ll f, ll t, ll st, ll ed, ll now)
{
    ll md = (st+ed)/2;
    if(f <= st and ed <= t)
        return grid[now];
    else if((f < st and t < st) or (f > ed and t > ed))
        return -inf;
    else
        return max(max_ask(f,t,md+1,ed,2*now+2),max_ask(f,t,st,md,2*now+1));
}
ll min_ask(ll f, ll t, ll st, ll ed, ll now)
{
    ll md = (st+ed)/2;
    if(f <= st and ed <= t)
        return grid3[now];
    else if((f < st and t < st) or (f > ed and t > ed))
        return inf;
    else
        return min(min_ask(f,t,md+1,ed,2*now+2),min_ask(f,t,st,md,2*now+1));
}
