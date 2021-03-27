#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Student
{
    string name; // Given
    int math; // Marks in math (Given)
    int phy; // Marks in Physics (Given)
    int che; // Marks in Chemistry (Given)
    int total; // Total marks (To be filled)
    int rank; // Rank of student (To be filled)
};

int comparador(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}
 
int comparador2(const void *a, const void *b) {
   if (*(int*)a > *(int*)b) {
      return 1;
   } else if (*(int*)a < *(int*)b) {
      return -1;
   } else {
      return 0;
   }
}


bool compareStrings(Student a, Student b)
{
    // If total marks are not same then
    // returns true for higher total
    if(a.name!=b.name) return a.name > b.name;
    if (a.total != b.total)
        return a.total > b.total;
 
    // If marks in Maths are same then
    // returns true for higher marks
    if (a.math != b.math)
        return a.math > b.math;
 
    if (a.phy != b.phy)
        return a.phy > b.phy;
 
    return (a.che > b.che);
}


// Fills total marks and ranks of all Students
void computeRanks(Student a[], int n)
{
    // To calculate total marks for all Students
    for (int i = 0; i < n; i++)
        a[i].total = a[i].math + a[i].phy + a[i].che;
 
    // Sort structure array using user defined
    // function compareTwoStudents()
    sort(a, a + 5, compareTwoStudents);
 
    // Assigning ranks after sorting
    for (int i = 0; i < n; i++)
        a[i].rank = i + 1;
}
 

 

int main (){
    int n; cin >> n;
    int lista[n];
    for(int i=0;i<n;i++){
        cin >> lista[i];
    }

    qsort(lista, n, sizeof(int), comparador);
// sort (lista.begin(), lista.end(), myobject);
    for(auto i: lista) cout << i << " ";
    cout << endl;

    return 0;
}