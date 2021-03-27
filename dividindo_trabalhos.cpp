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


int main () {
     int n;
    while(true){
        cin >> n;
        if(!cin) break;
        int lista[n+1];
        for(int i=0;i<n;i++) cin >> lista[i];


        int i=0, j=n-1;
        int rangel=0, gugu=0;
        while(i<=j){
            if(rangel<gugu){
                rangel+=lista[i];
                i++;
            }
            else{ 
                gugu += lista[j];
                j--;
            }
        }
        int x = rangel - gugu;
        if(x<0) x = -x;
        cout << x << endl;

    }

    return 0;
}