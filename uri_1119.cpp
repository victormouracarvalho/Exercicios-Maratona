#include <vector>
#include <iostream>
using namespace std;

int main () {
    int n, k,m;
    cin >> n >> k >> m;
    vector<int> roda;
    for(int i = 0; i <n;i++) roda.push_back(i+1);
    
    auto it1 = roda.begin(), it2 = roda.end();
    while(!roda.empty()){
        int i=1,j=1;
        while(i<k) {
            if(it1==roda.end()) it1=roda.begin();
            else it1++;
            i++;
        }
        while(j<m)  {
            if(it2==roda.begin()) it2=roda.end();
            else it2--;
            j++;
        }


        cout << *it1 << " " << *it2 << endl;

        if(*it1==*it2){
            roda.erase(it1);
            it1++;
        }
        else {
            roda.erase(it1);
            roda.erase(it2);
            it2--;
            it1--;  
        }
        

        for(int x=0;x<roda.size();x++) cout << roda[x] << ' ';
        cout << endl;
    }





    return 0;
}