#include <iostream>
#include "NohB.h"
#include "BTree.h"
using namespace std;

int main()
{
    BTree t(3);
    t.inserti(10); 
    t.inserti(20); 
    t.inserti(5); 
    t.inserti(6); 
    t.inserti(12); 
    t.inserti(30); 
    t.inserti(7); 
    t.inserti(17); 
  
    cout << "árvore percorrida é: "; 
    t.traverse(); 
  
    int k = 6; 
    (t.searchN(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
  
    k = 15; 
    (t.searchN(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present"; 
  
    return 0; 
}
