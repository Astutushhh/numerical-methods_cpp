// gauss_solver.h
#pragma once

#include <eigen3/Eigen/Dense>


class GaussForwardElimination {
    public:
        void forwardElimination(Eigen::MatrixXd& A);
    private:
        void isMatrixSingular(Eigen::MatrixXd& A, int matrixLength);
        void avoidIncreasingErr(Eigen::MatrixXd& A, int i, int matrixLength);
        void subtractNormolizedRow(Eigen::MatrixXd& A, int i, int matrixLength);
};

class GaussBackwardSubstitution {
    public:
        Eigen::VectorXd backwardSubstitution(Eigen::MatrixXd& U);
    private:
        double rowCalc(Eigen::RowVectorXd row, Eigen::VectorXd solution, int rowLen);
};

class GaussSolver {
    public:
        GaussSolver(Eigen::MatrixXd& A, Eigen::VectorXd& b);

        void solve();

        Eigen::VectorXd getResidual() const;
        double getConditionNumber() const;

        Eigen::VectorXd solution_;
    private:
        void checkMatrix(const Eigen::MatrixXd& A);
        void prepRectMatrixIfItsNeed(Eigen::MatrixXd& A);

        void checkDimensions(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);
        Eigen::MatrixXd makeAugmentedMatrix(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);

        Eigen::MatrixXd augmented_;

        GaussForwardElimination forward_;
        GaussBackwardSubstitution backward_;
        

        Eigen::VectorXd residual_;
        double cond_ = 0.0;
        bool solved_ = false;
};