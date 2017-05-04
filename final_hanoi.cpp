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

void Hanoi::legalMove(char origin_c, char objective_c){
    deque<int>& origin = get_tower(origin_c),& objective = get_tower(objective_c);

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

deque<int>& Hanoi::get_tower(char tower){
	
	
    switch(tower){
        case 'A':
            return A;
            break;
        case 'B':
            return B;
            break;
        case 'C':
            return C;
            break;
    }
}

deque<int>& Hanoi::get_tower_name(char tower){
	
	
    switch(tower){
        case 'A':
            return A;
            break;
        case 'B':
            return B;
            break;
        case 'C':
            return C;
            break;
    }
}
