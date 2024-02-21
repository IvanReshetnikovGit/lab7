#include<iostream>
#include<ctime>
#include<stack>

using namespace std;

double experiment(int stackSize,double probPush,double probPop)
{
    stack<int> stack;
    int maxSize = 0;

    for (int i = 0; i < stackSize; i++)
    {
        if ((double)rand() / RAND_MAX < probPush)
        {
            stack.push(rand() % 100);
        }

        if((double)rand()/RAND_MAX < probPop && !stack.empty())
        {
            stack.pop();
        }
        maxSize = max(maxSize, (int)stack.size());
    }
    return maxSize;
}

double averageMaxSizeStack(int stackSize,double probPush,double probPop,int numExperiments)
{
    double totalMaxSize = 0;
    for (int i = 0; i < numExperiments; i++)
        totalMaxSize += experiment(stackSize,probPush,probPop);
    
    return totalMaxSize/numExperiments;
}

int main()
{
    srand(time(0));
    int stackSize = 10;
    double probPush = 0.5, probPop = 0.5;

    cout<<"Average Max Size Stack = "<<averageMaxSizeStack(stackSize,probPush,probPop,1000)<<endl;
    return 0;
}