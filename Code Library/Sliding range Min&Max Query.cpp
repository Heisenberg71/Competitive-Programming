#define ll long long
#define ff first
#define ss second
set <pair <ll,ll> > s, s2;
set <pair <ll,ll> > :: iterator it;
void min_poop(ll x, ll cur, ll sz)
{
    while(s.size() > 0 and (s.rbegin() -> ff > x or s.rbegin() -> ss < cur-sz+1)){
        it = s.end(); it--;
        s.erase(it);
    }
    while(s.size() > 0 and s.begin() -> ss < cur-sz+1){
        s.erase(s.begin());
    }
    s.insert({x,cur});
}
void max_poop(ll x, ll cur, ll sz)
{
    while(s2.size() > 0 and (s2.begin() -> ff < x or s2.begin() -> ss < cur-sz+1)){
        s2.erase(s2.begin());
    }
    while(s2.size() > 0 and s2.rbegin() -> ss < cur-sz+1){
        it = s2.end(); it--;
        s2.erase(it);
    }
    s2.insert({x,cur});
}
