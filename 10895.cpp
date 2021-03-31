#include <iostream>
#include <vector>
using namespace std;


int main () {
    int n,m;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        vector<int> matriz[n+1];
        vector<int> sparte[m+1];
        vector<int> position(n);
        int r, aux;
        for(int i=1;i<n+1;i++){
            cin >>r;
            if(r==0){
                matriz[i].assign(m+1, 0);
                cin.ignore();
                continue;
            }
            matriz[i].assign(r+1,0);
            matriz[i][0] = r;
            for(int j=1;j<r+1;j++){
                cin >> aux;
                position[j] = aux;
            }
            
            for(int j=1;j<r+1;j++){
                cin >> aux;
                matriz[i][position[j]] =aux;
            }            
        }
        // cout << endl << endl << "MATRIZ LIDA: \n";
        // for(int i =1;i<n+1;i++){
        //     for(int j=1;j<m+1;j++){
        //         cout << matriz[i][j] << " ";
        //     }
        //     cout << endl;
        // }cout << endl << endl;

        // cout << endl << endl << "MATRIZ INVERSA: \n";
        vector<int> sparse[m+1];
        for(int i =1;i<m+1;i++){
            sparse[i].assign(n+2,0);
            int acc=0;
            for(int j=1;j<n+1;j++){
                sparse[i][j] = matriz[j][i];
                if(sparse[i][j]!=0) acc++;
                // cout << sparse[i][j] << " ";
            }
            sparse[i][0] = acc;
            // cout << endl;
        }

        cout << m << " " << n << endl;
        for(int i=1;i<m+1;i++){
            cout << sparse[i][0];
            for(int j=1;j<n+1;j++) 
                if(sparse[i][j]!=0) cout << " " << j;
            cout << endl;
            for(int j=1;j<n+1;j++) 
                if(sparse[i][j]!=0) {                
                    cout  <<  sparse[i][j];
                    if(j<n) cout << " "; 
                }
            cout << endl;

        }


    }


    return 0;
}