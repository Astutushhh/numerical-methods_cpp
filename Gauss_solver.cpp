#include <iostream>
#include "Gauss_solver.h"

void GaussSolver::checkMatrix(Eigen::MatrixXd& A)
{
    if(!(A.rows() >= A.cols() - 1))
        throw std::invalid_argument("Число уравнений меньше количества переменных");
}

void GaussSolver::prepRectMatrix(Eigen::MatrixXd& A)
{
    A = A.topRows(A.cols()-1);
}