#include <iostream>
#include <string>

using namespace std;


int main(){
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    int sum = 0;
    sum = a1*a1 + a2*a2 + a3*a3 + a4*a4 + a5*a5;
    cout << sum % 10;
    return 0;
}
