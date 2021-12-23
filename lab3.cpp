#include "GraphicsLib.h"
#include <fstream>
#include <iostream>

using namespace std;


void Draw::ClearDisplay(char* color)
{
	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n ClearDisplay" << std::endl;
		fout << "|0|?1?<" << color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawPixel(int_least16_t x0, int_least16_t y0, char* color)
{
	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawPixel" << std::endl;
		fout << "|1|?3?<" << x0 << ", " << y0 << ", " << color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1,
	char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawLine"<< std::endl;
		fout << "|2|?5?<" << x0 << ", " << y0 << ", " << x1 << ", " << y1 << ", "
			<< color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawRectangle(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h,
	char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawRectangle" << std::endl;
		
		fout << "|3|?5?<" << x0 << ", " << y0 << ", " << w << ", " << h << ", "
			<< color << ">";
	}
	fout.close();

	return;
}

void Draw::FillRectangle(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h,
	char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n FillRectangle" << std::endl;
		
		fout << "|4|?5?<" << x0 << ", " << y0 << ", " << w << ", " << h << ", "
			<< color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t radius_x, int_least16_t radius_y,
	char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawEllipse" << std::endl;
		
		fout << "|5|?5?<" << x0 << ", " << y0 << ", " << radius_x << ", " << radius_y << ", "
			<< color << ">";
	}
	fout.close();

	return;
}

void Draw::FillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t radius_x, int_least16_t radius_y,
	char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n FillEllipse" << std::endl;
		
		fout << "|6|?5?<" << x0 << ", " << y0 << ", " << radius_x << ", " << radius_y << ", "
			<< color << ">";
	}
	fout.close();

	return;
}

void Draw::FillCircle(int_least16_t x0, int_least16_t y0, int_least16_t radius, char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n FillCircle" << std::endl;
		
		fout << "|8|?4?<" << x0 << ", " << y0 << ", " << radius << ", " << color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawCircle(int_least16_t x0, int_least16_t y0, int_least16_t radius, char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawCircle" << std::endl;
		
		fout << "|7|?4?<" << x0 << ", " << y0 << ", " << radius << ", " << color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawRoundedRectangle(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h,
	int_least16_t radius, char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawRoundedRectangle" << std::endl;
	
		fout << "|9|?6?<" << x0 << ", " << y0 << ", " << w << ", " << h << ", "
			<< radius << ", " << color << ">";
	}
	fout.close();

	return;
}

void Draw::FillRoundedRectangle(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h,
	int_least16_t radius, char* color) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n FillRoundedRectangle" << std::endl;
		
		fout << "|10|?6?<" << x0 << ", " << y0 << ", " << w << ", " << h << ", "
			<< radius << ", " << color << ">";
	}
	fout.close();

	return;
}

void Draw::DrawText(int_least16_t x0, int_least16_t y0, char* str, char* color,
	int_least16_t type, uint_least8_t size) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawText" << std::endl;
		
		fout << "|11|?6?<" << x0 << ", " << y0 << ", " << str << ", " << color << ", "
			<< type << ", " << size << ">";
	}
	fout.close();


	return;
}

void Draw::DrawImage(int_least16_t x0, int_least16_t y0, int_least16_t width, int_least16_t height,
	char* imgData) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawImage" << std::endl;
		
		fout << "|12|?5?<" << x0 << ", " << y0 << ", " << width << ", " << height << ", "
			<< imgData << ">";
	}
	fout.close();

	return;
}

void Draw::SetOrientation(uint_least8_t orientation) {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\n DrawImage" << std::endl;
		
		fout << "|13|?1?<" << orientation << ">";
	}
	fout.close();

	return;
}

int_least16_t Draw::GetWidth() {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\nWidth" << std::endl;
		
		fout << "|14|?0?<" << ">";
	}
	fout.close();

	return 0;
}

int_least16_t Draw::GetHeight() {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\nHeight" << std::endl;
		
		fout << "|15|?0?<" << ">";
	}
	fout.close();

	return 0;
}

void Draw::GetTime_() {

	std::ofstream fout;
	fout.open("logs.txt");
	if (fout.is_open())
	{
		cout << "\nTime" << std::endl;

		fout << "|16|?0?<" << ">";
	}
	fout.close();

}
