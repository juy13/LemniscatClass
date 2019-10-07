// LemniscatBernulli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "LemniscatClass.h"

int main()
{
	LemniscatClass a(33);
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
		std::cout << "Input your fi: ";
		std::cin >> fi;
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
		std::cin >> ro;

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
		int choice;
		std::cout << "Enter your choice to continue or press ctrl+Z to quit:" << std::endl;
		std::cout << "1) Input c " << std::endl;
		std::cout << "2) Input F1 and F2" << std::endl;
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
					std::cin >> c;
					a.set_c(c);
				}
				catch (std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}
			}

			if (choice == 2)
			{
				try
				{
					std::cout << "Input your F1(x): ";
					Point f1;
					Point f2;
					std::cin >> f1.x;
					std::cout << "Input your F1(y): ";
					std::cin >> f1.y;

					std::cout << "Input your F2(x): ";
					std::cin >> f2.x;
					std::cout << "Input your F2(y): ";
					std::cin >> f2.y;
					a.set_Foc(f1, f2);
				}
				catch (std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
				}
			}
			
		}
		else
			fl1 = 0;

		system("pause");
	}


	//LemniscatClass a(33);
	//std::cout << a.get_c() << std::endl;
	//std::cout << a.get_F1() << std::endl;
	//std::cout << a.get_F2() << std::endl;
	//try
	//{
	//	std::cout << a.Len2Cent(1.54) << std::endl;
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << ex.what() << std::endl;
	//}
	//
	//Point a1(3, 0);
	//Point a2(-3, 0);
	//try
	//{
	//	LemniscatClass b(a1, a2);
	//	std::cout << b.get_c() << std::endl;
	//	std::cout << b.get_F1() << std::endl;
	//	std::cout << b.get_F2() << std::endl;
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << ex.what() << std::endl;
	//}
}