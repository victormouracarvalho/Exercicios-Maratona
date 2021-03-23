#include <iostream>
#include<vector>
using namespace std;

int main () {
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        vector<string> planeta;
        vector<int> temp;
        int aux, aux2;
        string frase;
        for (int i=0; i<n;i++){
            cin >> frase >> aux >> aux2;
            
            planeta.push_back(frase);
            temp.push_back(aux-aux2);
        }
        int maior = 1000000;
        int acc=0;
        for(int i=0; i<n;i++){
            if(temp[i]< maior) {
                maior = temp[i];
                acc=i;
            }
        }
        cout << planeta[acc] << endl;

    }


    return 0;
}