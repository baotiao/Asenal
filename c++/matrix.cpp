#include <iostream>
#include "assert.h"

using namespace std;

class Matrix
{
    private:
        double adData[4][4];


    public:
        Matrix()
        {
            for (int nRows = 0; nRows < 4; nRows++) {
                for (int nCols = 0; nCols < 4; nCols++) {
                    adData[nRows][nCols] = 0.0;
                }
            }
        }
        double &operator()(const int nRow, const int nCol);
};

double& Matrix::operator()(const int nRow, const int nCol)
{
    assert(nRow >= 0 && nRow < 4);
    assert(nCol >= 0 && nCol < 4);
    return adData[nRow][nCol];
}
int main()
{
    Matrix m;
    m(3, 5); //调用运算符重载的方法
    return 0;
}
