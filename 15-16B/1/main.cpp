//
// Created by matematyk60 on 17.06.17.
//


#include <iostream>


using namespace std;

template<class T>
class Matrix {
public:
    Matrix(int rows, int cols){
        if(rows < 1 || cols < 1){
            throw "Invalid size!";
        }
        this->rows = rows;
        this->cols = cols;
        matrix = new T[rows*cols];
        for(int i = 0 ; i < rows*cols ; i++){
            matrix[i] = T(2.3333+i);
        }
    }
    ~Matrix(){
        delete [] matrix;
    }

    T& operator()(int r, int c){
        if(r < 1 || r > rows || c < 0 || c > cols){
            throw "InvalidIndex";
        }
        return matrix[(r-1)*cols+c-1];
    }
    Matrix submatrix(int r1, int r2, int c1, int c2){
        if(c2<c1 || r2<r1 || c2>cols || r2>rows || r1 < 1 || c1 < 1){
            throw "InvalidIndex";
        }
        Matrix<T> copy(r2-r1+1,c2-c1+1);
        int p = 0;
        for(int i = r1 ; i <= r2 ; i++){
            for(int j = c1 ; j <= c2 ; j++){
                copy.matrix[p] = this->operator()(i,j);
                p++;
            }
        }
        return copy;

    }

    void PrintMatrix(){
        for(int i = 1 ; i < rows+1 ; i++){
            for(int j = 1 ; j < cols+1 ; j++){
                std::cout << this->operator()(i,j) << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    int rows;
    int cols;
    T* matrix;
};


int main(){
    Matrix<double> m1(5,3);
    m1.PrintMatrix();
    cout << endl << endl;

    auto m2 = m1.submatrix(1,4,2,3);
    m2.PrintMatrix();
};