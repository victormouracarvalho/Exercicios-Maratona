#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main () {
    int t; cin>> t;
    int caso=1;
    while(t--){
        int n,m; cin >> m;
        vector<set<int>> lista(m);
        vector<int> diferentes(m);
        for(int i =0;i<m;i++){
            cin >> n;
            int aux;
            for(int j =0;j<n;j++){
                cin >> aux;
                lista[i].insert(aux);
            }
        }
        for(int i =0;i<m;i++) diferentes[i] = lista[i].size();
        bool vero=false;
        for(int i =0;i<m; i++){
            for(auto it: lista[i]){
                if(vero){
                    vero = false;
                    break;
                }
                for(int j=0;j<m;j++){
                    // cout<<  i << " " << j << " " << it << "   ";
                    
                    if(lista[j].count(it)!=0 and i!=j) {
                        if(diferentes[i]>0) diferentes[i]--;
                        break;
                        // cout << "Deu " <<  i << " " << j << " " << it << " ";
                    }
                    // cout << endl;
                }
            }
        }
        // cout << "Aqui\n";
        double acc=0;
        for(int i =0;i<m; i++) {
            acc+= diferentes[i];
            // cout << diferentes[i] << " ";
        }
        if(acc==0) acc=1;
        // cout << endl << acc << endl;
        cout << "Case " << caso << ":";
        caso++;
        for(int i =0;i<m; i++) {
             string special = "%";
             double x = ((diferentes[i]/acc ) *100);

             printf(" %.6lf%c", x ,special[0]);
        }
        printf("\n");
    }
    return 0;
}