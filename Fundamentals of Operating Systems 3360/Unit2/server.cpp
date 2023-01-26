// A simple server in the internet domain using TCP
// The port nu1mber is passed as an argument

// Please note this is a C program
// It compiles without warnings with gcc
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
using namespace std;

void error(std::string msg)
{
    perror(msg.c_str());
    exit(1);
}
struct inargserver
{
    int prio;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    string* fibcode;
    int numlines;
};
struct message
{
        int prio;
};

struct message2
{
    int value;
    char buffer[256];
};
void fireman(int)
{
   while (waitpid(-1, NULL, WNOHANG) > 0)
      break;
}
int fib[100];
 int largestFiboLessOrEqual(int n)
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
    int index = largestFiboLessOrEqual(n);
 
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
//./client localhost 1282 < input1.txt
int main(int argc, char *argv[])
{
    //creating a server socket
     int sockfd, newsockfd, portno, clilen;
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,10);
     clilen = sizeof(cli_addr);
     int msg1;
    char buffer[256];
    inargserver argument_ptr;
    //signals when child terminates
    signal(SIGCHLD, fireman);     
    while (true)
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&clilen); //accept
        bzero(buffer,256);
        n = read(newsockfd,&msg1,sizeof(int)); //read
        if (n < 0) error("ERROR reading from socket");
        if (fork() == 0)
        {
            //printf("Here is the message: %d\n",msg1); //outputs prio
            strcpy(buffer,fibonacciEncoding(msg1)); //copies fib code to buffer
            n = write(newsockfd,&buffer,255); //write
            if (n < 0) error("ERROR writing to socket");
            sleep(5);
            _exit(0);
        }
    }
//./client localhost 1251 < input1.txt 
     return 0; 
}
