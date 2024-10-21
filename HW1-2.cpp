#include <iostream>
using namespace std;

// 遞迴函數來計算集合的冪集
void powerset(char set[], char subset[], int n, int index, int subsetSize) {
    // 基礎情況：當 index 等於集合大小時，輸出當前的子集
    if (index == n) {
        cout << "{";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i];
            if (i != subsetSize - 1)
                cout << ",";
        }
        cout << "}" << endl;
        return;
    }

    // 遞迴情況 1：不包含當前元素，直接進入下一層遞迴
    powerset(set, subset, n, index + 1, subsetSize);

    // 遞迴情況 2：包含當前元素，加入子集後進入下一層遞迴
    subset[subsetSize] = set[index];
    powerset(set, subset, n, index + 1, subsetSize + 1);
}

int main() {
    char set[] = { 'a', 'b', 'c' };  
    int n = sizeof(set) / sizeof(set[0]);  
    char* subset = new char[n];  

    cout << "Powerset: " << endl;
    powerset(set, subset, n, 0, 0);  
    return 0;
}
