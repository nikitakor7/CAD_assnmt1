#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include <sstream>
#include<string.h>
#include "generate_polish.h"

using namespace std;
string expression;
int  main()//generate_polish(int n)
{
	int n = 5;
	bool stray;
	//cin >>n; // Numbers of values to be taken
	const int MAX = n; //maximum value (of course, this must be at least the same as AMOUNT;

	int value[n];
	int pol[2*n-1]; //array to store the random numbers in

srand(time(NULL)); //always seed your RNG before using it

//generate random numbers:
for (int i=0;i<n;i++)
{
    bool check; //variable to check or number is already used
    int n; //variable to store the number in
    do
    {
    n=rand()%MAX; 
    stray = rand()%2;
    //cout<< stray<<"\t";
    //check or number is already used:
    check=true;
    for (int j=0;j<i;j++)
        if (n == value[j]) //if number is already used
        {
            check=false; //set check to false
            break; //no need to check the other elements of value[]
        }
    } while (!check); //loop until new, unique number is found
    value[i]=n; //store the generated number in the array
   
    //cout << value[i];
}
//cout<<endl;

//srand(time(NULL)); //always seed your RNG before using it
//int stray = rand()%2;

for (int i = 0; i< 2*n-1; i++)

{
	
	if(i%2 == 0)
	{
	pol[i] = value [i/2];
	
	
	expression = std:: to_string(value[i/2]);
}
	
	else 
	{
		if (stray= 1)
    		expression = "+";
    	else
    		expression = "-";
}
	//cout <<pol[i];
	//cout <<expression;
}
}
