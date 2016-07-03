//
//  Productor.h
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef Productor_h
#define Productor_h
#include "Storehouse.hpp"
class Productor
{
public:
    Productor()=default;
    Productor(Storehouse&);
    void Product();
    ~Productor();
    void Speak();
private:
    Storehouse &store;
};

#endif /* Productor_h */
