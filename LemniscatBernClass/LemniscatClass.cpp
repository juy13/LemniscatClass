#include "stdafx.h"
#define _USE_MATH_DEFINES 
#include "LemniscatClass.h"
#include <stdio.h>
#include <cmath>


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

LemniscatClass::LemniscatClass(double c) /*: F1(c / 2.0, 0), F2(-(c / 2.0), 0)*/
{
	this->c = c;
	if (c == 0)
		this->state = "Point";
	else
		this->state = "Lemniscat";
}

LemniscatClass::~LemniscatClass()
{

}

double LemniscatClass::get_c() const
{
	return this->c;
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

//Point LemniscatClass::get_F1() const
//{
//	return this->F1.x;
//}
//
//Point LemniscatClass::get_F2() const
//{
//	return this->F2.x;
//}

void LemniscatClass::set_c(double c)
{
	if (c < 0)
		throw std::exception("Illegal C, or it is only a point in (0,0)");
	else
	{
	/*	this->F1 = c / 2.0;
		this->F2 = -(c / 2.0);*/
		this->c = c;
		if (this->c == 0)
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

//void LemniscatClass::set_Foc(Point F1, Point F2)
//{
//	double	p1 = abs(F1.x) * abs(F2.x);
//	double c = 2 * p1;
//
//	this->F1 = F1;
//	this->F2 = F2;
//	this->c = c;
//	if (c == 0)
//		this->state = "Point";
//	else
//		this->state = "Lemniscat";
//}


double LemniscatClass::SqPolarSec(double fi) const
{
	if (fi <= 0)
		throw std::exception("Illegal fi");
	double S;
	S = ((this->c * this->c) / 2.0) * abs(sin(2 * (fi * 180 / M_PI)));
	return S;
}

double LemniscatClass::SqLem() const
{
	double S;
	S = ((this->c * this->c) / 2.0) * (4.0 / (double)M_PI);
	return (S + S);
}

double LemniscatClass::RadOfRad(double ro) const
{
	if (ro <= 0)
		throw std::exception("Illegal ro");
	double R;
	R = (2.0 * (this->c * this->c)) / (3.0 * ro);
	return R;
}

double LemniscatClass::RadOfAngle(double fi) const
{
	if (fi < 0)
		throw std::exception("Illegal fi");
	double R;
	R = ((2.0 * (this->c * this->c))) / (3 * sqrt(2 * (this->c * this->c) * abs(cos(2 * (fi * 180 / M_PI)))));
	return R;
}

double LemniscatClass::Len2Cent(double fi) const
{
	double ro = 0;
	if (fi < 0)
		throw std::exception("Illegal fi");
	ro = sqrt(2 * this->c * this->c * abs(cos(2 * (fi * 180 / M_PI))));
	return ro;
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
	out << "X: " << point.x << " Y: " << point.y << std::endl;
	return out;
}

