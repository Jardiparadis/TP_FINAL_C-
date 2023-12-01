#include "point.h"

Point::Point(int _x, int _y, TERRAIN _fieldType)
{
	x = _x;
	y = _y;
	fieldType = _fieldType;
}

Point::~Point()
{
}

const int& Point::getX() const
{
	return x;
}

const int& Point::getY() const
{
	return y;
}

const TERRAIN& Point::getFieldType() const
{
	return fieldType;
}

void Point::setX(int _x)
{
	x = _x;
}

void Point::setY(int _y)
{
	y = _y;
}

void Point::setFieldType(TERRAIN _fieldType)
{
	fieldType = _fieldType;
}
