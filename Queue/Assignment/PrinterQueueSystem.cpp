#include <iostream>
#include <queue>

using namespace std;

struct PrintJob
{
    int id;
    string filname;
    int pages;
};

queue<PrintJob> printQueue;
void AddJob(PrintJob job)
{
    printQueue.push(job);
}
void ProcessJob()
{
    if(!printQueue.empty())
    {
        PrintJob currentJob = printQueue.front();
        printQueue.pop();

        cout<<"Printing : "<<currentJob.filname<<endl;
    }
}
bool IsEmpty()
{
    return printQueue.empty();
}
void NextJob()
{
    if(!printQueue.empty())
    {
        PrintJob nextJob = printQueue.front();

        cout<<"Next File : "<<nextJob.filname<<endl;
    }
}
int main()
{
    PrintJob job1 = PrintJob();
    job1.id = 1;
    job1.filname = "DSA_quiz";
    job1.pages = 2;

    AddJob(job1);
    NextJob();
    ProcessJob();
}