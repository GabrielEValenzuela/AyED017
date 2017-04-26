#include <stack>

class Hanoi {
    private:
        /** Tres pilas representando cada torre.
          */
        std::stack<int> A, B, C;

        /** Cantidad de discos.
          */
        int n;

        /** Mueve el disco superior entre una torre y otra.
            @param origin Torre de donde sacar el disco.
            @param objective Torre en donde colocarlo.
          */
        void move();

        /** Llena la torre 'tower' con "discos" en orde creciente.
            @param tower Torre a llenar.
          */
        void populate(std::stack<int> tower);
        
        /** Saca todos los discos de la torre 'tower'.
            @param tower Torre a vaciar.
          */
        void clear(std::stack<int> tower);

    public:
        /** Constructor.
            @param NoD Número de discos.
          */
        Hanoi(int NoD);

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
};
