#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main () {
    int n, m;
    while(cin >> n >> m){
        string str;
        queue<int> fila;
        set<int> conferidor;
        cin >> str;
        fila.push(str[0]-'A'); fila.push(str[1]-'A'); fila.push(str[2]-'A');
        conferidor.insert(str[0]-'A'); conferidor.insert(str[1]-'A'); conferidor.insert(str[2]-'A');

        // cout << str << endl;
        vector<int> G[27];
        vector<int> ligado;
        ligado.assign(27,0);
        ligado[str[0]-'A'] =1; ligado[str[1]-'A'] =1; ligado[str[2]-'A'] =1; 
        vector<int> connection;
        connection.assign(27,0);
        connection[str[0]-'A'] =3; connection[str[1]-'A'] =3; connection[str[2]-'A'] =3; 
        vector<int> tempo;
        tempo.assign(27,0); 

        for(int i = 0; i < m; i++) {
            cin >> str;
            int a = str[0]-'A', b = str[1]-'A';
            G[a].push_back(b);
            G[b].push_back(a);
            conferidor.insert(a);
            conferidor.insert(b);
        }
        int acc=3;
        while(!fila.empty()){
            int a = fila.front(); fila.pop();
            // cout << "Pilha : " << a << endl; 
            if(ligado[a]){
                for(int i: G[a]){
                    // cout << i << " ";
                    if(!ligado[i]) connection[i]++;
                    if(connection[i]>=3 and (!ligado[i])){
                        fila.push(i);
                        ligado[i]=1;
                        acc++;
                        tempo[i]=tempo[a]+1;
                     }   
                }
            }
            // cout << endl;
        }
        // for(int i =0;i<26; i++) cout << tempo[i] << " ";
        // cout << endl;
        // for(int i =0;i<26; i++) cout << ligado[i] << " ";
        // cout << endl;
        // for(int i =0;i<26; i++) cout << connection[i] << " ";
        // cout << endl;
        // cout << "Acc = " << acc << endl;
        bool vero=true;
        int maior = 0;

        for(auto it: conferidor){
            if(!ligado[it]) {
                vero = false;
                break;
            }
            else{
                if(tempo[it]>maior) maior = tempo[it];
            } 
        }

        if(acc<n) {
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
        else{
            cout << "WAKE UP IN, " << maior << ", YEARS\n";
        } 

       
    }

  return 0;
}

