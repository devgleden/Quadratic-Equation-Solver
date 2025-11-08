#include <iostream>
#include <cmath>
#include <limits>
#include <complex>

double constant(char quadraticConstant)
{
	bool validInput = false;
	double a{};
	
	while (!validInput)
	{
		std::cout <<"Enter coefficient " <<quadraticConstant << ": ";
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cout << "Invalid input! Please enter a number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			validInput = true;
		}
	}
		
	return a;

}
double root1(double a, double b, double c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

double root2(double a, double b, double c)
{
	 return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

void quadraticRoots(double a, double b, double c)
{
	double discriminant{ (b * b) - (4 * a * c) };

	if (a == 0) 
	{
		std::cout << "Error: coefficient 'A' cannot be zero in a quadratic equation!\n";
		return ;
	}
	
	else if (discriminant > 0) 
	{
		double solvedRoot1{ root1(a, b, c) };
		double solvedRoot2{ root2(a, b, c) };
		std::cout << " The roots are: " << solvedRoot1 << " and " << solvedRoot2 << '\n';
	}
		
	else if (discriminant < 0)
	{
		double realPart{ -b / (2 * a) };
		double imaginaryPart{ sqrt(-discriminant) / (2 * a) };

		std::complex<double> complexRoot1{ realPart, imaginaryPart };
		std::complex<double> complexRoot2{ realPart, -imaginaryPart };
		std::cout << "\nRoots are complex numbers (real part, imaginary part): " << complexRoot1 << " and " << complexRoot2 <<'\n';
	}
	else
	{
		std::cout << "The root is: " << -b / (2 * a) << '\n';
	}
}

int main()
{
	std::cout << "This program solves for the roots of quadratic equation in standard form: Ax^2 + Bx + C = 0.\nPlease privide the following values:\n\n";
	const double value1{ constant('A')};
	const double value2{ constant('B')};
	const double value3{ constant('C')};

	quadraticRoots(value1, value2, value3);

	return 0;
}
