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
    // �ʺA���t��Ӱ}�C�Aindex �Ω�O�����ޡAvalue �Ω�O��������
    int* index = new int[m];
    int* value = new int[n];

    // ��l�� index �M value ���Ĥ@�Ӥ���
    index[0] = 0;
    value[0] = 1;

    // �N index ���Ѿl������l�Ƭ� -1�Avalue ��l�Ƭ� 1
    for (int i = 1; i <= m; i++) {
        index[i] = -1;
        value[i] = 1;
    }

    // �� index[m] ������ n �ɡA���_�i��j��
    while (index[m] != n) {
        index[0] = value[1];
        value[0] = index[0] + 1;
        int i = 1;
        // �u�n value[i] ���� index[i - 1]�A�N�i���s�A�åB i �����p�󵥩� m
        while (value[i] == index[i - 1] && i <= m) {
            index[i] = index[i] + 1;  // �W�[ index[i]
            value[i] = value[i - 1];  // value[i] �]���e�@�� value[i-1]
            i++;  
        }
    }

    // �� index[m] == n �ɡA��^ value[m]
    return value[m];
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        cout << "Recursive:" << recur(m, n) << endl;
        cout << "Nonrecursive:" << nonr(m, n) << endl;
    }
}
