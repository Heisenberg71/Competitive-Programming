#include <bits/stdc++.h>
#define ll long long
#define LIM 100005
using namespace std;

int trie[LIM][10], endpoint[LIM], prefix[LIM];
int cnt = 2;

void add(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = s[i] - '0';
        if(!trie[u][edg]){
            trie[u][edg] = cnt++;
        }
        u = trie[u][edg];
        prefix[u]++;
    }
    endpoint[u] = 1;
}

bool query(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = s[i] - '0';
        if(trie[u][edg]){
            u = trie[u][edg];
        }
        else return 1;
        if(endpoint[u]) return 0;
    }
    return (prefix[u] == 0);
}

void reset(int u)
{
    for(int i = 0; i < 10; i++){
        if(trie[u][i]) reset(trie[u][i]);
        trie[u][i] = endpoint[u] = prefix[u] = 0;
    }

}

int main()
{
    int t, cas = 1, n;
    char str[15];
    string s;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool ans = 1;
        cnt = 2;
        while(n--){
            getchar();
            scanf("%s", str);
            s = str;
            ans &= query(s);
            add(s);
        }
        printf("Case %d: ", cas++);
        if(ans) printf("YES\n");
        else printf("NO\n");

        reset(1);
    }

    return 0;
}
