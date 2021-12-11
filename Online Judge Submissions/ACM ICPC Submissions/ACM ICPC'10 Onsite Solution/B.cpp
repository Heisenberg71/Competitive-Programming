#include <bits/stdc++.h>
#define ll long long
using namespace std;

char grid[10][20], ans[10][20];

int findVal(int st)
{
    int a = 0;
    for(int i = 0; i < 9; i++){
        for(int j = st; j < st + 9; j++){
            if(grid[i][j] >= 'A' && grid[i][j] <= 'Z'){
                int val = grid[i][j];
                while(val){
                    if(val%2) a += 500;
                    else a += 250;
                    val /= 2;
                }
            }
        }
    }
    return a;
}

int findPos(int st)
{
    for(int i = 0; i < 7; i++){
        for(int j = st; j < st + 9; j++)
            if(grid[i][j - 1] == '/' && grid[i][j] == '\\') return i;
    }
}

void makeGrid()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 18; j++){
            if(j == 8 || j == 9) ans[i][j] = '|';
            else ans[i][j] = '.';
        }
    }
}

int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    int st = 0;
    for(int tc = 0; tc < t; tc++){
        for(int i = 0; i < 8; i++){
            getchar();
            for(int j = 0; j < 18; j++)
                scanf("%c", &grid[i][j]);
        }

        int leftVal = findVal(0);
        int rightVal = findVal(9);
        int leftPos = findPos(0);
        int rightPos = findPos(9);

        printf("Case %d:\n", cas++);
        if((leftVal < rightVal && leftPos < rightPos) || (leftVal > rightVal && leftPos > rightPos) || (leftVal == rightVal && leftPos == rightPos))
            printf("The figure is correct.\n");
        else{
            makeGrid();
            if(leftVal < rightVal){
                for(int i = 0; i < 5; i++, leftPos++){
                    for(int j = 0; j < 9; j++){
                        ans[i][j] = grid[leftPos][j];
                    }
                }
                for(int i = 2; i < 7; i++, rightPos++){
                    for(int j = 9; j < 18; j++){
                        ans[i][j] = grid[rightPos][j];
                    }
                }
            }
            else if(leftVal > rightVal){
                for(int i = 2; i < 7; i++, leftPos++){
                    for(int j = 0; j < 9; j++){
                        ans[i][j] = grid[leftPos][j];
                    }
                }
                for(int i = 0; i < 5; i++, rightPos++){
                    for(int j = 10; j < 18; j++){
                        ans[i][j] = grid[rightPos][j];
                    }
                }
            }
            else{
                for(int i = 1; i < 6; i++, leftPos++){
                    for(int j = 0; j < 9; j++){
                        ans[i][j] = grid[leftPos][j];
                    }
                }
                for(int i = 1; i < 6; i++, rightPos++){
                    for(int j = 9; j < 18; j++){
                        ans[i][j] = grid[rightPos][j];
                    }
                }
            }
            for(int i = 0; i < 7; i++){
                for(int j = 0; j < 18; j++)
                    printf("%c", ans[i][j]);
                printf("\n");
            }
        }



    }

    return 0;
}
