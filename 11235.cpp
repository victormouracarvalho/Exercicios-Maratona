#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int *segtreeBuild(int V[], int n, string type)
{
    int *tree = (int *)malloc((2 * n) * sizeof(int));
    //leaves
    for (int i = 0; i < n; i++)
        tree[i + n] = V[i];
    if (type == "sum")
    { //Sum-tree
        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    else if (type == "min")
    { //Min-tree
        for (int i = n - 1; i > 0; i--)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    else if (type == "max")
    { //Max-tree
        for (int i = n - 1; i > 0; i--)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    return tree;
}

//retorna um valor (sum, min, max) do intervalo [a, b]
int segtreeQuery(int tree[], int n, int a, int b, string type)
{
    int s = 0;
    a += n;
    b += n;
    if (type == "sum")
    { //Sum-tree
        while (a <= b)
        {
            if (a % 2 == 1)
                s += tree[a++];
            if (b % 2 == 0)
                s += tree[b--];
            a /= 2;
            b /= 2;
        }
    }
    else if (type == "min")
    { //Min-tree
        s = tree[a];
        while (a <= b)
        {
            if (a % 2 == 1)
                s = min(s, tree[a++]);
            if (b % 2 == 0)
                s = min(s, tree[b--]);
            a /= 2;
            b /= 2;
        }
    }
    else if (type == "max")
    { //Max-tree
        s = tree[a];
        while (a <= b)
        {
            if (a % 2 == 1)
                s = max(s, tree[a++]);
            if (b % 2 == 0)
                s = max(s, tree[b--]);
            a /= 2;
            b /= 2;
        }
    }
    return s;
}

//atualiza o valor A[i]=valor
void segtreeUpdate(int tree[], int n, int i, int valor, string type)
{
    i += n;
    tree[i] = valor;
    if (type == "sum")
    { //Sum-tree
        for (i /= 2; i >= 1; i /= 2)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    else if (type == "min")
    { //Min-tree
        for (i /= 2; i >= 1; i /= 2)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    else if (type == "max")
    { //Max-tree
        for (i /= 2; i >= 1; i /= 2)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
}

int main()
{
while(true){
    int N, q;
    scanf("%d", &N);
    if(N ==0) break;
    scanf("%d", &q);
    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    // for(int i =0;i<N; i++) cout << V[i] << " ";
    // cout << endl;
    // for(auto it: contador) cout << it << " ";
    // cout << endl;
   
    // for(int i =0;i<N; i++) cout << V[i] << " ";
    // cout << endl;
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        int lista[N];
        multiset<int> contador;
        int j=0;
        for (int i =a-1;i<b;i++){
             lista[j] = V[i];
             contador.insert(lista[j]);
             j++;
        }
        for(int i =0; i<j; i++) lista[i] = contador.count(lista[i]);
        // for(int i =0; i<j; i++) cout << lista[i] << " ";
        // cout << endl;



        int *tree = segtreeBuild(lista, j, "max");
        // for(int i =0;i<N; i++) cout << V[i] << " ";
        // cout << endl;
        cout<<segtreeQuery(tree, j, 0, j-1, "max")<<endl;
        free(tree);
    }

}
    return 0;
}