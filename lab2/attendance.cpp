#include <iostream>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int climbstairs(int n)
{
    return fib(n+1);
}

int main()
{
    int n_steps;

    cout << "How many steps are there?" << endl;
    cin >> n_steps;

    cout << climbstairs(n_steps);
}