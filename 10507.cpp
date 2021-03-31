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


class UnionFind {                                              // OOP style
public:
  vector<int> p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};





int main () {
    int n, m;
    while(cin >> n >> m){
        UnionFind UF(26);
        string str;
        getline(cin, str);
        getline(cin, str);
        cout << str << endl;
       
        for(int i=0;i<26;i++) cout << UF.rank[i] << " ";
        cout << endl;

        for(int i=0;i<m;i++){
            cin >> str;
            int first = str[0]-'A';
            int second = str[1]-'A';
            UF.unionSet(first,second);
        }
        for(int i=0;i<26;i++) cout << UF.rank[i] << " ";
        cout << endl;
        for (int i = 0; i < 26; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
            printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }

  return 0;
}

