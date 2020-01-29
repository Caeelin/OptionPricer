#include "OptionPricer.h"

OptionPricer::OptionPricer()
{
}

OptionPricer::~OptionPricer()
{
}

double OptionPricer::norm(const double& x)
{
	const double pi = 3.14159265358979323846;
	const double k = 1.0 / (1.0 + 0.2316419 * x);
	const double ksum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

	if (x >= 0.0)
		return (1.0 - (1.0 / (std::pow(2 * pi, 0.5))) * std::exp(-0.5 * x * x) * ksum);
	else
		return 1.0 - norm(-x);
}

double OptionPricer::calculateD1orD2(const int j, const double& stock, const double& strike, const double& rate, const double& volatility, const double& timeToMaturity)
{
	return (std::log(stock / strike) + (rate + (std::pow(-1, j - 1)) * 0.5 * volatility * volatility) * timeToMaturity) / (volatility * (std::pow(timeToMaturity, 0.5)));
}

double OptionPricer::callprice(	const double& strike, 
										const double& stock, 
										const double& rate, 
										const double& volatility, 
										const double& timeToMaturity)
{
	return stock * norm(calculateD1orD2(1, stock, strike, rate, volatility, timeToMaturity)) 
		- strike * std::exp(-rate * timeToMaturity) 
		* norm(calculateD1orD2(2, stock, strike, rate, volatility, timeToMaturity));
}

double OptionPricer::putprice(	const double& strike,
										const double& stock,
										const double& rate,
										const double& volatility,
										const double& timeToMaturity)
{
	return -stock * norm(-calculateD1orD2(1, stock, strike, rate, volatility, timeToMaturity)) 
		+ strike * std::exp(-rate * timeToMaturity) 
		* norm(-calculateD1orD2(2, stock, strike, rate, volatility, timeToMaturity));
}