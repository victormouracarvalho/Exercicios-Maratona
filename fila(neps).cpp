#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n; cin>> n;
    vector<int> fila(n);
    for(int i=0;i<n; i++) cin >> fila[i];
    int q; cin >> q;
    while(q--) {
        int op, sz = fila.size(), a,b;
        cin >> op >> a >>b;
        
        if(!op) fila.insert(fila.begin() + a, b);


        if(op){
            bool vero = false;
            for (int i=a-1; i>=0; i--){
                if(fila[i]> fila[a-1] + b) {
                    vero = true;
                    cout << i+1 << endl;
                    break;
                }
            }
            if(!vero) cout << 0 << endl;
        }


    }
    // for(auto i: fila) cout << i << " ";
    // cout << endl;

    return 0;
}