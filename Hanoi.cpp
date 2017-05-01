#include <iostream>
#include <sstream>
#include <string>
#include <deque>

#include "Hanoi.h"

using std::cout;        using std::deque;
using std::endl;        using std::string;
using std::ostringstream;

void Hanoi::populate(deque<int> tower){
    for (int i = n; i > 0; i--){
        tower.push_front(i);
    }
}

void Hanoi::clear(deque<int> tower){
    while(!tower.empty()){
        tower.pop_front();
    }
}

void Hanoi::reset(){
    clear(A);
    clear(B);
    clear(C);

    populate(A);
}

string Hanoi::move(deque<int> origin, deque<int> objective){
    ostringstream stm;

    stm << "Moviendo " << origin.front() << endl;

    objective.push_front(origin.front());
    origin.pop_front();

    return stm.str();
}

string Hanoi::print_towers(){
    ostringstream stm;
    
    stm << "Lista A: " << print_tower(A) << endl;
    stm << "Lista B: " << print_tower(B) << endl;
    stm << "Lista C: " << print_tower(C) << endl;
    stm << endl;
    
    return stm.str();
}

string Hanoi::print_tower(deque<int> tower){
    deque<int>::iterator it;
    ostringstream stm;
    
    for (it = tower.begin(); it != tower.end(); it++){
        stm << *it << " | ";
    }
    
    return stm.str();
}

string Hanoi::solve_iterative(){
    ostringstream stm;
    stm << "Método: Iterativo" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;


    return stm.str();
}

string Hanoi::solve_recursion_simple(){
    ostringstream stm;
    stm << "Método: Recursivo Simple" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;


    return stm.str();
}

string Hanoi::solve_recursion_double(){
    ostringstream stm;
    stm << "Método: Recursivo Doble" << endl
        << "Estado de las torres al entrar: " << endl
        << print_towers()<< endl << endl;


    return stm.str();
}

Towers_Of_Hanoi.cpp // Método que sale en el Wolfgang
/** Recursive function for "moving" disks. pre: start_peg, dest_peg, temp_peg are different, n >= 1.
post: displays a list of moves that solve the problem of moving n disks from start_peg to dest_peg.
@param n is the number of disks
@param start_peg is the starting peg @param dest_peg is the destination peg
@param temp_peg is the temporary peg 
@return A string with all the required disk moves
*/
void show_moves(int n, char start_peg,
char dest_peg, char temp_peg) {
if (n == 1)
{
cout << "Move disk 1 from peg " << start_peg
<< " to peg " << dest_peg << "\n";
}
else
{ // Recursive step
show_moves(n - 1, start_peg, temp_peg, dest_peg);
cout << "Move disk " << n << " from peg " << start_peg
<< " to peg " << dest_peg << "\n";
show_moves(n - 1, temp_peg, dest_peg, start_peg);
}
}
