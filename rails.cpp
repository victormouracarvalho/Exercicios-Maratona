#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main () {
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        stack<int> ini;
        stack<int> estacao;
        stack<int> fim;
        for(int i =0;i<n;i++){
            int aux;cin>>aux;
            ini.push(aux);
        }
        int aux;

        while(!ini.empty() or !estacao.empty()){
            if(!ini.empty()){
                aux = ini.top();
                ini.pop();
            }

            if(!estacao.empty()){
                // cout << "Estação\n";
                if(ini.empty()){ // acabou a entrada, manda o resto pra saída
                    while(!estacao.empty()){
                        int aux2 = estacao.top();
                        fim.push(aux2);
                        // cout << aux << " ";
                        estacao.pop();
                    }
                }
                else if(estacao.top() > ini.top()){
                    int aux2 = estacao.top();
                    fim.push(aux2);
                    // cout << aux << " ";

                    estacao.pop();
                }else {
                    if(aux > ini.top()){
                        fim.push(aux);
                    }
                    else {
                        estacao.push(aux);

                    }
                    // cout << aux << " ";
                }
                    
            }

            else if(!ini.empty()) {
                // cout << "ini\n";
            if(aux > ini.top()) fim.push(aux);
            else estacao.push(aux);
            }
            else{
                fim.push(aux);
            }
            
            
        }

        while(!fim.empty()){
            cout << fim.top() << endl;
            fim.pop();
        }
        


    }



    return 0;
}