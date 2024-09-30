
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include "clsLoginScreen.h";

using namespace std;



int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

   


}

