# calculateIncome

## 编译环境
> 基本系统：Kali GNU/Linux Rolling 64 位
> 编译器版本：gcc version 6.1.1 20160802 (Debian 6.1.1-11)
> boost版本：1.61.0
> ide: atom v1.9.9 for Linux

## 编译执行
> 编译：<bold>g++ solution.cc -lboost_system -lboost_date_time</bold>
> 执行：<bold>./a.out</bold>

## 输入输出
> 输入：input/input.csv
> 输出：output/output.csv & 屏幕


## 测试用例
### 题目给定用例

#### input.csv
```
2016-06-02 20:00~22:00 7
2016-06-03 09:00~12:00 14
2016-06-04 14:00~17:00 22
2016-06-05 19:00~22:00 3
2016-06-06 12:00~15:00 15
2016-06-07 15:00~17:00 12
2016-06-08 10:00~13:00 19
2016-06-09 16:00~18:00 16
2016-06-10 20:00~22:00 5
2016-06-11 13:00~15:00 11
```

### 结果
#### output.csv
```
 [Summary]

2016-06-02 20:00~22:00 +210 -240 -30
2016-06-03 09:00~12:00 +420 -180 +240
2016-06-04 14:00~17:00 +660 -600 +60
2016-06-05 19:00~22:00 +0 -0 0
2016-06-06 12:00~15:00 +450 -300 +150
2016-06-07 15:00~17:00 +360 -200 +160
2016-06-08 10:00~13:00 +570 -330 +240
2016-06-09 16:00~18:00 +480 -300 +180
2016-06-10 20:00~22:00 +150 -120 +30
2016-06-11 13:00~15:00 +330 -200 +130

Total Income:3630
Total Payment:2470
Profit:1160
```

### 测试用例1
#### input.csv
```
2016-08-02 20:00~22:00 7
2016-09-03 09:00~12:00 14
2016-10-04 14:00~17:00 22
2016-11-05 19:00~22:00 3
2016-12-06 12:00~15:00 15
2016-13-07 15:00~17:00 12（测试月份大于12）
2016-01-08 10:00~13:00 19
2016-02-09 17:00~19:00 16（测试跨收费区域）
2016-03-10 20:00~22:00 5
2016-00-11 13:00~15:00 11（测试月份小于1）
```

### 结果
#### output.csv
```
[Summary]

2016-08-02 20:00~22:00 +210 -240 -30
2016-09-03 09:00~12:00 +420 -240 +180
2016-10-04 14:00~17:00 +660 -600 +60
2016-11-05 19:00~22:00 +0 -0 0
2016-12-06 12:00~15:00 +450 -300 +150
Month number is out of range 1..12
2016-01-08 10:00~13:00 +570 -330 +240
2016-02-09 16:00~18:00 +480 -390 +90
2016-03-10 20:00~22:00 +150 -120 +30
Month number is out of range 1..12

Total Income:2940
Total Payment:2220
Profit:720
```

### 测试用例2
#### input.csv
2016-08-0220:00~22:00 7（格式不对，不能切分时）

### 结果
#### output.csv
```
[Summary]

The record format is wrong!

Total Income:0
Total Payment:0
Profit:0
```

### 测试用例3
#### input.csv
2016-09-03 08:00~11:00 14（9:00以前开始）

### 结果
#### output.csv
```
[Summary]

it's too early to start.

Total Income:0
Total Payment:0
Profit:0
```

### 测试用例4
#### input.csv
2016-10-04 14:00~18:00 14（超过3小时）

### 结果
#### output.csv
```
[Summary]

The last time of sport is incorrect!

Total Income:0
Total Payment:0
Profit:0
```

### 测试用例5
#### input.csv
2016-08-02 20:00-22:00 7（时间格式不对）

### 结果
#### output.csv
```
[Summary]

The daration format is incorrect!

Total Income:0
Total Payment:0
Profit:0
```

### 测试用例6
#### input.csv
2016-08-02 20:00~22:00 b（人数不是数字）
 
### 结果
#### output.csv
 ```
[Summary]

bad lexical cast:source type value could not be interpreted as target
Total Income:0
Total Payment:0
Profit:0
```

### 测试用例7
#### input.csv
2016-08-02 20:00~22:00 7
（出现空行）
2016-06-09 14:00~17:00 20

### 结果
#### output.csv
```
[Summary]

2016-08-02 20:00~22:00 +210 -240 -30
The record format is wrong!
2016-06-09 14:00~17:00 +600 -450 +150

Total Income:810
Total Payment:690
Profit:120
```

### 测试用例8
#### input.csv
2016-08-02 20:00~22:00 7
2016-06-09 14:00~17:00 -20（人数为负数）

### 结果
#### output.csv
```
[Summary]

2016-08-02 20:00~22:00 +210 -240 -30
The number of people is negative.
Total Income:210
Total Payment:240
Profit:-30
```
