/*
3. My mother always took a little red counter to the grocery store. The counter was
used to keep tally of the amount of money she would have spent so far on that visit
to the store if she bought everything in the basket. The counter had a four-digit
display, increment buttons for each digit, and a reset button. An overflow indicator
came up red if more money was entered than the $99.99 it would register. (This
was a long time ago.)

Write and implement the member functions of a class Counter that simulates and
slightly generalizes the behavior of this grocery store counter. The constructor should
create a Counter object that can count up to the constructor’s argument. That is,
Counter(9999) should provide a counter that can count up to 9999. A newly constructed
counter displays a reading of 0. 
The member function void reset( ); sets the counter’s number to 0. 
The member function void incr1( ); increments the units digits by 1, 
void incr10( ); increments the tens digit by 1, 
and void incr100( ); and void incr1000( ); increment the next two digits, respectively.

Accounting for any carrying when you increment should require no further action than
adding an appropriate number to the private data member. 
A member function bool overflow( ); detects overflow. 
(Overflow is the result of incrementing the counter’s private data member beyond the maximum entered at counter construction.)
Use this class to provide a simulation of my mother’s little red clicker. Even though
the display is an integer, in the simulation, the rightmost (lower order) two digits
are always thought of as cents and tens of cents, the next digit is dollars, and the
fourth digit is tens of dollars.
Provide keys for cents, dimes, dollars, and tens of dollars. Unfortunately, no choice of
keys seems particularly mnemonic.  Or use L for cents, R for dimes, W for dollars, H for tens. 
One choice is to use the keys asdfo: a for cents,
followed by a digit 1 to 9; s for dimes, followed by a digit 1 to 9; d for dollars, followed
by a digit 1 to 9; and f for tens of dollars, again followed by a digit 1 to 9. Each entry
(one of asdf followed by 1 to 9) is followed by pressing the Return key. 

a is ten of dollars, s is dollars, d is tens of cents, f is cents,
a3<return> should increment the counter by 3000; f1<return> should increment the counter by 1.
Adding 14.99 would be
    a1<ret>
    s4<ret>
    d9<ret>
    f9<ret>
Show counter after each entry.
Overflow check
r to reset
Any overflow is reported after each operation. Overflow can be requested by pressing the o key.
Forget requesting overflow, that's stupid.
*/

#include <iostream>

    class Counter{
        public:
            Counter(){
                countLim = 9999;
            };

            Counter(int a){
                if(a<1 || a > 9999){
                    countLim = 9999;
                }else{
                    countLim = a;
                }
            };

            void reset();
            void inc0001();
            void inc0010();
            void inc0100();
            void inc1000();
            int getCount();
            int getLim();
            bool checkOverflow();
        private:
            int countLim;
            int countOut;
    };

    void instruct();

    int main(){
        int clicks;
        char col = ' ';
        Counter aco;
        
        std::cout << "This is a counter.  It has this limit " << aco.getLim() << " ." << std::endl;
        std::cout << "It currently has this count " << aco.getCount() << " ." << std::endl;
        instruct();
        std::cout << "Start clicking: [a/s/d/f, o, r, i, q]"; std::cin >> col;     
        
        while(col != 'q'){
            switch(col){
                case 'a':
                    std::cout << "How many clicks? "; std::cin >> clicks;
                    for(int i=0; i < clicks; i++){
                        aco.inc1000();
                    }
                    break;
                case 's':
                    std::cout << "How many clicks? "; std::cin >> clicks;
                    for(int i = 0; i < clicks; i++){
                        aco.inc0100();
                    }
                    break;
                case 'd':
                    std::cout << "How many clicks? "; std::cin >> clicks;
                    for(int i = 0; i < clicks; i++){
                        aco.inc0010();
                    }
                    break;
                case 'f':
                    std::cout << "How many clicks? "; std::cin >> clicks;
                    for(int i = 0; i < clicks; i++){
                        aco.inc0001();
                    }
                    break;
                case 'r':
                    aco.reset();
                    break;
                case 'i':
                    instruct();
                    break;
                default:
                    break;
            } //end-switch
            if( aco.checkOverflow() ){
                std::cout << "Counter overflowed" << std::endl;
            } else {
                std::cout << "No overflow.  Current count is: " << aco.getCount() << " ." << std::endl;
            }
             std::cout << "Start clicking: [a/s/d/f, o, r, i, q]"; std::cin >> col;    
        } //end-while driving the test

        std::cout << "Be astonished." << std::endl;

        return 0;

    }

    void instruct(){
            std::cout << "To increment use a for tens, s for dollars, d for dimes, f for cents." << std::endl;
            std::cout << "then use 1-9 for the number of 'clicks' of that value." << std::endl;
            std::cout << "For example, a3 would add 3000 to the counter.  d9 would add 90." << std::endl;
            std::cout << "To reset choose 'r'.  To check overflow choose 'o'.  To quit choose 'q'." << std::endl;
            std::cout << "To see these instructions again choose 'i'." << std::endl;
    }

    void Counter::reset(){
        countOut = 0;
    };

    int Counter::getCount(){
        return countOut;
    }

    int Counter::getLim(){
        return countLim;
    }

    bool Counter::checkOverflow(){
        if(countOut > countLim){
            return true;
        } else {
            return false;
        }
    }

    void Counter::inc0001(){
        countOut++;
    }

    void Counter::inc0010(){
        countOut = countOut + 10;
    }

    void Counter::inc0100(){
        countOut = countOut + 100;
    }

    void Counter::inc1000(){
        countOut = countOut + 1000;
    }
