#include <iostream>
#include<vector>
using namespace std;

int main () {
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a > (b+c)){
        cout << (b*2) + (c*4) << endl;

    }
    else if (c > (a+b)){
        cout << (a*4) + (b*2) << endl;

    }
    else {
        cout << (a*2) + (c*2) << endl;
    }

    return 0;
}