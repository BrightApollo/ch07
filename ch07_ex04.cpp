/*
4. You operate several hot dog stands distributed throughout town.
Define a class named HotDogStand
	that has a member variable for the hot dog stand�s ID number
	and a member variable for how many hot dogs the stand sold that day.
Create a constructor that allows a user of the class to initialize both values.
Also create a function named JustSold that increments the number of hot dogs the stand has sold by one.
	This function will be invoked each time the stand sells a hot dog
	so that you can track the total number of hot dogs sold by the stand.
Add another function that returns the number of hot dogs sold.
Finally, add a static variable that tracks the total number of hot dogs sold by all hot dog stands
	and a static function that returns the value in this variable.
Write a main function to test your class
	with at least three hot dog stands
	that each sell a variety of hot dogs.
*/

#include <iostream>

	class HotdogStand{
		public:
			HotdogStand(int a, int b){
				if(a < 0 || b < 0) {
					std::cout << "You are fucking stupid." << std::endl;
					exit(-1);
				}
				a = checkID(a);
				standID = a;
				dailySold = b;
			};

			void justSold();
			int sellCount();
			int showID();
			static int allSellCount();

		private:
			static int ID;
			static int standTotals;

			int standID;
			int dailySold;

			int checkID(int a);
	};

	int HotdogStand::ID = 0;
	int HotdogStand::standTotals = 0;

	void testStandWith(HotdogStand &s, int b);

	int main(){
		
		HotdogStand stand01(1,0);
		HotdogStand stand02(2,0);
		HotdogStand stand03(3,0);

		testStandWith(stand01, 4);
		std::cout << stand01.sellCount() << " sold after call." << std::endl;

		testStandWith(stand02,12);

		testStandWith(stand03, 3);

		testStandWith(stand01, 11);
		std::cout << stand01.sellCount() << " sold after call." << std::endl;

		return 0;

	}

	int HotdogStand::checkID(int a){
		if(a == ID) {
			return ++a;
		} else if (a > ID) {
			ID = a;
			return a;
		} else {
			return a;
		}
	}

	void HotdogStand::justSold(){
		dailySold++;
		standTotals++;
	}

	int HotdogStand::sellCount(){
		return dailySold;
	}

	int HotdogStand::allSellCount(){
		return standTotals;
	}

	int HotdogStand::showID(){
		return standID;
	}

	void testStandWith(HotdogStand &s, int b){
		for(int i = 0; i < b; i++){
			s.justSold();
		}
		std::cout << "The hotdog stand "<< s.showID() << " has sold  " << s.sellCount() << " and all stands have sold " << HotdogStand::allSellCount() << std::endl;
	}