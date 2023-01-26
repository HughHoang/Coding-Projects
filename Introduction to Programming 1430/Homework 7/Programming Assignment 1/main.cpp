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
using namespace std;

struct inarg
{
   char symbol;
   string word;
   map<char, int> *freqmap;
   int prio;
   char* fibcode;
};

int fib[100];
 
void * fibbcodegenerator(void *ptr)
{
    inarg *freqmap_ptr = (inarg*)ptr;
    int freq = freqmap_ptr->prio;
    int pos;
    fib[0] = 1;  
    fib[1] = 2;  
    for (pos=2; fib[pos-1]<=freq; pos++)
        fib[pos] = fib[pos-1] + fib[pos-2];
 
    int index = pos-2;
 
    char* code = (char*)malloc(100*sizeof(char)); 
    //cout<<index<<" ";
    int i = index;
 
    while (freq)
    {
        code[i] = '1';
 
        freq = freq - fib[i];
 
        i = i - 1;
 
        while (i>=0 && fib[i]>freq)
        {
            code[i] = '0';
            i = i - 1;
        }
    }
 
    code[index+1] = '1';
    code[index+2] = '\0';
    freqmap_ptr->fibcode=code;
    return nullptr;
}
void *count(void *ptr)
{
   inarg *freqmap_ptr = (inarg*)ptr;
   int freq = 0; 
  
   for (int i=0;i<freqmap_ptr->word.length();i++){
      if (freqmap_ptr->word[i] == freqmap_ptr->symbol) {
         freq++; 
      }
   }
   (*freqmap_ptr->freqmap)[freqmap_ptr->symbol]=(int)(freq);
   return nullptr;
}

int main()
{
   string filename;
   string instring;
   string filestring;
   ifstream infile;
   
   cin >> instring;
   cin >> filename;
   infile.open( filename.c_str() );
   infile >> filestring;

   if( !infile.is_open() )
   {
      cout << "File couldn't be opened successfully!" << endl;
      return 1;
   }
   map<char, int> freqmap;
   vector<inarg> arguments;

   for(int i=0; i<instring.length(); i++){
      inarg temp;
      temp.symbol = instring[i];
      temp.freqmap=&freqmap;
      temp.word=filestring;
      arguments.push_back(temp);
   }
   
   pthread_t tid[instring.length()];
   for(int i=0; i<instring.length(); i++){
      pthread_create(&tid[i], nullptr, count, &arguments[i]);
   }
   for(int i=0; i<instring.length(); i++){
      pthread_join(tid[i], nullptr);
   }
   string strsort=instring;
   char strch;
   for(int i=0; i<strsort.length(); i++)
    {
        for(int j=0; j<(strsort.length()-1); j++)
        {
            if(freqmap[strsort[j]]<freqmap[strsort[j+1]])
            {
                strch = strsort[j];
                strsort[j] = strsort[j+1];
                strsort[j+1] = strch;
            }
            else if((freqmap[strsort[j]]==freqmap[strsort[j+1]])&&(strsort[j]<strsort[j+1]))
            {
                int temp=strsort[j];
                strsort[j]=strsort[j+1];
                strsort[j+1]=temp;
            }
        }
    }
    string asciisort= instring;
    char asciich;
    for(int i=0; i<asciisort.length(); i++)
    {
        for(int j=0; j<(asciisort.length()-1); j++)
        {
            if(asciisort[j]>asciisort[j+1])
            {
                asciich = asciisort[j];
                asciisort[j] = asciisort[j+1];
                asciisort[j+1] = asciich;
            }
        }
    }
    for(int i=0; i<asciisort.length(); i++)
    {
        for(int j=0; j<(strsort.length()); j++)
        {
            if(asciisort[i]==strsort[j]){
                arguments[i].prio=j+1;
            }
        }
    }
    map<char, int> n;
    pthread_t tid2[instring.length()];
    for(int i=0; i<instring.length(); i++){
        pthread_create(&tid2[i], nullptr, fibbcodegenerator, &arguments[i]);
    }
    for(int i=0; i<instring.length(); i++){
        pthread_join(tid2[i], nullptr);
    }
    
    for(int i=0; i<strsort.length(); i++){
        cout<<"Symbol: "<< asciisort[i] << ", Frequency: "<< freqmap[asciisort[i]]<<", Code: "<<arguments[i].fibcode<<endl;
    }
}