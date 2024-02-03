#include <iostream>
#include <random>

namespace mt
{
    class matrix
    {
        int N;//строки
        int M;//стобцы
        int **mas;


    public:
        matrix(int n, int m): N(n), M(m)
        {

            mas = new int* [N];
            for(int i = 0; i < N; i++) {
                mas[i] = new int[M];
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    mas[i][j] = rand() % 10;
                }
            }

            std::cout << "Const" << this << "\n";
        }
        ~matrix()
        {
            for (int i = 0; i < N; ++i)
                delete[] mas[i];
            delete[] mas;

            std::cout << "Dest" << this << "\n";
        }


        matrix(const matrix& other) //конструктор копирования
        {
            N = other.N;
            M = other.M;
            mas = new int* [N];

            for(int i = 0; i < N; i++) {
                mas[i] = new int[M];
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    mas[i][j] = other.mas[i][j];
                }
            }
            std::cout<<"CopyConstr"<< this << "\n";

        }

        matrix & operator = (const matrix& other) //Оператор присваивания копированием
        {
            for (int i = 0; i < N; ++i)
                delete[] mas[i];
            delete[] mas;
            

            N = other.N;
            M = other.M;
            this->mas = new int* [N];

            for(int i = 0; i < N; i++) {
                this->mas[i] = new int[M];
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    this->mas[i][j] = other.mas[i][j];
                }
            }
            std::cout << "Oper" << this << "\n";
            return  *this;

        }


        void Print() {
            for (int i = 0; i < N; i++) {
                std::cout << "\n";
                for (int j = 0; j < M; j++)
                    std::cout << mas[i][j];
            }
        }
    };
}

int main() {

    mt::matrix A(2,3);
    A.Print();
    mt::matrix B(A);
    B.Print();

    



    std::cout << "\n";

    return 0;
}
