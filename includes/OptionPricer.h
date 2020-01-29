#ifndef __OPTIONPRICER_H__
# define __OPTIONPRICER_H__

# include <cmath>
# include "Option.h"

class OptionPricer
{
public:
	OptionPricer();
	~OptionPricer();
	double callprice(const double& strike, const double& stock, const double& rate, const double& volatility, const double& timeToMaturity);
	double putprice(const double& strike, const double& stock, const double& rate, const double& volatility, const double& timeToMaturity);
	double norm(const double& x);
	double calculateD1orD2(const int j, const double& stock, const double& strike, const double& rate, const double& volatility, const double& timeToMaturity);
private:

};

#endif // __OPTIONPRICER_H__