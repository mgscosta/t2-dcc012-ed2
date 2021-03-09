#include <iostream>
#include "Arvb.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ArvB t(3);
    t.inserti(10);
    t.inserti(20);
    t.inserti(5);
    t.inserti(6);
    t.inserti(12);
    t.inserti(30);
    t.inserti(7);
    t.inserti(17);

    cout << "árvore percorrida é: ";
    t.cross();

    int k = 6;
    (t.searchNoh(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.searchNoh(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}
