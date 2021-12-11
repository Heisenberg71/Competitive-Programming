#include <bits/stdc++.h>
using namespace std;

bool isleap(int year){
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int main()
{
    int dd, mm, yy, year, t, cas = 1;
    cin >> t;
    while(t--){
        cin >> dd >> mm >> yy >> year;
        yy++;
        int cnt = 0;
        while(yy <= year){
            if(dd == 29 && mm == 2){
                if(isleap(yy)) cnt++;
            }
            else
                cnt++;
            yy++;
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
    return 0;
}
