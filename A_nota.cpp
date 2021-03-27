#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
#define MOD	1000000007
int main () {
    while(true){
        long long int n, m; cin >> n >> m;
        if(!cin  ) break;
        vector<long long int> lista(n);
        for(int i=0;i<n;i++) cin >> lista[i];
        sort(lista.begin(),lista.end());
        long long int k=0;
        // for(auto i: lista) cout << i <<  " "; 
        // cout << endl;
    
        for(int i = n-1;i>=n-m;i--) {
            k = ((k % MOD) + (lista[i] % MOD)) % MOD;
        }
        cout << k << endl;
    }


    return 0;
}