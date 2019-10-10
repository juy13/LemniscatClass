#pragma once
#include <string>
#include <iostream>


typedef struct Point
{
	double x, y; 
	Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	friend std::ostream & operator<<(std::ostream & out, const Point &point);
}Point;


class LemniscatClass
{
private:
	double c;
	Point F1;
	Point F2;
	std::string state = "Point";

	/*double get_c_p(Point a) const;*/

public:
	LemniscatClass(double c = 3);
	LemniscatClass(Point f1, Point f2);
	~LemniscatClass();

	/*геттеры и сеттеры */
	double get_c() const;
	std::string get_st() const;
	//double get_fi() const;
	//double get_ro() const;
	Point get_F1() const;
	Point get_F2() const;

	void set_c(double c);
	/*void set_fi(double fi);*/
	void set_Foc(Point F1, Point F2);

	/* методы класса */
	double SqPolarSec(double fi) const;
	double SqLem() const;
	double RadOfRad(double ro) const;	
	double RadOfAngle(double fi) const;	
	double Len2Cent(double fi) const; // расстояние до центра
};

