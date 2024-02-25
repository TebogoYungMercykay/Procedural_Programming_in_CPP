#include <iostream>
#include <cmath>

double linearEquation(int valuex)
{
    return 3*valuex -1;
}

double quadraticEquation(int valuex)
{
    return ((pow(linearEquation(valuex),2))+((3*linearEquation(valuex))+4));
}

double exponentialEquation(int valuex,double result1,double result2){
    result1=linearEquation(valuex);
    result2 =quadraticEquation(valuex);
    return result1*pow(result2,valuex);
}
int main()
{
    std::cout<<"--- MATHEMATICS CALCULATOR ---\n";
    bool blnContinue;
    do{
        blnContinue = !false;
        int intInput;
        std::cout<<"What would you like to do?\n"    //menu option
        <<"1) Calculate F(x)\n"
        <<"2) Calculate G(x)\n"
        <<"3) Calculate S(x)\n"
        <<"4) EXIT\n";
        std::cout<<"Enter your choice: "; //asks the user for input
        std::cin>>intInput;
        double Results1;
        double Results2;
        switch(intInput){
            case 1:
            {
                int value_x;
                double Results;
                std::cout<<"Enter the value of x: ";
                std::cin>>value_x;
                Results =linearEquation(value_x);
                std::cout<<"Results = "<<Results<<std::endl;
                break;
            }
            case 2:
            {
                int value_x;
                double Results;
                std::cout<<"Enter the value of x: ";
                std::cin>>value_x;
                Results =quadraticEquation(value_x);
                std::cout<<"Results = "<<Results<<std::endl;
                break;
            }
            case 3:
            {
                int value_x;
                double Results;
                std::cout<<"Enter the value of x: ";
                std::cin>>value_x;
                Results =exponentialEquation(value_x,Results1,Results2);
                std::cout<<"Results = "<<Results<<std::endl;
                break;
            }
            default:
            {
                // cerr<<"your input was outsie the boundray\nProgram exited\n";
                blnContinue=false;
                break;
            }
        }
    }while(blnContinue==true);
    return 0;
}
