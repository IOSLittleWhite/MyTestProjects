//
//  Sark.m
//  TempiOSTest
//
//  Created by JZ_Stone on 2017/6/11.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import "Sark.h"

@implementation Sark

- (void)willChangeValueForKey:(NSString *)key {
    NSLog(@"%@", NSStringFromSelector(_cmd));
    [super willChangeValueForKey:key];
}

- (void)didChangeValueForKey:(NSString *)key {
    NSLog(@"%@", NSStringFromSelector(_cmd));
    [super didChangeValueForKey:key];
}


@end
