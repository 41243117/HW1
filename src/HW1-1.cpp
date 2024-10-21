#include<iostream>
using namespace std;

int recur(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return recur(m - 1, 1);
    else
        return recur(m - 1, recur(m, n - 1));
}

int nonr(int m, int n) {
    // 動態分配兩個陣列，index 用於記錄索引，value 用於記錄對應值
    int* index = new int[m];
    int* value = new int[n];

    // 初始化 index 和 value 的第一個元素
    index[0] = 0;
    value[0] = 1;

    // 將 index 的剩餘部分初始化為 -1，value 初始化為 1
    for (int i = 1; i <= m; i++) {
        index[i] = -1;
        value[i] = 1;
    }

    // 當 index[m] 不等於 n 時，不斷進行迴圈
    while (index[m] != n) {
        index[0] = value[1];
        value[0] = index[0] + 1;
        int i = 1;
        // 只要 value[i] 等於 index[i - 1]，就進行更新，並且 i 必須小於等於 m
        while (value[i] == index[i - 1] && i <= m) {
            index[i] = index[i] + 1;  // 增加 index[i]
            value[i] = value[i - 1];  // value[i] 設為前一個 value[i-1]
            i++;  
        }
    }

    // 當 index[m] == n 時，返回 value[m]
    return value[m];
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        cout << "Recursive:" << recur(m, n) << endl;
        cout << "Nonrecursive:" << nonr(m, n) << endl;
    }
}
