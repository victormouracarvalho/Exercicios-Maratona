#include <iostream>
#include <vector> 
#include <sstream>
using namespace std;

int main () {
    int n; cin >> n;
    string sd,sn;
    int a,b,c,d;
    a=0;
    b=0;
    c=0;
    d=0;
    for(int i=0;i<n;i++){
        cin >> sd >> sn;
        if(sd=="chuva"){
            d++;
            if(c>0) c--;
            else a++;
        }
        if(sn=="chuva"){
            c++;
            if(d>0) d--;
            else b++;
        }
    }
    cout << a << " " << b << endl;



    return 0;//
}