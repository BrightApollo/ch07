/*
6. This Programming Project requires you to first complete Programming Project 6.7
from Chapter 6, which is an implementation of a Pizza class. 
Add an Order class that contains a private vector of type Pizza. This class represents a customer's
entire order, where the order may consist of multiple pizzas. 
Include appropriate functions so that a user of the Order class can add pizzas to the order (type is deep
dish, hand tossed, or pan; size is small, medium, or large; number of pepperoni or
cheese toppings). 
You can use constants to represent the type and size. 
Also write a function that outputs everything in the order along with the total price. 
Write a suitable test program that adds multiple pizzas to an order(s).


7. Define a class called Pizza that has member variables to track the type of pizza
(either deep dish, hand tossed, or pan) along with the size (either small, medium,
or large) and the number of pepperoni or cheese toppings. You can use constants to
represent the type and size. Include mutator and accessor functions for your class.
Create a void function, outputDescription( ), that outputs a textual description
of the pizza object. Also include a function, computePrice( ), that computes the
cost of the pizza and returns it as a double according to the following rules:
Small pizza = $10 + $2 per topping
Medium pizza = $14 + $2 per topping
Large pizza = $17 + $2 per topping
Write a suitable test program that creates and outputs a description and price of
various pizza objects.
*/

#include <iostream>
#include <iomanip>
#include <vector>

struct tops {
            std::string quantity;    //half or whole
            std::string topType;
};

class Pizza {
    public:
        void showToppingChoices();
        void showPizzaSizes();
        void showPizzaTypes();
        void showYourPizza();
        void showMenu();
        void buildYourPizza();
        double totalUpPizza();
    private:
        std::string type;
        std::string size;
        double smlPrice = 10.00;
        double medPrice = 14.00;
        double lgPrice = 17.00;
        double topPrice = 2.00;
        tops myTops[10];
};

const std::string topTypes[] = {
    "Pepperoni",
    "Meatball",
    "Extra Cheese",
    "Onions",
    "Peppers",
    "Cherry Peppers",
    "Sausage",
    "Mushroom",
    "Anchovies",
    "Sun Dried Tomato"
};

class Order {
    public:
        Order(){
         };
        void showOrder();
        void totalOrder();
        void manageOrder();
        void addPie();
        void killPie();
    private:
        static double orderTotal;
        std::vector<Pizza> pz;
};

    double Order::orderTotal = 0.0;


    int main(){

        Order myOrder;
        myOrder.manageOrder();

        return 0;

    }

void Pizza::showToppingChoices(){
    const int STRL = 18;  //set to max

    std::cout << "You can choose from these: " << std::endl;

    for(int i = 0; i < 5; i++){
        std::cout << std::left << std::setw(STRL) << std::to_string(i+1) + "- " + topTypes[i];
        std::cout << std::left << std::setw(STRL) << std::to_string(i+6) + "- " + topTypes[i+5] << std::endl;
    }
    std::cout << "And you can choose half the pie or the whole thing with the topping." << std::endl;
}

void Pizza::showPizzaSizes(){
    std::cout << "You can order a small, medium, or large." << std::endl;
}

void Pizza::showPizzaTypes(){
    std::cout << "We do pan pizza, deep-dish Chicago style casserole pizza (hilarious), and hand-tossed (whatever that is)." << std::endl;
}

void Pizza::showYourPizza(){
    bool SOMETHING = false;
    std::string toppings;
    for(int i = 0; i < 10; i++){
        if(myTops[i].quantity == "half") {
            if(!SOMETHING) {
                toppings = toppings + " with half " + myTops[i].topType;
            } else {
                toppings = toppings + ", half " + myTops[i].topType;
            }
            SOMETHING = true;
        } else if (myTops[i].quantity == "whole"){
            if(!SOMETHING) {
                toppings = toppings + " with " + myTops[i].topType;
            } else {
                toppings = toppings + ", " + myTops[i].topType;
            }
            SOMETHING = true;
        }
    }
    std::cout << "You ordered a " << size << " " << type << " pie" << toppings << " which cost $" << totalUpPizza() << std::endl;
}

void Pizza::showMenu(){
    showPizzaSizes();
    showPizzaTypes();
    showToppingChoices();
    std::cout << "Current pricing is $" << smlPrice << " for small, $" << medPrice << " for a medium, and $" << lgPrice << " for a large." << std::endl;
    std::cout << "Each topping is $" << topPrice << " for the whole pie, and $" << (topPrice / 2) << " for half the pie." << std::endl;
}


void Pizza::buildYourPizza(){
    int chooser, topCnt = -1, offset;
    char choice = 't';

    showMenu();
    std::cout << "What kind of pizza would you like? 1-pan pizza, 2-deep-dish, or 3-hand-tossed: "; std::cin >> chooser;
    switch(chooser){
        case 1:
            type = "pan";
            break;
        case 2:
            type = "deep-dish";
            break;
        case 3:
        default:
            type = "hand-tossed"; //I'm not dealing with range restrictions
            break;
    }
    std::cout << "I got a " << type << " pizza.  What size? 1-small, 2-medium, or 3-large: "; std::cin >> chooser;
    switch(chooser){
        case 1:
            size = "small";
            break;
        case 2:
            size = "medium";
            break;
        case 3:
        default:
            size = "large"; //I'm not dealing with range restrictions
            break;
    }

    for(int i = 0; i < 10; i++){
        myTops[i].quantity = "none";
    }

    std::cout << "I got a " << size << " " << type << " pizza.  You want toppings? We go half the pie, or the whole pie: (y/n)"; std::cin >> choice;

    if(choice == 'y'){
        char wild = 't';
        std::cout << "You can have as many as you like.  Enter a zero to quit.  Do not order the same topping twice, just act normal." << std::endl;
        std::cout << "Which topping (1-10, 0 to quit): "; std::cin >> chooser;
        
        while(chooser != 0) {   
            /* chooser is displayed as canonical not offset, so subtract to use offset*/
            offset = chooser - 1;
            std::cout << "On the whole pie (w) or half the pie (h)? "; std::cin >> wild;
            if(wild == 'h'){
                myTops[offset].quantity = "half";
                myTops[offset].topType = topTypes[offset];
            } else {
                myTops[offset].quantity = "whole";    //again, not sanitizing input because I don't have all day
                myTops[offset].topType = topTypes[offset];
            }
            showYourPizza();
            showToppingChoices();
            std::cout << "Which topping (1-10, 0 to quit): "; std::cin >> chooser;
            if(chooser == 0) {
                break;
            }
        } // found a zero!
    }
}

double Pizza::totalUpPizza(){
    double price = 0.0;
    //size pricing
    if(size=="small") {
        price = price + smlPrice;
    } else if(size=="medium") {
        price=price + medPrice;
    } else {
        price = price+ lgPrice; //not sanitizing
    }

    for(int i = 0; i < 10; i++){
        if(myTops[i].quantity == "half") {
            price=price + (topPrice / 2);
        } else if (myTops[i].quantity == "whole") {
            price = price + topPrice;
        }
    }
     return price;
}

void Order::showOrder() {
    std::cout << "The current order is: " << std::endl;
    for (unsigned int i = 0; i < pz.size(); i++) {
        std::cout << "Order number " << i+1 << std::endl;
        pz[i].showYourPizza();
    }
    std::cout << std::endl << "Order total is $" << Order::orderTotal << "." << std::endl;
}

void Order::totalOrder(){
    Order::orderTotal = 0.0;
    for (unsigned int i = 0; i < pz.size(); i++) {
        Order::orderTotal = Order::orderTotal + pz[i].totalUpPizza();
    }
}

void Order::addPie(){
    Pizza myPie;
    myPie.buildYourPizza();
    pz.push_back(myPie);
    totalOrder();
}

void Order::killPie(){
    int chooser;
    if(pz.size() > 0) {
        std::cout << "Which pie must die?" << std::endl;
        for(int i = 0; i < pz.size(); i++){
            std::cout << "Pie " << i+1 << "..." << std::endl;
            pz[i].showYourPizza();
        }
        std::cout << "Which pie must die? "; std::cin >> chooser;
        if(chooser > 0 && chooser <= pz.size()){
            pz.erase(pz.begin() + (chooser - 1));
            orderTotal = 0.0;
            totalOrder();
        }
    }
}

void Order::manageOrder(){
    char chooser;
    std::cout << "Welcome to Joe's Pizza.  Whaddya want?" << std::endl;
    std::cout << "You can o)rder a pie, c)heck your current order, r)emove a pie, or q)uit: "; std::cin >> chooser;
    while(chooser != 'q'){
        switch(chooser){
            case 'o':
                std::cout << "New pie." << std::endl;
                addPie();
                break;
            case 'c':
                std::cout << "Show order!" << std::endl;
                showOrder();
                break;
            case 'r':
                std::cout << "Kill a pie!" << std::endl;
                killPie();
                break;
            case 'q':
                break;
            default:
                std::cout << "I can't do nothin' with that choice.  Try again." << std::endl;
                break;
        }
        if(chooser == 'q'){
            break;
        } else {
            std::cout << "You can o)rder a pie, c)heck your current order, r)emove a pie, or q)uit: "; std::cin >> chooser;
        }
    }

    std::cout << "This concludes our transaction." << std::endl;
    showOrder();
}
    