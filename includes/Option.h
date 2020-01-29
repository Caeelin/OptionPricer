#ifndef		__OPTION_H__
# define	__OPTION_H__

class Option
{
public:
	Option(const double& stock, const double& strike, const double& rate, const double& volatility, const double& timeToMaturity);
	~Option();
	double getStock() const;
	double getStrike() const;
	double getRate() const;
	double getVolatility() const;
	double getTimeToMaturity() const;
private:
	const double _stock;
	const double _strike;
	const double _rate;
	const double _volatility;
	const double _timeToMaturity;
};

#endif //	__OPTION_H__
