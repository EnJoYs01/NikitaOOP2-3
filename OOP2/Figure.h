#pragma once
class Figure {
protected:
	int x;
	int y;
public:
	Figure(int, int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};

