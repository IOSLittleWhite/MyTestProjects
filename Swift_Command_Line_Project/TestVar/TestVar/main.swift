//
//  main.swift
//  TestVar
//
//  Created by JZ_Stone on 2017/6/25.
//  Copyright © 2017年 JZ_Stone. All rights reserved.
//

import Foundation

print("Hello, World!");

var abc = 333.33;
print(abc);


var optionalString: String?;

optionalString = "34";

var string = optionalString;


print(optionalString!);
print("string\(string!)"); // 变量被赋值一个可选变量，也需要！取值


var myString:String?

myString = "Hello, Swift!"

if let yourString = myString {
    print("你的字符串值为 - \(yourString)")
}else{
    print("你的字符串没有值")
}
