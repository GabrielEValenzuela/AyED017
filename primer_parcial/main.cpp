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
        h.legal_move('A', 'C');
        stm << h.print_towers();
        if (h.solved()) break;
        ++pasos;
        h.legal_move('A', 'B');
        stm << h.print_towers();
        ++pasos;
        h.legal_move('C', 'A');
        stm << h.print_towers();
        ++pasos;
        h.legal_move('B', 'C');
        stm << h.print_towers();
    }

    stm << "Pasos totales: " << pasos << "." << endl << endl;

    return stm.str();
}

string solve_recursion_simple_aux(Hanoi& h, int pasos, ostringstream& stm){  

    ++pasos;
    h.legal_move('A', 'C');
    stm << h.print_towers();
    if (h.solved()) {
        stm << "Pasos totales: " << pasos << "." << endl << endl;
        return stm.str();
    }
    ++pasos;
    h.legal_move('A', 'B');
    stm << h.print_towers();
    ++pasos;
    h.legal_move('C', 'A');
    stm << h.print_towers();
    ++pasos;
    h.legal_move('B', 'C');
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
		
	ostringstream buffer_double;

    stm << solve_recursion_simple_aux(h, 0, buffer_double) << endl;

    return stm.str();
}

string solve_recursion_double_aux(Hanoi h, int steps, ostringstream& stm){
	
	// Incremento de pasos
	steps++;
	//Si está resuelto el problema, devuelve el string para el archivo
	
	 if (h.solved()) {
        stm << "Pasos totales: " << steps << "." << endl << endl;
        return stm.str();
    }
    
    /*Soloo hay 4 posibles casos de movimiento: De A a B, B a C, C a B, B a A. Por lo que depende del No de paso en el cual se encuentre
    la ejecución del programa. */
    stm << h.print_towers();
	if(h.is_legal(h.get_tower('A'),h.get_tower('B')) || h.is_legal(h.get_tower('B'),h.get_tower('A'))) {
		return solve_recursion_double_aux(h.legal_move('A','B'), steps, stm);
		}
	else if (h.is_legal(h.get_tower('B'),h.get_tower('C')) || h.is_legal(h.get_tower('C'),h.get_tower('B'))) {
		return solve_recursion_double_aux(h.legal_move('B','C'), steps, stm);
	}
}

int main(){
    ofstream log_file("Hanoi_log.txt");

    int n = 0;
    while (n <= 0 ){
        cout << "Introduzca el numero de discos: ";
        cin >> n;
        cout << endl;
    }

    Hanoi h(n);
	
	log_file << "Resolución de las Torres de Hanoi (Édouard Lucas --- 1863)\n\n";
	log_file << " _|_    |     |  \n";
	log_file << "__|__   |     |  \n";
	log_file << "===== ===== =====\n";
	log_file << "  A     B     C  \n\n";
    log_file << solve_recursion_simple(h);

    h.reset();
    log_file << solve_iterative(h);

    h.reset();
    log_file << solve_recursion_double(h);
    
    log_file << "  |     |    _|_\n";
	log_file << "  |     |   __|__\n";
	log_file << "===== ===== =====\n";
	log_file << "  A     B     C  \n\n";
    
    log_file.close();

    cout << "Problema resuelto. Log guardado en: Hanoi_log.txt" << endl;

    return 0;
}
