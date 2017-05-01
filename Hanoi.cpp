#include <iostream>
#include <sstream>
#include <string>
#include <deque>

#include "Hanoi.h"

using std::cout;        using std::deque;
using std::endl;        using std::string;
                        using std::ostringstream;

void Hanoi::clear(deque<int>& tower){
    while(!tower.empty()){
        tower.pop_front();
    }
}

void Hanoi::reset(){
    for (int i = 0; i < n; i++) A.push_front(i);
    clear(B);
    clear(C);
}

bool Hanoi::isLegal(const deque<int>& origin, const deque<int>& destination) const{
    if (origin.empty()) return false;
    else if (destination.empty()) return true;
    else return origin.back() < destination.back();
}

void Hanoi::move(deque<int>& origin, deque<int>& objective){
    objective.push_back(origin.back());
    origin.pop_back();
}

void Hanoi::legalMove(deque<int>& origin, deque<int>& objective){
    if (isLegal(origin, objective)){
        move(origin, objective);
    } else if (isLegal(objective, origin)){
        move(objective, origin);
    }
}

string Hanoi::print_towers(){
    ostringstream stm;
    
    stm << "Lista A: " << print_tower(A) << endl;
    stm << "Lista B: " << print_tower(B) << endl;
    stm << "Lista C: " << print_tower(C) << endl;
    stm << endl;
    
    return stm.str();
}

string Hanoi::print_tower(const deque<int>& tower) {
    deque<int>::const_iterator it;
    ostringstream stm;
    
    for (it = tower.begin(); it != tower.end(); it++){
        stm << *it << " | ";
    }
    
    return stm.str();
}

string Hanoi::solve_iterative_aux(){
    ostringstream stm;
    int pasos = 0;
    
    while (true){
        ++pasos;
        legalMove(A, C);
        stm << print_towers();
        if (solved()) break;
        ++pasos;
        legalMove(A, B);
        stm << print_towers();
        ++pasos;
        legalMove(C, A);
        stm << print_towers();
        ++pasos;
        legalMove(B, C);
        stm << print_towers();
    }

    stm << "Pasos totales: " << pasos << ".";

    return stm.str();
}

string Hanoi::solve_iterative(){
    ostringstream stm;
    stm << "Método: Iterativo" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;

    stm << solve_iterative_aux() << endl;

    return stm.str();
}

string Hanoi::solve_recursion_simple(){
    ostringstream stm;
    stm << "Método: Recursivo Simple" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;

    //solve_recursion_simple_aux(n, A, C);

    return stm.str();
}

string Hanoi::solve_recursion_double(){
    ostringstream stm;
    stm << "Método: Recursivo Doble" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;


    return stm.str();
}
