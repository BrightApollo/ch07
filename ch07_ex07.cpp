/*
7. Do Programming Project 6.8, the definition of a Money class, except create a default
constructor that sets the monetary amount to 0 dollars and 0 cents, and create
a second constructor with input parameters for the amount of the dollars and cents
variables. Modify your test code to invoke the constructors.


ch06-08. Define a class named Money that stores a monetary amount. The class should have
two private integer variables, one to store the number of dollars and another to
store the number of cents. Add accessor and mutator functions to read and set both
member variables. Add another function that returns the monetary amount as a
double. Write a program that tests all of your functions with at least two different
Money objects.
*/

#include <iostream>

class Money {
    public:
        Money(){
            dollars = 0;
            cents = dollars;
        };

        Money(int d, int c){
            dollars = d;
            cents = c;
        };

        void setDollars();
        void setCents();
        std::string getDollars();
        std::string getCents();
        void getMoney();
    private:
        int dollars;
        int cents;
};

    int main() {

        Money myMoney;

        myMoney.setDollars();
        myMoney.setCents();

        myMoney.getMoney();

        Money yourMoney(16, 122);

        yourMoney.getMoney();

        return 0;

    }

    void Money::setDollars(){
        std::cout << "How many dollars? "; std::cin >> dollars;
    }

    void Money::setCents(){
        std::cout << "How much change? "; std::cin >> cents;
        while(cents > 99) {
            dollars++;
            cents = cents - 100; 
        }   
    }

    std::string Money::getDollars(){
        std::string outS;
        switch(dollars) {
            case 0:
                outS =  "No dollars!";
                break;
            case 1:
                outS = "One dollar!";
                break;
            default:
                outS = std::to_string(dollars) + " dollars.";
                break;
        }
        return outS;
    }

    std::string Money::getCents(){
        std::string outS;
        switch(cents) {
            case 0:
                outS = "No change!";
                break;
            case 1:
                outS = "One penny!";
                break;
            default:
                outS = std::to_string(cents) + " cents.";
                break;
        }
        return outS;
    }
    
    void Money::getMoney(){
        int d, c;
        double m = 0.0;

        std::cout << "You have " << getDollars() << " and " << getCents() << std::endl;

        d = std::stoi(getDollars());
        c = std::stoi(getCents());
        m = d * 1.0;
        m = m + (c*0.01);

    std::cout << "You have $" << m << " in cash." << std::endl;
    }