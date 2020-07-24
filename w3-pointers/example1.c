#include <stdio.h>

int main(int argc,char *argv[]){

	printf("Number of Arguments %d",argc);

	int var = 20; // Variable
	int *ip; // pointer variable declaration

	ip = &var; // pointer variable store address of var

	printf("Address of var variable: %x\n",&var);

	// address stored in pointer varibale
	printf("Address stored in ip variable: %x\n", ip);

	// Access the value using the pointer  (e.g. 20)
	printf("Value of *ip variable: %d\n", *ip);

	return 0;

}