#include <bits/stdc++.h>
#define ll long long
#define LIM 1000006
using namespace std;

int trie[LIM][52], endpoint[LIM], cnt = 2;

int conv(char ch)
{
    if('a' <= ch && ch <= 'z') return ch - 'a' + 26;
    return ch - 'A';
}

void add(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = conv(s[i]);
        if(!trie[u][edg]){
            trie[u][edg] = cnt++;
        }
        u = trie[u][edg];
    }
    endpoint[u]++;
}

int query(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        int edg = conv(s[i]);
        if(trie[u][edg]){
            u = trie[u][edg];
        }
        else return 0;
    }
    return endpoint[u];
}

void reset(int u)
{
    for(int i = 0; i < 52; i++){
        if(trie[u][i]) reset(trie[u][i]);
        trie[u][i] = 0;
    }
    endpoint[u] = 0;
}

int main()
{
    int t, cas = 1, n, m;
    char str[10005];
    string s;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cnt = 2;
        while(n--){
            getchar();
            scanf("%s", str);
            s = str;
            //cout << s << endl;
            if(s.size() > 2) sort(s.begin()+1, s.end()-1);
            add(s);
        }
        scanf("%d", &m); getchar();
        printf("Case %d:\n", cas++);
        while(m--){
            //getchar();
            getline(cin, s);
            //s = str;
            //cout << s << endl;
            string tem;
            int ans = 1;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' '){
                    if(tem.size() > 2)
                        sort(tem.begin()+1, tem.end()-1);
                    if(!tem.empty()) ans *= query(tem);
                    tem.clear();
                }
                else tem += s[i];
            }
            if(tem.size() > 2)
                sort(tem.begin()+1, tem.end()-1);
            if(!tem.empty()) ans *= query(tem);
            printf("%d\n", ans);
        }

        reset(1);
    }
    return 0;
}
/**

1
8
bggaers
bgagres
in
the
bwleod
blowed
barn
bran



*/
