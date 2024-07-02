// TASK 2 
// SIMPLE CALCULATOR
// Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers and choose an operation to perform.

#include<iostream>
#include<stdlib.h>
#include <iomanip>

using namespace std;

class Calculator{
    private:
    float a;
    char op;
    float b;

    public:
    void setA(const float a) {
        this->a = a;
    }

    void setOp(const char op){
        this->op = op;
    }

    void setB(const float b)
    {
        this->b = b;
    }

    float add(){
        return a+b;
    }

    float sub(){
        return a-b;
    }

    float mul(){
        return a*b;
    }

    float div(){
        return a/b;
    }
};

int main(){
    
    Calculator calci;
    cout << "\n\t\t\t\tCalculator" << endl;
    
        while (1)
    {
        float n1, n2;
        char op;
        cout << "Enter number1: ";
        cin >> n1;
        calci.setA(n1);
        cout << "Enter operator: ";
        cin >> op;
        calci.setOp(op);
        cout << "Enter number2: ";
        cin >> n2;
        calci.setB(n2);

        switch (op)
        {
        case '+':
            cout << calci.add() << endl;
            break;
        case '-':
            cout << calci.sub() << endl;
            break;

        case '*':
            cout << calci.mul() << endl;
            break;
        case '/':
           { float result = calci.div();
            cout << setprecision(2)<< result << endl;
            break;
           }

        default:
            cout << "Enter valid input" << endl;
            break;
        }
    }

    return 0;
}
