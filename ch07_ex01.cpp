/*
1. Define a class called RainbowColor that is an abstract data type for a color in the visible
spectrum of light. Your class will have a member variable of type int to represent
a color. Include all the following member functions:
	a constructor to set the color using the first letter in the name of the color as an argument,
	a constructor to set the color using an integer as an argument,
	a default constructor,
*** (text was written poorly, interpreting) *** getters and setters for the color by int or init char
	and a member function that returns the next color in the spectrum as a value of type RainbowColor.
Embed your class definition in a test program.

	color key
		ultra 360
	    violet 380 to 420
		indigo 420 to 450
		blue 450 to 490
		cyan 490 to 520
		green 520-565
		yellow 565-590
		orange 590-625
		red 625-750
		infra 900
*/

#include <iostream>

	class RainbowColor{
		public:
			RainbowColor(char c) {
				switch (c){
					case 'v':
						color = "Violet"; wavelength = 420; waveLeft = 450; waveRight = 360;
						break;
					case 'i':
						color = "Indigo"; wavelength = 450; waveLeft = 490; waveRight = 420;
						break;
					case 'b':
						color = "Blue"; wavelength = 490; waveLeft = 520; waveRight = 450;
						break;
					case 'c':
						color = "Cyan"; wavelength = 520; waveLeft = 565; waveRight = 490;
						break;
					case 'g':
						color = "Green"; wavelength = 565; waveLeft = 590; waveRight = 520;
						break;
					case 'y':
						color = "Yellow"; wavelength = 590; waveLeft = 625; waveRight = 565;
						break;
					case 'o':
						color = "Orange"; wavelength = 625; waveLeft = 750; waveRight = 590;
						break;
					case 'r':
						color = "Red"; wavelength = 750; waveLeft = 900; waveRight = 625;
						break;
					default:
						color = "Infrared"; wavelength = 900; waveLeft = 1200; waveRight = 750;
						break;
				}
			};

			RainbowColor(int c) {
				if (c < 380) {
					color = "UltraViolet"; wavelength = 360;
				} else if (c >= 380 && c <= 420){
						color = "Violet"; wavelength = 420;
				} else if (c > 420 && c <= 450){
						color = "Indigo"; wavelength = 450;
				} else if (c > 450 && c <= 490){
						color = "Blue"; wavelength = 490;
				} else if (c > 490 && c <= 520){
						color = "Cyan"; wavelength = 520;
				} else if (c > 520 && c <= 565){
						color = "Green"; wavelength = 565;
				} else if (c > 565 && c <= 590){
						color = "Yellow"; wavelength = 590;
				} else if (c > 590 && c <= 625){
						color = "Orange"; wavelength = 625;
				} else if (c > 625 && c <= 750){
						color = "Red"; wavelength = 750;
				} else {
						color = "Infrared"; wavelength = 900;
				}
			};

			RainbowColor() {
				color = "Undefined"; wavelength = 0;
			};

			void setColor(int c);

			void setColor (char c);

			int getColorWavelength();

			std::string getColorName();

			RainbowColor nextColorRight();
			RainbowColor nextColorLeft();

		private:
			int wavelength;
			std::string color;
			int waveLeft; 	//color towards infrared, or lengthening
			int waveRight;	// color towards ultraviolet, or narrowing
	};

	int main(){

		RainbowColor newColor;
		newColor.setColor('v');

		RainbowColor color2('r');
		RainbowColor color3(535);
		
		std::cout << "The color is " << newColor.getColorName() << " and it has a wavelength of " << newColor.getColorWavelength() << " . " << std::endl;

		std::cout << "The next color is " << color2.getColorName() << " and it has a wavelength of " << color2.getColorWavelength() << " . " << std::endl;

		std::cout << "The other color is " << color3.getColorName() << " and it has a wavelength of " << color3.getColorWavelength() << " . " << std::endl;

		RainbowColor color4 = newColor.nextColorRight();
		RainbowColor color5 = newColor.nextColorLeft();

		std::cout << "The color to the right of " << newColor.getColorName() << " is " << color4.getColorName() << " and to the left is " << color5.getColorName() << std::endl;


		return 0;

	}




	void RainbowColor::setColor(int c) {
		if (c < 380) {
			color = "UltraViolet"; waveLeft = 380; waveRight = 300;
		} else if (c >= 380 && c <= 420){
				color = "Violet"; waveLeft = 420; waveRight = 380;
		} else if (c > 420 && c <= 450){
				color = "Indigo"; waveLeft = 450; waveRight = 420; 
		} else if (c > 450 && c <= 490){
				color = "Blue"; waveLeft = 490; waveRight = 450; 
		} else if (c > 490 && c <= 520){
				color = "Cyan"; waveLeft = 520; waveRight = 490;
		} else if (c > 520 && c <= 565){
				color = "Green"; waveLeft = 565; waveRight = 520;
		} else if (c > 565 && c <= 590){
				color = "Yellow"; waveLeft = 590; waveRight = 565;
		} else if (c > 590 && c <= 625){
				color = "Orange"; waveLeft = 625; waveRight = 590;
		} else if (c > 625 && c <= 750){
				color = "Red"; waveLeft = 800; waveRight = 625; 
		} else {
				color = "Infrared"; waveLeft = 900; waveRight = 750;
		}
		wavelength = c;
	}

	void RainbowColor::setColor (char c){
		switch (c){
			case 'v':
				color = "Violet"; wavelength = 420; waveLeft = 450; waveRight = 360;
				break;
			case 'i':
				color = "Indigo"; wavelength = 450; waveLeft = 490; waveRight = 420;
				break;
			case 'b':
				color = "Blue"; wavelength = 490; waveLeft = 520; waveRight = 450;
				break;
			case 'c':
				color = "Cyan"; wavelength = 520; waveLeft = 565; waveRight = 490;
				break;
			case 'g':
				color = "Green"; wavelength = 565; waveLeft = 590; waveRight = 520;
				break;
			case 'y':
				color = "Yellow"; wavelength = 590; waveLeft = 625; waveRight = 565;
				break;
			case 'o':
				color = "Orange"; wavelength = 625; waveLeft = 750; waveRight = 590;
				break;
			case 'r':
				color = "Red"; wavelength = 750; waveLeft = 900; waveRight = 625;
				break;
			default:
				color = "Infrared"; wavelength = 900; waveLeft = 1200; waveRight = 750;
				break;
		}
	}
		
	int RainbowColor::getColorWavelength(){
		return wavelength;
	};

	std::string RainbowColor::getColorName(){
		return color;
	}

	RainbowColor RainbowColor::nextColorRight(){
		return RainbowColor(waveRight);
	}

	RainbowColor RainbowColor::nextColorLeft(){
		return RainbowColor(waveLeft);
	}
