#include "Canvas.h"
#include <cmath>
#include <iostream>

Canvas::Canvas(int width, int height)
{
	char** q = new char* [height];
	for (int i = 0; i < height; i++)
		q[i] = new char[width];
	this->p = q;
	this->n = height;
	this->m = width;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			p[i][j] = ' ';
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	double xm, ym, xx, yy, dist, r;
	r = ray;
	xm = x + 0.5;
	ym = y + 0.5;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			xx = i + 0.5;
			yy = j + 0.5;
			dist = sqrt((xm - xx) * (xm - xx) + (ym - yy) * (ym - yy));
			if (dist == ray)
				p[i][j] = ch;
			if (abs(dist - ray) < 0.7)
				p[i][j] = ch;

		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	double xm, ym, xx, yy, dist, r;
	r = ray;
	xm = x + 0.5;
	ym = y + 0.5;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			xx = i + 0.5;
			yy = j + 0.5;
			dist = sqrt((xm - xx) * (xm - xx) + (ym - yy) * (ym - yy));
			if (dist <= ray)
				p[i][j] = ch;
			if (abs(dist - ray) < 0.7)
				p[i][j] = ch;

		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int i;
	for (i = left; i <= right; i++)
		p[top][i] = p[bottom][i] = ch;
	for (i = top; i <= bottom; i++)
		p[i][left] = p[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = top; i <= bottom; i++)
		for (j = left; j <= right; j++)
			p[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	p[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int aux;
	bool ok = 0;;
	if (x1 > x2)
	{
		if (y1 > y2)
		{
			aux = x1;
			x1 = x2;
			x2 = aux;
			aux = y1;
			y1 = y2;
			y2 = aux;
		}
		else
		{
			ok = 1;
			aux = x2;
			x2 = x1;
			x1 = aux;
			aux = y2;
			y2 = y2 + y2 - y1;
			y1 = aux;

		}

	}
	else
		if (y1 > y2)
		{
			ok = 1;
			y2 = y1 + (y1 - y2);
		}
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		if (!ok)
			p[x][y] = ch;
		else
			p[x][y1 - (y - y1)] = ch;

		if (D > 0)
			y++, D = D - 2 * dx;
		D = D + 2 * dy;
	}

}

void Canvas::Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << p[i][j];
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			p[i][j] = ' ';

}