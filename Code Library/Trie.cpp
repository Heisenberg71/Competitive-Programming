string s;
int n, trie[LIM][15], cnt = 2;
bool flag[LIM], endpoint[LIM];

void add()
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = s[i] - '0';
        if(!trie[u][edg]){
            trie[u][edg] = cnt++;
        }
        u = trie[u][edg];
        flag[u] = 1;
    }
    endpoint[u] = 1;
}

bool query()
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = s[i] - '0';
        if(trie[u][edg])
           u = trie[u][edg];
        else
            return 1;
        if(endpoint[u]) return 0;
    }

    return (flag[u] == 0);
}

void reset(int u)
{
    for(int i = 0; i < 10; i++){
        if(trie[u][i]) reset(trie[u][i]);
        trie[u][i] = flag[u] = endpoint[u] = 0;
    }
}
