#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
#define mat_int int
#define mod 10007
using namespace std;

struct matrix{
    int dimR, dimC, MOD = 10007;
    vector <vector <mat_int> > mat;
    matrix(int _dimR, int _dimC){
        dimR = _dimR;
        dimC = _dimC;
        mat.clear();
        mat.resize(dimR, vector <mat_int> (dimC, 0));
        if(dimR == dimC){
            for(int i = 0; i < dimR; i++)
                mat[i][i] = 1;
        }
    }

    matrix operator * (const matrix &oth)
    {
        int nr = dimR;
        int nc = oth.dimC;
        matrix newMat(nr, nc);
        for(int i = 0; i < nr; i++){
            for(int j = 0; j < nc; j++){
                mat_int sum = 0;
                for(int k = 0; k < dimC; k++)
                {
                    sum += (mat[i][k] * oth.mat[k][j]) % MOD;
                    sum %= MOD;
                }
                newMat.mat[i][j] = sum;
            }
        }
        return newMat;
    }

    matrix operator ^ (ll p)
    {
        matrix res(dimR, dimC);
        matrix x = *this;

        while(p){
            if(p % 2 == 1) res = x * res;
            x = x * x;
            p /= 2;
        }

        return res;
    }

    void print()
    {
        cout << "......" << endl;

        for(int i = 0; i < dimR; i++){
            for(int j = 0; j < dimC; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << "......" << endl;
    }

};
int main()
{
    int t, cas = 1, n, a, b, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &a, &b, &c);
        printf("Case %d: ", cas++);
        if(n <= 2) printf("0\n");
        else{
            matrix A(4, 4);
            A.mat[0][0] = a; A.mat[0][1] = 0; A.mat[0][2] = b; A.mat[0][3] = 1;
            A.mat[1][0] = 1; A.mat[1][1] = 0; A.mat[1][2] = 0; A.mat[1][3] = 0;
            A.mat[2][0] = 0; A.mat[2][1] = 1; A.mat[2][2] = 0; A.mat[2][3] = 0;
            A.mat[3][0] = 0; A.mat[3][1] = 0; A.mat[3][2] = 0; A.mat[3][3] = 1;

            matrix ans = A ^ (n - 2);

            printf("%d\n", (ans.mat[0][3] * c)%mod);
        }
    }
    return 0;
}
