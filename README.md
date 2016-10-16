# calculateIncome
##编译环境
<hr>
>基本系统：Kali GNU/Linux Rolling 64 位<br/>
>编译器版本：gcc version 6.1.1 20160802 (Debian 6.1.1-11)<br/>
>boost版本：1.61.0<br/>
>ide: atom v1.9.9 for Linux<br/>
<br/>
##编译执行
<hr>
>编译：<bold>g++ solution.cc -lboost_system -lboost_date_time</bold><br/>
>执行：<bold>./a.out</bold><br/>
##输入输出
<hr>
>输入：input/input.csv<br/>
>输出：output/output.csv & 屏幕<br/>
<br/>
<hr>
##测试用例
###题目给定用例
<hr>
####input.csv
<hr>
>>2016-06-02 20:00~22:00 7<br/>
>>2016-06-03 09:00~12:00 14<br/>
>>2016-06-04 14:00~17:00 22<br/>
>>2016-06-05 19:00~22:00 3<br/>
>>2016-06-06 12:00~15:00 15<br/>
>>2016-06-07 15:00~17:00 12<br/>
>>2016-06-08 10:00~13:00 19<br/>
>>2016-06-09 16:00~18:00 16<br/>
>>2016-06-10 20:00~22:00 5<br/>
>>2016-06-11 13:00~15:00 11<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>  [Summary]<br/>
>><br/>
>>2016-06-02 20:00~22:00 +210 -240 -30<br/>
>>2016-06-03 09:00~12:00 +420 -180 +240<br/>
>>2016-06-04 14:00~17:00 +660 -600 +60<br/>
>>2016-06-05 19:00~22:00 +0 -0 0<br/>
>>2016-06-06 12:00~15:00 +450 -300 +150<br/>
>>2016-06-07 15:00~17:00 +360 -200 +160<br/>
>>2016-06-08 10:00~13:00 +570 -330 +240<br/>
>>2016-06-09 16:00~18:00 +480 -300 +180<br/>
>>2016-06-10 20:00~22:00 +150 -120 +30<br/>
>>2016-06-11 13:00~15:00 +330 -200 +130<br/>
>><br/>
>>Total Income:3630<br/>
>>Total Payment:2470<br/>
>>Profit:1160<br/>
<hr>
###测试用例1
<hr>
####input.csv
<hr>
>>2016-08-02 20:00~22:00 7<br/>
>>2016-09-03 09:00~12:00 14<br/>
>>2016-10-04 14:00~17:00 22<br/>
>>2016-11-05 19:00~22:00 3<br/>
>>2016-12-06 12:00~15:00 15<br/>
>>2016-13-07 15:00~17:00 12（测试月份大于12）<br/>
>>2016-01-08 10:00~13:00 19<br/>
>>2016-02-09 17:00~19:00 16（测试跨收费区域）<br/>
>>2016-03-10 20:00~22:00 5<br/>
>>2016-00-11 13:00~15:00 11（测试月份小于1）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>2016-08-02 20:00~22:00 +210 -240 -30<br/>
>>2016-09-03 09:00~12:00 +420 -240 +180<br/>
>>2016-10-04 14:00~17:00 +660 -600 +60<br/>
>>2016-11-05 19:00~22:00 +0 -0 0<br/>
>>2016-12-06 12:00~15:00 +450 -300 +150<br/>
>>Month number is out of range 1..12<br/>
>>2016-01-08 10:00~13:00 +570 -330 +240<br/>
>>2016-02-09 16:00~18:00 +480 -390 +90<br/>
>>2016-03-10 20:00~22:00 +150 -120 +30<br/>
>>Month number is out of range 1..12<br/>
>><br/>
>>Total Income:2940<br/>
>>Total Payment:2220<br/>
>>Profit:720<br/>
<hr>
###测试用例2
<hr>
####input.csv
<hr>
>>2016-08-0220:00~22:00 7（格式不对，不能切分时）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>The record format is wrong!<br/>
>><br/>
>>Total Income:0<br/>
>>Total Payment:0<br/>
>>Profit:0<br/>
<hr>
###测试用例3
<hr>
####input.csv
<hr>
>>2016-09-03 08:00~11:00 14（9:00以前开始）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>it's too early to start.<br/>
>><br/>
>>Total Income:0<br/>
>>Total Payment:0<br/>
>>Profit:0<br/>
<hr>
###测试用例4
<hr>
####input.csv
<hr>
>>2016-10-04 14:00~18:00 14（超过3小时）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>The last time of sport is incorrect!<br/>
>><br/>
>>Total Income:0<br/>
>>Total Payment:0<br/>
>>Profit:0<br/>
<hr>
###测试用例5
<hr>
####input.csv
<hr>
>>2016-08-02 20:00-22:00 7（时间格式不对）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>The daration format is incorrect!<br/>
>><br/>
>>Total Income:0<br/>
>>Total Payment:0<br/>
>>Profit:0<br/>
<hr>
###测试用例6
<hr>
####input.csv
<hr>
>>2016-08-02 20:00~22:00 b（人数不是数字）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/>
>><br/>
>>bad lexical cast:source type value could not be interpreted as target<br/>
>>Total Income:0<br/>
>>Total Payment:0<br/>
>>Profit:0<br/>
<hr>
###测试用例7
<hr>
####input.csv
<hr>
>>2016-08-02 20:00~22:00 7<br/>
>>（出现空行）<br/>
>>2016-06-09 14:00~17:00 20<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/><br/>
>><br/>
>>2016-08-02 20:00~22:00 +210 -240 -30<br/>
>>The record format is wrong!<br/>
>>2016-06-09 14:00~17:00 +600 -450 +150<br/>
>><br/>
>>Total Income:810<br/>
>>Total Payment:690<br/>
>>Profit:120<br/>
<hr>
###测试用例8
<hr>
####input.csv
<hr>
>>2016-08-02 20:00~22:00 7<br/>
>>2016-06-09 14:00~17:00 -20（人数为负数）<br/>
<hr>
###结果
<hr>
####output.csv
<hr>
>>[Summary]<br/><br/>
>><br/>
>>2016-08-02 20:00~22:00 +210 -240 -30<br/>
>>The number of people is negative.<br/>
>>Total Income:210<br/>
>>Total Payment:240<br/>
>>Profit:-30<br/>
<hr>
