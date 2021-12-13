#include <bits/stdc++.h>
#define ll long long
#define LIM 3000006
using namespace std;

int trie[LIM][26], cnt[LIM], len[LIM], node = 2, ans;

void add(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int d = s[i] - 'A';
        if(!trie[u][d])
            trie[u][d] = node++;
        len[trie[u][d]] = len[u] + 1;
        cnt[trie[u][d]]++;
        u = trie[u][d];
    }
}

void reset(int u)
{
    for(int i = 0; i < 26; i++){
        if(trie[u][i]){
            ans = max(ans, len[trie[u][i]] * cnt[trie[u][i]]);
            len[trie[u][i]] = cnt[trie[u][i]] = 0;
            reset(trie[u][i]);
        }
        trie[u][i] = 0;
    }
}

int main()
{
    int t, cas = 1, n;
    char str[55];
    string s;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        node = 2;
        while(n--){
            getchar();
            scanf("%s", str);
            s = str;
            add(s);
        }
        ans = 0;
        reset(1);

        printf("Case %d: %d\n", cas++, ans);
    }

    return 0;
}
