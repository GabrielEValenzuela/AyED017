#include <iostream>

#include "Hanoi.h"

using namespace std;

int main(){
    int n;
    cout << "Introduzca el numero de discos: ";
    cin >> n;

    Hanoi h = new Hanoi(n);

    h.solve_recursion_simple();

    h.reset();
    h.solve_iterative();

    h.reset();
    h.solve_recursion_double();

    return 0;
}
