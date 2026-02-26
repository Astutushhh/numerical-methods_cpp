#include "Gauss_solver.h"
#include <iostream>
//#include <stdexcept>

void GaussForwardElimination::checkMatrix(Eigen::MatrixXd& A)
{
    if(!(A.rows() >= A.cols() - 1))
        throw std::invalid_argument("Число уравнений меньше количества переменных");
}

void GaussForwardElimination::prepRectMatrix(Eigen::MatrixXd& A)
{
    A = A.topRows(A.cols()-1);
}

void GaussForwardElimination::avoidIncreasingErr(Eigen::MatrixXd& A, int i, int matrixLength)
{
    int segmentIndexMaxRow;
    A.col(i).segment(i, matrixLength - i).cwiseAbs().maxCoeff(&segmentIndexMaxRow); // Нашли максимальный элемент
    A.row(i).swap(A.row(segmentIndexMaxRow + i));                                   // Поменяли строчки 
}

void GaussForwardElimination::subtractNormolizedRow(Eigen::MatrixXd& A, int i, int matrixLength)
{
    for(int j = i + 1; j < matrixLength; j++)
        A.row(j) -= A.row(i) * A(j, i);   
}

void GaussForwardElimination::forwardElimination(Eigen::MatrixXd& A)
{

    int matrixLength = A.rows();
    for(int i = 0; i < matrixLength; i++)
    {
        GaussForwardElimination::avoidIncreasingErr(A, i, matrixLength);
        
        if(A(i,i))//Лучше проверить до входа в цикла, зарарнее и быстрее прервать выполнение не тратя лишнее время и ресурсы
            A.row(i) /= A(i,i);                                                // Нормализовали строку
        else
            std::cout << "Диагональный элемент матрицы ноль, матрица некорректна" << std::endl;

        GaussForwardElimination::subtractNormolizedRow(A, i, matrixLength);
    }
    
}