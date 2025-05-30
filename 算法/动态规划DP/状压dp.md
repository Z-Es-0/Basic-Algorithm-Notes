# P1896 [SCOI2005] 互不侵犯
[P1896 [SCOI2005] 互不侵犯 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1896)
## 问题描述

# [SCOI2005] 互不侵犯

## 题目描述

在 $N \times N$ 的棋盘里面放 $K$ 个国王，使他们互不攻击，共有多少种摆放方案。国王能攻击到它上下左右，以及左上左下右上右下八个方向上附近的各一个格子，共 $8$ 个格子。

## 输入格式

只有一行，包含两个数 $N,K$。

## 输出格式

所得的方案数

## 样例 #1

### 样例输入 #1

```
3 2
```

### 样例输出 #1

```
16
```

## 提示

### 数据范围及约定

对于全部数据，$1 \le N \le 9$，$0 \le K \le N\times N$。

---

$\text{upd 2018.4.25}$：数据有加强。

‍

## 思路

我们发现 n非常小，K才81，那么考虑dfs或者高纬dp；

对于某一行的情况，我们考虑二进制表示这一行的状态，那么对于这一行的情况需要从前一行的状态进行转移；

我们发现我们完全可以进行子集枚举状态；复杂度   $2^n$ ;

外层需要枚举行和选择国王数，那么总复杂度为:

‍

                                   $2*n$​*$k$*​$2^n$

把$n = 9 , k = n*n$ 带入计算运算次数

                              ​*$counts = 2*9*9*2^9 = 82944$*  

1s 内可行

## 状态表示

> $dp[N][N*N][1<<N]$  `//第i行 选了j个国王 当前行状态(bitset)l 时 的情况数;`​

## 状态转移

>  位运算高效check两行的状态，我们发现，对于相邻的两行， $s[i][j]!=s[i-1][j-1]!=s[i-1][j+1]$   是我们的需求；这样的判断我们可以用位运算实现；
>
> 即:  m & ((l<<1)|l|(l>>1)) 为假

‍

> ‍
>
> ```cpp
> for (int i = 0; i < n; ++i) {                                                // 枚举第几行
>         for (int j = 0; j <= k; ++j) {                                       // 枚举目前选了几个国王
>             for (int l =0;l<(1<<n);l++) {                                    // 枚举当前行的状态
>                 if (l &(l<<1))continue;                                      // 当前行不合法
>                 if (dp[i][j][l]){                                            // 当前行合法且转移有贡献
>                     for (int m = 0;m<(1<<n);m++) {                           // 枚举下一行状态                      
>                         if (m &(m<<1))continue;                              // 下一行自己不合法
>                         if (m & ((l<<1)|l|(l>>1)))continue;                  // 下一行和当前行组合不合法
> //                        if (m & (l>>1))continue; 
>                         count=__builtin_popcount(m);                         // 合法情况取当前状态二进制的数量
>                         if (j+count<=k){
>                             dp[i+1][j+count][m]+=dp[i][j][l];                // 选择国王数在范围内进行状态转移
>                         }
>                     }
>                 }
>             }
>         }
>
>     }
> ```

‍

## 答案

答案只需要累加第n行，使用国王数为k，枚举l 进行累加即可

‍

‍

## code

```cpp

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define lowbit(x) x&(-x)
#define N 11
int dp[N][N*N][1<<N]; // 第i行 选了j个国王 当前行状态(bitset)l 时 的情况数;
int n, k;
void solve() {
    cin>>n>>k;
    dp[0][0][0]=1;

    int count=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l =0;l<(1<<n);l++) {
                if (l &(l<<1))continue;
                if (dp[i][j][l]){
                    for (int m = 0;m<(1<<n);m++) {
                        if (m &(m<<1))continue;
                        if (m & ((l<<1)|l|(l>>1)))continue;
//                        if (m & (l>>1))continue;
                        count=__builtin_popcount(m);
                        if (j+count<=k){
                            dp[i+1][j+count][m]+=dp[i][j][l];
                        }
                    }
                }
            }
        }

    }
    cout<<accumulate(dp[n][k],dp[n][k]+(1<<n),0ll)<<endl;
//    int ans = 0;
//    for (int i = 0; i <= n ; ++i) {
//        for (int j = 0; j < (1<<n); ++j) {
//            ans+=dp[i][k][j];
//        }
//    }
//    cout<<ans<<endl;
}


signed main() {
//    cin>>t;
//    while (t--){
    solve();
//    }
    return 0;
}

```
