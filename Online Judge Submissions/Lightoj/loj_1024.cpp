#include <bits/stdc++.h>
#define ll long long
#define LIM 10000
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector <pair<ll,ll> > num[LIM+5], lcm;
void fac()
{
    ll i, k, cnt, tem;
    for(i = 2; i <= LIM; i++){
        tem = i;
        for(k = 2; k*k <= tem; k++){
            cnt = 0;
            while(tem%k == 0){
                tem /= k;
                cnt++;
            }
            if(cnt) num[i].pb({k,cnt});
        }
        if(tem != 1) num[i].pb({tem,1});
    }
}
void fnd(ll x)
{
    ll i, j;
    for(i = 0; i < num[x].size(); i++){
        for(j = 0; j < lcm.size(); j++){
            if(num[x][i].ff == lcm[j].ff){
                if(lcm[j].ss < num[x][i].ss) lcm[j].ss = num[x][i].ss;
                break;
            }
        }
        if(j == lcm.size()) lcm.pb(num[x][i]);
    }
}
ll power(ll n, ll p)
{
    ll ans = 1;
    while(p--)
        ans *= n;
    return ans;
}
string mult(string s1,string s2){
	string ss;
	int c = 0;
	for(int i=s2.length()-1;i>=0;i--){
		int carry=0;
		string s;
		for(int j=s1.length()-1;j>=0;j--){
			int n=((s1[j]-48)*(s2[i]-48))+carry;
			s.push_back((n % 10)+48);
			carry=n/10;
		}
		while(carry){
			s.push_back((carry % 10)+48);
			carry /= 10;
		}
		c++;
		if (c > 1)
		{
			for (int m = 0;m < c - 1;m++)s.insert(s.begin(), '0');
			carry = 0;
			for (int i = 0,j=0;i<s.length();i++,j++) {
				if (j <ss.length())
				{
					int n = (ss[j] - 48) + (s[i] - 48) + carry;
					ss[j] = (n % 10) + 48;
					carry = n / 10;
				}
				else
				{
					int n = (s[i] - 48) + carry;
					ss.push_back((n % 10) + 48);
					carry = n / 10;
				}
			}
			while (carry) {
				ss.push_back((carry % 10) + 48);
				carry /= 10;
			}
		}
		if (c == 1) {
			ss = s;
		}
	}
	reverse(ss.begin(), ss.end());
	return ss;
}
string bigint()
{
    string ans = "1";
    ll num = 1, tem, i;
    for(i = 0; i < lcm.size(); i++){
        tem = power(lcm[i].ff,lcm[i].ss);
        string temp;
        while(tem){
            temp += (tem%10)+'0';
            tem /= 10;
        }
        reverse(temp.begin(),temp.end());
        ans = mult(ans,temp);
    }
    return ans;
}
int main()
{
    fac();
    ll t, n, i, x, cas = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; i++){
            cin >> x;
            fnd(x);
        }
//        for(i = 0; i < lcm.size(); i++)
//            cout << lcm[i].ff << " " << lcm[i].ss << endl;
        printf("Case %lld: ", cas++);
        cout << bigint() << endl;
        lcm.clear();
    }
    return 0;
}

