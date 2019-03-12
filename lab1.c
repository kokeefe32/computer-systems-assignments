/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: O'Keefe
 * First Name: Kayli
 * Netid: ko733
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/* Function declarations: do not change that, but you may add your own functions */
void arrange(int *, int);
void find_fibonacci(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);



/* Add here function declarations of your own, if any. */

int fib(int);



/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be arranged\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Gnerate random numbers in the range [0, 100) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 100;
	    
	    /* Print the unsorted array */
	    printf("The original array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    printf("The arranged array:\n");
	    arrange(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y and y < 1 million\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_fibonacci(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to put the even numbers first (if any), sorted in ascending order, followed
 * by the odd numbers (if any) sorted in ascending order too.
 * Example: a list of 5 elements: 5 4 3 2 1 
 * The output will be: 2 4 1 3 5 
 * Finally, print the array on the screen.
 * */
void arrange(int *list, int num)
{
	
	/*Create an array for even numbers and for odd numbers */
	int even[num];
	int odd[num];

	int i, n, temp;
	
	
	int j = 0;	/* initialize even array index */
	int k = 0;	/* initialize odd array index */
	

	/* Iterate through given array and add even numbers to even 		array and odd numbers to odd array */
	for(i = 0; i < num; i++){
		if(list[i] % 2 == 0 ){
			even[j] = list[i];
			j++;
		}
		else{
			odd[k] = list[i];
			k++;
		}
	
	}
	
	/* Sort and print even array in ascending order */
	for(i = 0; i < j; i++){

		for(n = i+1; n < j; n++){
			if(even[i] >even[n]){
				temp = even[i];
				even[i] = even[n];
				even[n] = temp;
			}
		}
		
	printf("%d ", even[i]);
	}
	
	/* Sort and print odd array in ascending order */
	for(i = 0; i < k; i++){

		for(n = i+1; n < k; n++){
			if(odd[i] > odd[n]){
				temp = odd[i];
				odd[i] = odd[n];
				odd[n] = temp;
			}
		}
		
	printf("%d ", odd[i]);
	}
	
	printf("\n");	
}


/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integer, x and y, larger than 0.
 * You need to print all the Fibonacci numbers between x and y (NOT including x and y themselves), if any.
 */
void find_fibonacci(int x, int y)
{
	int c;
	
	
	for (c =1; c < 35; c++){
		/*Print the fibonacci series between x and y */
		if((fib(c) > x) &&(fib(c) < y)){
			printf("%d ", fib(c));
		}
	
	}
	printf("\n");

  
  
}


/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */
void flipping(unsigned int num)
{
	unsigned int x;
	unsigned int reverse = 0; /* Set the new number to 0 */
	int remainder;
	
	x = num;
	while (x != 0){
		remainder = x % 10;
		reverse = reverse * 10 + remainder;
		x = x/10;	
	}
	
	printf("%d\n", reverse);
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of characters (can be upper case letters, lower case letters, numbers, ...).
 * The output is a histogram of the file printed on the screen ONLY for lower case letters.
 * Example: 
 * The input file in.txt contains:  a1aaAbBBb709bbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file can contain any characters, not necessarily only lower case characters.
 */
void file_histogram(char *filename)
{
 	
  	/* Pointer fo the file */
	FILE *fptr;
	int i;
	char c;
	int alphabet[26];
	fptr = fopen(filename, "r");

	
	
	/* set character frequency to 0 for lowercase alphabet */
	for (i=0; i<26; i++){
		alphabet[i] = 0;
	}
	/* read the file character by character */
	while((c = fgetc(fptr)) != EOF){
		/* if character is lowercase increase its frequency by 1 */
		if(c >= 'a' && c <= 'z'){
			alphabet[c - 97]++;
		}

	}	
  	
	/* print frequency of all lowercase characters */
	for(i = 0; i < 26; i++){
		printf("%c : %d\n", (i+97), alphabet[i]);
	}

	fclose(fptr);
  
  
}

/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: mmmm 
 * The output filename is: mmmmCAPITAL
 */
void file2upper(char *filename)
{
	/* pointer to input file */
	FILE *input, *output;
	int c;
	
	input = fopen(filename, "r");

	if(input == NULL)
		printf("Error opening 'filename' .\n");
	
	char* new_file_name = malloc(strlen(filename) + 8);
	strcpy(new_file_name, filename);
	strcat(new_file_name, "CAPITAL");
	output= fopen(new_file_name, "w+");
	
	
	while((c = fgetc(input)) != EOF){
		fputc(toupper(c), output);
		
	}
	/* close both files */
	fclose(input);
	fclose(output);

  
}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */
void file_encrypt(char * filename)
{	
	/* Pointer fo the file */
	FILE *fptr;
	int c;
	
	fptr = fopen(filename, "r");

	/* read each character from file and shift */
	while ((c = fgetc(fptr)) != EOF){
		if(c == 'a')
			putchar('x');
		else if(c == 'b')
			putchar('y');
		else if(c == 'c')
			putchar('z');
		else if ((c >= 'd') && (c <= 'z'))
			putchar(c -3);
		else if (c == ' ')
			putchar(' ');
			
	}
	printf("\n");	

	/* close file */
	fclose(fptr);		
		


}

/* This is a recursive function that returns the fibonacci series up to n terms */
int fib(int n){
	if(n == 0)
		return 0;
	else if(n== 1)
		return 1;
	else
		return(fib(n-1) + fib(n-2));
	
}

  

