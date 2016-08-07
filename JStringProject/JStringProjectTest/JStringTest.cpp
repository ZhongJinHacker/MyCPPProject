//
//  JStringTest.cpp
//  JStringProject
//
//  Created by JiangZhongjin on 16/8/2.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <stdio.h>
#include "JString.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace grady;
TEST(JtringTest, helloGtest)
{
    printf("hello gtest\n");
}

TEST(JtringTest, test)
{
    JString str1("hello world");
    JString str;
    JString str2("hello ");
    JString str3("world");
    str = str2 + str3;
    ASSERT_EQ(str1, str);
}

TEST(JtringTest, test2)
{
    JString str("hello world");
    
    JString str1 = str.subString(4, 6);
    std::cout << str << str1 << std::endl;
    JString strFinnal = "o worl";
    std::cout <<  str1 << std::endl;
    ASSERT_EQ(str1, strFinnal);
}

TEST(JtringTest, testLeng)
{
    JString str("hello world");
    
    int length = 11;
    ASSERT_EQ(str.leng(), length);
}

