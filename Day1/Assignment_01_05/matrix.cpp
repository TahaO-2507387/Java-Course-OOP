#include <iostream>
#include <stdexcept>
#include <array>

class Matrix3
{
public:
    Matrix3() {};
    void init()
    {
        for (int i{}; i < 3; i++)
        {
            for (int j{}; j < 3; j++)
            {
                m_matrix[i][j] = i * j;
            }
        }
    }
    double get(int row, int col) const
    {
        if (0 < row < 3 && 0 < col < 3)
        {
            return m_matrix[row][col];
        }
        else
        {
            throw std::out_of_range("Index out of range\n");
        }
    }
    void set(int row, int col, double value)
    {
        if (0 <= row && row < 3 && 0 <= col && col < 3)
        {
            m_matrix[row][col] = value;
        }
        else
        {
            throw std::out_of_range("Index out of range\n");
        }
    }
    void add(const Matrix3 &m)
    {
        for (int i{}; i < 3; i++)
        {
            for (int j{}; j < 3; j++)
            {
                m_matrix[i][j] += m.get(i, j);
            }
        }
    }
    Matrix3 multiply(const Matrix3 &m) const
    {
        Matrix3 product{};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                double sum{};
                for (int k = 0; k < 3; k++)
                {
                    sum += (m_matrix[i][k] * m.get(k, j));
                }
                product.set(i, j, sum);
            }
        }
        return product;
    }
    void print() const
    {
        for (int i{}; i < 3; i++)
        {
            for (int j{}; j < 3; j++)
            {
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

private:
    std::array<std::array<double, 3>, 3> m_matrix{};
};

int main()
{
    Matrix3 m{};
    m.init();
    m.print();
    std::cout << '\n';
    Matrix3 m2{};
    m2.init();
    m.add(m2);
    m.print();
    Matrix3 m3 = m.multiply(m2);
    m3.print();
    return 0;
}
