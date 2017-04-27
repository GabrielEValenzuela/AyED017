#include <iostream>
#include <sstream>
#include <string>
#include <deque>

#include "Hanoi.h"

using std::cout;        using std::deque;
using std::endl;        using std::string;
using std::list;        using std::ostringstream;

Hanoi::Hanoi(int NoD): n(NoD) {
    populate(A);
    clear(B);
    clear(C);
}

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

void Hanoi::move(deque<int> origin, deque<int> objective){
    objective.push_front(origin.front());
    origin.pop_front();
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

void Hanoi::solve_iterative(){

}

void Hanoi::solve_recursion_simple(){

}

void Hanoi::solve_recursion_double(){

}
