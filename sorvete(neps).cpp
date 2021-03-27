#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () 
{
   int cont = 1;
   while(true){
       int n,t,i;
   vector <pair<int,int>> sorvete;
   pair <int, int> tmp;
   cin >> n >> t;
   if(n==0 and t==0 ) break;
    
   for(i=0;i<t;i++){
       cin >> tmp.first >> tmp.second;
       sorvete.push_back(tmp);
       
   }
    //for(i=0;i<t;i++){
   //  cout << sorvete[i].first << ' ' << sorvete[i].second << endl;
  // }
    sort(sorvete.begin(),sorvete.end());
  //  for(i=0;i<t;i++){
   //     cout << sorvete[i].first << ' ' << sorvete[i].second << endl;
   //  }
   
   
    vector <int> acc;
    
    i=0;
    
    for(i=0;i<(sorvete.size()-1);i++){
      // cout << sorvete[i].first << ' ' << sorvete[i].second << endl;
      //  cout << sorvete[i+1].first << ' ' << sorvete[i+1].second << endl;
         if(sorvete[i].second >= sorvete[i+1].first){
             if(sorvete[i].second >= sorvete[i+1].second){
                 sorvete.erase(sorvete.begin() + (i+1));
                 i=-1;
             }else {
                 sorvete[i].second = sorvete[i+1].second;
                 sorvete.erase(sorvete.begin() + (i+1));
                 i=-1;
             }
         }
         
    }
    cout << "Teste " << cont << endl;
    cont++;
   for(i=0;i<(sorvete.size());i++){
        cout << sorvete[i].first << ' ' << sorvete[i].second << endl;
   }
   
   }
    
    return 0;
}