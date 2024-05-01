/*
5. In an ancient land, the beautiful princess Eve had many suitors. She decided on
the following procedure to determine which suitor she would marry.
	First, all of the suitors would be lined up one after the other and assigned numbers.
	The first suitor would be number 1, the second number 2, and so on up to the last suitor, number n.
	Starting at the first suitor she would then count three suitors down the line (because of the three letters in her name)
		she would count UP three numbers
	and the third suitor would be eliminated from winning her hand and removed from the line.
	Eve would then continue, counting three more suitors, and eliminating every third suitor.
	When she reached the end of the line she would continue counting from the beginning.
For example, if there were six suitors then the elimination process would proceed
as follows:
123456 initial list of suitors, start counting from 1, then 2, then 3.
12456 suitor 3 eliminated, continue counting from 4, then 5, then 6
1245 suitor 6 eliminated, continue counting from 1, then 2, then 4.
125 suitor 4 eliminated, continue counting from 5, then 1, then 2.
15 suitor 2 eliminated, continue counting from 5, then 1, then 5.
1 suitor 5 eliminated, 1 is the lucky winner.
Write a program that uses a vector to determine which position you should stand in to marry the princess if there are n suitors.
You will find the following function from the Vector class useful:
	// Removes element at position iter
	v.erase(iter);
For example, to use this function to erase the fourth element from the beginning of a vector variable named theVector,
	use theVector.erase(theVector.begin( ) + 3);
The number 3 is used because the first element in the vector is at index position 0.
*/

#include <iostream>
#include <vector>

	int loopSome(int off, int skip, std::vector<int>& s);  // we want to alter it.  a lot.
	int josephusIteration(int n,int k);

	int main(){
		int num, kth;
		std::vector<int> suits;
		std::vector<int>::iterator it;
 
    	it = suits.begin();
    
		std::cout << "Enter the number of people: "; std::cin >> num;
		std::cout << "Now enter the skip sequence [e.g. 3 for every third]: "; std::cin >> kth;

		for(unsigned int i = 0; i < num; i++){
			suits.push_back(i+1);
		}
		
		std::cout << "You entered: ";
		for (unsigned int i = 0; i < suits.size(); i++) {
			std::cout << suits[i] << " ";
		}
		std::cout << std::endl;

		int index = 0, offset = 0;

		while(suits.size() > 1){
			offset = loopSome(offset, kth, suits);
			if (offset == suits.size()){
				offset = 0;
			}
		}
		std::cout << "Maybe it's this? " << suits[offset] << std::endl;

		/*
		while(suits.size() > 1){
		 	it = suits.begin() + kth;
			suits.erase(it);
		}
		*/

		std::cout << "VERIFYING: the number of soldiers is " << num << " and we remove every " << kth << "th person so the safe spot is " << josephusIteration(num, kth) << " . " << std::endl;

		return 0;
	}

	int loopSome(int off, int skip, std::vector<int>& s){
		for(int i = 0; i < skip; i++){
			off = off % s.size();
			off++;
		}
		off--;
		s.erase(s.begin( ) + off);
		return off;
	}
	
	
	int josephusIteration(int n,int k) {
		int a=1;
		for(int i=1;i<=n;i++) {
			a=(a+k-1)%i+1;
		}
		return a;
	}