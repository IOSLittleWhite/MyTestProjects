//
//  HMTestClass.m
//  TempOCTest
//
//  Created by JZ_Stone on 2017/6/11.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import "HMTestClass.h"
#import "HMTestClass_Extension.h"

@interface HMTestClass ()

/**
 *  属性
 */
@property (nonatomic, copy) NSString *propertyImplementation;

@end


@implementation HMTestClass
{
    NSString *_ivarImplementation; // 实例变量，在iOS开发中也叫成员变量
    NSInteger _count;
}

@dynamic propertyInterface;

NSString *_ivarWhole; // 实例变量，在iOS开发中也叫成员变量

- (void)speak
{
    _ivarWhole = @"dlkfjalkd";
}

+ (void)testClassMethod
{
    _ivarWhole = @"jdflakjlkd";
}

- (void)log
{
    NSLog(@"ivar: %@", _ivarInterface);
//    NSLog(@"property: %@", propertyInterface);
}

- (void)testCategoryFirst
{
    NSLog(@"我来自本类");
}

- (void)testExtension
{
    self.extension = @"extension";
    NSLog(@"extension: %@ ", self.extension);
}

//- (NSString *)ivar
//{
//    return _ivar;
//}
//
//- (void)setIvar:(NSString *)ivar
//{
//    _ivar = ivar;
//}

- (void)dealloc
{
    CFRelease(_count);
}

@end


@implementation HMTestClass (GayExtention)

- (void)burst
{
    
}

- (void)testCategoryFirst
{
    NSLog(@"我来自category");
}

@end
