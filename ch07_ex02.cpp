/*
2. Define a class called Rectangle that has two member variables of type double to
represent the width and height of a rectangle. Include these member functions:
a constructor to construct the Rectangle class using width and height as arguments,
a default constructor that initializes both width and height to 5, and a
member function each to set width and height. Also include a member function
that computes the area of the rectangle, and output functions to display the width,
height, and area of the rectangle.
*/

#include <iostream>

	class Rectangle {
		public:
			Rectangle(int a, int b){
				width = a;
				height = b;
			};
			Rectangle(){
				width = 5;
				height = width;
			};

			void setWidth(int a);
			void setHeight(int a);

			int getWidth();
			int getHeight();

			int getArea();

		private:
			int width;
			int height;
	};

	int main(){

		Rectangle ang(3,12);
		Rectangle le;

		std::cout << "Rectangle ang is " << ang.getWidth() << " wide and " << ang.getHeight() << " tall.  It has an area of " << ang.getArea() << " . " << std::endl;
		std::cout << "Rectangle le is " << le.getWidth() << " wide and " << le.getHeight() << " tall.  It has an area of " << le.getArea() << " . " << std::endl;

		le.setWidth(42); le.setHeight(9);

		std::cout << "Rectangle le after mod is " << le.getWidth() << " wide and " << le.getHeight() << " tall.  It has an area of " << le.getArea() << " . " << std::endl;

		return 0;

	}

	void Rectangle::setWidth(int a){
		width = a;
	};

	void Rectangle::setHeight(int a){
		height = a;
	};

	int Rectangle::getWidth(){
		return width;
	};

	int Rectangle::getHeight(){
		return height;
	};

	int Rectangle::getArea(){
		return (height * width);
	};
