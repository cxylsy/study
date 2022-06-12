#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10
int parent[MAXN];

//初始化
void init(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

//查找
int find(int x) {
    if(parent[x] == x) {
        return parent[x];
    } else {
        find(parent[x]);
    }
}

//查找，路径压缩

int find1(int x) {
    if(parent[x] == x) {
        return x;
    } else {
        parent[x] = find(x);
        return find(parent[x]);
    }
}
//合并
void meger(int x, int y) {
    parent[find(x)] = find(y);
}

// https://blog.csdn.net/weixin_38279101/article/details/112546053