#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 65;
int N;
int vid[MAX][MAX];
int isAll(int start, int end, int size);
void compress(int start, int end, int size);
//queue<char> q;

int main() {
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            vid[i][j] = s[j] - '0';
        }
    }

    compress(0, 0, N);

    return 0;
}



void compress(int x, int y, int size) {
    int a = isAll(x, y, size);
    //printf("isAll: %d\n", a);
    if (a == 0) {
        cout << 0;
        return;
    }
    if (a == 1) {
        cout << 1;
        return;
    }
    cout << '(';
    compress(x, y, size/2);
    compress(x + size/2, y, size/2);
    compress(x, y +size/2, size/2);
    compress(x + size/2, y+size/2, size/2);
    cout << ')';

}

int isAll(int y, int x, int size) {
    bool isAllOne = true; 
    bool isAllZero = true;
    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++) {
            if (vid[i][j] == 1) isAllZero = false;
            if (vid[i][j] == 0)isAllOne = false;
        }
    }
    if (isAllZero)return 0;
    else if (isAllOne)return 1;
    else return 2;
}