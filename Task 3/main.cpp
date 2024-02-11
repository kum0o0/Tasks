#include <iostream>
#include <cstring>

namespace mc {
    class String {
        char *m_str;
        int m_size;

    public:
        String() : String("") {}

        String(const char* str)
        {
            std::cout << "Constr" << std::endl;
            m_size = strlen(str) + 1;
            m_str = new char[m_size];
            std::copy(str, str+m_size, m_str);
        }

        ~String()
        {
            std::cout << "Destr" << std::endl;
            if (!m_str) return;
            delete[] m_str;

        }

        String(const String& other) : String(other.m_str) // конструктор копирования
        {
            std::cout << "copy constr" << std::endl;
        }


        // =
        void Swap(String& other)
        {
            std::swap(m_str, other.m_str);
            std::swap(m_size, other.m_size);
        }
        String& operator=(String other)
        {
            Swap(other);
            return *this;
        }


        // +
        String operator+(const String& other)
        {
            String tmp;
            tmp.m_size = this->m_size + other.m_size - 1;
            tmp.m_str = new char[m_size];

            int i = 0;
            for(; i < m_size-1; i++)
            {
                tmp.m_str[i] = m_str[i];
            }
            for(int j = 0; j < other.m_size; i++,j++)
            {
                tmp.m_str[i] = other.m_str[j];
            }

            return tmp.m_str;
        }

        // +=
        String& operator+=(const String other)
        {
            *this = *this + other;

            return *this;
        }


        // << >>
        friend std::ostream& operator<<(std::ostream& out,const String& str);
        friend std::istream& operator>>(std::istream& in,const String& str);


        // []
        char& operator[](int index){
            return m_str[index];
        }

        const char& operator[](int index) const{
            return m_str[index];
        }

        // ==
        bool operator==(const String& other)
        {
            return !strcmp( m_str,other.m_str);
        }

        // >
        bool operator>(const String& other)
        {
            return strcmp(m_str,other.m_str) > 0;
        }

        // <
        bool operator<(const String& other)
        {
            return strcmp(m_str,other.m_str) < 0;
        }

        // length
        int length()
        {
            return m_size-1;
        }

        char* c_str()
        {
            return m_str;
        }

        int find(char a)
        {
            for (int i = 0; i < m_size; ++i) {
                    if (m_str[i] == a)
                        return i;
            }
            return char('not find');
        }

        char at(int i)
        {

            if(i < m_size && i > 0)
                return m_str[i];
            std::cout << "out of range";
            return 0;
        }

    };

    std::ostream& operator<<(std::ostream& out,const String& str)
    {
        out<<str.m_str;
        return out;
    }
    std::istream& operator>>(std::istream& in,const String& str)
    {
        in>>str.m_str;
        return in;
    }



}

int main() {

    mc::String A("abc");
    mc::String B;

    mc::String C("dfe");




    std::cout << C << std::endl;



    return 0;
}
