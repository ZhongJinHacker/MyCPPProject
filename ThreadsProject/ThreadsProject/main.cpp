//
//  main.cpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/2.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include "Productor.h"
#include "Consumer.h"
#include "Storehouse.hpp"
#include <thread>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n" << "I will code something about the Threads" << std::endl;
    
    Storehouse mStorehouse;
    mStorehouse.Speak();
    
    Productor mProductor(mStorehouse);
    mProductor.Speak();
    
    Consumer mConsumer(mStorehouse);
    mConsumer.Speak();
    
    Consumer mConsumer2(mStorehouse);
    
    std::thread productTask(&Productor::Product, mProductor);
    std::thread consumeTask1(&Consumer::Consume, mConsumer);
    std::thread consumeTask2(&Consumer::Consume, mConsumer2);
    
    productTask.join();
    consumeTask1.join();
    consumeTask2.join();
    
    return 0;
}