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

        /** Mueve el disco superior desde 'origin' hasta 'objective'.
            @param origin Torre de donde sacar el disco.
            @param objective Torre en donde colocarlo.
            @returns Un string indicando el elemento que fue movido.
          */
        void move(std::deque<int>& origin, std::deque<int>& objective);
        
        /** Saca todos los discos de la torre 'tower'.
            @param tower Torre a vaciar.
          */
        void clear(std::deque<int>& tower);
    
        /** Genera el string para imprimir de una sola torre.
            @param tower: Torre a imprimir.
            @returns Un string con el estado de la torre.
          */
        std::string print_tower(const std::deque<int>& tower);

        std::deque<int>& get_tower(char tower);

    public:
        /** Constructor. Crea las tres torres, llena la torre a con 'n' discos.
            @param NoD NÃºmero de discos.
          */
        Hanoi(int NoD): n(NoD) { reset(); };

        /** Mueve el disco superior entre una torre y otra Ã©n la direccion que sea legal.
            @param origin Torre de donde sacar el disco.
            @param objective Torre en donde colocarlo.
            @returns Un string indicando el elemento que fue movido.
          */
        void legalMove(char origin, char objective);

       /** Resetea el sistema al estado original.
          */
        void reset();
    
        /** Estado del sistema.
            @return true si el sistema estÃ¡ resuelto.
          */
        bool solved() const { return C.size() == n; };

        bool isLegal(const std::deque<int>& origin, const std::deque<int>& destination) const;
    
        /** Arma un string con el estado de las tres torres.
          @returns El strring con dicho estado.
          */
        std::string print_towers();
        
        std::deque<int>& get_tower_name(char tower);
        
};
