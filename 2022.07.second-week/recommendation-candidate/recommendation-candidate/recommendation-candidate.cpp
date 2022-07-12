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
void PICprint();
void STUprint();
void S();

int main() {
    cin >> N; // 사진틀의 개수
    cin >> rec; // 학생들의 총 추천 횟수
    for (int i = 0; i < N; i++) {
        cin >> pic[i];
        stu[pic[i]-1] = 1;
        for (int j = 0; j <= i; j++) {
            due[pic[j]-1]++;
        }
    }
    S();
    //STUprint();
    //PICprint();
    for (int i = N; i < rec; i++) {
        int num;
        cin >> num; // 학생 번호 입력 받기
        //printf("전: ");
        if (stu[num-1] == 0) {
            // 사진틀에 존재하지 않는 학생 신규 추천
            stu[pic[N - 1] - 1] = 0;
            due[pic[N - 1] - 1] = 0;
            pic[N - 1] = num;
            stu[num - 1] = 1;

            for (int j = 0; j < N; j++) {
                due[pic[j] - 1]++;
            }
            
            //print();


            //STUprint();
            //PICprint(); printf("------------------------\n\n");
            S();
            
        }
        else {
            //사진 틀에 이미 존재하는 학생 또 추천
            stu[num-1]++;

            for (int j = 0; j < N; j++) {
                due[pic[j] - 1]++;
            }

            S();
            
        }
        //STUprint();
        //PICprint();
    }

    sort(pic, pic + N, compare);
    for (int i = 0; i < N; i++) {
        cout << pic[i] << " ";
    }
    return 0;
}

bool compare(int a, int b) {
    return a < b;
}

void PICprint() {
    printf("사진틀:      ");
    for (int i = 0; i < N; i++) {
        printf("%d ", pic[i]);
    }
    printf("\n\n");
}

void STUprint() {
    printf("학생들 뽑힌 수: ");
    for (int i = 0; i < STU_MAX; i++) {
        printf("%d ", stu[i]);
    }
    printf("\n\n");
}

void S() {
    for (int j = 0; j < N - 1; j++) {
        for (int k = 0; k < N - 1; k++) {
            if ((stu[pic[k] - 1] < stu[pic[k + 1] - 1]) || (stu[pic[k] - 1] == stu[pic[k + 1] - 1] && due[pic[k] - 1] > due[pic[k + 1] - 1])) {
                //printf("pic[%d]: %d, pic[%d]: %d\n\n", k, pic[k], k + 1, pic[k + 1]);
                int t = pic[k];
                pic[k] = pic[k + 1];
                pic[k + 1] = t;

                //STUprint();
               // PICprint();printf("------------------------\n\n");
            }
        }
    }
}