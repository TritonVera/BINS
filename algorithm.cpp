#include <numbers>
#include "algorithm.h"

#define U 7.292115e-5

using namespace boost::numeric::ublas;

matrix<double> algorithm::puasson(matrix<double> wg, matrix<double> we, matrix<double> mat, time_t difference) {
    matrix<double> d_mat = prod(mat, wg) - prod(we, mat);
    return mat + (d_mat*difference);
}

vector<double> algorithm::earth(double latitude) {
    latitude *= std::numbers::pi/180.0;
    vector<double> we(3);
    we(1) = U * cos(latitude);
    we(2) = U * sin(latitude);
    return we;
}
