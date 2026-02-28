#include "build_and_print_report.h"
#include <iostream>
#include <iomanip>

void buildAndPrintReport(GaussSolver& solver)
{
    Eigen::VectorXd solution = solver.solve();

    double absFirst = solver.absFirstResidualNorm();
    double absInfinite = solver.absInfiniteResidualNorm();

    double relFirst = solver.relFirstResidualNorm();
    double relInfinite = solver.relInfiniteResidualNorm();

    double conditionNumber = solver.conditionNumber();

    std::cout << "Вектор решений матрицы:" << std::endl << solution << std::endl;

    std::cout << std::scientific << std::setprecision(17);
    std::cout << "Абсолютная погрешность(первая норма) = " << absFirst << std::endl;
    std::cout << "Абсолютная погрешность(бесконечная норма) = " << absInfinite << std::endl;

    std::cout << std::endl;

    std::cout << "Относительная погрешность(первая норма) = " << relFirst << std::endl;
    std::cout << "Относительная погрешность(бесконечная норма) = " << relInfinite << std::endl;

    std::cout << std::endl;

    std::cout << "Порядок числа обусловленности матрицы = " << conditionNumber << std::endl;
    
    std::cin.get();
}