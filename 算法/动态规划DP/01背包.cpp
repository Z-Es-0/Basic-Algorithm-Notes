/*有 N
 件物品和一个容量是 V
 的背包。每件物品只能使用一次。

第 i件物品的体积是 vi，价值是 wi

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V
，用空格隔开，分别表示物品数量和背包容积。

接下来有 N
 行，每行两个整数 vi,wi
，用空格隔开，分别表示第 i
 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。
*/
#import <bits/stdc++.h>
#import <cstring>
#include <algorithm>
using namespace std;
#define N 1010
int n,m;
int f[N][N];
int v[N],w[N];
int main(){
    cin>>n>>m;
    for (int i = 1; i<=n ; i++){
        cin>>v[i]>>w[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if (j>=v[i]){
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
            }
        }
    }
//    int ans=0;
//    for (int i=0;i<=m;i++) {ans = max(ans,f[n][i]);}
//    cout<<ans<<endl;
    cout<<f[n][m]<<endl;
    return 0;
}