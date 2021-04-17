#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    int acc=1;
    while(acc<5){
       if(n%2==0) n/=2;
       else n = (n/2 )+1;

       if(m%2==0) m/=2;
       else m = (m/2 )+1;
        if(n==m){
            if(acc==1) cout << "oitavas\n";
            if(acc==2) cout << "quartas\n";
            if(acc==3) cout << "semifinal\n";
            if(acc==4) cout << "final\n";
            break;
        }

        acc++;
    }
    return 0;
}