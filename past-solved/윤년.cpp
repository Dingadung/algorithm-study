#include <iostream>
#include <string>

using namespace std;


int main(){
    int year;
    cin >> year;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}
