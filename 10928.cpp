#include <iostream>
#include <vector> 
#include <sstream>
using namespace std;

int main () {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int lista[n];
        int menor = 1000000;
        cin.ignore();
        for (int i=0;i<n;i++){
            string line;
            getline(cin, line);
            istringstream input(line);
            string word;
            vector<int> output;
            while(input >> word){
                int j = stoi(word);
                // cout << j << " ";
                output.push_back(i);
            }
            // cout << endl;

            lista[i] = output.size();
            if(menor > output.size()) menor = output.size();
        }
        int acc=0;
        for(int i=0;i<n;i++) {
            if(lista[i] == menor) {
                if(acc ==0) cout << i+1;
                else cout << " " << i+1;
                acc++;
            }
            }
        cout << endl ;


    }



    return 0;//
}