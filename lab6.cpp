/**************************
 *Zachary Supina
 *CPSC 1021, Section 3, F20
 *zsupina@g.clemson.edu
 *Elliot McMillan/Victoria Xu
 **************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) { return rand()%i;}

int main(int argc, char const *argv[]) {
  // IMPLEMENT as instructed below
  /*This is to seed the random generator */
  srand(unsigned (time(0)));

  /*Create an array of 10 employees and fill information from standard input with prompt messages*/
	int i;
	employee array[10];
	employee randArray[5];
	employee* listStartPtr = &array[0];
	employee* listEndPtr = &array[10];
	employee* randListStartPtr= &randArray[0];
	employee* randListEndPtr= &randArray[5];
	for(i = 0; i < 10; i++)
	{
		cout << "Please enter employee #" << i + 1 << " first name ";
		cin >> array[i].firstName;
		cout << "Please enter employee #" << i + 1 << " last name ";
		cin >> array[i].lastName;
		cout << "Please enter employee #" << i + 1 << " birth year ";
		cin >> array[i].birthYear;
		cout << "Please enter employee #" << i + 1 << " hourly wage ";
		cin >> array[i].hourlyWage;
	}

	//assigning the precision of floats that are outputted 3.1459 -> 3.14
	cout << setprecision(2) << fixed;

  /*After the array is created and initialzed we call random_shuffle() see the
   *notes to determine the parameters to pass in.*/
	 random_shuffle(listStartPtr, listEndPtr, myrandom);

   /*Build a smaller array of 5 employees from the first five cards of the array created
    *above*/
		for(i = 0; i < 5; i++)
		{
			randArray[i] = array[i];
		}

		//printing the random list
		cout << "Randomized list of 5:" << endl << endl;
		for(i = 0; i < 5; i++)
		{
			cout << setw(20) << right << randArray[i].lastName + ", " + randArray[i].firstName << endl;
			cout << setw(20) << right << randArray[i].hourlyWage << endl;
			cout << setw(20) << right << randArray[i].birthYear << endl << endl;
		}

    /*Sort the new array.  Links to how to call this function is in the specs
     *provided*/
		 sort(randListStartPtr, randListEndPtr, name_order);

    /*Now print the array below */
		cout << "Sorted list of 5:" << endl << endl;
		for(i = 0; i < 5; i++)
		{
			cout << setw(20) << right << randArray[i].lastName + ", " + randArray[i].firstName << endl;
			cout << setw(20) << right << randArray[i].hourlyWage << endl;
			cout << setw(20) << right << randArray[i].birthYear << endl << endl;
		}
  return 0;
}
/*This function will be passed to the sort funtion. Hints on how to implement
* this is in the specifications document.*/
bool name_order(const employee& lhs, const employee& rhs) {
  if (lhs.lastName < rhs.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
