#include <iostream>
#include <sstream>
#include <fstream>

#include "Hanoi.h"

using namespace std;

string solve_iterative_aux(Hanoi& h){
    ostringstream stm;
    int pasos = 0;
    
    while (true){
        ++pasos;
        h.legalMove('A', 'C');
        stm << h.print_towers();
        if (h.solved()) break;
        ++pasos;
        h.legalMove('A', 'B');
        stm << h.print_towers();
        ++pasos;
        h.legalMove('C', 'A');
        stm << h.print_towers();
        ++pasos;
        h.legalMove('B', 'C');
        stm << h.print_towers();
    }

    stm << "Pasos totales: " << pasos << "." << endl << endl;

    return stm.str();
}

string solve_recursion_simple_aux(Hanoi& h, int pasos, ostringstream& stm){  

    ++pasos;
    h.legalMove('A', 'C');
    stm << h.print_towers();
    if (h.solved()) {
        stm << "Pasos totales: " << pasos << "." << endl << endl;
        return stm.str();
    }
    ++pasos;
    h.legalMove('A', 'B');
    stm << h.print_towers();
    ++pasos;
    h.legalMove('C', 'A');
    stm << h.print_towers();
    ++pasos;
    h.legalMove('B', 'C');
    stm << h.print_towers();

    return solve_recursion_simple_aux(h, pasos, stm);
}

string solve_iterative(Hanoi& h){
    ostringstream stm;
    stm << "Método: Iterativo" << endl
        << "Estado de las torres al entrar: " << endl << endl
        << h.print_towers();

    stm << solve_iterative_aux(h) << endl;

    return stm.str();
}

string solve_recursion_simple(Hanoi& h){
    ostringstream stm;
    stm << "Método: Recursivo Simple" << endl
        << "Estado de las torres al entrar: " << endl << endl
        << h.print_towers();

    ostringstream buffer;

    stm << solve_recursion_simple_aux(h, 0, buffer) << endl;

    return stm.str();
}

string solve_recursion_double(Hanoi& h){
    ostringstream stm;
    stm << "Método: Recursivo Doble" << endl
        << "Estado de las torres al entrar: " << endl << endl
        << h.print_towers();


    return stm.str();
}

int main(){
    ofstream log_file("Hanoi_log.txt");

    int n;
    cout << "Introduzca el numero de discos: ";
    cin >> n;

    Hanoi h(n);

    log_file << solve_recursion_simple(h);

    h.reset();
    log_file << solve_iterative(h);

    //h.reset();
    //log_file << solve_recursion_double(h);

    log_file.close();

    return 0;
}
