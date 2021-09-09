#include <iostream>
#include "Distributions.hpp"
#include "paireddata.hpp"

int main( int argc, const char *argv[] ) {
    const std::string name = "uniform distribution in c++";

    UniformDistribution u(1.0,2.0);
    PairedData          pd(std::vector<double>{1.0,2.0,3.0,4.0},std::vector<double>{10.0,20.0,30.0,40.0});
    auto output = pd.f(4.01);


    std::cout << "Searched value " << output << std::endl;
    std::cout << name << ", " << u.inv_cdf(0.25) << "!" << std::endl;
    return 0;
}