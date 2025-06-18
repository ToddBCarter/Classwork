/*Todd Carter
Section 3
Lab 14
12-5-2021*/

#include<iostream>
#include<cstdlib>
using namespace std;

/*For the sake of simplicity, the functions were
passed the length of the array, the array itself,
and a reference to the relevant variable in main.
No random seed was used in case that helps with 
ease of grading.*/

void print(int[], int);
void average(int[], double&, int);
void summation(int[], int&, int);

int main() {
    int array[10];
    int len = 10;
    for (int i = 0; i < len; i++) {
        array[i] = rand() % 100;
    }
    cout << "The array values are:\n";
    print(array, len);

    double avg = 0;
    average(array, avg, len);
    cout << "The average value is: " << avg << endl;

    int sum = 0;
    summation(array, sum, len);
    cout << "The sum of the values is: " << sum << endl;
}

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

void average(int arr[], double& ave, int len)
{
    int sum = arr[0];
    for (int i = 1; i < len; i++)
    {
        sum = sum + arr[i];
    }
    ave = sum / len;
}

void summation(int arr[], int& sum, int len)
{
    sum = arr[0];
    for (int i = 1; i < len; i++)
    {
        sum = sum + arr[i];
    }
}