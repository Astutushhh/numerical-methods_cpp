#include <eigen3/Eigen/Dense>
#include <iostream>
#include <windows.h>



int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    using namespace Eigen;
    using namespace std;

    // Матрица системы
    MatrixXd A(3, 3); // Заполняется элементами попорядку(сначала первая строка слева направо, потом втора и тд), первый элемент - номер строки с 0, второй - номер столбца с 0
    A << 2, 1, 1, 4, 3, 3, 8, 7, 9;
    
    // Вектор правой части
    VectorXd b(3);
    b << 1, 3, 7;
    
    cout << "=== Метод Гаусса ===" << endl;
    cout << "\nМатрица A:\n" << A << endl;
    cout << "\nВектор b:\n" << b << endl;
    
    // Решение
    VectorXd x = A.colPivHouseholderQr().solve(b);
    
    cout << "\nРешение x:\n" << x << endl;
    
    // Невязка
    VectorXd residual = A * x - b;
    cout << "\nНевязка (A*x - b):\n" << residual << endl;
    
    // Нормы невязки
    double norm1 = residual.norm();
    double norm_inf = residual.cwiseAbs().maxCoeff();
    
    cout << "\n||невязка||₂ = " << norm1 << endl;
    cout << "||невязка||_∞ = " << norm_inf << endl;
    
    cin.ignore();
    cout << "\nНажмите Enter для выхода...";
    cin.get();
    
    return 0;
}