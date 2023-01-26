#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <pthread.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netdb.h> 
#include <semaphore.h>
using namespace std;
 /*
 You must write a C++ program to implement a parallel Fibonacci code generator you created for programming assignment 1 using synchronization mechanisms. 


Your program will read the input from STDIN. 

This program reads the information about the alphabet (symbols and frequencies) from STDIN, sorting the symbols in the alphabet in decreasing order based on the frequency. If two or more symbols have the same frequency, you will use the symbol's ASCII value to break the tie (the higher the value, the higher the priority).

After assigning a positive integer value (starting from 1) to the symbols in the sorted alphabet, your program must create a child thread per number of symbols in the alphabet.  Each child thread will determine the Fibonacci code based on the received integer value from the main thread. After the child threads calculate the Fibonacci code, they will print the information about the symbol, its frequency, and the Fibonacci code, writing the Fibonacci code into a memory location available to the main thread. Finally, the main thread will use the codes generated by the child threads to decompress a file.
Each child thread will execute the following tasks:

Receive the integer value needed to calculate the Fibonacci code from the main thread.
Calculate the Fibonacci code.
Print the information about the symbol (symbol, frequency, Fibonacci code). You must use the output message provided in the example below.
Write the received information into a memory location accessible by the main thread.
Finish its execution.
Input Format: The Moodle server will use input redirection using the following input file format: 

The number of symbols in the alphabet (integer value)
n lines (where n is the number of symbols in the alphabet) with the information about the symbols in the alphabet. Each line has one character and one integer representing a symbol and its frequency (separated by a single white space).
The name of the compressed file.
Example Input File:

7
C 2
O 1
S 1
  1
3 2
6 1
0 1
compfile1.txt
Your program must print the information about the symbols based on their order in the input file. Therefore, you must use synchronization mechanisms to guarantee that child threads print the information about each symbol in the correct order. 

After receiving the Fibonacci codes from the child threads, the main thread decompresses the contents of a file (sequence of bits represented as a string) and prints the decompressed message.

Given the previous input file and the following compressed file:

111011001111010110110110001110011 
The expected output is:

Symbol: C, Frequency: 2, Code: 11
Symbol: O, Frequency: 1, Code: 1011
Symbol: S, Frequency: 1, Code: 0011
Symbol:  , Frequency: 1, Code: 01011
Symbol: 3, Frequency: 2, Code: 011
Symbol: 6, Frequency: 1, Code: 00011
Symbol: 0, Frequency: 1, Code: 10011
Decompressed message = COSC 3360
Notes:
 
You can safely assume that the input files will always be in the proper format.
You cannot use global variables. A 10% penalty will be applied to submissions using global variables. 
You must define the critical sections following the guidelines that we discussed in class.
You must use POSIX threads. A penalty of 100% will be applied to submissions using a thread library other than the pthread library.
You can only use named POSIX semaphores, pthreads mutex semaphores, or pthreads condition variables to achieve synchronization. Using pthread_join or sleep to synchronize your threads is not allowed. A penalty of 100% will be applied to submissions using the previous system calls to synchronize the child threads.
You cannot use different memory addresses to pass the information from the parent thread to the child threads.
You must use the output statement format based on the example above.
You can implement your solution only using the main.cpp requested file  (you do not need to use the provided files to implement an OOP-based solution).
 */
struct inarg
{
   char symbol;
   int freq;
   int prio;
   int printprio;
   int numlines;
   char* fibcode;
   string code;
};
struct inargserver
{
    char symbol;
    int prio;
    int printprio;
    int freq;
    string* fibcode;
    pthread_mutex_t *bsem;
    pthread_cond_t *waitTurn;
    pthread_cond_t *mainTurn;
    int *turn;
    int nthreads;
    inargserver *next;
};
 int largestFiboLessOrEqual(int n,int fib[])
{
    fib[0] = 1;  // Fib[0] stores 2nd Fibonacci No.
    fib[1] = 2;  // Fib[1] stores 3rd Fibonacci No.
 
    // Keep Generating remaining numbers while previously
    // generated number is smaller
    int i;
    for (i=2; fib[i-1]<=n; i++)
        fib[i] = fib[i-1] + fib[i-2];
 
    // Return index of the largest fibonacci number
    // smaller than or equal to n. Note that the above
    // loop stopped when fib[i-1] became larger.
    return (i-2);
}
 
/* Returns pointer to the char string which corresponds to
   code for n */
char* fibonacciEncoding(int n)
{
    int fib[100];
    int index = largestFiboLessOrEqual(n,fib);
 
    //allocate memory for codeword
    char *codeword = (char*)malloc(sizeof(char)*(index+3));
 
    // index of the largest Fibonacci f <= n
    int i = index;
 
    while (n)
    {
        // Mark usage of Fibonacci f (1 bit)
        codeword[i] = '1';
 
        // Subtract f from n
        n = n - fib[i];
 
        // Move to Fibonacci just smaller than f
        i = i - 1;
 
        // Mark all Fibonacci > n as not used (0 bit),
        // progress backwards
        while (i>=0 && fib[i]>n)
        {
            codeword[i] = '0';
            i = i - 1;
        }
    }
 
    //additional '1' bit
    codeword[index+1] = '1';
    codeword[index+2] = '\0';
 
    //return pointer to codeword
    return codeword;
}
//returns fib value based on position
string fibbdecoder(string compressed, vector<inarg> arguments)
{
    string decodedstr = "";
    string curr = "";
    string prev = "";
    string fib;
    int fiblength;
    int sum;
    int count = 0;
    //splits string into readable parts
    for (int i = 0; i < compressed.length()+1; i++) {
        if ((curr == "1") && (prev == "1"))
        {
            for(int i=0;i<arguments[0].numlines;i++){
                if(std::string(arguments[i].code)==fib){
                    decodedstr+=arguments[i].symbol;
                }
            }
            //resets variables
            fib = "";
            curr = "";
            prev = "";
            count = 0;
        }
 
        //create current split fib code
        curr = compressed[i];
        if (count != 0) {
            prev = compressed[i - 1];
        }
        count++;
        fib += curr;
    }
    return decodedstr;
}
 
void *pthreadsemaphore(void *void_ptr_argv)
{
    //create a struct of the argument pointer
    inargserver argument_ptr = *((inargserver *)void_ptr_argv);
    //convert the priority into fibcode
    string fib=fibonacciEncoding(argument_ptr.prio);
    //assign to fibcode pointer
    *argument_ptr.fibcode=fib;
    //broadcast for the main function to run
    pthread_cond_broadcast(&*argument_ptr.mainTurn);

    pthread_mutex_lock(&*argument_ptr.bsem);
    //tells all other threads to wait their turn
    while(*argument_ptr.turn!=argument_ptr.printprio)
        pthread_cond_wait(&*argument_ptr.waitTurn,&*argument_ptr.bsem);
    pthread_mutex_unlock(&*argument_ptr.bsem);
    
    pthread_mutex_lock(&*argument_ptr.bsem);
    //increment turn
    *argument_ptr.turn = *argument_ptr.turn +1;
    //print info
    cout<<"Symbol: "<< argument_ptr.symbol << ", Frequency: "<< argument_ptr.freq <<", Code: "<<fib<<endl;
    //broadcast that its done
    pthread_cond_broadcast(&*argument_ptr.waitTurn);
    pthread_mutex_unlock(&*argument_ptr.bsem);
    return NULL;
}
int main()
{
    int numlines;
    string instring;
    string insymbol;
    vector<inarg> arguments;
    int count;
    cin>>numlines;
    getline (cin, instring); //read empty line
    for(int i=0; i<numlines; i++){
        getline (cin, instring); //read lines
        inarg temp; 
        temp.symbol = instring[0]; //asign variables to temp
        int freq1 = instring[2]-'0';
        temp.freq=freq1;
        temp.printprio=i+1;
        temp.numlines=numlines;
        arguments.push_back(temp);
    }
    string compressedfile;
    cin>> compressedfile;//reads txt file name
    inarg temp;
    for(int i=0; i<numlines; i++)
    {
        for(int j=0; j<(numlines-1); j++)
        {
            if(arguments[j].freq<arguments[j+1].freq)//sorts vector by freq
            {
                temp = arguments[j];
                arguments[j] = arguments[j+1];
                arguments[j+1] = temp;
            }
            else if((arguments[j].freq==arguments[j+1].freq)&&(arguments[j].symbol<arguments[j+1].symbol)) //sorts vector by ascii
            {
                temp = arguments[j];
                arguments[j] = arguments[j+1];
                arguments[j+1] = temp;
            }
        }
    }
    //sets the priority to its position in vector
    for(int i=0; i<numlines; i++)
    {
        arguments[i].prio=i+1;
    }
    pthread_t *tid= new pthread_t[numlines];
    
    //Determine the starting thread (thread with the highest odd number)
    pthread_mutex_t bsem;
    pthread_cond_t waitTurn=PTHREAD_COND_INITIALIZER;
    pthread_cond_t mainTurn=PTHREAD_COND_INITIALIZER;
    int turn=1;
    string fibcode;
    pthread_mutex_init(&bsem, NULL);// Initialize access to 1
    vector<inargserver> servarguments;
    //creates arguments for threads
    for(int i=0; i<numlines; i++){
        inargserver temp;
        temp.prio=arguments[i].prio;
        temp.symbol=arguments[i].symbol;
        temp.freq=arguments[i].freq;
        temp.printprio=arguments[i].printprio;
        temp.bsem=&bsem;
        temp.turn=&turn;
        temp.fibcode=&fibcode;
        temp.waitTurn=&waitTurn;
        temp.mainTurn=&mainTurn;
        servarguments.push_back(temp);
    }
 
    //create threads and send through socket
    inargserver argument;
    for(int i=0; i<numlines; i++){
        //assign each slot to struct argument
        argument=servarguments[i];
        pthread_create(&tid[i],nullptr,pthreadsemaphore,(void *) &argument);

        pthread_mutex_lock(&bsem);
        //wait until the function is done using struct
        pthread_cond_wait(&mainTurn,&bsem);
        //assign fibcode to main struct
        arguments[i].code=*argument.fibcode;
        pthread_mutex_unlock(&bsem);
        
    }
    // Wait for the other threads to finish.
    for (int i = 0; i < numlines; i++)
        pthread_join(tid[i], NULL);
    delete [] tid;
    /*  test other variables
 
    for(int i=0; i<numlines; i++){
        cout<<arguments[i].code<<endl;
    }
    */
    //opens file
    string decompressedcode;
    string line;    
    ifstream myfile (compressedfile);
    if (myfile.is_open())
    {
        //set variable line to string in file
        getline (myfile,line); 
        myfile.close();
    }
    //call function fibbdecoder to decode compressed code
    decompressedcode=fibbdecoder(line, arguments);
    //output decompressed message
    cout<<"Decompressed message = "<<decompressedcode;
    return 0;
}
 
 
 
