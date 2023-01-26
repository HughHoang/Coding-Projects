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
struct inarg
{
   char symbol;
   int freq;
   int prio;
   int numlines;
   char* fibcode;
};
struct inargserver
{
    char symbol;
    int prio, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char* fibcode;
};
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
                //cout<<arguments[i].fibcode;
                if(std::string(arguments[i].fibcode)==fib){
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
void *writeserver(void *ptr){
    //create memory space           ./client localhost 1256 < input1.txt
    char *buffer = new char[256];
    int n;
    inargserver *argument_ptr = (inargserver*)ptr; //create pointer of argument that has port no and server
    //cout<<argument_ptr->prio<<" "<< argument_ptr->portno<<endl;
    struct sockaddr_in serv_addr;
    int portno = argument_ptr->portno; //assign port no
    struct hostent *server = argument_ptr->server; //asign server no
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
    if (sockfd < 0) 
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    bzero(buffer, 256);
    //fgets(buffer,255,stdin);
    n = write(sockfd,&argument_ptr->prio,sizeof(argument_ptr->prio)); //write the priority number
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255); //reading in buffer array
    if (n < 0) 
         error("ERROR reading from socket");
    argument_ptr->fibcode=buffer;
    //cout<<argument_ptr->fibcode<<endl;
    return NULL;
}

 
//g++ client.cpp -lpthread
//g++ client.cpp -pthread -o client
//gcc client1.c -pthread -o client1
//g++ server.cpp -pthread -o server
//gcc server1.c -pthread -o server1
//./client localhost 1255 < input1.txt 
//./server 1234
//./client localhost 1234
int main(int argc, char *argv[])
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
    int portno;
    struct hostent *server;
    char buffer[256];
    //check arguments
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    //get port number
    portno = atoi(argv[2]);
    //get host number
    server = gethostbyname(argv[1]);
    //create thread number
    pthread_t *tid = new pthread_t[numlines];
    vector<inargserver> servarguments;
    //create arguments for threads
    for(int i=0; i<numlines; i++){
        inargserver temp;
        temp.portno = portno;
        temp.prio=arguments[i].prio;
        temp.server=server;
        temp.symbol=arguments[i].symbol;
        servarguments.push_back(temp);
    }
    //create threads and send through socket
    for(int i=0; i<numlines; i++){
        pthread_create(&tid[i], NULL, writeserver, &servarguments[i]);
    }
    
   //join threads 
    for (int i = 0; i < numlines; i++)
        pthread_join(tid[i], NULL);
    delete [] tid;

    //assigns fibcode from threads to main thread
    for(int i=0; i<numlines; i++){
        arguments[i].fibcode=servarguments[i].fibcode;
    }
    
    /*  test other variables
    for(int i=0; i<numlines; i++){
       //cout<<"Symbol: "<< arguments[i].symbol << ", Frequency: "<< arguments[i].freq<<", Code: "<<arguments[i].fibcode<<", Prio: "<<arguments[i].prio<<endl;
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
}