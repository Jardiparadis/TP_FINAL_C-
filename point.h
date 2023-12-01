#pragma once

enum class TERRAIN
{
	PLAINE,
	OBSTACLE,
	VALLEE,
	PIC
};

class Point
{
public:
	Point(int _x, int _y, TERRAIN _type = TERRAIN::PLAINE);
	~Point();
	const int& getX() const;
	const int& getY() const;
	const TERRAIN& getFieldType() const;
	void setX(int _x);
	void setY(int _y);
	void setFieldType(TERRAIN _fieldType);
private:
	int x;
	int y;
	TERRAIN fieldType;
};
