Name: Muhammad Awawdi
Student Number: 209319003
Name: Muhammad sarahni
Student Number: 207662958

Algorithm Implementation:

void Renderer::DrawLine(const glm::ivec2& p1, const glm::ivec2& p2, const glm::vec3& color)
{
	
	// TODO: Implement bresenham algorithm
	// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	double x1, x2, y1, y2, c, e, deltax, deltay;
	double a, tmp;
	c = e = 0;
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
	glm::vec3 color1(0, 0, 255);
	if (p2.x <= p1.x)
	{
		tmp = p2.x;
		x2 = x1;
		x1 = tmp;
		tmp = p2.y;
		y1 = tmp;
		y2 = p1.y;

	}
	deltay = (y2 - y1);
	deltax = (x2 - x1);
	if (deltax == 0)
	{
		while (y1 <= y2)
		{
			PutPixel(x1, y1, color);
			y1 += 1;
		}
		while (y2 <= y1)
		{
			PutPixel(x2, y2, color);
			y2 += 1;
		}
		return;
	}
	deltay = (y2 - y1);
	deltax = (x2 - x1);
	a = deltay / deltax;
	if (a == 0)
	{
		while (x1 <= x2)
		{
			PutPixel(x1, y1, color);
			x1 += 1;
		}
	}
	if (x1 < x2)
	{
		if (y1 < y2)
		{
			if (a >= 0 && a <= 1)//Bresenham algorithm לפי ההרצאה
			{

				e = -(x2 - x1);
				while (x1 <= x2)
				{
					if (e > 0) {
						y1 += 1;
						e = e - 2 * (x2 - x1);
					}
					PutPixel(x1, y1, color);
					x1 += 1;
					e += 2 * (y2 - y1);
				}
			}
			if (a > 1)
			{
				e = -(y2 - y1);
				while (y1 <= y2)
				{

					if (e > 0) {
						x1 += 1;
						e = e - 2 * (y2 - y1);
					}
					PutPixel(x1, y1, color);
					y1 += 1;
					e += 2 * (x2 - x1);
				}
			}
		}
		if (y1 > y2)
		{
			if (a < 0 && a >= -1)
			{
				e = -(x2 - x1);
				while (x1 <= x2)
				{
					if (e > 0) {
						y1 -= 1;
						e = e - 2 * (x2 - x1);
					}
					PutPixel(x1, y1, color);
					x1 += 1;
					e += 2 * (y1 - y2);
				}
			}
			if (a < -1)
			{
				e = (y2 - y1);
				while (y1 > y2)
				{

					if (e > 0) {
						x1 += 1;
						e = e - 2 * -(y2 - y1);
					}
					PutPixel(x1, y1, color);
					y1 -= 1;
					e += 2 * (x2 - x1);
				}
			}
		}
	}


}
![LinesToAllDirections.png](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/LinesToAllDirections.png)

![Art.png](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Art.png)
