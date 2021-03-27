#include <iostream>
#include <vector>

using namespace std;


int main () {
   int fita[10000];
   int n,  cor=0;
   cin >> n;
   for(int i=0; i<n; i++) cin >> fita[i];

   for(int i=0;i<10;i++){
       for(int j=0;j<n; j++){

           if(fita[j]==cor and fita[j]!=9){
               if(fita[j-1]==-1){
                   fita[j-1] = cor+1;
               }
               if(fita[j+1]==-1){
                   fita[j+1] = cor+1;
               }
           }
       }
       if(cor<10) cor++;
   }

    for(int i=0;i<n;i++) if(fita[i]==-1) fita[i] =9;

    for(int i=0;i<n;i++){cout << fita[i] << " ";}
    cout << endl;

    return 0;
}