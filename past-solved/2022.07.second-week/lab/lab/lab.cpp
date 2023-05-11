#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;


const int MAX = 8;
int N, M;
int v[MAX][MAX], tmp[MAX][MAX];
bool isVisited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

bool isInside(int x, int y);
void wall(int);
void bfs();
void copy(int a[][MAX], int b[][MAX]);

int SAFE = 0;

void print();

int main() {
    cin >> N >> M; // 세로 i, 가로 j
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int t;
            cin >> t;
            v[i][j]=t;
        }
    }
    //printf("-------------------------------------------------------\n\n");
    //print();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 0) {
                copy(tmp, v);
                //print();
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << SAFE;
    return 0;
}

void bfs() {
    int after[MAX][MAX];
    copy(after, tmp);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (after[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (isInside(nx, ny) && after[nx][ny] == 0) {
                after[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }
    int c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (after[i][j] == 0) {
                c++;
            }
        }
    }
    if (c > SAFE)SAFE = c;
}

void wall(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(cnt+1);
                tmp[i][j] = 0;
            }
            
        }
    }
}


bool isInside(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < M);
}

void copy(int a[][MAX], int b[][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}


void print() {
    printf("-----------------------------------------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    
}