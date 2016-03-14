/**
  * @file circle.cpp
  * @brief Implementación de las funciones que manejan círculos
  * @author Miguel Lentisco & Antonio Coín
  */

#include <iostream>
#include <cmath> // M_PI
#include "circle.h"

using namespace std;

Circle ReadCircle ()
{
  Circle c;
  char f;

  cin >> c.radius >> f;
  c.center = ReadPoint();

  return c;
}

bool ReadCircle ( istream& is, Circle& c )
{
  char f;

  is >> c.radius >> f;
  
  return ReadPoint( is, c.center );
}

void WriteCircle ( const Circle& c )
{
  cout << c.radius << "-";
  WritePoint( c.center );
}

bool WriteCircle ( ostream& os, const Circle& c )
{
  os << c.radius << "-";

  return WritePoint ( os, c.center );
}

void InitCircle ( Circle& c, Point center, double radius )
{
  c.radius = radius;
  c.center = center;
}

Point GetCenter ( const Circle& c )
{
  return c.center;
}

double GetRadius ( const Circle& c )
{
  return c.radius;
}

double Area ( const Circle& c )
{
  return c.radius * c.radius * M_PI;
}

bool IsWithin ( const Point& p, const Circle& c )
{
  return Distance( p, c.center ) < c.radius;
}

double Distance ( const Circle& c1, const Circle& c2 )
{
  return Distance( c1.center, c2.center ) - ( c1.radius + c2.radius );
}
