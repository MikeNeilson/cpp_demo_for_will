
class DistributedVariable {
    public:
        virtual double inv_cdf( double probability ) = 0;
};


class UniformDistribution : public DistributedVariable {
    private:
        double min;
        double max;

    public:
        UniformDistribution( double min, double max) : min(min), max(max) {}
        double inv_cdf(double probability) {
            return min + ((max-min) * probability );
        }
};