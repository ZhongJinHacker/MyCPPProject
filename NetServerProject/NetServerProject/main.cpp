//
//  main.cpp
//  NetServerProject
//
//  Created by JiangZhongjin on 16/7/9.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <unistd.h>

#define BUFF 4 * 1024

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World! 写一个服务端程序" << std::endl;
    
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    
    time_t time_now;
    
    char buf[BUFF];
    
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }
    
    bzero(&servaddr, sizeof(servaddr));
    bzero(&cliaddr, sizeof(cliaddr));
    
    /* 开始设置IP */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9347);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if ( (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr))) < 0 )
    {
        perror("bind");
        exit(1);
    }
    
    listen(listenfd, 20);
    
    while (1)
    {
        int len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
        if (connfd < 0)
        {
            perror("accept");
            exit(1);
        }
        
        printf("a client has connected\n");
        
        time_now = time(NULL);
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&time_now));
        write(connfd, buf, strlen(buf));
        close(connfd);
        
    }
    
    return 0;
}
