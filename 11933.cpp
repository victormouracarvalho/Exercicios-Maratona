#include <bits/stdc++.h>
using namespace std;

#define M 32

int main () {

    int n;
    while(true){
        scanf("%d", &n);
        if(n==0) break;

        bitset<M> entrada(n);
        bitset<M> a;
        bitset<M> b;
        bool reveza = true;
        for (int i=0;i<32;i++){
            if(entrada[i] == 1){
                if(reveza){
                    a[i]=1;
                    reveza = false;
                }
                else 
                {
                    b[i]=1;
                    reveza = true;
                }
            }
        }

        // cout << entrada << endl;
        // cout << a << endl;
        // cout << b << endl;
        
        cout << (int)(a.to_ulong()) << " " << (int)(b.to_ulong()) << endl;
        
        
    }
    return 0;
}