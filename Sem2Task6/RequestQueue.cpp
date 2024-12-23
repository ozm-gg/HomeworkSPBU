#include "RequestQueue.h"

Request RequestQueue::Pop() {
    Request req = queue.Pop();
    req.countOfTreatments -= 1;
    return req;
}

void RequestQueue::Push(Request request) {
    queue.Push(request);
}

std::ostream &operator<<(std::ostream &os, const RequestQueue q) {
    return os << q.queue;
}

std::ostream &operator<<(std::ostream &os, const Request req) {
    return os << req.prodTime << "\t" << req.countOfTreatments<<"\t";
}
