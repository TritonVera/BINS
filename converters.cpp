#include "converters.h"
#include <exception>
#include <cmath>
#include <numbers>

matrix<double> Converters::ori2mat(vector<double> ori) {
    if (ori.size() != 3)
        throw std::invalid_argument("Вектор должен состоять из 3 компонент");
    double c_psi = std::cos(ori(0));
    double s_psi = std::sin(ori(0));
    double c_theta = std::cos(ori(1));
    double s_theta = std::sin(ori(1));
    double c_gamma = std::cos(ori(2));
    double s_gamma = std::sin(ori(2));

    matrix<double> out(3, 3);
    out(0, 0) = (c_gamma * c_psi) + (s_gamma * s_psi * s_theta);
    out(0, 1) = c_theta * s_psi;
    out(0, 2) = (c_psi * s_gamma) - (s_psi * c_gamma * s_theta);
    out(1, 0) = (s_gamma * s_psi * s_theta) - (c_gamma * s_psi);
    out(1, 1) = c_theta * c_psi;
    out(1, 2) = (-s_psi * s_gamma) - (c_gamma * c_psi * s_theta);
    out(2, 0) = -c_theta * s_gamma;
    out(2, 1) = s_theta;
    out(2, 2) = c_theta * c_gamma;

    return out;
}

matrix<double> Converters::d_ori2mat(vector<double> ori) {
    vector<double> vec(ori.size());
    for (size_t i = 0; i < ori.size(); ++i)
        vec(i) = std::numbers::pi*ori(i)/180;
    return ori2mat(vec);
}

vector<double> Converters::mat2ori(matrix<double> mat) {
    if (mat.size1() != 3 && mat.size2() != 3)
        throw std::invalid_argument("Матрица должна быть 3х3");
    vector<double> out(3);
    out(0) = std::atan2(mat(0, 1), mat(1, 1));
    out(1) = std::asin(mat(2, 1));
    out(2) = -std::atan2(mat(2, 0), mat(2, 2));
    return out;
}

vector<double> Converters::mat2d_ori(matrix<double> mat) {
    if (mat.size1() != 3 && mat.size2() != 3)
        throw std::invalid_argument("Матрица должна быть 3х3");
    vector<double> out = mat2ori(mat);
    for (size_t i = 0; i < out.size(); ++i)
        out(i) *= 180/std::numbers::pi;
    return out;
}

matrix<double> Converters::cososimmerty(vector<double> ang) {
    if (ang.size() != 3)
        throw std::invalid_argument("Вектор должен состоять из 3 компонент");
    matrix<double> out(3, 3);
    out(0, 1) = -ang(2);
    out(0, 2) = ang(1);
    out(1, 0) = ang(2);
    out(1, 2) = -ang(0);
    out(2, 0) = -ang(1);
    out(2, 1) = ang(0);
    return out;
}
