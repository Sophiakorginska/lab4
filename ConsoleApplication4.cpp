#include "stdafx.h"
#include <iostream>
using namespace std;

class Figures
{
public:
	virtual double Square()//to calculate the square
	{
		return 0;
	}
	virtual int Get()//to imput
	{
		return 0;
	}
};

class Plane : public Figures
{
public:
	virtual double Square()
	{
		return 0;
	}
	virtual int Get()
	{
		return 0;
	}

};

class Circle : public Plane//class for tha figures that are on 2d
{
public:
	int Get()
	{
		cout << " Enter radius :";
		cin >> r;
		return 0;
	}
	double Square()
	{
		return 3.14*r*r;
	}
private:
	int r;
};

class Rectangle : public Plane
{
public:
	int Get()
	{
		cout << "Enter a : ";
		cin >> a;
		cout << "Enter  b : ";
		cin >> b;
		return 0;
	}
	double Square()
	{
		return a*b;
	}
private:
	int a, b;
};

class Point : public Plane
{
public:
	int Get()
	{
		cout << "Enter coordinate of x :";
		cin >> x;
		cout << "Enter coordinate of y:";
		cin >> y;
		cout << "X" << '(' << x << ',' << y << ')' << '\n';
		return 0;
	}

private: int x, y;
};

class Segment : public Plane
{
public:
	int Get()
	{
		cout << "Enter the coordinates of the segment:" << endl;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Length:";
		size = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (size>0) cout << size << "\n";
		else cout << -size << "\n";
		return 0;
	}
private:
	double x1, y1, x2, y2, size;
};

class Space : public Figures
{
public:
	virtual int Get()
	{
		return 0;
	}
	virtual double Square()
	{
		return 0;
	}
	virtual double Extent()
	{
		return 0;
	}
};

class Parallelepiped : public Space//class for tha figures that are on 3d
{
public:
	int Get()
	{
		cout << "Enter 1 side of Parallelepiped :";
		cin >> a;
		cout << "Enter 2 side of Parallelepiped :";
		cin >> b;
		cout << "Enter 3 side of Parallelepiped :";
		cin >> c;
		return 0;
	}
	double Square()
	{
		return 2 * (a*b + a*c + b*c);
	}
	virtual double Extent()
	{
		return a*b*c;
	}
private:
	int a, b, c;
};

class Sphere : public Space
{
public:
	int Get()
	{
		cout << "Enter radius: ";
		cin >> r;
		return 0;
	}
	double Square()
	{
		return 4 * 3.14*r*r;
	}
	double Extent()
	{
		return 4 / 3 * 3.14*r*r*r;
	}
private:
	int r;
};

int main()

{
	cout << "Enter figure:" << endl;
	cout << "1)Circle" << endl;
	cout << "2)Rectangle" << endl;
	cout << "3)Point" << endl;
	cout << "4)Segment" << endl;
	cout << "5)Parallelepiped" << endl;
	cout << "6)Sphere" << endl;

	int choise;
	cin >> choise;
	if (choise == 1)
	{
		Plane *ptr1 = new Circle;
		ptr1->Get();
		cout << "Square:" << (ptr1->Square()) << endl;
	}
	else if (choise == 2)
	{
		Plane *ptr2 = new Rectangle;
		ptr2->Get();
		cout << "Square:" << (ptr2->Square()) << endl;
	}
	else if (choise == 3)
	{
		Plane *ptr3 = new Point;
		ptr3->Get();

	}
	else if (choise == 4)
	{
		Segment ptr4;
		ptr4.Get();
	}
	else if (choise == 5)
	{
		Space *ptr5 = new Parallelepiped;
		ptr5->Get();
		cout << "Square:" << (ptr5->Square()) << endl;
		cout << "Volume: " << (ptr5->Extent()) << endl;
	}
	else if (choise == 6)
	{
		Space *ptr6 = new Sphere;
		ptr6->Get();
		cout << "Square:" << (ptr6->Square()) << endl;
		cout << "Volume: " << (ptr6->Extent()) << endl;
	}
	else
		cout << "Error" << endl;

	system("pause");
	return 0;
}

