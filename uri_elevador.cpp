    // C++ program to use priority_queue to implement min heap
    #include <iostream>
    #include <queue>
    using namespace std;
    
    // Driver code
    int main ()
    {
        // Creates a min heap
        int n; cin >> n;
        priority_queue <int, vector<int>, greater<int> > cima;
        for(int i=0;i<n;i++) {
            int aux; cin >> aux;
            cima.push(aux);
        }
        bool vero = true;
        if(cima.top()>8) vero = false;
        else{
            int x= cima.top();
            cima.pop();
            while(!cima.empty()){
                if(abs(cima.top() - x) > 8) {
                    vero = false;
                    break;
                }
                else{
                    x = cima.top();
                    cima.pop();
                }
            }
        }
        if(vero) cout << "S\n";
        else cout << "N\n";
        return 0;
    }