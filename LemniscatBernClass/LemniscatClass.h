#pragma once
class LemniscatClass
{
private:
	double c = 0;
	double ro = 0;
	double fi = 0;
	double F1 = 0;
	double F2 = 0;

public:
	LemniscatClass();
	~LemniscatClass();

	double SqPolarSec(double fi) const;
	double SqLem() const;
	double RadOfRad(double ro) const;
	double RadOfAngle(double fi) const;
	double LentoCent(double x, double y, double fi) const;
};

