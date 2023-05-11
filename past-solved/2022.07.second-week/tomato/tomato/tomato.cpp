#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>
using namespace std;

const int MAX = 101;

int M, N, H;

int tmt[MAX][MAX][MAX] = { 0 };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dz[] = { 0, 1, -1 };
queue<tuple<int, int, int>> q; // x, y, z

void printTmt();
bool isInside(int x, int y, int z);
void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H; // 가로j 세로i 높이

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tmt[i][j][k];
                if (tmt[i][j][k] == 1) {
                    //익은 토마트가 들어올 경우 q에 넣어주기
                    q.push({ j, k, i }); // x, y, z
                }
            }
        }
    }
    
    bfs();
    //printTmt();
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tmt[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                //printf("tmt: %d\n", tmt[i][j][k]);
                ans = ans > tmt[i][j][k] ? ans : tmt[i][j][k];
            }
        }
    }
    
    cout << ans-1;
    return 0;
}

void bfs() {
    while (!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int zz = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nz = zz + dz[i];

            if (isInside(xx, yy, nz) && tmt[nz][xx][yy] == 0) {
                tmt[nz][xx][yy] = tmt[zz][xx][yy] + 1;
                q.push({ xx, yy, nz });
            }

        }
        for (int j = 0; j < 4; j++) {
            int nx = xx + dx[j];
            int ny = yy + dy[j];

            if (tmt[zz][nx][ny] == 0 && isInside(nx, ny, zz)) {
                tmt[zz][nx][ny] = tmt[zz][xx][yy] + 1;
                q.push({ nx, ny, zz });
            }


        }
    }
    
}

bool isInside(int x, int y, int z) {
    return 0 <= x && x < N && 0 <= y && y < M && 0 <= z && z < H;
}


void printTmt() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cout << tmt[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "\n\n";
    }
}