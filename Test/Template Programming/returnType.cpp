#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Matrix {
    T** mat;

public:
    Matrix(int row, int col) {
        mat = new T * [row];
        for (int i = 0;i < row;i++) {
            mat[i] = new T[col];
        }
        mat[1][1] = 3.9;
    }
    T& at(int row_i, int col_j) {
        return mat[row_i][col_j];
    }
};
template<typename T, typename S>
T& get(int x, int y, Matrix<S>& a) {// this return a reference ,so cannot cout 3.9???
    return (T&)a.at(x, y);
}
int main() {
    Matrix<float> a(2, 3);
    cout << get<double>(1, 1, a);
    //cout << get<double>(1, 1, a) << endl;
    return 0;
}