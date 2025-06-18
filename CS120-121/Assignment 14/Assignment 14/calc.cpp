#include<cstdlib> 
#include<iostream>  
#include<string.h>   
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "\nFor addition, use the the form: 1 + 1\n";
        cout << "For multiplication, use the form: 1 x 1\n";
        cout << "For division, use the form: 1 / 1\n";
        cout << "For the remainder, use the form: 1 % 1\n";

        return 0;
    }
    double answer = 0;
    int operand1, operand2;
    operand1 = atoi(argv[1]);
    operand2 = atoi(argv[3]);
    if (strcmp("+", argv[2]) == 0) {
        answer = double(operand1) + double(operand2);
    }

    if (strcmp("-", argv[2]) == 0) {
        answer = double(operand1) - double(operand2);
    }

    if (strcmp("x", argv[2]) == 0) {
        answer = double(operand1) * double(operand2);
    }

    if (strcmp("/", argv[2]) == 0) {
        if (operand2 != 0)
        {
            answer = double(operand1) / double(operand2);
        }
        else
        {
            cout << "You can't divide by zero!\n";
            return 0;
        }        
    }

    if (strcmp("%", argv[2]) == 0) {
        if (operand2 != 0)
        {
            answer = operand1 % operand2;
        }
        else
        {
            cout << "You can't divide by zero!\n";
            return 0;
        }
    }

    cout << operand1 << " " << argv[2] << " " << operand2 << " = " << answer << endl;
}

