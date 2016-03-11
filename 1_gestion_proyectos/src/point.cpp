/**
  * @file point.cpp
  * @brief Implementación de las funciones que manejan puntos en 2D
  * @author Miguel Lentisco & Antonio Coín
  */
  
#include <iostream>
#include <cmath> // sqrt
#include "point.h"

using namespace std;

Point ReadPoint()
{
  Point p;
  char c;

  cin >> c >> p.x >> c >> p.y >> c;

  return p;
}

void WritePoint ( const Point& p )
{
  cout << "(" << p.x << "," << p.y << ")";
}

void InitPoint ( Point& p, double cx, double cy )
{
  p.x = cx;
  p.y = cy;
}

double GetX ( const Point& p )
{
  return p.x;
}

double GetY ( const Point& p )
{
  return p.y;
}

double Distance ( const Point& p1, const Point& p2 )
{
  double d1 = p1.x - p2.x;
  double d2 = p1.y - p2.y;

  return sqrt( d1 * d1 + d2 * d2 );
}

Point MiddlePoint ( const Point& p1, const Point& p2 )
{
  double x = ( p1.x + p2.x ) / 2;
  double y = ( p1.y + p2.y ) / 2;
  Point p;

  p.x = x;
  p.y = y;

  return p;
}
