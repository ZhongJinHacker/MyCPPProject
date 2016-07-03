//
//  Storehouse.hpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef Storehouse_hpp
#define Storehouse_hpp

#include <stdio.h>
#include <vector>
#include "Good.hpp"
#include <condition_variable>
#include <mutex>

class Storehouse
{
public:
    Storehouse();
    ~Storehouse();
    void Speak();
    //void AddToList(const Good *good);
    //void RemoveOneFromList();
    void AddCount();
    void DecreaseCount();
    const static int MAX_COUNT;
private:
    //std::vector<Good&> mVector;
    std::condition_variable isFull;
    std::condition_variable isEmpty;
    std::mutex mMutex;
    int count = 0;
    
};
#endif /* Storehouse_hpp */
