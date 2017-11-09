//This file is used to construct the simulated annealing code
#include <iostream>
#include<string.h>
#include<fstream> //open a file for writing
#include<stdlib.h>
#include "math.h"
#include "limits.h"
#include "time.h" //Time n srand function
using namespace std;

/********************************************************************************************/
/*defining my data structure for simulated annealing*/

class Areamin
{
	private:
		//We are using euclidean distance to calculate the width and the heigh which helps us to calculate the area
		int n; //variable for determinin no of iterations
		double *x, *y;
		char distance_type[30]; /***think**/
		double **adjacency_matrix; //http://www.eskimo.com/~scs/cclass/int/sx8.html
		int *current_path, *next_path, *min_path; //pointers declared for current, next and minimum path
		double temperature; 
		clock_t time_calculate;
	
	public:
		Areamin();
		void simulatedannealing();
		void readmydata(); //Reads parsed data available
		void retraceback(); // Retraces back after finding the cost to help us know the tree
		int generateRandom_numbers();
		void swap(int, int , int*);
		void init();
		int Cost_function(int*);
		void two_opt(int , int , int *);
	};
	
Areamin :: Areamin()
{
  temperature=1000000000000000000;
  time_calculate = clock();
	}


void Areamin::simulatedannealing()
 {
  int r1, r2, i;
  double c1, c2, gain, random_number, prob;
  readmydata(); 
  init();

  while(1)
  {
   i=100;
   while(--i)
   {
    for(int i=1;i<n;i++)    
    next_path[i]=current_path[i];  

    r1=generateRandom_numbers();
    r2=generateRandom_numbers();
    two_opt(r1, r2, next_path);

    gain=Cost_function(next_path) - Cost_function(current_path);
    random_number=(double) (rand()/ (double) RAND_MAX);

    prob=1/(1+ pow(M_E, (gain/temperature)));
    if(prob > 	random_number)
     for(int i=1;i<n;i++)    
    current_path[i]=next_path[i];
   
    if(Cost_function(next_path) < Cost_function(min_path) )
    {
     for(int i=1;i<n;i++)    
      min_path[i]=next_path[i];
     readmydata();
    }
   }
   temperature*=0.999;
  }
 }
		
	
void Areamin::two_opt(int r1, int r2, int *next_path)
 {
  int i, j, k, limit, temp;

//for(i=0;i<n+1;i++) cout<<next_path[i]<<" ";cout<<"   :   ";

  if(r1 > r2)
  {
   temp=r1;
   r1=r2;
   r2=temp;
  }
  limit=floor((r2-r1+1)/2);
  i=r1, j=r2;


  for(k=0;k<limit+1;k++)
   swap(i++, j--, next_path);

//for(i=0;i<n+1;i++) cout<<next_path[i]<<" ";cout<<endl;
 }


 void Areamin::init()
 {
  current_path=new int[n+1];
  current_path[0]=current_path[n]=0;
  for(int i=1;i<n;i++)
   current_path[i]=i;

  next_path=new int[n+1];
  next_path[0]=next_path[n]=0;
  for(int i=1;i<n;i++)
   next_path[i]=i;

  min_path=new int[n+1];
  min_path[0]=min_path[n]=0;
  for(int i=1;i<n;i++)
   min_path[i]=i;
 }

 int Areamin::Cost_function(int *path)
 {
  int cost=0;
  for(int i=0;i<n;i++)
   cost+=adjacency_matrix[path[i]][path[i+1]];
  return cost;
 }


 void Areamin::readmydata()
 {
  int i, j;
  
  cin>> distance_type;  /****/
  if(strcmp(distance_type, "non")==0)  
  	cin>>distance_type;
  cin>>n;
 
  x=new double[n]; y=new double[n];

  adjacency_matrix=new double*[n];
  for(i=0;i<n;i++)
   adjacency_matrix[i]=new double[n]; 

  for(i=0;i<n;i++)
  {
   cin>>x[i]>>y[i];
  }
 
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    cin>>adjacency_matrix[i][j];
   }
  }
 }

 int Areamin::generateRandom_numbers()
 {
  return (rand()%(n-1))+1;
 }
  
 void Areamin::swap(int r1, int r2, int *next_path)
 {
  int temp=next_path[r1];
  next_path[r1]=next_path[r2];
  next_path[r2]=temp;
 }

 void Areamin::retraceback()
 {
  printf("Time taken: %.2fs\n", (double)(clock() - time_calculate)/CLOCKS_PER_SEC);
  cout<<"The shortest cost obtained so far is "<<Cost_function(min_path)<<endl;
  for(int i=0;i<n;i++)
   cout<<min_path[i]+1<<" ";cout<<endl;
 }

 int main()
 {
  Areamin t;
  t.simulatedannealing();
  return 0;
 }		
