#include <bits/stdc++.h>
#define ll long long
#define LIM 1000005
using namespace std;

int trie[LIM][130], cnt = 2, dst = 0;
bool fin[LIM];
string sstr;

void add(string &s)
{
    int u = 1;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(!trie[u][ch]){
            trie[u][ch] = cnt++;
        }
        u = trie[u][ch];
    }
    fin[u] = 1;
}

void reset(int u)
{
    for(int i = 0; i < 130; i++){
        if(trie[u][i]) reset(trie[u][i]);
        trie[u][i] = 0;
    }
    if(fin[u]) dst++;
    fin[u] = 0;
}

int main()
{
    int t;
    char str[1005];
    scanf("%d", &t);
    while(t--){
        scanf("%s", &str);
        sstr = str;
        cnt = 2, dst = 0;
        for(int i = 0; i < sstr.size(); i++){
            string temstr;
            for(int j = i; j < sstr.size(); j++){
                temstr += sstr[j];
                add(temstr);
            }
        }
        reset(1);
        printf("%d\n", dst);
    }

    return 0;
}
