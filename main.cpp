#include <iostream>
#include <fstream>

#include "Hanoi.h"

using namespace std;

int main(){
    ofstream log_file("Hanoi_log.txt");

    int n;
    cout << "Introduzca el numero de discos: ";
    cin >> n;

    Hanoi h(n);

    log_file << h.solve_recursion_simple();

    h.reset();
    log_file << h.solve_iterative();

    h.reset();
    log_file << h.solve_recursion_double();

    log_file.close();

    return 0;
}
