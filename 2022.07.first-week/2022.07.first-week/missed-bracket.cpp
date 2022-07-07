#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 51;
int M, N, K;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int chu[MAX][MAX] = { 0 };

queue<pair<int, int>> q;

bool isInside(int x, int y);
void bfs(int x, int y);
bool isChecked[MAX][MAX];
//void test(int chu[][MAX]);

int cnt = 0;

int main() {
    int T; // 테스트 케이스의 개수
    cin >> T;



    while (T--) {//테스트 케이스
        cin >> M >> N >> K; // 배추밭의 가로 길이, 세로길이, 배추가 심어져 있는 위치의 개수
        int x, y;

        while (K--) {
            cin >> y >> x;
            chu[x][y] = 1; // 배추가 심어짐
        }
        //test(chu);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!isChecked[i][j] && chu[i][j] == 1) {
                    cnt++; // 배추 모임 수
                    bfs(i, j);
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                isChecked[i][j] = false;
                chu[i][j] = 0;
            }
        }
    }



    return 0;
}

void bfs(int x, int y) {
    q.push({ x, y });
    isChecked[x][y] = true;
    int xx, yy;
    while (!q.empty()) {
        xx = q.front().first;
        yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (isInside(nx, ny) && !isChecked[nx][ny] && chu[nx][ny] == 1) {
                q.push({ nx, ny });
                isChecked[nx][ny] = true;
            }
        }
    }
}


bool isInside(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void test(int chu[][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", chu[i][j]);
        }printf("\n");
    }printf("------------------------------------------\n");
}