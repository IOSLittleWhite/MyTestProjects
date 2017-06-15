//
//  HMTestClass.h
//  TempOCTest
//
//  Created by JZ_Stone on 2017/6/11.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HMTestClass : NSObject <NSCopying>
{
    @public
    NSString *_ivarInterface; // 实例变量，在iOS开发中也叫成员变量
}

/**
 *  属性
 */
@property (nonatomic, copy) NSString *propertyInterface;


- (void)speak;

- (void)testCategoryFirst;

- (void)log;

+ (void)testClassMethod;

@end


@interface HMTestClass (GayExtention)
- (void)burst;
- (void)testCategoryFirst;
@end
