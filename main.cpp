#include <eigen3/Eigen/Dense>
#include <iostream>
#include <windows.h>
#include "Gauss_solver.h" 



int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    using namespace Eigen;
    using namespace std;

    MatrixXd matrix(4, 4);
    matrix << 31.2000,        -1.3200,        -7.6800,         4.0900,
              7.2300,      -126.0000,         7.1400,         3.0400,
              9.4900,         6.4000,         6.0000,         8.4500,
              2.6800,        -3.2900,         0.2800,        13.4000;

    VectorXd b(4);
    b << -83.3200, 38.9000, -56.7000, -504.0900;

    GaussSolver solver(matrix, b);
    
    solver.solve();

    cout << solver.solution_ << endl;
    std::cin.get();
}