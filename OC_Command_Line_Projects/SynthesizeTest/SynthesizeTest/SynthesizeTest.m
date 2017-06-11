//
//  SynthesizeTest.m
//  SynthesizeTest
//
//  Created by JZ_Stone on 2017/6/6.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import "SynthesizeTest.h"

@implementation SynthesizeTest
{
    NSString *_publicString;
}

//@synthesize string; // 必须要在 .h 中有对应的 @property，该关键词告诉编译器自动生成set get 方法，一般不需要使用，默认就有该关键字
//@dynamic string; // 必须要在 .h 中有对应的 @property，该关键词告诉编译器，该属性的的set get 由开发者自行编写，也可以不编写，但调用时奔溃

@synthesize testString = _realString;

- (void)setString:(NSString *)string
{
    _string = string;
}

- (NSString *)string
{
    return _string;
}

- (void)test
{
    self.string = @"test";
    
    NSLog(@"string: %@", self.string);
    
    NSLog(@"testPerform: %@", [self performSelector:@selector(addString:) withObject:@"addaddaddadd"]);
}

- (void)logRealString
{
    NSLog(@"realString: %@", _realString);
    NSLog(@"testString: %@", self.testString);
}

- (NSString *)addString:(NSString *)string
{
    return [NSString stringWithFormat:@"xxxxxxx%@", string];
}

@end
