/*
8. Write a program that outputs a histogram of grades for an assignment given to a class of students. 
The program should input each student's grade as an integer and store the grade in a vector. 
Grades should be entered until the user enters -1 for a grade. 
The program should then scan through the vector and compute the histogram. 
In computing the histogram, the minimum value of a grade is 0, 
    but your program should determine the maximum value entered by the user. 
Output the histogram to the console. See Programming Project 5.7 for information on how to compute a histogram.

ch05_ex07. Generate a text-based histogram for a quiz given to a class of students. The quiz is
graded on a scale from 0 to 5. Write a program that allows the user to enter grades
for each student. As the grades are being entered, the program should count, using
an array, the number of 0s, the number of 1s, the number of 2s, the number of
3s, the number of 4s, and the number of 5s. The program should be capable of
handling an arbitrary number of student grades.
You can do this by making an array of size 6, where each array element is initialized
to zero. Whenever a zero is entered, increment the value in the array at index 0.
Whenever a one is entered, increment the value in the array at index 1, and so on,
up to index 5 of the array.
Output the histogram count at the end. For example, if the input grades are 3, 0,
1, 3, 3, 5, 5, 4, 5, 4, then the program should output
1 grade(s) of 0
1 grade(s) of 1
0 grade(s) of 2
3 grade(s) of 3
2 grade(s) of 4
3 grade(s) of 5
*/

    #include <iostream>
    #include <cmath>
    #include <vector>
    
    struct gradeCNT{
        int gradeVal;
        int count;
    };

    void getGrades(std::vector<gradeCNT>& a);
    int find(std::vector<gradeCNT> a, struct gradeCNT g);
    void graph(std::vector<gradeCNT>& a);
    void printAsterisks(int n);
 
    int main(){
       std::vector<gradeCNT> assignmentGrades;

        std::cout << "This program displays a graph showing the grade distribution for a class" << std::endl;
        getGrades(assignmentGrades);
        graph(assignmentGrades);
        
        return 0;
    }
  
    void getGrades(std::vector<gradeCNT>& a){
        unsigned int gradeCnt = 0, inGrade, curGrade = 0;
        struct gradeCNT newGrade;
        /*
        create new grade struct, populate it, find it, if not found pushback else update existing
        */
        while(curGrade != -1){
            std::cout << "Enter a grade between zero and five, and a negative number to quit: "; std::cin >> newGrade.gradeVal;
            if(newGrade.gradeVal < 0){
                break;
            } else {
                curGrade = find(a, newGrade);
                if(curGrade > 0){
                    a[curGrade].count++;
                } else{
                    newGrade.count = 1;
                    a.push_back(newGrade);
            }
        }
    }  

    int find(std::vector<gradeCNT> a, struct gradeCNT g){

    }
 
    void graph(std::vector<gradeCNT>& a){
        std::cout << "Here's your grade distro";
        for (unsigned int i=0; i< a.size(); i++){
            switch(i){
                case 0: 
                    std::cout << std::endl << "Zeros  count: " << a[i].count << " ";
                    printAsterisks(a[i].count);
                    break;
                case 1:  
                    std::cout << std::endl << "Ones   count: " << inArr[i] << " ";
                    printAsterisks(inArr[i]);
                    break;
                case 2: 
                    std::cout << std::endl << "Twos   count: " << inArr[i] << " "; 
                    printAsterisks(inArr[i]);
                    break;
                case 3: 
                    std::cout << std::endl << "Threes count: " << inArr[i] << " "; 
                    printAsterisks(inArr[i]);
                    break;
                case 4: 
                    std::cout << std::endl << "Fours  count: " << inArr[i] << " "; 
                    printAsterisks(inArr[i]);
                    break;
                case 5: 
                    std::cout << std::endl << "Fives  count: " << inArr[i] << " "; 
                    printAsterisks(inArr[i]);
                    break;
                default:
                    std::cout << "BROKEN LOOP" << inArr[i] << std::endl; 
                    break;
                cout << endl;
            }
        }
    }

    void printAsterisks(int n){
        for (int i = 1; i <= n; i++){
            std::cout << "*";
        }
    }