#include <iostream>

class Figure
{
public:
	Figure()
	{
		_name = "Фигура";
	}

	virtual std::string& getName()
	{
		return _name;
	}

	virtual unsigned int getSideCount()
	{
		return _sideCount;
	}

	virtual bool isCorrect()
	{
		return getSideCount() == 0;
	}

	// не обязан быть виртуальным
	void printInfo()
	{
		std::cout << getName() << std::endl;
		std::cout << (isCorrect() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << getSideCount() << std::endl;
		printSideInfo();
		printAngleInfo();
		std::cout << std::endl;
	}

protected:
	std::string _name;
	unsigned int _sideCount = 0;

	virtual void printSideInfo()
	{

	}

	virtual void printAngleInfo()
	{

	}
};

class Triangle : public Figure
{
public:
	Triangle(double a, double b, double c, double A, double B, double C)
	{
		_a = a;
		_b = b;
		_c = c;
		_A = A;
		_B = B;
		_C = C;
		_name = "Треугольник";
		_sideCount = 3;
	}

	double geta()
	{
		return _a;
	}

	double getb()
	{
		return _b;
	}

	double getc()
	{
		return _c;
	}

	double getA()
	{
		return _A;
	}

	double getB()
	{
		return _B;
	}

	double getC()
	{
		return _C;
	}

	bool isCorrect() override
	{
		return getSideCount() == 3 && (getA() + getB() + getC() == 180);
	}

protected:
	void printSideInfo() override
	{
		std::cout << "Стороны: ";
		std::cout << "a = " << geta() << ", ";
		std::cout << "b = " << getb() << ", ";
		std::cout << "c = " << getc() << std::endl;
	}

	void printAngleInfo()
	{
		std::cout << "Углы: ";
		std::cout << "A = " << getA() << ", ";
		std::cout << "B = " << getB() << ", ";
		std::cout << "C = " << getC() << std::endl;
	}

private:
	double _a, _b, _c, _A, _B, _C;
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
		_name = "Прямоугольный треугольник";
	}

	bool isCorrect() override
	{
		return Triangle::isCorrect() && getC() == 90;
	}
};

class IsoScelesTriangle : public Triangle
{
public:
	IsoScelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{
		_name = "Равнобедренный треугольник";
	}

	bool isCorrect() override
	{
		return Triangle::isCorrect() && geta() == getc() && getA() == getC();
	}
};

class EquilateralTriangle : public IsoScelesTriangle
{
public:
	EquilateralTriangle(double a) : IsoScelesTriangle(a, a, 60, 60)
	{
		_name = "Равносторонний треугольник";
	}

	bool isCorrect() override
	{
		return Triangle::isCorrect() && geta() == getb() && getb() == getc() && getA() == 60 && getB() == 60 && getC() == 60;
	}
};

// четырехугольник не наследуется от треугольника
class Quadrangle : public Figure
{
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
	{
		_a = a;
		_b = b;
		_c = c;
		_d = d;
		_A = A;
		_B = B;
		_C = C;
		_D = D;
		_name = "Четырехугольник";
		_sideCount = 4;
	}

	double geta()
	{
		return _a;
	}

	double getb()
	{
		return _b;
	}

	double getc()
	{
		return _c;
	}

	double getd()
	{
		return _d;
	}

	double getA()
	{
		return _A;
	}

	double getB()
	{
		return _B;
	}

	double getC()
	{
		return _C;
	}

	double getD()
	{
		return _D;
	}

	bool isCorrect() override
	{
		return getSideCount() == 4 && (getA() + getB() + getC() + getD() == 360);
	}

protected:
	virtual void printSideInfo()
	{
		std::cout << "Стороны: ";
		std::cout << "a = " <<geta() << ", ";
		std::cout << "b = " <<getb() << ", ";
		std::cout << "c = " <<getc() << ", ";
		std::cout << "d = " <<getd() << std::endl;
	}

	virtual void printAngleInfo()
	{
		std::cout << "Углы: ";
		std::cout << "A = " << getA() << ", ";
		std::cout << "B = " << getB() << ", ";
		std::cout << "C = " << getC() << ", ";
		std::cout << "D = " << getD() << std::endl;
	}

private:
	double _a, _b, _c, _d, _A, _B, _C, _D;
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		_name = "Паралелограмм";
	}

	bool isCorrect() override
	{
		return Quadrangle::isCorrect() && geta() == getc() && getb() == getd() && getA() == getC() && getB() == getD();
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
	{
		_name = "Прямоугольник";
	}

	bool isCorrect() override
	{
		return Parallelogram::isCorrect() && getA() == 90 && getB() == 90 && getC() == 90 && getD() == 90;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B)
	{
		_name = "Ромб";
	}

	bool isCorrect() override
	{
		return Parallelogram::isCorrect() && geta() == getb() && getc() == getd();
	}
};

class Square : public Rectangle
{
public:
	Square(double a) : Rectangle(a, a)
	{
		_name = "Квадрат";
	}

	bool isCorrect() override
	{
		return Rectangle::isCorrect() && geta() == getb() && getc() == getd();
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");

	Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70);
	triangle->printInfo();
	delete triangle;

	Figure* rightTriangle1 = new RightTriangle(10, 20, 30, 50, 60);
	rightTriangle1->printInfo();
	delete rightTriangle1;

	Figure* rightTriangle2 = new RightTriangle(10, 20, 30, 50, 40);
	rightTriangle2->printInfo();
	delete rightTriangle2;

	Figure* isoScelesTriangle = new IsoScelesTriangle(10, 20, 50, 60);
	isoScelesTriangle->printInfo();
	delete isoScelesTriangle;

	Figure* equilateralTriangle = new EquilateralTriangle(30);
	equilateralTriangle->printInfo();
	delete equilateralTriangle;

	Figure* quadrangle = new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle->printInfo();
	delete quadrangle;

	Figure* rectangle = new Rectangle(10, 20);
	rectangle->printInfo();
	delete rectangle;

	Figure* square = new Square(20);
	square->printInfo();
	delete square;

	Figure* parallelogram = new Parallelogram(20, 30, 30, 40);
	parallelogram->printInfo();
	delete parallelogram;

	Figure* rhombus = new Rhombus(30, 30, 40);
	rhombus->printInfo();
	delete rhombus;
}
