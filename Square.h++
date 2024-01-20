#pragma once


namespace sq{

    class Square{
    public:
        void PrintAll();
        Square(int Side);
        ~Square();
        void SetSide(int Side);
        int GetSide();
        int Find_S(int Side);
        int Find_P(int Side);
        double Find_D(int Side);
    private:
        int Side;
    };
}


