//
//  main.m
//  SynthesizeTest
//
//  Created by JZ_Stone on 2017/6/6.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SynthesizeTest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        SynthesizeTest *test = [SynthesizeTest new];
//        test.string = @"nssdjflakl";
//        
//        
//        NSLog(@"string: %@", test.string);
        
//        [test test];
        
        test.testString = @"testttt";
        [test logRealString];
        [test test];
    }
    return 0;
}
