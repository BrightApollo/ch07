#include <iostream>

    int josephusIteration(int n,int k);

    int main() {
        int num = 10, kth = 3;
        std::cout << "The number of soldiers is " << num << " and the killing is on the " << kth << "th person so the safe spot is " << josephusIteration(num, kth) << " . " << std::endl;
    }


int josephusIteration(int n,int k) {
    int a=1;
    for(int i=1;i<=n;i++) {
        a=(a+k-1)%i+1;
    }
    return a;
}