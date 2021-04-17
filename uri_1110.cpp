    #include <vector>
#include <iostream>
using namespace std;

int main () {
    int n;
    while(true){
        cin >> n;
        if(n==0){ break;}
        vector<int> pilha;
        for(int i=1;i<n+1;i++) pilha.push_back(i);
        vector<int> descarte;
        while(pilha.size()>1){
            descarte.push_back(pilha[0]);
            pilha.erase(pilha.begin());
            pilha.push_back(pilha[0]);
            pilha.erase(pilha.begin());
        }
        cout << "Discarded cards:";
        for(int i=0;i<descarte.size();i++) {
            cout << " " << descarte[i];
            if(i<descarte.size()-1) cout << ",";
        }
        cout << endl;
        cout << "Remaining card: " << pilha[0] << endl;
         

    }



    return 0;
}