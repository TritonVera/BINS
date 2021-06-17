#ifndef ALGORITM_H
#define ALGORITM_H

#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

namespace algorithm {
    matrix<double> puasson(matrix<double> wg, matrix<double> we, matrix<double> mat, time_t difference);
    vector<double> earth(double latitude);
}

#endif // ALGORITM_H
