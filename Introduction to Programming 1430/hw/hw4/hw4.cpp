#include <iostream>
#include <fstream>
#include <string>
#include <queue>  
#include <iomanip>
#include<string.h>
#include <vector>
#include <stdlib.h>
#include "ArgumentManager.h"
#include <stack>
using namespace std;
class Process
{
private:
    int process = -1;
    int startTime = -1;
    int executionTime=-1;
    int waitTime = -1;
    int endTime = -1;
    int currentTime = 0;
public:
    void setprocess(int inprocess)
    {
        process = inprocess;
    }
    void setstartTime(int instart)
    {
        startTime = instart;
    }
    void setexecutionTime(int inexecutionTime)
    {
        executionTime = inexecutionTime;
    }
    void setwaitTime(int inwaitTime)
    {
        waitTime = inwaitTime;
    }
    void setendTime(int inendTime)
    {
        endTime = inendTime;
    }
    bool done()
    {
        return (executionTime == currentTime);
    }
    void timepass()
    {
        currentTime++;
    }
    int getprocess()
    {
        return process;
    }
    int getstartTime()
    {
        return startTime;
    }
    int getexecutionTime()
    {
        return executionTime;
    }
    int getwaitTime()
    {
        return waitTime;
    }
    int getendTime()
    {
        return endTime;
    }
    int getcurrentTime()
    {
        return currentTime;
    }
};
class Server
{
private:
    Process ProcessorBeingUsed;
    bool free;
public:
    Server()
    {
        free = true;
    }
    void addProcess(Process proc)
    {
        ProcessorBeingUsed = proc;
        free = false;
    }
    void serversetendTime(int endtime)
    {
        ProcessorBeingUsed.setendTime(endtime);
    }
    void setwaitTime(int inwaitTime)
    {
        ProcessorBeingUsed.setwaitTime(inwaitTime);
    }
    void setfree()
    {
        free = true;
    }
    void servertimepass()
    {
        ProcessorBeingUsed.timepass();
    }
    Process currentserve()
    {
        return ProcessorBeingUsed;
    }
    bool isFree()
    {
        if (free) return true;
        if (ProcessorBeingUsed.done())
            free = true;
        return free;
    }
};
typedef pair<int, Process> pd;

struct myComp {
    constexpr bool operator()(pair<int, Process> const& a, pair<int, Process> const& b)
        const noexcept
    {
        return a.first > b.first;
    }
};
int main(int argc, char* argv[])
{

    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");
    const string command = am.get("command");

    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(input);
    outputFile.open(output);

    int num;
    string x, m, n;
    string line = "";
    string sinput;
    getline(inputFile, line, ' ');
    x = line;
    getline(inputFile, line, ' ');
    m = line;
    getline(inputFile, line);
    n = line;
    int maxtime = stoi(x);
    int processes = stoi(m);
    int numservers = stoi(n);
    outputFile << "Max time: " << maxtime << endl;
    outputFile << "Number of processes: " << processes << endl;
    outputFile << "Number of servers: " << numservers << endl<<endl;
    queue<Process> processQueue;
    priority_queue<pd, vector<pd>, myComp> processdone;
    int totaltime = 0;
    int processnum = 1;
    while (!inputFile.eof()) {
        inputFile >> num;
        totaltime += num;
        Process inprocess;
        inprocess.setexecutionTime(num);
        inprocess.setprocess(processnum);
        processQueue.push(inprocess);
        processnum++;
    }
    vector <Server> servers(numservers);
    for (int i = 0; i < totaltime; i++) {
        for (int t = 0; t < numservers; t++)
        {
            if (!processQueue.empty()) {
                Process process1 = processQueue.front();
                if (process1.getexecutionTime() == 0) {
                    if (process1.getstartTime() == -1) {
                        process1.setstartTime(i);
                    }
                    if (process1.getwaitTime() == -1) {
                        process1.setwaitTime(i);
                    }
                    process1.setendTime(i);
                    processdone.push(make_pair(process1.getprocess(), process1));
                    processQueue.pop();
                }
            }
            if (servers[t].currentserve().done()) {
                //cout << servers[t].currentserve().getprocess()<<endl;
                servers[t].serversetendTime(i);
                servers[t].setwaitTime(i - servers[t].currentserve().getexecutionTime());
                processdone.push(make_pair(servers[t].currentserve().getprocess(), servers[t].currentserve()));

                servers[t].setfree();
            }
            //cout << servers[t].currentserve().getprocess() << endl;
            //cout << servers[t].currentserve().getcurrentTime() << endl;
            if ((servers[t].currentserve().getcurrentTime() % maxtime == 0) && (servers[t].currentserve().getcurrentTime() != 0)) {
                Process kick = servers[t].currentserve();
                kick.setwaitTime(kick.getwaitTime() + maxtime);
                processQueue.push(kick);
                servers[t].setfree();
            }
            if (servers[t].isFree() && (!processQueue.empty()))
            {
                Process process = processQueue.front();
                if (process.getstartTime() == -1) {
                    process.setstartTime(i);
                }
                if (process.getwaitTime() == -1) {
                    process.setwaitTime(i);
                }
                servers[t].addProcess(process);
                processQueue.pop();
            }
            servers[t].servertimepass();
        }
    }
    while (!processdone.empty()) {
        Process processprint = processdone.top().second;
        outputFile << "Process: " << processprint.getprocess() << endl;
        outputFile << "Execution time: " << processprint.getexecutionTime() << endl;
        outputFile << "Wait Time: " << processprint.getwaitTime() << endl;
        outputFile << "Start Time: " << processprint.getstartTime() << endl;
        outputFile << "End Time: " << processprint.getendTime();
        processdone.pop();
        if (!processdone.empty()) {
            outputFile << endl << endl;
        }
    }
    inputFile.close();
    outputFile.close();
}




