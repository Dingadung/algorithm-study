#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int PIC_MAX = 21;
const int STU_MAX = 101;

int N, rec;
int pic[PIC_MAX] = { 0 };
int stu[STU_MAX] = { 0 };
int due[STU_MAX] = { 0 };

bool compare(int a, int b);
int isEmpty();
void PICprint();
void STUprint();
void S();

int main() {
    cin >> N; // ����Ʋ�� ����
    cin >> rec; // �л����� �� ��õ Ƚ��

    for (int i = 0; i < rec; i++) {
        int num;
        cin >> num; // �л���ȣ �Է¹ޱ�
        int c = isEmpty();
        if (c != -1) {
            // �� ����Ʋ�� �ִ� ���
            if (stu[num - 1] == 0) {
                pic[c] = num;
                stu[pic[c] - 1] = 1;
                for (int k = 0; k <= i; k++) {
                    due[pic[k] - 1]++;
                }
            }
            else {
                stu[num - 1]++;
                for (int k = 0; k <= i; k++) {
                    due[pic[k] - 1]++;
                }
            }
            S();
        }
        else {
            if (stu[num - 1] == 0) {
                // ����Ʋ�� �������� �ʴ� �л� �ű� ��õ
                stu[pic[N - 1] - 1] = 0;
                due[pic[N - 1] - 1] = 0;
                pic[N - 1] = num;
                stu[num - 1] = 1;

                for (int j = 0; j < N; j++) {
                    due[pic[j] - 1]++;
                }
                S();

            }
            else {
                //���� Ʋ�� �̹� �����ϴ� �л� �� ��õ
                stu[num - 1]++;

                for (int j = 0; j < N; j++) {
                    due[pic[j] - 1]++;
                }

                S();

            }

        }
    }

    sort(pic, pic + N, compare);
    for (int i = 0; i < N; i++) {
        if (pic[i] == 0)continue;
        cout << pic[i] << " ";
    }
    return 0;
}

bool compare(int a, int b) {
    return a < b;
}

void PICprint() {
    printf("����Ʋ:      ");
    for (int i = 0; i < N; i++) {
        printf("%d ", pic[i]);
    }
    printf("\n\n");
}

void STUprint() {
    printf("�л��� ���� ��: ");
    for (int i = 0; i < STU_MAX; i++) {
        printf("%d ", stu[i]);
    }
    printf("\n\n");
}

void S() {
    for (int j = 0; j < N - 1; j++) {
        for (int k = 0; k < N - 1; k++) {
            if ((stu[pic[k] - 1] < stu[pic[k + 1] - 1]) || (stu[pic[k] - 1] == stu[pic[k + 1] - 1] && due[pic[k] - 1] > due[pic[k + 1] - 1])) {
                int t = pic[k];
                pic[k] = pic[k + 1];
                pic[k + 1] = t;
            }
        }
    }
}

int isEmpty() {
    for (int j = 0; j < N; j++) {
        if (pic[j] == 0) {
            return j;
        }
    }
        return -1;
}