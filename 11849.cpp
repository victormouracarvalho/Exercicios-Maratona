#include <iostream>
#include <set>
using namespace std;

int main () {
    int n,m;
    while(true){
        cin >> n >> m;
        if(n==0 and m==0) break;
        set<int> jack;
        set<int> jill;
         int aux;
         for (int i=0;i<n; i++) {cin >> aux; jack.insert(aux);}
         for (int i=0;i<m; i++) {cin >> aux; jill.insert(aux);}

        set<int> diferenca;
        for(auto it: jack){
            if(jill.count(it)!=0) diferenca.insert(it);
        }
        
        for(auto it: jill){
            if(jack.count(it)!=0) diferenca.insert(it);
        }
        
        // for(auto it: diferenca)
        //    cout << it << " ";

        cout <<  diferenca.size() << endl;
    }

    return 0;
}