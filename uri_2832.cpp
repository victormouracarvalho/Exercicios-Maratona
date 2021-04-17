    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <set>
    using namespace std;

    int main()
    {
        long long int n,f; scanf("%lli%lli", &n, &f);
        long long int lista[n];
        for(int i =0;i<n;i++) scanf("%lli", &lista[i]);
        long long int dias=1;
        long long int acc=0;
        
        long long int esq=1, dir = 100000000;
        while(esq<dir){
            int rodada = 0;
            long long int meio = (esq + dir)/2;
            
            for(int i=0;i<n;i++)
                rodada += meio /lista[i];

            if(rodada >=f){
                dir = meio;
            }
            else {
                esq = meio+1;
            }
        }


        printf("%lli\n", esq);

        return 0;
    }