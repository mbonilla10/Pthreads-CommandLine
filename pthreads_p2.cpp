/*
 @file: pthreads_skeleton.cpp
 
 @author: student Melvin Bonilla Jr, mbonill2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
int inputs[10];

void *routineName(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   cout << "Thread is running..." << endl;
   return 0;
}

// Counts and displays the amount of negatives in 10 numbers
void *countNegatives(void *arg)
{
	int sum = 0; 
	for (int i = 0; i <= 9; i++){
	   if (inputs[i] < 0){
		   sum++;
	   }
   }
	cout << "Total negative numbers: " << sum << endl;
	cout << endl;
	return 0;
}

// Adds 10 digits and divides by 10
void *average(void *arg)
{
	int sum = 0; 
	for (int i = 0; i <= 9; i++){
	   sum += inputs[i];
	   }
	   
	sum = sum / 10;
	cout << "Average: " << sum << endl;
	cout << endl;
	return 0;
}

// Prints user numbers in reverse order
void *reverse(void *arg)
{ 
	cout << "The numbers in reverse: " << endl;
	
	for (int i = 9; i >= 0; i--){
		cout << inputs[i] << endl;
		}
	return 0;
}

int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id, id2, id3, id4;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input
   // Takes in 10 numbers from user
   cout << "Enter 10 numbers" << endl;
   for (int i = 0; i <= 9; i++){
	   cin >> inputs[i];
   }
   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   rc = pthread_create(&id, NULL, routineName, NULL);
   rc = pthread_create(&id2, NULL, countNegatives, NULL);
   rc = pthread_create(&id3, NULL, average, NULL);
   rc = pthread_create(&id4, NULL, reverse, NULL);
   

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
