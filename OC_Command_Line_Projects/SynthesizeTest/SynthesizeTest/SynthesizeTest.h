//
//  SynthesizeTest.h
//  SynthesizeTest
//
//  Created by JZ_Stone on 2017/6/6.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SynthesizeTest : NSString
{
    @public
    NSString *_string; // 当使用 @dynamic 时，必须在此已下划线开头申明属性
    
    NSString *_realString;
}

//@property (nonatomic, copy) NSString *string; // @property 是公开属性申明必须使用的，私有属性可以不使用

@property (nonatomic, copy) NSString *testString;

- (void)test;
- (void)logRealString;

@end
