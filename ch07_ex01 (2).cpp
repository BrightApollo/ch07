/*
1. Define a class called RainbowColor that is an abstract data type for a color in the visible
spectrum of light. Your class will have a member variable of type int to represent
a color. Include all the following member functions:
	a constructor to set the color using the first letter in the name of the color as an argument,
	a constructor to set the color using an integer as an argument,
	a default constructor,
	an input function that reads the color as an integer,
	an OUTPUT (correcting input from text) function that outputs the color as an integer,
	an output function that outputs the name of the color,
	and a member function that returns the next color in the spectrum as a value of type RainbowColor.
Embed your class definition in a test program.
*/

#include <iostream>

	class RainbowColor{
		public:
			RainbowColor(char c) {
			};

			RainbowColor(int c) {
			};

			RainbowColor() {
			};

			void setColor(int c);

			int showWavelength();

			std::string showColor();

			RainbowColor nextColorRight();
			RaindowColor nextColorLeft();

		private:
			int wavelength;
			std::string color;
	};

	int main(){

		return 0;

	}


	/* violet 380 to 420
		indigo 420 to 450
		blue 450 to 490
		cyan 490 to 520
		green 520-565
		yellow 565-590
		orange 590-625
		red 625-750
