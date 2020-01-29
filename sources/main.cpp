#include <iostream>
#include "OptionPricer.h"
#include "Option.h"

int main(int ac, char** av)
{
	if (ac != 6)
	{
		std::cout << "Usage : \"./a.out stock, strike, volatility in percentage, interestRate in percentage, time in years\" " << std::endl;
		return 0;
	}
	double strike = std::strtod(av[1], nullptr);
	double stock = std::strtod(av[2], nullptr);
	double rate = std::strtod(av[3], nullptr);
	double volatility = std::strtod(av[4], nullptr);
	double timeToMaturity = std::strtod(av[5], nullptr);

	Option option(strike, stock, rate, volatility, timeToMaturity);
	OptionPricer pricer;
	
	double callprice = pricer.callprice(option.getStrike(), option.getStock(), option.getRate() / 100, option.getVolatility() / 100, option.getTimeToMaturity());
	double putprice = pricer.putprice(option.getStrike(), option.getStock(), option.getRate() / 100, option.getVolatility() / 100, option.getTimeToMaturity());
	
	std::cout << "Stock option is : " << stock << "." << std::endl;
	std::cout << "Strike option is : " << strike << "." << std::endl;
	std::cout << "Rate option is : " << rate << "." << std::endl;
	std::cout << "Volatility option is : " << volatility << "." << std::endl;
	std::cout << "TimeToMaturity option is : " << timeToMaturity << "." << std::endl;
	std::cout << "Call Price of option is : " << callprice << "." << std::endl;
	std::cout << "Put Price of option is : " << putprice << "." << std::endl;
	
	return 0;
}