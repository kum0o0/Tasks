//Квадрат, расчет площади, периметра и длины диагонали.

#include <iostream>
#include "Square.h++"

int main() {
    int some = 4;
    sq::Square A(some);


    //   A.PrintAll();
    std::cout<<A.Find_S(A.GetSide());
    return 0;

}