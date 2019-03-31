1.sizeof()返回字节数，size_t 类型，一种 整型 类型，里面保存的是一个整数

2.枚举变量enum，每个名称都会比它前面一个名称大1，从0开始

3.#define 没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用，而 typedef 有自己的作用域。

4.字符常量是括在单引号中。如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'）

5.const用法，#define，把常量定义为大写字母形式，是一个很好的编程实践。const限定符定以后是不可以改变的，所以在定义时必须赋初始值，要不然是错误的，除非这个变量是用extern修饰的外部变量
```cpp
  const double pi;                      //圆周率的值用pi表示
  pi=3.14159265; //这样是错误的，因为定义成const后，就不能再进行就修改。
  const double pi = 3.141592654; //正确
  
  //从右往左读
  char  * const cp; ( * 读成 pointer to ) 
  //cp is a const pointer to char 

  const char * p; 
  //p is a pointer to const char; 

```

6.auto 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。
```cpp
  auto f = 3.14;      //double
  auto s("hello");  //const char*
  auto z = new auto(9); // int*
  auto x1 = 5, x2 = 5.0, x3 ='r';//错误，必须是初始化为同一类型
```

7.static变量的一个用处是在子函数中定义，当调用离开后，该值仍然存在，比如statc int c = 10 ，那么c--变为9，之后如果下一次再调用这个函数，进来后c的值不是10，而是9。静态局部变量在程序执行到该对象的声明处时被首次初始化，即以后的函数调用不再进行初始化；static存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用static修饰局部变量可以在函数调用之间保持局部变量的值。static 修饰符也可以应用于全局变量。当static修饰全局变量时，会使变量的作用域限制在声明它的文件内。extern存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用'extern'时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置，类似于链接到另一个文件中已经定义的变量。

8.&符号可用于给出地址，如&a，会返回a的地址

9.for( ; ; )表示一个无限循环

10.函数的默认值：定义一个函数，您可以为参数列表中后边的每一个参数指定默认值。当调用函数时，如果实际参数的值留空，则使用这个默认值。

11.匿名函数，Lambda表达式：[capture](parameters)->return-type{body}，类似于函数声明。

12.cpp中生成随机数。http://www.runoob.com/cplusplus/cpp-numbers.html
```cpp
 //设置种子，使用了 time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数
 srand( (unsigned)time( NULL ) );
 
   /* 生成 10 个随机数 */
   for( i = 0; i < 10; i++ )
   {
      // 生成实际的随机数
      j= rand();
      cout <<"随机数： " << j << endl;
   }
  //同样的种子，产生的随机数是相同的，产生一定范围的随机数 可以用：
  rand()%x
  //产生[m,n]的随机数
  int num=rand()%(n-m+1)+m;
```

13.对于字符串，获得字符串的地址（第一个字符的内存地址），可使用以下方法：强制转化为其他指针（非 char*）。可以是 void *，int *，float *， double * 等。使用 &s[0] 不能输出 s[0]（首字符）的地址。因为 &s[0] 将返回 char*，对于 char*（char 指针），cout 会将其作为字符串来处理，向下查找字符并输出直到字符结束。
```cpp
  cout << "Address of var[" << i << "] = ";
  cout << (int *)ptr << endl;
```

14.C++ 不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针
```cpp
//字符串数组的初始化，要注意位数
char a4[6] = "runoob";          // 报错，没有 null 的位置，一定要记得null，即，'\0'
```
15.setw(int n)产生n-1个空格，setfill(可加其他字符)

16.数组初始化时可以用聚合方法，但是赋值时候不可以用聚合方法
```cpp
  int array[] = {5,10,20,40}; //合法
  int array[]；  array[] = {5,10,20,40}; //非法
```
17.数组在使用时可以是一个含有变量的表达式，但是，在数组声明时必须用常量表达式。定义时，长度必须为一个常量，或者转化为const int

18.在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。NULL指针是一个定义在标准库中的值为零的常量。
```cpp
  int  *ptr = NULL; //ptr的值是0
```

19.int (*ptr)[3];一个指针 ptr 指向一个数组，简称数组指针。

20.引用必须在声明时将其初始化，不能先声明后赋值。int& r = i;

21.默认情况下，类的所有成员都是私有的。

22.继承：1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private。2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private。3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private,private,private。注意用的是单个冒号，而不是双冒号！！！！public继承中，基类的private不能被派生类访问，但可以通过调用基类的public或者protected来间接操作。通常使用 public 继承！！！protected和private的区别在于派生类中能否访问，两者在类外都是不能访问的。

23.多继承，就是继承多个类：
```cpp
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
<派生类类体>
};
```

24.new和delete，C++不保证下一次使用的地址是delete后的释放的地址。vector的使用必须包含<vector>头文件，且在命名空间std中。array需要包含<array>头文件，同样位于命名空间std中。相同长度的array之间可以直接整个赋值，但是数组必须逐个赋值。

25.基于范围的for循环：
```cpp
  double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
  for (double x : prices) //貌似C++98 不支持
    cout << x << endl;

  for (double &x : prices)
    x = x * 0.8; //要修改值，必须用引用的方法
```

26.用cin作为输入时，会忽略空格和换行，这时候用cin.get(ch)做补救，ch就是一个定义的char。

27.if中将条件写成(value == variable)可以有效避免少写一个等号造成的赋值情况，因为这样写如果少一个等号，会报错，因为那样是将一个变量赋给一个值。

27.cin读取输入时，其实都是字符，具体读取多少取决于其输入到什么变量类型。
```cpp
  char word[50];
  cin.geline(word,50);
```

28.对于文件的读取和写入，C++中头文件#include <fstream>，位于命名空间std，其中有inFile，outFile，fin，fout。
```cpp
  using namespace std;
  ofstream outFile;
  outFile.open("carinfo.txt")
  //这是一个输出到文件的例子，之后可以将outFile像cout一样使用
  outFile.close();
  //这里的代码打开已有文件接受输出时，原有的内容将被清除，所以需要改变这种默认的设置

  ifstream inFile;
  inFile.open("carinfo.txt");
  //这是一个输入读取的例子，之后inFile就可以像cin那样使用，比如读取一行：
  char line[80];
  inFile.getline(line, 80);

  //判断打开是否成功用is_open方法：
  inFile.open("bowling.txt");
  if (!inFile.is_open())
    exit(EXIT_FAILURE);//需要头文件<cstdlib>
  //如果成功打开了，is_open将返回true
  while (inFile.good())

  inFile.good()
  inFile.fail()
  inFile.eof()
  
  //文件读取到末尾
  ch = cin.get() != EOF;
```

29.在cpp中用new来分配动态内存是比malloc()更好的方式，只能用指针来访问所分配的内存块，delete用于释放new的内存，使用delete的关键在于，他的对象是new的内存，而不一定要求是用于new的指针。
```cpp
  int *pn = new int;
  delete pn; 			//pn这个指针仍然是存在的，只是指向的内存被释放，可以用pn指向新的地址

  typeName * pointer_name = new typeName //通用格式 
  // 用delete来释放
```

30.getline()用法:
```cpp
  string str;
  getline(cin, str);//这个函数在string库中
  inFile.get()//在文件的输入时末尾的换行符，应该用inFile.get()来处理
```

40.对于const和指针的使用：
```cpp
  int age = 39;
  const int * pt = &age;
  //该声明表示pt指向一个const int，因此不能用pt来修改这个值
  *pt += 20； // invalid
  cin >> *pt;  // invalid
  *pt = 20;  // invalid
  age = 20;  // valid 但是可以通过age来修改
  pt = &sage; //但是pt可以指向其他变量，但是仍然无法通过他改变值

  const float g_earth = 9.80;
  const float * pe = &g_earth; //valid pe和g_earth均不能改变值 允许将const的值的地址给const指针

  const float g_earth = 9.80;
  float * pe = &g_earth; // invalid 不允许将const的值给一个非const的指针， 数组传参时要注意const

  int * const finger = &sloth; // A const point to int, 指针指向的地址不能改，但可以通过指针来更改值
  const int * finger = &sloth; // A point to const int
```

41.二维数组作为函数的参数时：
```cpp
  int data[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

  int * data [4]; //声明的是由4个整形指针构成的数组；

  int sum(int (*data)[4], int size); // 这里data的括号是必须的
  int sum(int data[][4], int size); // 这种也是可以的，都是直接告诉了行数
```

42.有很多在输入时判断是否成功的方法：
```cpp
  int a;
  while (cin >> a); // 如果cin的输入不满足int，则会返回false

  cin >> temp;
  if (!cin) // bad input
  {
  	cin.clear(); // 清除cin的异常状态，使得cin可以使用
  	while （cin.get() != '\n'）
  		continue;  // 清除缓冲区
  }
```

43.vector、array初步：
```cpp
  # include <vector>
  # include <array>
  using namespace std;

  vector<int> vi; // 创建一个空的向量，长度可以后续调整，动态分配内存，类似于自动化的new、delete
  vector<double> vt(n) // 创建一个n长的向量

  array<int, 5> ai; // array和数组更接近长度固定，静态内存分配
  array<int, 5> ab;
  ai = ab; //可以直接赋值，而数组需要一个一个赋值

  // array的函数传递,这里不包括引用
  void show(array<int, 5>ai) // 创建一个新对象，这样的效率太低
  {
  	ai[0] = ...;
  }
  show(ai);
  
  void fill(array<int, 5> * ai) // 表达的方法太复杂
  {
  	(*ai) [0] = ...;
  }
  fill(&ai);
  // 更好的方法是引用，在第八章
```

44.函数指针：
```cpp
  think(); // 有一个函数think；
  process(think); // think表示函数的地址，如果写的是think()则表示的是think这个函数的返回值，这里是传参

  // 下面看看如何声明
  double pam(int); // pam函数返回一个double，需要传入一个int变量，函数原型
  double (*pf) (int);// 这是正确的指针类型声明 将pam换成(*pf)
  pf = pam; // 必须返回类型和特征标均一致
  
  double y = (*pf)(5)
  double y = pf(5) //可以用这两种方法调用函数

  // C++的函数原型是可以不用包含变量名字的：
  void cheers(int); //这里可以不写n
  void cheers(int n)
  {
  	...
  }

```
45.关于cin、cin.getline、getline：
```cpp
https://blog.csdn.net/a3192048/article/details/80303547
https://blog.csdn.net/k346k346/article/details/48213811
```