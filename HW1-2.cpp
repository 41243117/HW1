#include <iostream>
using namespace std;

// ���j��ƨӭp�ⶰ�X������
void powerset(char set[], char subset[], int n, int index, int subsetSize) {
    // ��¦���p�G�� index ���󶰦X�j�p�ɡA��X��e���l��
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

    // ���j���p 1�G���]�t��e�����A�����i�J�U�@�h���j
    powerset(set, subset, n, index + 1, subsetSize);

    // ���j���p 2�G�]�t��e�����A�[�J�l����i�J�U�@�h���j
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
