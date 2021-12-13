
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int r,c,n;
PII me;
string grid[20];
vector<PII>gold;
LL dp[(1<<16)+10][20];

LL dist(PII a,PII b)
{
    return max(abs(a.F-b.F) ,abs(a.S-b.S));
}

LL solve(int mask,int prev_idx)
{
    if(mask==((1<<n)-1)) return dist(gold[prev_idx],gold[0]);
    LL &ret = dp[mask][prev_idx];

    if(ret!=-1) return ret;

    ret = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            LL dis = dist(gold[i],gold[prev_idx]);
            ret = min(ret,dis+solve(mask|(1<<i),i));
        }
    }

    return ret;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        gold.clear();

        cin>>r>>c;

        for(int i=0;i<r;i++)
            cin>>grid[i];

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]=='g' || grid[i][j]=='x') gold.push_back({i,j});

        n = gold.size();

        memset(dp,-1,sizeof dp);
        LL ans = solve(1,0);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}
