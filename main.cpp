#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "converters.h"
#include "algorithm.h"

void loop(boost::numeric::ublas::matrix<double> mat_prev) {
    using namespace boost::numeric;
    time_t t , t_prev = 0;
    double wx, wy, wz, ax, ay, az;
//    std::ifstream data("../../../data.txt");
    while(1) {
        std::cin >> wx >> wy >> wz >> ax >> ay >> az >> t;
//        if (data >> wx >> wy >> wz >> ax >> ay >> az >> t) {
//            std::cerr << "Файл прочитан" << std::endl;
//            break;
//        }
        ublas::vector<double> vec_gyro(3), vec_acc(3);
        vec_gyro(0) = wx; vec_gyro(1) = wy; vec_gyro(2) = wz;
        vec_acc(0) = ax; vec_acc(1) = ay; vec_acc(2) = az;
        auto vec_earth = algorithm::earth(55.0);
        time_t diff_t = t - t_prev;

        auto wg = Converters::cososimmerty(vec_gyro);
        auto we = Converters::cososimmerty(vec_earth);

        ublas::matrix<double> mat = algorithm::puasson(wg, we, mat_prev, diff_t);
        std::cout << mat_prev << "\v" << mat << std::endl;
        vector<double> out = Converters::mat2d_ori(mat);
        std::cout << "Курс: " << out(0) << "; Тангаж: " << out(1) << "; Крен: " << out(2) << std::endl;

        t_prev = t;
        mat_prev = mat;
    }
//    data.close();
}

int main()
{
    using namespace std;
    boost::numeric::ublas::vector<double> vec(3);
    cout << "Введи курс: ";
    cin >> vec(0);
    cout << "Введи тангаж: ";
    cin >> vec(1);
    cout << "Введи крен: ";
    cin >> vec(2);

    boost::numeric::ublas::matrix<double> mat = Converters::d_ori2mat(vec);

    loop(mat);
    return 0;
}
