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
// 特别是缓冲区的概念
https://blog.csdn.net/a3192048/article/details/80303547
https://blog.csdn.net/k346k346/article/details/48213811
```

46.引用变量：
```cpp
  int rat;
  int & rodent = rat; // 引用变量必须在声明时进行初始化，之后这个就相当于rat的一个别名，&rodent就表示rat的地址。 可以看做是一个指向固定地址的指针
  int * const pr = &rat;

  int & rodent;
  rodent = rat;  // wrong！！！！！

  // 引用变量传参：
  int main()
  {
  	int wallet1 = 10, wallet2 = 20;
  	swap(wallet1, wallet2);   // 这里使用引用传参，函数的功能是两个值交换，注意形式上和传值传参是一模一样
    // 返回后 wallet1 = 20， wallet2 = 10
    ...
  }

  void swap(int & a, int & b)
  {
  	int tmp;
  	tmp = a;
  	a = b;
  	b = tmp;
  }

  // 引用对象，不能是表达式
  // 尽可能地使用const
  // 左值引用和右值引用

  // 返回引用，最重要的一点是，应避免返回函数终止时不再存在的内存单元引用：
  fee & Function(fee & p) // 错误的引用例子
  {
  	fee  q;
  	q = p;
  	return q;    // 这个函数返回了一个p的引用，但是函数终止时，q就被释放了 
  	return p;    // 注意这里并没有&，最简单的方法是返回一个作为参数传递给函数的引用，比如这里的q
  }

  // p268 的引用返回？
  // 将类对象传递给函数时，C++通常的做法是使用引用，如果返回临时变量的引用，可能会使得程序崩溃
  // 使用引用相对于传值效率更高，因为不需要创建新的临时变量
```

47.类的引用一些要点：
```cpp
  // 基类引用可以指向派生类，构建函数时，参数类型为 ofstream &，也可以接受ifstream &
  // 关于函数重载部分见书本第八章
```

48.函数模版
```cpp
  // 函数模版通用形式如下，这里以声明为例，其中的typename在某些较旧的版本中需要改为class
  template <typename T>
  void Function(T &a);

  // 如果需要对某种参数类型做特别的实例化，声明如下：
  template <> void Function(int &a);
```

49.关于#include中<>和""的区别：
```cpp
  #include<iostream>  // 用<>, 将首先在存储标准头文件的文件系统中查找
  #include"your.h"    // 用"", 将首先在当前工作目录或者源代码目录查找，因此使用自己定义的头文件应该使用" "

  // 头文件所包含的内容：1.函数原型 2.结构体、类的定义 3.const变量 4.内联函数定义
```

50.未引入名称空间，变量的链接性：内部、外部、无链接性：
```cpp
  int global;   // 链接性为外部，其余文件也可以使用
  static int one_file；  // 链接性为内部，只有该文件的代码能使用
  int main()
  {
  	...
  }
  // 注意上下两个static的含义不同，上一个表示内部链接性，下一个表示存储连续性
  void function(int n)
  {
  	static int cont; // 无链接性，只有函数内可以使用
  }

  // 外部变量的使用方式，C++中变量只能有一次定义，C++提供了定义和声明两种方式
  double up;              // 定义，初始化为0
  extern int blem;        // 声明，注意不能赋值，赋值即视作定义
  extern char gr = 'z';   // 定义

  // 多文件使用方式：
  // file01.cpp
  extern int cat = 20;   // 定义
  int dogs = 22;         // 定义
  int fleas;             // 定义
  // file02.cpp
  extern int cat;        // 声明
  extern fleas;          // 声明 如果没有声明，那么在file02中就无法访问fleas
  // extern dogs;           // 声明
  int dogs = 5;          // ERROR!!!! 即使想用相同的名称来命名变量，这样也是错的，因为违反了单定义规则
  static int dogs = 5;   // 这是可以的，用链接性为内部的变量覆盖

  // C++中const全局变量的链接性为内部的
  const int finger = 10;

  // 动态内存由运算符new和delete控制，因此可以在一个函数中分配内存，而在另一个函数将其释放，new的初始化
  int *pi = new int (6);
  double *pd = new double (99.99); // C++98
  struct where {double x, double y, double z};
  struct where *one = new where {2.5, 7.3, 7.02};
  int *ar = new int [4] {2, 3, 4, 5};  // C++11
  ```

51.名称空间：名称，在C++中可以使变量、函数、结构、枚举、类以及类和结构的成员
```cpp
  // 创建名称空间，关键词：namespace，注意不能位于代码块中
  // 名称空间是开放的(open)

  // using声明和using编译指令
  // using声明：使得特定的标识符可用
  // using编译：使得整个命名空间可用
  char fetch;
  int main()
  {
  	using Jill::fetch;
  	double fetch;     // Error!! 使用声明的方式会覆盖全局变量
  	cin >> fetch;     // input to Jill::fetch
  	cin >> ::fetch;   // input to global fetch
  }
  // using编译，关键字：using namespace
  // Jill::fetch
  char fetch;
  int main()
  {
  	using namespace Jill;
  	double fetch;     // No Error!!! 局部辩论覆盖
  	cin >> fetch;     // input to local fetch
    cin >> ::fetch;   // input to global fetch
    cin >> Jill::fetch; // input to Jill::fetch
  }

  // 命名空间声明可以嵌套
  namespace elements{
  	namespace fire{
  		int flame;
  		...
  	}
  	float water;
  }

  namespace myth
  {
  	using Jill::fetch;
  	using namesapce elements;
  	using std::cout;
  	using std::cin;
  }
  using namesapce myth;
  // 等价于下面两句话，using编译指令是可以传递的
  using namesapce myth;
  using namesapce elements;

  // 创建别名
  namesapce my_very_favorite_things {...};
  namesapce mvft = my_very_favorite_things;

  // 较为推荐的用法：
  int x;
  std::cin >> x;
  std::cout << x << std::endl;

  using std::cin;
  using std::cout;
  using std::endl;
  int x;
  cin >> x;
  cout << x <<endl;
```

52.类：一般来说，类规范由两个部分组成：1.类声明：以数据成员的方式描述数据部分，以成员函数（被称为方法）的方式描述公有接口。 2.类方法定义：描述如何实现类成员函数。 简单来说，类声明提供了类的蓝图，而方法定义则提供了细节。类设计尽可能将公有接口与实现细节分开。公有接口表示设计的抽象组建。将实现细节放在一起并将它们与抽象分开被称为封装。数据隐藏是一种封装，将实现的细节隐藏在私有部分中也是一种封装，将类函数定义和类声明放在不同的文件中也是一种封装。隐藏数据是OOP主要的目标之一，因此数据项通常放在私有部分，组成类接口的成员函数放在私有部分。
```cpp
  class World
  {
  	float mass;          // 类声明中默认使用private
  	char name[20];

  public:
  	void tellall(void);
  	...

  };

  // 定义类方法
  // 定义成员函数时，使用作用域解析符(::)来表示函数所属的类；
  // 类方法可以访问类的private组件
  void Stock::update(double price)
  // Stock类的其他成员函数不用作用域解析运算符就可以使用update
  // 定义位于类声明中的函数都将自动成为内联函数

  // 类的一般格式：
  class classname
  {
  private:
  	data member declarations
  public:
  	member function prototype
  };

  // 类的构造函数——构造函数没有声明类型，程序声明对象时，将自动调用构造函数
  // 下面是Stock类的构造函数原型，结合了默认值
  Stock(const string &co, long n = 0, double pr = 0.0);
  // 定义
  Stock::Stock(const string &co, long n, double pr) // 注意构造函数的参数是赋给类成员的值，参数名不能与类成员相同
  {                                                 // 常见的做法是：在数据成员名中使用m_前缀或者使用_后缀
  	...
  }
  // 使用构造函数，第一种显式调用
  Stock food = Stock("World Cabbage", 250, 1.25);
  // 第二种隐式调用构造函数
  Stock garment("Furry Mason", 50, 2.5);
  // 构造函数与new混合使用
  Stock *pstock = new Stock("Electronshock Games", 18, 19.0);
  // 不能通过调用普通的对象函数一样的方法来调用构造函数，因为构造函数是用于对象的创建的，所以不能通过对象来调用

  // 默认构造函数，只有在未定义任何构造函数的情况下，程序才会自动提供一个默认构造函数
  Stock fluffy_the_cat;    // 正确！这就像
  int x;
  // 如果定义了一个像上面的构造函数
  Stock stock1;      // Error!!!
  // 解决方式： 1.为构造函数的所有参数提供默认值，2.通过函数重载来定义另一个构造函数——一个没有参数的构造函数
  // 总之，在对象定义时，程序是会自动调用构造函数的
  // 实际上，通常应初始化所有对象，以确保所有成员一开始就有已知的合理值
  Stock::Stock()
  {
  	company = "no name";
  	shares = 0;
  	share_val = 0.0;
  	total_var = 0.0;
  }

  // 注意区分：
  Stock first("Concrete Conglomerate");   // 调用构造函数
  Stock second();                         // 返回一个Stock对象的函数
  Stock third;                            // 调用默认构造函数，隐式调用默认构造函数时不需要括号！！

  // 析构函数
  // 类对象必须有一个析构函数，和构造函数一样，如果未定义，则程序会提供一个默认的析构函数
  // Stock类的析构函数
  ~Stock();
  Stock::~Stock()
  {
  	...
  }
  
  stock1 = stock2;    // 和结构一样，类也可以直接相互之间赋值
  // C++11也支持用{}来初始化，当然参数要符合构造函数
  Stock hot_tip = {"Derivatives Plus Plus", 100, 45.0};
  Stock jock {"Sport Age Storage, Inc"};
  Stock temp {};

  // 讨论一个关于show()的问题，之前我们show的函数输入都是const的，但是这里这样不行，因为输入第调用私有变量的方式
  const Stock land {"iKun"};
  land.show();    // Error! 因为无法保证show()不会对参数做修改
  void show() const;  // 修改函数原型和定义
  void stock::show() const
  {
  	...
  }

  // this指针，this指针指向调用对象
  // 对象数组，初始化对象数组的方案是，首先使用默认构造函数创建数组元素，然后花括号中的构造函数将创建临时对象，然后
  // 将临时对象的内容复制到相应的元素中。因此，要创建类对象数组，则这个类必须有默认**构造函数**
  const int STKS = 10;
  Stocks stocks[STKS] = {
  	Stock("NanoSmart", 12.5, 20),
  	Stock(),
  	Stock("Monolithic Obelisks", 130, 3.25)
  };

  // 作用域内枚举
  enum egg {Small, Medium, Large, Jumbo};
  enum t_shirt {Small, Medium, Large, Xlarge}; // Error! 因为egg Small和t_shirt Small位于相同的作用域内，会冲突

  enum class egg {Small, Medium, Large, Jumbo};
  enum class t_shirt {Small, Medium, Large, Xlarge};  // 也可以使用关键字struct代替class
  egg choice = egg::Large;        // 作用域下的枚举变量不会自动转换为整形


```

53.字符串和string以及const之间赋值的一些问题
```cpp
  // 首先如果是const char * a，想赋值给char *b
  const char *a = "Hey";
  char *pc = new[LENGTH];
  pc = a;         // Error! 不可以这样直接赋值，const char* 不可以用直接赋值的方式转化为char *
  strcpy(pc, a);  // Correct！这才是正确的
  strncpy(pc, a, LENGTH); // 这也是正确的！

  // 接着将string赋值给char *或者const char*
  string a = "Hey";
  char * pc;
  char *pc = a.c_str();   // 用了string类中的这个方法
  const char *pcc = a.cstr()

  // 计算string转化为char数组后的长度
  string a = "Hey";
  const int len =a.length() + 1; 
```

54.类再深入。讲的是运算符的重载、友元函数、状态成员、rand()随机数、类的转换
```cpp

  // 在类内定义常数的话有两种方式：
  const static int a = 4;
  enum {a = 4};

  // 运算符重载，关键字：operator
  operator**op**(argument-list) // 模版！这里的**表示的只是分隔，注意这里没有空格
  operator+()        // 当然重载的运算符是需要本来就存在且有意义的，比如@就不可以重载
  // 在定义时将operator+当做一个函数名来看待即可
  // 这里以P384的程序为例，Time类中有下列成员函数的声明：
  Time operator+(const Time & t) const;    // 原型
  Time Time::operator+(const Time &t) const
  {
  	Time sum;
  	sum.minutes = minutes + t.minutes;
  	sum.hours = hours + t.hours + sum.minutes / 60;
  	sum.minutes %= 60;
  	return sum;
  } 
  
  total = coding + fixing;
  total = coding.operator+(fixing);
  total = coding + fixing +thrid;  // 这也是正确的
  // 对于二元操作符的成员函数其左侧的为其调用对象，右侧被作为参数被传递的参数
  
  // 但是这里遇到一个问题，比如说我重载了一个*，那么
  total = coding * 2.5; // ok
  total = 2.5 * coding; // false,因为coding是调用对象，这样写是错的，那怎么使得这个表达式正确呢

  friend Time operator*(double m, const Time &t);  // 友元函数的原型放在类声明中，友元函数的关键字friend，使得该函数也能访问类内的私有变量，这部分是在类内
  Time operator*(double m, const Time &t)   // 注意，虽然该函数的原型是在类内，但是其定义不用写Time::，完全看作一个类外的函数定义，但同时它可以访问类的私有变量
  {
  	return t * m;     // 这是很好的一种方式，使用 t.operator*(m)
  }

  // <<的重载，这个符号其实已经被重载过了，这里主要是看怎么和cout使用，在ostream类中将operator<<()函数实现为返回一个指向ostream对象的引用
  ostream & operator<<(ostream &os, const Time &t)
  {
  	os << t.hours << "hours, " << t.minutes << "minutes";
  	return os;  // 返回ostream的引用是有意义的。这个函数同样适用fout
  }
  cout << "Trip time: " << trip << " Tuesday\n";  // 只有返回ostream的引用才能完成这样连续的<< 
  // 在类内定义的函数会汇编**成内联函数**

  // 那么到底应该选择成员函数还是非成员函数呢：非成员函数的重载运算符函数所需的形参数目与运算符使用的操作数数目相同；而成员版本所需的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象

  // 关注P400页中定义的Vector类里枚举的用法
  enum Mode {REC, POL}; // 后续直接用Mode表示这种枚举变量，注意的是这个类的作用域只有这个类内，所以要Vector::REC，Vector::POL
  friend Vector operator*(double n, const Vector &a);
  friend std::ostream & operator<<(std::ostream &os, const Vector &v);
  // 写函数的时候还是要注意参数名不可以与类的私有变量重名

  Vector Vector::operator+(const Vector &b) const
  {
  	return Vector(x + b.x, y + b.y); // 这里调用了构造函数，虽然说构造函数定义和原型是没有返回类型的，但是这样写会生成一个临时变量，推荐这样写！！！！！用构造函数来生成新的实例可以减小犯错的概率
  }
  // 上面的Vector定义在VECTOR命名空间中
  Vector folly(3.0, 4,0);    // 在构造函数中原型给了Mode的默认值，RECT
  Vector foolery(20.0, 30.0, VECTOR::Vector::POL);

  // 重载-，这个符号既可以表示减法，也可以表示取负
  Vector operator-() const;  // 这里的疑问是对于一元的操作符，默认右边的是第一个参数？？？
  Vector Vector::operator-() const
  {
  	return Vector(-x, -y);
  }

  // 关于产生随机数
  #include<cstdlib> // 这个库中包含了srand()和rand()
  srand(time(0));   // srand产生的随机数种子比rand产生的更随机，time(0)会返回从某一个时间开始的秒数，产生种子只需要做一遍即可。
  rand();

  // 类的强制转换——从某种类型到类类型的转换
  // 这一点主要利用了构造函数的隐式调用，构造函数有默认值等
  Stonewt myCat;
  myCat = 19.6;  // Stonewt(myCat)
  // 如何禁止这种隐式调用呢：
  explicit Stonewt(double lbs); // 这样就禁止了隐式调用
  // 什么情况会发生隐式调用：
  1. 将Stornewt对象初始化为double值时
  2. 将double值赋给Stonewt时
  3. 将double值传递给接受Stonewt参数的函数时
  4. 返回值被声明为Stonewt的函数试图返回double时

  // 转换函数——从类类型转换为其他类型：转换函数
  1. 转换函数必须是类方法
  2. 转换函数不能指定返回类型
  3. 转换函数不能有参数
  operator int();
  operator double() const;

  Stonewt::operator int() const
  {
  	return int (pounds + 0.5);
  }
  Stonewt poppins;
  double p_wt = poppins;  // 隐式调用
  cout << "Poppins" << int(popins) << "pounds.\n";  // 显式调用，这里必须显式，因为没有要转化为double的暗示
  explicit operator int();  // 这样就禁止显式调用 


```

55.关于类的动态分配内存问题
```cpp
  
  // 这里的侧重点是内存分配的问题，首先new和delete的匹配问题，delete []必须和new []相匹配，当然delete可以处理值为0的指针，空指针C中关键字为NULL，其实就是被define为0.C++中提供了关键字nullptr。
  // 这里以自己定义的字符串类为例子展示了这种思想，StringBad、String
  
  // 考虑这样一个问题，我现在要使得所有的对象均共用一个变量，比如我想要用这个量来计数对象的个数
  class StringBad  // 位于strngbad.h
  {
  	static int num_strings;
  	...
  } // 可以看P427的图，这样所有的对象共享这一个变量，下面注意如何初始化

  int StringBad::num_strings = 0;  // 在strngbad.c中初始化，注意作用域，注意初始化时有int，但是没有static，如果是const或者enum则可以在类声明中初始化。

  // 以下是构造函数中的内容： 复习一下new，new的接受者必须是一个指针
  len = std::strlen(s);
  str = new char [len + 1];
  std::strcpy(str, s);
  num_strings++;

  // 以下是析构函数中的内容：
  --num_strings
  delete [] str;

  // 理解以下为什么下列不可以。字符串并不保存在对象中，字符串单独保存在堆内存中，对象仅仅保存了去哪里找字符串。
  str = s;    // 这样只保存了地址，而没有创建字符串副本

  // 复制构造函数，当我们用一个对象来初始化另一个对象时，会用到复制构造函数
  C++会默认提供一下的成员函数：
  1. 默认构造函数，如果没有定义构造函数；
  2. 默认析构函数，如果没有定义；
  3. 复制构造函数，如果没有定义；
  4. 赋值运算符，如果没有定义；
  5. 地址运算符，如果没有定义

  // 默认的复制构造函数只是将每个函数成员简单的进行赋值，这是一种简单的非深度复制。复制函数的原型通常如下：
  StringBad(const StringBad &);
  // 只要产生对象副本时均会调用复制构造函数，注意要理解，包括函数按值传递或者返回对象时，均会调用复制构造函数，也包括直接用=来给对象赋值
  // 现在有两个对象sailor和sport，默认的复制构造函数仅仅做到了：
  sailor.str = sport.str;  // 这得到两个指向同一个字符串的指针，但是析构函数会释放对应的内存，这就是问题
  // 必须定义复制构造函数的原因在于，一些类成员是使用new初始化的、指向数据的指针，而不是数据本身，需要深度复制
  赋值构造函数见P437，精髓在于其中的 delete [] str;

  // 静态类成员函数
  1. 不能通过对象来调用；
  2. 不能使用this指针
  3. 可以使用类名和作用域解析运算符来调用
  static int HowMany() {return num_strings};
  int count = String::HowMany();

```