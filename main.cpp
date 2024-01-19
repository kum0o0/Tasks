//Квадрат, расчет площади, периметра и длины диагонали.

#include <iostream>
#include "Square.h++"

int main() {
    sq::Square A;


    A.SetSide(6);

    std::cout<<A.Find_S(A.GetSide());
    return 0;

}
