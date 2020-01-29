#include "Option.h"

Option::Option(const double& stock, const double& strike, const double& rate, const double& volatility, const double& timeToMaturity) : _stock(stock), _strike(strike), _rate(rate), _volatility(volatility), _timeToMaturity(timeToMaturity)
{
}

Option::~Option()
{
}

double Option::getRate() const
{
	return this->_rate;
}

double Option::getStock() const
{
	return this->_stock;
}

double Option::getStrike() const
{
	return this->_strike;
}

double Option::getVolatility() const
{
	return this->_volatility;
}

double Option::getTimeToMaturity() const
{
	return this->_timeToMaturity;
}
