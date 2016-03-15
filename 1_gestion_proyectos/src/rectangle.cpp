/**
  * @file rectangle.cpp
  * @brief Implementación de funciones para manejar rectángulos
  * @author Miguel Lentisco & Antonio Coín
  */

#include <iostream>
#include "rectangle.h"
using namespace std;

// Funciones auxiliares
//--------------------------------

void SwapCorners( Point& p, Point& q )
{
   Point aux = p;
   p = q;
   q = aux;
}

void MoveCorners( Point& p, Point& q )
{
   p.y = q.y;
   q.x = p.x;
}

//----------------------------

bool ReadRectangle( istream& is, Rectangle& r )
{
  Point p, q;
  char c;
  bool success = ReadPoint( is, p ) && ( is >> c ) && ( c == '-' ) && ReadPoint( is, q );

  if ( success )
  {
    InitRectangle( r, p, q ); // Esta función se encarga de ponerlo en el orden correcto
  }

  return success;
}

bool WriteRectangle( ostream& os, const Rectangle& r )
{
  WritePoint( os, r.ll_corner );
  os << "-";

  return WritePoint( os, r.ur_corner );
}

void InitRectangle( Rectangle& r, const Point& p, const Point& q )
{
  bool greater_x = p.x > q.x;

  Point p1( p ), p2( q );

  if( p.y > q.y )
  {
    if( greater_x )
      SwapCorners( p1, p2 );
    else
      MoveCorners( p1, p2 );
  }
  else if( greater_x )
  {
     MoveCorners( p1, p2 );
     SwapCorners( p1, p2 );
  }

  r.ll_corner = p1;
  r.ur_corner = p2;
}

Point GetLowerLeft( const Rectangle& r )
{
  return r.ll_corner;
}

Point GetUpperRight( const Rectangle& r )
{
  return r.ur_corner;
}

double Area( const Rectangle& r )
{
  return ( r.ur_corner.x - r.ll_corner.x ) * ( r.ur_corner.y - r.ll_corner.y );
}

bool IsWithin( const Point& p, const Rectangle& r )
{
  return p.x > r.ll_corner.x && p.x < r.ur_corner.x
         && p.y > r.ll_corner.y && p.y < r.ur_corner.y;
}
