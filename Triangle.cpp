// Triangle.cpp
// Реализация класса треугольника.
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include "Triangle.h"
using namespace std;
//----------------------
//Конструктор треугольника по 3-точкам.
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident):
  v1(_v1), v2(_v2), v3(_v3)
{
  char buf[16];

  objID = new char[strlen(ident) + 1];
  strcpy(objID, ident);

  count++;

  sprintf(buf, "Треугольник %d", count);
  name = new char[strlen(buf) + 1];
  strcpy(name, buf);
  a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
  b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
  c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
  cout << "Constructor_1 for: " << objID
    << " (" << name << ") " << endl;
}
//-------------------------------------------------------
//Конструктор копирования.
Triangle::Triangle(Triangle& tria)
{
	v1 = tria.v1;
	v2 = tria.v2;
	v3 = tria.v3;

	cout << "Конструктор копирования для: " << tria.objID << endl;

	objID = new char[strlen(tria.objID) + strlen("(копия)") + 1];
	strcpy(objID, tria.objID);
	strcat(objID, "(копия)");

	name = new char[strlen(tria.name) + 1];
	strcpy(name, tria.name);
	a = tria.a;
	b = tria.b;
	c = tria.c;
}
//--------------------------------------------------------
//конструктор нулевого треугольника.
Triangle::Triangle(const char* ident)
{
  char buf[16];
  objID = new char[strlen(ident) + 1];
  strcpy(objID, ident);

  count++;
  sprintf(buf, "Треугольник %d", count);
  name = new char[strlen(buf) + 1];
  strcpy(name, buf);
  a = b = c  = 0;
  cout << "Constructor_2 for: " << objID
    << " (" << name << ")" << endl;
}
//--------------------------------------------------------
//деструктор
Triangle::~Triangle(){
  cout << "Destructor for: " << objID << endl;
  delete[] objID;
  delete[] name;
}
//----------------------------------------------------------
void Triangle::Show() const{
  cout << name << " : " << endl;
  v1.Show(); v2.Show(); v3.Show();
  cout << endl;
}
//----------------------------------------------------------
/*
void Triangle::ShowSideAndArea() const{
  double p = (a + b + c) / 2;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << "------------------------------------" << endl;
  cout << name << " : ";
  cout.precision(4);
  cout << " a= " << setw(5) << a;
  cout << " b= " << setw(5) << b;
  cout << " c= " << setw(5) << c;
  cout << ":\ts= " << s << endl;
}
*/
//-------------------------------------------------------
void Triangle::Move(Point dp){
	v1 += dp;  v2 += dp;  v3 += dp;
}
//-------------------------------------------------------
//метод сравнения треугольников по площади.
//------------------------------------------------------
bool Triangle::operator>(const Triangle& tria) const
{
  double p = (a + b + c) / 2;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
	double p1 = (tria.a + tria.b + tria.c) / 2;
  double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));

	if(s > s1)
		return true;
	else 
		return false;
}
//----------------------------------------------------
//перегрузка оператора присваивания. (=)
Triangle& Triangle::operator=(Triangle& tria)
{
	cout << "Оператор присваивания. " << objID << " = " << tria.objID << endl;
	if(&tria == this)
		return *this;
	delete[] name;
	name = new char[strlen(tria.name) + 1];
	strcpy(name, tria.name);
	a = tria.a; b = tria.b; c = tria.c;
	return *this;
}



