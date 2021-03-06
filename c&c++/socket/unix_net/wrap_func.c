#include "wrap_func.h"

int Socket(int family, int type, int protocol)
{
    int n;
    if ((n = socket(family, type, protocol)) < 0)
    {
        perror("socket error");
        exit(1);
    }

    return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(fd, sa, salen) < 0)
    {
        perror("bind error");
        exit(1);
    }
}

void Listen(int fd, int backlog)
{
    char *ptr;
    if ((ptr = getenv("LISTENQ")) != NULL)
    {
        backlog = atoi(ptr);
    }

    if (listen(fd, backlog) < 0)
    {
        perror("listen error");
        exit(1);
    }
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;

again:
    if ((n = accept(fd, sa, salenptr)) < 0)
    {
#ifdef EPROTO
        if (errno == EPROTO || errno == ECONNABORTED)
#else
        if (errno == ECONNABORTED)
#endif
            goto again;
        else
        {
            perror("accept error");
            exit(1);
        }
    }
    return n;
}

void Close(int fd)
{
    if (close(fd) == -1)
    {
        perror("close error");
        exit(1);
    }
}

void Write(int fd, void *ptr, size_t nbytes)
{
    if (write(fd, ptr, nbytes) != nbytes)
    {
        perror("write error");
        exit(1);
    }
}