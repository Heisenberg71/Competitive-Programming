#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll tc,n;

    cin>>tc;
    while(tc--)
    {
        cin>>n;
        vector<ll>vec;

        if(n==1)
        {
            cout<<1<<endl;
        }
        else if(n==2)
        {
            cout<<-1<<endl;
        }
        else
        {
            vec.push_back(1);
            vec.push_back(n-1);

            for(ll i=0; i<n-2; i++)
            {
                vec.push_back(n);
            }

            for(ll i=0; i<vec.size(); i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }

        vec.clear();
    }
}
