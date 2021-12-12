#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
using namespace std;

int trie[LIM][30], cnt = 2, fin[LIM];
string sstr;

void add(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i] - 'a';
        if(!trie[u][ch]){
            trie[u][ch] = cnt++;
        }
        u = trie[u][ch];
    }
    fin[u] = 1;
}

int query(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i] - 'a';
        if(trie[u][ch]){
            u = trie[u][ch];
        }
        else{
            return -1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 30; i++)
        cnt += trie[u][i];
    if(cnt == 0) return -1;
    return u;
}

void dfs(int u, string &s)
{
    //cout << s << " " << sstr << endl;
    if(s.size() > sstr.size() && fin[u]) cout << s << endl;
    for(int i = 0; i < 30; i++){
        if(trie[u][i]){
           s +=  'a' + i;
           dfs(trie[u][i], s);
           s.erase(s.size()-1);
        }
    }
}

int main()
{
    int t, cas = 1, n;
    char str[25];
    scanf("%d", &n);
    while(n--){
        scanf("%s", str);
        sstr = str;
        add(sstr);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        sstr = str;
        int u = query(sstr);
        printf("Case #%d:\n", cas++);
        if(u == -1) printf("No match.\n");
        else{
            string tem = sstr;
            dfs(u, tem);
        }
    }

    return 0;
}
