//
//  main.m
//  TempOCTest
//
//  Created by JZ_Stone on 2017/6/9.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HMTestClass.h"
#import "NSObject+DLIntrospection.h"

@interface NSNumber (plus)

- (NSNumber *)factorial;

@end


@implementation NSNumber (plus)

- (NSNumber *)factorial
{
    //    return @(tgamma([self doubleValue] + 1));
    return @(fabs([self doubleValue]+1));
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
//        // NSExpression
//        //==============================================================================
//        NSExpression *expression1 = [NSExpression expressionWithFormat:@"FUNCTION(100, 'factorial')"];
//        id value1 = [expression1 expressionValueWithObject:nil context:nil];
//        NSLog(@"NSExpression vlue1 %@",value1);
//        
//        
//        NSArray*numbers = @[@1,@2,@3,@4,@5,@6];
//        NSExpression *expression2 = [NSExpression expressionForFunction:@"now" arguments:@[[NSExpression expressionForConstantValue:numbers]]];
//        id value2 = [expression2 expressionValueWithObject:nil context:nil];
//        NSLog(@"NSExpression value2 %@",value2);
//        
//        //        NSArray *numbers1 = @[@100, @22, @33, @12, @1000, @99, @44];
//        NSExpression *expression3 = [NSExpression expressionForFunction:@"random" arguments:@[[NSExpression expressionForConstantValue:@22]]];
//        NSLog(@"NSExpression value3 %@", [expression3 expressionValueWithObject:nil context:nil]); // => 3.21859...
//        //==============================================================================
//        
//        
//        // NSNumber
//        //==============================================================================
//        NSString *str1 = @"89480.9520760";
//        NSLog(@"value %@", @([str1 doubleValue]));
//        
//        
//        // GCD
//        //==============================================================================
//        NSLog(@"1");
//        dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
//            sleep(10);
//            NSLog(@"2");
//        });
//        NSLog(@"3");
        
        HMTestClass *sark = [HMTestClass new];
//        sark.propertyInterface = @"我是一个property";
        sark -> _ivarInterface = @"我是一个ivar";
        
//        sark.ivar = @"哈德解放路卡";
        [sark testCategoryFirst];
        [sark log];
        
        HMTestClass *dark = [sark copy];
    }
    return 0;
}

























