#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
int main () {
    int n; cin >> n;
    set<int> lista;
    multiset<int> repetidos;
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        lista.insert(aux);
        repetidos.insert(aux);
    }

    for(auto i: lista){
        cout << i << " aparece " << repetidos.count(i) << " vez(es)\n";
    }






    return 0;
}