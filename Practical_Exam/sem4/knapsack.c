#include<stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
void main(){
    int w = 10;
    int n = 4;
    int val[] = {20,30,10,50};
    int wt[] = {1,3,4,6};
    int dp[w+1][n+1];
    for(int i=0;i<w+1;i++){
        dp[0][i] =0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] =0;
    }
    for(int item =1;item<=n;item++){
        for(int cap =1;cap<=w;cap++){
            //Don't take it 
            int ignoreCurrent = dp[item-1][cap];
            int takeCurr = 0;
            if(cap>=wt[item-1]){
                    takeCurr = val[item-1];
                    int remCap = cap - wt[item-1];
                    takeCurr+= dp[item-1][remCap];

            }
            dp[item][cap] = MAX(ignoreCurrent,takeCurr);
        }
    }
    printf("%d ",dp[n][w]);
}