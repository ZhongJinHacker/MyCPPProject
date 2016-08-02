//
//  main.cpp
//  JStringProjectTest
//
//  Created by JiangZhongjin on 16/8/2.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include "JString.hpp"
#include <gtest/gtest.h>

using namespace grady;
int main(int argc, /*const*/ char * argv[]) {//配置半天居然是要去掉const，汗
    JString str = "grady";
    std::cout << "Hello, World! " << str << std::endl;
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
