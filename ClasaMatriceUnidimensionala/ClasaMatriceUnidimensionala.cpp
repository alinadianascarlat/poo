#include <iostream>

int main()
{
    Matrice* m = new Matrice();

    m->read();
    // citesti numarul de linii si coloane
    // citesti matricea si o salvezi intr-un tablou unidimensional

    m->print(); // iti afiseaza sub forma de matrice
    //  1 2 3
    //  3 4 5

    int lines = m->numberOfLines();
    int cols = m->numberOfColums();
    int ** matrice1 = m->toBidimensional(); // returnezi o matrice bidiminensionala
    // afisezi matrice1

}
