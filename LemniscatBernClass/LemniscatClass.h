#pragma once
#include <string>


typedef struct Point
{
	double x, y; 
	Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	friend std::ostream & operator<<(std::ostream & out, const Point &point);
}Point;

typedef struct Paramentr
{
	double x = 0;
	bool active = false;
}Pr;

typedef struct Paramentr_point
{
	Point x;
	bool active = false;
	Paramentr_point(double x0 = 0, double y0 = 0) { x.x = x0; x.y = y0; }
	Paramentr_point& operator=(const Point& right);
}Pr_p;

class LemniscatClass
{
private:
	Pr c;
	//Pr ro;
	//Pr fi;
	Pr_p F1;
	Pr_p F2;
	std::string state = "Point";

	/*double get_c_p(Point a) const;*/

public:
	LemniscatClass(double c = 0);
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
	double Len2Cent(double fi) const;
};

