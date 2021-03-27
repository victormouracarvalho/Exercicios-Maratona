#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

string RemoveSpecials(string str)
{
	int i=0,len=str.length();
	while(i<len)
	{
		char c=str[i];
		if(((c>='0')&&(c<='9'))||((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z'))) 
		{
			if((c>='A')&&(c<='Z')) str[i]+=32; //Assuming dictionary contains small letters only.
            if((c>='0')&&(c<='9')) str[i]= ' ';
			++i;
		}
		else
		{
			str[i] = ' ';
            i++;
		}
	}
	return str;
}
void imprime (set<string> unicos){
    for(auto i: unicos) cout << i << endl;
}


int main () {
    string linha;
    vector<string> palavras;
        set<string> unicos;
    while(true){
        cin >> linha;
        if(!cin) {
            imprime(unicos);
            break;
        }
        linha =RemoveSpecials(linha);
        string token;
        istringstream ss(linha);
        while(ss >> token){
            // cout << token << " ";
            unicos.insert(token);
        }

    }





    return 0;
}