## Shell 脚本 

1.shell脚本的文件末尾为.sh

2.数组，shell中的数组时用括号括起来，元素之间用空格分隔开：
```bash
  array_name=(value0 value1 value2 value3)
  array_name=(value0
  	value1
  	value2
  	value3
  	)
  # 也可以单独用下标一个个赋值，并且下标的范围无限制，也不一定要连续
  ${array_name[i]}            # 读取
  echo ${array_name[@]}       # 用@返回数组中的所有元素
  length=${#array_name[@]}    # 用#返回数组元素个数或者
  length=${#array_name[*]}
  length=${#array_name[i]}    # 得到单个元素的长度
```

3.字符串，用双引号更好，感觉会减少犯错：
```bash
  string="abcd"
  echo ${#string}  # 输出4，和数组一样，符号#返回长度

  # 字符串的截取
  var="http://www.aaa.com/123.htm"
  echo ${var#*//} # 在这里#是运算符，表示从左边开始删除第一个//及左边的所有字符
  output:www.aaa.com/123.htm

  echo ${var##*/} # 表示找到最后面的一个/，删除/及其左边的字符，##表示从右边开始找
  output:123.htm   # #和##均是删除左边字符保留右边字符

  echo ${var%/*} # 表示从右边开始找到第一个/，删除/及其右边字符
  output:http://www.aaa.com

  echo ${var%%/*} # 表示从左边开始招第一个/，删除/及其右边字符
  output:http:

  echo ${var:0:5} # 0表示左边第一个字符，5表示总共5个字符
  output:http:

  echo ${var:7}  # 表示左边第8个字符开始，一直到结束
  output:www.aaa.com/123.htm

  echo ${var:0-7:3}  #  0-7表示右边算起的第7个字符，3表示字符的个数
  output:123

  echo ${var:0-7}  # 右边第7个字符开始，一直到结束
  output:123.htm  # 数字的一直是向右取得，最后一个字符为0-1

```

4.从键盘读取变量的值：
```bash
  read -p "input a val:" a  # 获取键盘输入的a变量数字
  read -p "input a val:" b  # 获取键盘输入的b变量数字
  r=$[a+b]     # 注意[]
  echo "result = ${r}"

  input a val:1
  input b val:2
  result = 3
```

5.基本运算符
```bash
  # 首先是基本的数学运算

  val=`expr 2 + 2` #这里的空格都不能省
  val=`expr $a + $b`
  val=$(expr 10 + 20 )

  a=$b    #赋值

  [ $a == $b ]
  [ $a != $b ]     
  # 条件判断语句，注意表达式和方括号之间必须有空格，变量和运算符之间也必须有空格 
  # 乘法必须是\*

  # 下面是关系运算符：
  -eq : [ $a -eq $b ]  # 是否等于
  -ne     # 不相等
  -gt     # 大于
  -lt     # 小于
  -ge     # 大于等于
  -le     # 小于等于

  # 布尔运算符——位运算
  ! : [ !false ] # 非,对表达式用
  -o : [ $a -lt 20 -o $b -gt 100] # 或运算，表达式有一个为true则true
  -a  # 与运算

  # 逻辑运算符
  && : [[ $a -lt 100 && $b -gt 100 ]]
  ||
  # 使用[[]]更好，&&在[]中会报错

  #((expression1 OP expression2))，OP 可以为 >、<、>=、<=、==、!=

  # 字符串比较
  [ $a = $b ]
  [ $a != $b ]
  [ -z $a ]   # 长度为0，返回true
  [ -n "$a" ]  # 长度不为0， 返回true
  [ $a ]       # 不为空，返回true
```

6.关于echo
```bash

  echo -e "OK \n"  # -e 开启转义， echo默认会加一行的
  echo -e "OK \c"  # \c不换行
  # 单引号是不会转义的，也不会取变量

  read -p "请输入两个值" src1 src2
```

7.条件控制
```bash

  if condition
  then
  	conmmand1
  	conmmand2
  	...
  fi

  if condition
  then
  	...
  else
  	...
  fi

  if condition1
  then
  	...
  elif condition2
  then
  	...
  else
  	...
  fi
```

8.循环控制
```bash

  for var in item1 item2 ... itemN
  do
  	...
  done

  for var in item1 item2 ... itemN; do  command1; command2... done;
  # 还有一种for用法
  for (( i = 0; i < 10; i++ ));do
  	...
  done;


  while condition
  do
  	command
  	...
  done

  case $num in
  	module1)
		command1
		...
		;;
	module2)
		command2
		...
		;;
	...
	*)
		command
		...
  esac
  #几个条件一起写 1|2|3|4|...), 注意两个分号其实相当于break, *可以看作default

  break  
  continue
```

