//
//  PlayData.hpp
//  ExternProject
//
//  Created by JiangZhongjin on 16/7/16.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef PlayData_hpp
#define PlayData_hpp

#include <stdio.h>
#include <iostream>

namespace downloadManager {

    class iPlayData
    {
    public:
        iPlayData()
        {
            std::cout << "contruct iPlayData" << std::endl;
        }
    
        virtual ~iPlayData()
        {
            std::cout << "Decontruct iPlayData" << std::endl;
        }
     
        //此处可以定义函数（如下），或声明为纯虚函数，否则如果仅仅是声明，编译会报找不到定义错误
        virtual void printPlayData()
        {
            
        }
    
        virtual void printPlayDataTwo()
        {
            std::cout << " iPlayData : printPlayDataTwo" << std::endl;
        }
    };
    
    void dmDownloadIPlayData();
    
    extern void dmDownloadIPlayDataTwo();
    //说明编译器默认增加extern，加不加一样
    
    extern iPlayData *dmCreatePlayData();
}
#endif /* PlayData_hpp */
