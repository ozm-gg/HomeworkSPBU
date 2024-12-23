#include <iostream>
#include <random>
#include <time.h>
#include "RequestQueue.h"


double GetRandomValueBetween(double lower_bound, double upper_bound) {
    double f = (double)rand() / RAND_MAX;
    return lower_bound + f * (upper_bound - lower_bound);
}

int main() {
    srand(time(0));
    double a1 = 0, a2 = 10;
    double b1 = 0, b2 = 2;

    int countOfProcessedReq = 0;

    RequestQueue queue;

    double nextTime = GetRandomValueBetween(a1, a2);
    double time = 0;
    double idleTime = 0;

    int numOfReq = 1000;

    while(countOfProcessedReq < numOfReq*4) {

        Request request = queue.Pop();
        if(request.prodTime){
            time += request.prodTime;
        }else{
            idleTime += nextTime - time;
            time = nextTime;
            nextTime += GetRandomValueBetween(a1, a2);
            queue.Push(Request{GetRandomValueBetween(b1, b2)});
        }

        while (nextTime < time) {
            nextTime += GetRandomValueBetween(a1, a2);
            queue.Push(Request{GetRandomValueBetween(b1, b2)});
        }
        if(request.prodTime) {
            if (request.countOfTreatments > 0) {
                queue.Push(request);
            }
            countOfProcessedReq++;
        }

        if(countOfProcessedReq % 100 == 0){
            std::cout<<queue<<std::endl;
            std::cout<<"req processed: "<<countOfProcessedReq<<"\ttime: "<<time<<"\tidle time: "<<idleTime<<std::endl;
        }
    }


    return 0;
}
