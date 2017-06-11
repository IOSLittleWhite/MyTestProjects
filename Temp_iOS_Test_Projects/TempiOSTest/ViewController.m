//
//  ViewController.m
//  TempiOSTest
//
//  Created by JZ_Stone on 2017/6/11.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import "ViewController.h"
#import "Sark.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // po Sark.class
    // po object_getClass(sark)
    Sark *sark = [Sark new];
    // breakpoint 1
    [sark addObserver:self forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
    // breakpoint 2
    sark.name = @"萨萨萨";
    [sark removeObserver:self forKeyPath:@"name"];
    // breakpoint 3
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    if ([@"name" isEqualToString:keyPath]) {
        //自己的逻辑处理
        // object为B对象
        //值的变化情况可以通过change获取
        NSLog(@"change: %@", change);
    } 
}


@end
