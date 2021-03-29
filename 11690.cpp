#include <iostream>
#include <vector>

#define MAXN 1000000

using namespace std;

// declaro as variáveis que vou precisar

// funções do Union-Find otimizadas
int Find(int G[], int x)
{
    while (G[x] != x)
    {
        G[x] = G[G[x]]; //path compression
        x = G[x];
    }
    return x;
}

int Union(int G[], int size[], int a, int b, int debt[])
{
    int A = Find(G, a); //set of a
    int B = Find(G, b); //set of b
    if (A == B)
        return 0;
    if (size[A] < size[B])
    { //smallest points to the bigger

        size[B] += size[A]; //update size
        debt[B] += debt[A]; //update size
        debt[A] = 0;
        G[A] = B;
        return B;
    }
    else
    {
        size[A] += size[B];
        debt[A] += debt[B];
        debt[B]=0;
        G[B] = A;
        return A;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int G[n + 1], size[n + 1], debt[n + 1];
        for (int i = 1; i < n+1; i++) cin >> debt[i];
        for(int i =1; i<n+1; i++){
            G[i]=i;
            size[i]=1;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            int x = Union(G, size, a + 1, b + 1, debt);
        }
        // for (auto i : debt) cout << i << " ";
        // cout << endl;
        // for (auto i : G) cout << i << " ";
        // cout << endl;

        bool vero = false;
        for(int i=1;i<n+1;i++){
            if(debt[i]!=0) {
                vero=true;
                break;
            }
        }
        if(!vero) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }
}