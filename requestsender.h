#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H


class RequestSender{
public:
    template <class ReplyHandler>
    static void SendRequest(QUrl& url, ReplyHandler replyHandler);
private:
    RequestSender() = delete;
};

#include "requestsender.tpp"

#endif // REQUESTSENDER_H
