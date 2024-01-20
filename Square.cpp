#include "Square.h++"
#include <iostream>
#include <cmath>

namespace sq
{
    void Square::SetSide(int a)
    {
        Side = a;
    }

    int Square::GetSide()
    {
        return Side;
    }

    Square::Square(int a): Side(a) {
    }

    Square::~Square() {
        std::cout << "\nDEFUALT Dist";
    }

    void Square::PrintAll()
    {
        std::cout <<"Side = "<< Side <<"\nS = "<< Find_S(Side) << "\nP = " << Find_P(Side) << "\nD = " << Find_D(Side);
    }

    int Square::Find_S(int Side)
    {
        return pow(Side,2);
    }

    int Square::Find_P(int Side)
    {
        return Side*4;
    }

    double Square::Find_D(int Side)
    {
        return sqrt(pow(Side,2)*2);
    }

}
