#pragma once


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
}Pr_p;

class LemniscatClass
{
private:
	Pr c;
	Pr ro;
	Pr fi;
	Pr_p F1;
	Pr_p F2;

	bool acces2eq(Point a) const;
	double get_c_p(Point a) const;

public:
	LemniscatClass();
	~LemniscatClass();

	/*геттеры и сеттеры */
	double get_c() const;
	double get_fi() const;
	double get_ro() const;
	Point get_F1() const;
	Point get_F2() const;

	void set_c(double c);
	void set_fi(double fi);
	void set_Foc(Point F1, Point F2);

	/* методы класса */
	double SqPolarSec(double fi) const;
	double SqLem() const;
	double RadOfRad(double ro) const;
	double RadOfAngle(double fi) const;
	double Len2Cent(Point a, double fi) const;
};

