#include <iostream>
#include "Queue.h"

#ifndef SEM2TASK6_REQUESTQUEUE_H
#define SEM2TASK6_REQUESTQUEUE_H

struct Request{
    double prodTime{};
    int countOfTreatments{4};
};


class RequestQueue{
public:
    Lessons::Queue<Request> queue;
    Request Pop();
    void Push(Request request);
};

std::ostream &operator<<(std::ostream &os, const RequestQueue q);
std::ostream &operator<<(std::ostream &os, const Request req);


#endif //SEM2TASK6_REQUESTQUEUE_H
