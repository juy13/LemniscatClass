#include "stdafx.h"
#define _USE_MATH_DEFINES 
#include "LemniscatClass.h"
#include <cmath>



LemniscatClass::LemniscatClass()
{

}


LemniscatClass::~LemniscatClass()
{

}

double LemniscatClass::SqPolarSec(double fi) const
{
	double S;
	S = ((this->c * this->c) / 2.0) * sin(2 * fi);
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
	double R;
	R = (2.0 * (this->c * this->c)) / (3.0 * ro);
	return R;
}

double LemniscatClass::RadOfAngle(double fi) const
{
	double R;
	R = ((2.0 * (this->c * this->c))) / (3 * sqrt(2 * (this->c * this->c) * cos(2 * fi)));
	return R;
}

double LemniscatClass::LentoCent(double x, double y, double fi) const
{
	double len = 0;
	double c1 = 0;
	double c2 = 0;
	double p = sqrt(tan((M_PI / 4.0) - fi));

	c1 = (x / sqrt(2)) * ((1 + pow(p, 4)) / (p + pow(p, 3)));
	c2 = (y / sqrt(2)) * ((1 + pow(p, 4)) / (p - pow(p, 3)));
}

