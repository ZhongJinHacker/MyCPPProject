//
//  Consumer.h
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef Consumer_h
#define Consumer_h
#include "Storehouse.hpp"
class Consumer
{
public:
    Consumer()=default;
    Consumer(Storehouse&);
    ~Consumer();
    void Consume();
    void Speak();
private:
    Storehouse &store;
};

#endif /* Consumer_h */
