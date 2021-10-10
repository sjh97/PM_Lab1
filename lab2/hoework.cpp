#include<iostream>
#include<string>
using namespace std;

int answer[10], selection[10];
int num;

void solve_problem(int depth)
{

}

int main()
{
    num = 0;
    cout << "Enter the 10 answers : " << endl;
    for(int i=0;i<10;i++){
        cin >> answer[i];
    }
    solve_problem(0);
    cout << "The result is : " << num << endl;
}