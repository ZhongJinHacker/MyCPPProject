//
//  main.cpp
//  JStringProject
//
//  Created by JiangZhongjin on 16/7/17.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include "JString.hpp"

using namespace grady;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n" << "写一个自定义的String类" << std::endl;
    
    JString str("hello ");
    JString str2("world! gradyjiang");
    JString str3 = str + str2;
    
    std::cout << str3 << std::endl;
    return 0;
}
