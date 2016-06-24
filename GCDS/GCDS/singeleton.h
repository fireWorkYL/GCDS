//
//  singeleton.h
//  GCDS
//
//  Created by yanli on 16/6/24.
//  Copyright © 2016年 fireWorkYL. All rights reserved.
//


#if __has_feature(objc_arc)
//.h文件 拼接用##
#define singeleton_h(name) +(instancetype)shared##name;

//.m
#define singeleton_m(name)  static id _instanceType;\
+(instancetype)shared##name\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instanceType = [[self alloc]init];\
});\
return _instanceType;\
}\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instanceType = [super allocWithZone:zone];\
});\
return _instanceType;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instanceType;\
}

#else
//.h文件 拼接用##
#define singeleton_h(name) +(instancetype)shared##name;

//.m
#define singeleton_m(name)  static id _instanceType;\
+(instancetype)shared##name\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instanceType = [[self alloc]init];\
});\
return _instanceType;\
}\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instanceType = [super allocWithZone:zone];\
});\
return _instanceType;\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
return _instanceType;\
}\
-(instancetype)retain\
{\
return _instanceType;\
}\
-(oneway void)release\
{\
\
}\
-(instancetype)autorelease\
{\
return _instanceType;\
}\
-(NSUInteger)retainCount\
{\
return 1;\
}

#endif


