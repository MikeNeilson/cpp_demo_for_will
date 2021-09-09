#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

class PairedData {
    private:
        std::vector<double> xvals;
        std::vector<double> yvals;
    public:

        PairedData( std::vector<double> xvals, std::vector<double> yvals ) noexcept {            
            this->xvals = xvals;
            this->yvals = yvals;
        }

        double f( double x ) noexcept {
            if( x < xvals[0] ) {
                return 0.0;
            }

            size_t size = xvals.size();

            double error_margin = 0.000000000001;
            if( std::abs( x - xvals[0] ) < error_margin ) {
                return yvals[0];
            }

            auto output = std::upper_bound( xvals.begin(), xvals.end(), x);
            auto upper = output - xvals.begin();
            auto lower = upper - 1;
            auto slope = (yvals[upper] - yvals[lower]) / (xvals[upper] - xvals[lower] );
            std::cout << upper << " " << lower << " " << slope << std::endl;
            return yvals[lower] + slope * ( x - xvals[lower] );
        }

};