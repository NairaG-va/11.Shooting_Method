//Метод стрельбы
#include <iostream> 
#include <cmath>
#include <vector> 

double shoot(double ksi, double h, int n, std::vector<double>& y, std::vector<double>& z)
{
	z[0] = ksi;
	y[0] = ksi - 0.6;
	
	for (int i = 0; i != n - 1; i++)
	{
		double y_1 = y[i] + 0.5*h*z[i];
		double z_1 = z[i] + 0.5*h*(2.0*z[i] + 3.0*y[i] + exp(4.0*i*h));
		y[i+1] = y[i] + h*z_1;
		z[i+1] = z[i] + h*(2.0*z_1 + 3.0*y_1 + exp(4.0*(i*h + 0.5*h)));
	}
	
	std::cout << "\n";
	
	return z[n-1] + y[n-1] - 4.0*exp(3.0) - exp(4.0);
}



int main (int argc, char* argv[])
{
	if (argc < 4)
	{
		std::cout << "No arguments" << "\n";
		return 1;
	}

	double m, left, right;

	try
	{
		m = std :: stod(argv[1]);
		left = std :: stod(argv[2]);
		right = std :: stod(argv[3]);

	}
	catch(...)
	{
		std::cout << "Not able to parse arguments" << "\n";
		return 1;
	}
	
	
	int n = 11;
	double h = 1.0/(n-1);
	
	std::vector<double> y(n);
	std::vector<double> z(n);
	
	double ksi = -51.0;
	double min = 10.0;
	for (double i = left; i < right; i += m)
	{
		double k = fabs(shoot(i, h, n, y, z));
		if (k < min)
		{
			min = k;
			ksi = i;
		}
	}
	
	std::cout << "ksi = " << ksi << "\n";
	
	double temp = shoot(ksi, h, n, y, z);
	//std::cout << temp << "\n";

	if (fabs(temp) > 1.0) 
	{
		std::cout << "Bad boundaries" << "\n";
	}
	else
	{
		for (int i = 0; i != n - 1; i++)
		{
			std::cout << "x[" << i + 1 << "]= " << (i+1)*h << " y[" << i + 1 << "]= " << y[i+1] << "\n";
		} 
	}
	
	return 0;
	
}
 
