#include "stdafx.h"
#define _USE_MATH_DEFINES 
#include "LemniscatClass.h"
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <iostream>



//bool LemniscatClass::acces2eq(Point a) const
//{
//	if (this->c.active != true)
//	{
//		throw std::exception("No parametre c in class");
//	}
//	double p1 = 0;
//	double p2 = 0;
//
//	p1 = pow(((a.x * a.x) + (a.y * a.y)), 2);
//	p2 = 2 * this->c.x * this->c.x * ((a.x * a.x) - (a.y * a.y));
//	
//	if (p1 != p2)
//		return false;
//	else
//		return true;
//}

//double LemniscatClass::get_c_p(Point a) const
//{
//	return 0.0;
//}

LemniscatClass::LemniscatClass(double c): F1(c/2.0, 0), F2(- (c/2.0), 0)
{
	if (c < 0)
		throw std::exception("Too small c");
	else
	{
		this->c.x = c;
		this->c.active = true;
		this->F1.active = true;
		this->F2.active = true;
		if (c == 0)
			this->state = "Point";
		else
			this->state = "Lemniscat";
	}
}

LemniscatClass::LemniscatClass(Point f1, Point f2)
{
	double	p1 = abs(f1.x) * abs(f2.x);
	double c = 2 * p1;

	if (f1.y != 0 || f2.y != 0)
		throw std::exception("It isn't a Lemniscat");
	else
	{
		this->c.x = c;
		this->c.active = true;
		this->F1.x = f1;
		this->F2.x = f2;
		this->F1.active = true;
		this->F2.active = true;
		if(this->c.x == 0)
			this->state = "Point";
		else
			this->state = "Lemniscat";
	}
}

LemniscatClass::~LemniscatClass()
{

}

double LemniscatClass::get_c() const
{
	if (this->c.active)
		return this->c.x;
	else
		throw std::exception("There is no activated parametre c");
}

std::string LemniscatClass::get_st() const
{
	return this->state;
}

//double LemniscatClass::get_fi() const
//{
//	if (this->fi.active)
//		return this->fi.x;
//	else
//		throw std::exception("There is no activated parametre fi");
//}
//
//double LemniscatClass::get_ro() const
//{
//	if (this->ro.active)
//		return this->ro.x;
//	else
//		throw std::exception("There is no activated parametre ro");
//}

Point LemniscatClass::get_F1() const
{
	if (this->F1.active)
		return this->F1.x;
	else
		throw std::exception("There is no activated parametre F1");
}

Point LemniscatClass::get_F2() const
{
	if (this->F2.active)
		return this->F2.x;
	else
		throw std::exception("There is no activated parametre F2");
}

void LemniscatClass::set_c(double c)
{
	if (c < 0)
		throw std::exception("Illegal C, or it is only a point in (0,0)");
	else
	{
		this->F1.x = c/2.0;
		this->F2.x = -(c/2.0);
		this->F1.active = true;
		this->F2.active = true;
		this->c.x = c;
		this->c.active = true;
		if (this->c.x == 0)
			this->state = "Point";
		else
			this->state = "Lemniscat";
	}
		
}

//void LemniscatClass::set_fi(double fi)
//{
//	if (fi <= 0)
//		throw std::exception("Illegal fi");
//	else
//	{
//		this->fi.x = fi;
//		this->fi.active = true;
//	}
//		
//}

void LemniscatClass::set_Foc(Point F1, Point F2)
{
	if (F1.y != 0 || F2.y != 0)
		throw std::exception("Illegal focuses");
	else
	{
		double	p1 = abs(F1.x) * abs(F2.x);
		double c = 2 * p1;

		this->F1.x = F1;
		this->F2.x = F2;
		this->F1.active = true;
		this->F2.active = true;
		this->c.x = c;
		this->c.active = true;

		if (c == 0)
			this->state = "Point";
		else
			this->state = "Lemniscat";
	}
}


double LemniscatClass::SqPolarSec(double fi) const
{
	if (fi < -1 || fi > 1 || abs(2 * fi) > 1)
	{
		throw std::exception("Not good fi");
	}
	if (this->c.active != true)
	{
		throw std::exception("No parametre c in class");
	}
	double S;
	S = ((this->c.x * this->c.x) / 2.0) * sin(2 * fi);
	return S;
}

double LemniscatClass::SqLem() const
{
	if (this->c.active != true)
	{
		throw std::exception("No parametre c in class");
	}
	double S;
	S = ((this->c.x * this->c.x) / 2.0) * (4.0 / (double)M_PI);	
	return (S + S);
}

double LemniscatClass::RadOfRad(double ro) const
{
	if (this->c.active != true)
	{
		throw std::exception("No parametre c in class");
	}
	double R;
	R = (2.0 * (this->c.x * this->c.x)) / (3.0 * abs(ro));
	return R;
}

double LemniscatClass::RadOfAngle(double fi) const
{
	if (fi < -1 || fi > 1 || abs(2 * fi) > 1)
	{
		throw std::exception("Not good fi");
	}
	if (this->c.active != true)
	{
		throw std::exception("No parametre c in class");
	}
	double R;
	R = ((2.0 * (this->c.x * this->c.x))) / (3 * sqrt(2 * (this->c.x * this->c.x) * cos(2 * fi)));
	return R;
}

double LemniscatClass::Len2Cent(double fi) const
{
	double ro = 0;
	if (fi < -1 || fi > 1 || abs(2 * fi) > 1)
	{
		throw std::exception("Not good fi");
	}
	if (this->c.active != true)
	{
		throw std::exception("No parametre c in class");
	}
	ro = sqrt(2 * this->c.x * this->c.x * cos(2 * fi));
	return ro;
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
	out << "X: " << point.x << " Y: " << point.y << std::endl;
	return out;
}

Paramentr_point & Paramentr_point::operator=(const Point & right)
{
	x.x = right.x;
	x.y = right.y;
	return *this;
}
