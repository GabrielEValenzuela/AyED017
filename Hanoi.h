#include <deque>
#include <string>

class Hanoi {
    private:
        /** Tres pilas representando cada torre.
          */
        std::deque<int> A, B, C;

        /** Cantidad de discos.
          */
        int n;

        /** Mueve el disco superior entre una torre y otra.
            @param origin Torre de donde sacar el disco.
            @param objective Torre en donde colocarlo.
          */
        void move(std::deque<int> origin, std::deque<int> objective);

        /** Llena la torre 'tower' con "discos" en orde creciente.
            @param tower Torre a llenar.
          */
        void populate(std::deque<int> tower);
        
        /** Saca todos los discos de la torre 'tower'.
            @param tower Torre a vaciar.
          */
        void clear(std::deque<int> tower);
    
        /** Genera el string para imprimir de una sola torre.
            @param tower: Torre a imprimir.
          */
        std::string print_tower(std::deque<int> tower);

    public:
        /** Constructor.
            @param NoD Número de discos.
          */
        Hanoi(int);

        /** Resuelve el puzzle con un método iterativo.
          */
        void solve_iterative();
        
        /** Resuelve el puzzle con un método recursivo simple.
          */ 
        void solve_recursion_simple();
        
        /** Resuelve el puzzle con un étodo recursivo doble.
          */ 
        void solve_recursion_double();

        /** Resetea el sistema al estado original.
          */
        void reset();
    
        /** Estado del sistema.
            @return true si el sistema está resuelto.
          */
        bool solved() { return C.size() == n; };
    
        /** Imprime el estado de las tres torres.
          */
        std::string print_towers();
};
