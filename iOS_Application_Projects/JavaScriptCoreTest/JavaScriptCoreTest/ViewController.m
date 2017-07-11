//
//  ViewController.m
//  JavaScriptCoreTest
//
//  Created by JZ_Stone on 2017/6/10.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(20, 100, 200, 40)];
    label.textColor = [UIColor blackColor];
    label.font = [UIFont systemFontOfSize:15];
    
    NSAttributedString *attibutedString = [[NSAttributedString alloc] initWithString:@"I'm a attributedString"];
    
    label.text = @"I'm a text";
    label.attributedText = nil;
    
    [self.view addSubview:label];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
