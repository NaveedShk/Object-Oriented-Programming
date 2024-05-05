#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Matrix {
protected:
    T** data;

public:
    int rows, cols;

    Matrix(int r, int c)  {
        this->rows=r;
        this->cols=c;

        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T& get(int r, int c) {
        return data[r][c];
    }

    void set(int r, int c, T val) {
        data[r][c] = val;
    }

    const T** getData() const {
        return const_cast<const T**>(data);
    }

    Matrix<T>& operator=(const Matrix<T>& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;
            data = new T*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new T[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw "The dimensions for multiplication are invalid";
        }

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                T sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    virtual void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Specialized IntMatrix Class
class IntMatrix : public Matrix<int> {
public:
    IntMatrix(int r, int c) : Matrix<int>(r, c) {}

    IntMatrix(const Matrix<int>& other) : Matrix<int>(other.rows, other.cols) {
        const int** otherData = other.getData();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this->data[i][j] = otherData[i][j];
            }
        }
    }

    void display() const override {
        cout << "IntMatrix:" << endl;
        Matrix<int>::display();
    }
};

// Specialized DoubleMatrix Class
class DoubleMatrix : public Matrix<double> {
public:
    DoubleMatrix(int r, int c) : Matrix<double>(r, c) {}

    DoubleMatrix(const Matrix<double>& other) : Matrix<double>(other.rows, other.cols) {
        const double** otherData = const_cast<const double**>(other.getData());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this->data[i][j] = otherData[i][j];
            }
        }
    }

    void display() const override {
        cout << "DoubleMatrix:" << endl;
        Matrix<double>::display();
    }
};

int main() {
    IntMatrix intMat1(2, 3);
    intMat1.set(0, 0, 1);
    intMat1.set(0, 1, 2);
    intMat1.set(0, 2, 3);
    intMat1.set(1, 0, 4);
    intMat1.set(1, 1, 5);
    intMat1.set(1, 2, 6);

    IntMatrix intMat2(3, 2);
    intMat2.set(0, 0, 7);
    intMat2.set(0, 1, 8);
    intMat2.set(1, 0, 9);
    intMat2.set(1, 1, 10);
    intMat2.set(2, 0, 11);
    intMat2.set(2, 1, 12);

    IntMatrix intMatSum(intMat1 + intMat2);
    IntMatrix intMatDiff(intMat1 - intMat2);
    IntMatrix intMatProd(intMat1 * intMat2);

    intMatSum.display();
    intMatDiff.display();
    intMatProd.display();

    DoubleMatrix doubleMat1(2, 2);
    doubleMat1.set(0, 0, 1.5);
    doubleMat1.set(0, 1, 2.5);
    doubleMat1.set(1, 0, 3.5);
    doubleMat1.set(1, 1, 4.5);

    DoubleMatrix doubleMat2(2, 2);
    doubleMat2.set(0, 0, 5.5);
    doubleMat2.set(0, 1, 6.5);
    doubleMat2.set(1, 0, 7.5);
    doubleMat2.set(1, 1, 8.5);

    DoubleMatrix doubleMatSum(doubleMat1 + doubleMat2);
    DoubleMatrix doubleMatDiff(doubleMat1 - doubleMat2);
    DoubleMatrix doubleMatProd(doubleMat1 * doubleMat2);

    doubleMatSum.display();
    doubleMatDiff.display();
    doubleMatProd.display();

    return 0;
}
