

/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-24 22:43:41
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-29 19:41:31
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\树的拓扑(bfs).cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
#define inf (INT_MAX)
int t,n,g[N];
char s[N];

vector<int>top;

int co;
vector<int> treeTopSort(const vector<vector<int>>& adjList, int root = 1) { // 默认根为1； 参数是树的邻接表；
    queue<int>q;
    q.push(1);
    vector<int>ans ;

    while (!q.empty()){
        co=q.front();
        ans.push_back(co);
        q.pop();
//        cout<<co<<":  ";
        for (int i : adjList[co]) {
            if (i != g[co]){                      //这里的g是co的父节点；我们先记录下来父节点；防止bfs出环；
//                cout<<i<<' ';
                q.push(i);
            }
        }
//        cout<<endl;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


/*
 * _______________#########_______________________ 
 * ______________############_____________________ 
 * ______________#############____________________ 
 * _____________##__###########___________________ 
 * ____________###__######_#####__________________ 
 * ____________###_#######___####_________________ 
 * ___________###__##########_####________________ 
 * __________####__###########_####_______________ 
 * ________#####___###########__#####_____________ 
 * _______######___###_########___#####___________ 
 * _______#####___###___########___######_________ 
 * ______######___###__###########___######_______ 
 * _____######___####_##############__######______ 
 * ____#######__#####################_#######_____ 
 * ____#######__##############################____ 
 * ___#######__######_#################_#######___ 
 * ___#######__######_######_#########___######___ 
 * ___#######____##__######___######_____######___ 
 * ___#######________######____#####_____#####____ 
 * ____######________#####_____#####_____####_____ 
 * _____#####________####______#####_____###______ 
 * ______#####______;###________###______#________ 
 * ________##_______####________####______________ 
 */