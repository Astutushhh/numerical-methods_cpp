// gauss_solver.h
#pragma once

#include <eigen3/Eigen/Dense>


class GaussForwardElimination {
    public:
        void forwardElimination(Eigen::MatrixXd& A);
        
    private:
        void checkMatrix(Eigen::MatrixXd& A);
        void avoidIncreasingErr(Eigen::MatrixXd& A, int i, int matrixLength);
        void subtractNormolizedRow(Eigen::MatrixXd& A, int i, int matrixLength);
};

class GaussBackwardSubstitution {
    public:
        Eigen::VectorXd backwardSubstitution(Eigen::MatrixXd& U);
        bool isUpperTriangular(const Eigen::MatrixXd& U) const;

    private:
        double rowCalc(Eigen::RowVectorXd row, Eigen::VectorXd solution, int rowLen);

};

class GaussSolver {
    public:
        void checkMatrix(Eigen::MatrixXd& A);
        void prepRectMatrix(Eigen::MatrixXd& A);
        
        Eigen::VectorXd solve(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);
        Eigen::VectorXd getResidual() const;
        double getConditionNumber() const;
        
    private:
        GaussForwardElimination forward_;
        GaussBackwardSubstitution backward_;
        Eigen::VectorXd residual_;
        double cond_ = 0.0;
        bool solved_ = false;
};