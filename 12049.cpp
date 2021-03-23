#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main () {
    int n,m;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        multiset<int> list1;
        multiset<int> list2;
         int aux;
         for (int i=0;i<n; i++) {cin >> aux; list1.insert(aux);}
         for (int i=0;i<m; i++) {cin >> aux; list2.insert(aux);}
        multiset<int> l1 = list1;
        multiset<int> l2 = list2;
        
        
        for(auto it: list1){
            if(list2.count(it)!=0) {
                l1.erase(it);
            }
        }
                
        for(auto it: list2){
            if(list1.count(it)!=0) {
                l2.erase(it);
            }
        }
        multiset<int> x,y,z;

        set_difference(make_move_iterator(list1.begin()), 
                    make_move_iterator(list1.end()), 
                    l1.begin(), l1.end(), 
                    inserter(x, x.begin()));
        set_difference(make_move_iterator(list2.begin()), 
                            make_move_iterator(list2.end()), 
                            l2.begin(), l2.end(), 
                            inserter(y, y.begin()));
        set_difference(make_move_iterator(y.begin()), 
                            make_move_iterator(y.end()), 
                            x.begin(), x.end(), 
                            inserter(z, z.begin()));
        set_difference(make_move_iterator(x.begin()), 
                            make_move_iterator(x.end()), 
                            y.begin(), y.end(), 
                            inserter(z, z.begin()));

 
 
        
        
        // cout << endl;
        // for(auto it: x) cout << it << " ";
        // cout << endl;
        // for(auto it: y) cout << it << " ";
        // cout << endl;
        // for(auto it: z) cout << it << " ";
        // cout << endl;
        // cout << list1.size() << " " << list2.size() << endl;
        // cout << x.size() << "  " << y.size() << endl;
        // cout << z.size() << endl;

        cout  << (list1.size()-x.size()) + (list2.size()-y.size()) + z.size() << endl;
    }
    return 0;
}