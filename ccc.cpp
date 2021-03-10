#include <iostream>
#include <stack>
using namespace std;

int main (){
	int n; cin >> n;
	int lista[n];

	stack<int> entrada;
	stack<int> meio;
	stack<int> saida;
	for (int i=0;i<n;i++)
		entrada.push(n-i);

	while(!entrada.empty()) {
		cout << entrada.top() << " ";
		entrada.pop();
	}
	cout << "\n";
	return 0;
}