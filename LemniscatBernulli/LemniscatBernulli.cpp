// LemniscatBernulli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "LemniscatClass.h"

bool getNum(double& num)
{
	double n;
	std::cin >> n;

	bool g = std::cin.good();

	if (g)
		num = n;

	return g;
}

void input_par(double &par)
{
	double a;
	while (true)
	{
		bool fl = getNum(a);
		if (fl == false)
		{
			std::cout << "Error, try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (fl == true)
		{
			par = a;
			break;
		}
	}
}


int main()
{
	LemniscatClass a;
	int fl1 = 1;
	double fi = 0;
	double ro = 0;
	while (fl1)
	{
		std::cout << "Your figure is: " << a.get_st() << std::endl;
		if (a.get_st() == "Point")
		{
			goto N1;
		}
		std::cout << "Input your fi in grad: ";
		input_par(fi);
		try
		{
			std::cout << "distance to centre in polar system: " << a.Len2Cent(fi) << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		try
		{
			std::cout << "distance to centre depended of angle: " << a.RadOfAngle(fi) << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		
		std::cout << "Input your polar rad: ";
		input_par(ro);

		try
		{
			std::cout << "distance to centre in depended of polar radius: " << a.RadOfRad(ro) << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		try
		{
			std::cout << "distance to centre in polar sector: " << a.SqPolarSec(fi) << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		try
		{
			std::cout << "full square: " << a.SqLem() << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		
N1:
		double choice;
		std::cout << "Enter your choice to continue or press ctrl+Z to quit:" << std::endl;
		std::cout << "1) Input c " << std::endl;
		/*std::cout << "2) Input F1 and F2" << std::endl;*/
		std::cout << "Your choice: ";
		std::cin >> choice;
		if (std::cin.good()) 
		{
			if (choice == 1)
			{
				try
				{
					std::cout << "Input your c: ";
					double c;
					input_par(c);
					a.set_c(c);
				}
				catch (std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}
			}

			/*if (choice == 2)
			{
				try
				{
					std::cout << "Input your F1(x): ";
					Point f1;
					Point f2;
					input_par(f1.x);
					std::cout << "Input your F1(y): ";
					input_par(f1.y);

					std::cout << "Input your F2(x): ";
					input_par(f2.x);
					std::cout << "Input your F2(y): ";
					input_par(f2.y);
					a.set_Foc(f1, f2);
				}
				catch (std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}
			}*/
			
		}
		else
			fl1 = 0;

		system("pause");
	}
}