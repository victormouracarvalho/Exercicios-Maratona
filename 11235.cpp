#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    while (true)
    {
        int N, q;
        scanf("%d", &N);
        if (N == 0)
            break;
        scanf("%d", &q);
        int V[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &V[i]);
        }
        // for(int i =0;i<N; i++) cout << V[i] << " ";
        // cout << endl;
        // for(auto it: contador) cout << it << " ";
        // cout << endl;

        // for(int i =0;i<N; i++) cout << V[i] << " ";
        // cout << endl;
        while (q--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int lista[N];
            int j = 0;
            int maior = 0;
            for (int i = a - 1; i < b; i++)
            {
                if (i == a - 1)
                {
                    lista[j] = 1;
                }
                else if (V[i] == V[i - 1] and j > 0)
                {
                    lista[j] = lista[j - 1] + 1;
                }
                else if (V[i] != V[i - 1] and j > 0)
                {
                    lista[j] = 1;
                }
                else if (i == b - 1)
                {
                    lista[j] = lista[j - 1] + 1;
                }
                if (lista[j] > maior)
                    maior = lista[j];
                j++;
                //  lista[j] = V[i];
                //  contador.insert(lista[j]);
                //  j++;
            }
            // for(int i =0; i<j; i++) lista[i] = contador.count(lista[i]);
            // for(int i =0; i<j-1; i++) cout << lista[i] << " ";
            // cout << endl;
            cout << maior << endl;
            // int *tree = segtreeBuild(lista, j, "max");
            // for(int i =0;i<N; i++) cout << V[i] << " ";
            // cout << endl;
            // cout<<segtreeQuery(tree, j, 0, j-1, "max")<<endl;
            // free(tree);
        }
    }
    return 0;
}