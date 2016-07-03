//
//  Good.hpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef Good_hpp
#define Good_hpp

#include <stdio.h>

class Good
{
public:
    Good() = default;
    ~Good();
    void setID(int id);
private:
    int goodID = -1;
};

#endif /* Good_hpp */
