#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "Hanoi.h"

using std::cout;        using std::stack;
using std::endl;        using std::string;

Hanoi::Hanoi(int NoD){
    n = NoD;
    
    populate(A);
    clear(B);
    clear(C);
}

void Hanoi::populate(stack<int> tower){
    for (int i = n; i > 0; i--){
        tower.push(i);
    }
}

void Hanoi::clear(stack<int> tower){
    while(!tower.empty()){
        tower.pop();
    }
}

void Hanoi::reset(){
    clear(A);
    clear(B);
    clear(C);

    populate(A);
}

void Hanoi::move(stack<int> origin, stack<int> objective){
    objective.push(origin.top());
    origin.pop();
}

void Hanoi::print_towers(){
    osstream stm;
    
    stm << "Lista A: " << print_tower(A) << endl;
    stm << "Lista B: " << print_tower(B) << endl;
    stm << "Lista C: " << print_tower(C) << endl;
    stm << endl;
    
    cout << stm.str();
}

string Hanoi::print_tower(stack<int> tower){
    list<int> buffer_list (tower);
    ostream stm;
    
    for (int i = 0; i < n; i++){
        stm << buffer_list[i] << " | "
    }
    
    return stm.str();
}

void Hanoi::solve_iterative(){

}

void Hanoi::solve_recursion_simple(){

}

void Hanoi::solve_recursion_double(){

}
