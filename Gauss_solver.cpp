#include <iostream>
#include "Gauss_solver.h"

void GaussSolver::checkMatrix(const Eigen::MatrixXd& A)
{
    if(!(A.rows() >= A.cols() - 1))
        throw std::invalid_argument("Число уравнений меньше количества переменных");
}

void GaussSolver::prepRectMatrixIfItsNeed(Eigen::MatrixXd& A)
{
    if(!(A.rows() == A.cols() - 1))
        A = A.topRows(A.cols()-1);
}

void GaussSolver::checkDimensions(const Eigen::MatrixXd& A, const Eigen::VectorXd& b)
{
    if(A.rows() != b.size())
        throw std::invalid_argument("Длина матрицы и решений матрицы не совпадает");
}

Eigen::MatrixXd GaussSolver::makeAugmentedMatrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& b)
{
    checkDimensions(A, b);

    Eigen::MatrixXd Aug (A.rows(), A.cols() + 1);
    Aug << A, b;
    return Aug;
}

GaussSolver::GaussSolver(Eigen::MatrixXd& A, Eigen::VectorXd& b) : augmented_(makeAugmentedMatrix(A, b))
{
    checkMatrix(augmented_);
    prepRectMatrixIfItsNeed(augmented_);
}

void GaussSolver::solve()
{
    forward_.forwardElimination(augmented_);
    solution_ = backward_.backwardSubstitution(augmented_);
}
