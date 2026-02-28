#include "Gauss_solver.h"
#include "iostream"

// Матрица nxn... Нужно написать провеку и уддаление лишних строк в случаи наличия 

// rowLen - длина строки в которой до сих пор столбец b
double GaussBackwardSubstitution::rowCalc(Eigen::RowVectorXd row, Eigen::VectorXd solution, int rowLen)
{  
    return row(rowLen - 1) - row.head(rowLen - 1).dot(solution);//перенос в левую часть -> вычли из b
}

Eigen::VectorXd GaussBackwardSubstitution::backwardSubstitution(Eigen::MatrixXd& U)
{
    int matrixDimension = U.rows();

    Eigen::VectorXd solution(matrixDimension);

    for(int i = matrixDimension - 1; i >= 0; i--)
        solution(i) = rowCalc(U.row(i), solution, matrixDimension + 1);   
    
    return solution;
}

