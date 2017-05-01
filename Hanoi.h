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
            @returns Un string indicando el elemento que fue movido.
          */
        std::string move(std::deque<int> origin, std::deque<int> objective);

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
            @returns Un string con el estado de la torre.
          */
        std::string print_tower(std::deque<int> tower);

    public:
        /** Constructor. Crea las tres torres, llena la torre a con 'n' discos.
            @param NoD Número de discos.
          */
        Hanoi(int NoD): n(NoD) { reset(); };

        /** Resuelve el puzzle con un método iterativo.
          @returns Un string con todo el proceso para resolver el sistema.
          */
        std::string solve_iterative();
        
        /** Resuelve el puzzle con un método recursivo simple.
          @returns Un string con todo el proceso para resolver el sistema.
          */ 
        std::string solve_recursion_simple();
        
        /** Resuelve el puzzle con un método recursivo doble.
          @returns Un string con todo el proceso para resolver el sistema.
          */ 
        std::string solve_recursion_double();

        /** Resetea el sistema al estado original.
          */
        void reset();
    
        /** Estado del sistema.
            @return true si el sistema está resuelto.
          */
        bool solved() { return C.size() == n; };
    
        /** Arma un string con el estado de las tres torres.
          @returns El strring con dicho estado.
          */
        std::string print_towers();
};
