#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second

vector <int> v[1005], w[1005];
int arr[10005];

void dj(int dis, int node)
{
    priority_queue <pii, vector< pii >, greater<pii > > pq;
    pii up;
    memset(arr,127,sizeof arr);
    pq.push({dis,node}); arr[node] = 0;
    while(!pq.empty()){
        up = pq.top(); pq.pop();
        for(int i = 0; i < v[up.ss].size(); i++){
            int ver = v[up.ss][i];
            int wei = w[up.ss][i];
            if(wei+up.ff < arr[ver]){
                pq.push({wei+up.ff,ver});
                arr[ver] = wei+up.ff;
            }
        }
    }
}
