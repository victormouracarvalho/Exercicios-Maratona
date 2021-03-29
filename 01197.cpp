#include <iostream>
#include <vector>
#include <set>
using namespace std;

int Find(int G[], int x)
{
    while (G[x] != x)
    {
        G[x] = G[G[x]]; //path compression
        x = G[x];
    }
    return x;
}

int Union(int G[], int size[], int a, int b)
{
    int A = Find(G, a); //set of a
    int B = Find(G, b); //set of b
    if (A == B)
        return 0;
    if (size[A] < size[B])
    { //smallest points to the bigger

        size[B] += size[A]; //update size
        G[A] = B;
        return B;
    }
    else
    {
        size[A] += size[B];
        G[B] = A;
        return A;
    }
}




int main () {
    ios::sync_with_stdio(false);
    int n, m;
    while(true){
        cin >> n >> m;
        if(n==0 and m==0) break;
        int G[n + 1], size[n + 1];
        for(int i =1; i<n+1; i++){
                G[i]=i;
                size[i]=1;
        }
        for(int i=1;i<m+1;i++){
            int k;cin >> k;
            int first; cin >> first;
            for(int j=1;j<k;j++){
                int x; cin >> x;
                int a = Union(G, size, first + 1, x + 1);
            }
        }
        // for(int i=1;i<n+1; i++) cout << size[i] << " ";
        // cout << endl;
        // cout << G[1] << endl;
        cout << size[G[1]] << endl;

    }


}

