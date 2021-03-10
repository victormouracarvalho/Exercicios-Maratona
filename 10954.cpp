#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main (){
    int n; 
    while(true){
        cin>> n;
        if(n==0) break;
        priority_queue<unsigned long long  int, vector< unsigned long long int>,   
                       greater<unsigned long long  int> > fila;
        for(int i=0;i<n;i++){
            unsigned long long aux; cin >> aux;
            fila.push(aux);
        }
        unsigned long long int acc=0, aux=0, aux_2 =0;
        // while(!fila.empty()) {
        //     cout << fila.top() << " ";
        //     fila.pop();
        // }
        // aux=fila.top(); fila.pop();
        while(fila.size()>1){
            aux = fila.top(); fila.pop();
            aux_2 =fila.top(); fila.pop();
            acc += (aux + aux_2);
            fila.push(aux+aux_2);   
        }
        
        cout << acc << endl;
    }

    return 0;
}