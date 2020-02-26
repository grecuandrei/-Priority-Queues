#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("testX.out",ios::out); /// unde X este numarul testului

    srand(time(nullptr));

    file<<Y<<" "; /// unde Y este numarul de operatii aplicate pe implementari
    file<<Z<<" "; /// unde Z este numarul de elemente

    for( int x = 0; x < Z; x++){
        file<<rand() % Z + OF<<" "; /// unde OF este "offset-ul" dat
                                    /// adica daca OF e cu -Z/2 vor exista
                                    /// si numere negative in teste
    }

    file.close();
    return 0;
}
