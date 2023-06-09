#include <iostream>
#include <unistd.h>

int main()
{
    std::cout<<"Current process Id : "<<getpid()<<std::endl;

    pid_t childProcessId = fork();

    // If fork call Code after
    if(childProcessId < 0)
    {
        std::cout<<"Failed to Create a new Process"<<std::endl;
    }
    else if (childProcessId == 0)
    {
        // This code will be executed in Child Process Only
        std::cout<<"Child Process Id : "<<getpid()<< " Its parent ID : "<<getppid()<<std::endl;
    }
    else if (childProcessId > 0)
    {
        // This code will be executed in Parent Process Only
        std::cout<<"Parent Process Id : "<<getpid()<< " Its Child Process ID : "<<childProcessId<<std::endl;
    }

}
