#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

namespace Converters {
    matrix<double> ori2mat(vector<double> ori);
    matrix<double> d_ori2mat(vector<double> ori);
    vector<double> mat2ori(matrix<double> mat);
    vector<double> mat2d_ori(matrix<double> mat);
    matrix<double> cososimmerty(vector<double> ang);
};

#endif // CONVERTERS_H
