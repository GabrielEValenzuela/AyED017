#include <iostream>
#include <stack>

#include "Hanoi.h"

using std::cout;        using std::stack;
using std::endl;

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

void Hanoi::solve_iterative(){

}

void Hanoi::solve_recursion_simple(){

}

void Hanoi::solve_recursion_double(){

}
