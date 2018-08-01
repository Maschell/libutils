#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include <sys/select.h>

#include <nsysnet/socket.h>
#include <system/CThread.h>
#include <wut_types.h>

#include <coreinit/cache.h>
#include "utils/logger.h"

class TCPServer {
public:
    TCPServer(int32_t port, int32_t priority);
    virtual ~TCPServer();

    BOOL isConnected() {
        return connected;
    }
protected:
    BOOL shouldExit() {
        return (exitThread == 1);
    }

    int32_t getClientFD() {
        return clientfd;
    }

    int32_t getSocketFD() {
        return sockfd;
    }

    void setThreadPriority(int32_t priority) {
        if(pThread != NULL){
            pThread->setThreadPriority(priority);
        }
    }

    struct sockaddr_in getSockAddr() {
        return sock_addr;
    }
private:
    virtual void CloseSockets();
    virtual void ErrorHandling();

    static void DoTCPThread(CThread *thread, void *arg);
    virtual void DoTCPThreadInternal();

    virtual BOOL acceptConnection() = 0;

    virtual void onConnectionClosed(){
        DEBUG_FUNCTION_LINE("Default onConnectionClosed \n");
    }

    /**
        Called when a connection has be accepted.
    **/
    virtual BOOL whileLoop() = 0;

    struct sockaddr_in sock_addr;
    volatile int32_t sockfd = -1;
    volatile int32_t clientfd = -1;

    int32_t port = 0;
    volatile BOOL connected = false;

    volatile int32_t exitThread = 0;
    CThread *pThread = NULL;
};

#endif //_TCPSERVER_H_
