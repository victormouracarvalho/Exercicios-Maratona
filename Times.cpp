#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main () {
    int n,m;
    cin >> n >> m;
    vector<pair<int, string>> lista;
    while(n--){
        int a; string nome;
        cin >> nome >> a;
        lista.push_back(make_pair(a,nome));
    }
    sort(lista.begin(),lista.end());
    int i=0;
    vector<vector<string>> nomes(m);
    int aux =0;
    for(int i=lista.size()-1;i>=0;i--){
        nomes[aux].push_back(lista[i].second);
        aux++;
        if(aux==m) aux =0;
    }
    
    for(int i = 0; i < nomes.size(); i++){
        cout << "Time " << i+1 << endl;
        sort(nomes[i].begin(),nomes[i].end());
        for(int j=0; j< nomes[i].size(); j++){
            cout << nomes[i][j] << endl;
        } cout << endl;
    }




    return 0;
}