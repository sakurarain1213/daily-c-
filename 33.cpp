#include <bits/stdc++.h>
using namespace std ;



class //类名
{
    public:
    //公共的行为或属性
 
    private:
    //公共的行为或属性
}; //结束部分的分号不能省略

//成员函数在public 直接定义的例子    
 /* class Point 
{
    public:
    void setPoint(int x, int y) //实现setPoint函数
    {  xPos = x;  yPos = y;  }
    void printPoint() //实现printPoint函数
    {
        cout<< "x = " << xPos << endl;
        cout<< "y = " << yPos << endl;
    }
    private:
       int xPos;
       int yPos;
};
int main()
{
    Point M; //用定义好的类创建一个对象 点M
    M.setPoint(10, 20); //设置 M点 的x,y值
    M.printPoint(); //输出 M点 的信息
    return 0;
} */


  //在类外定义成员函数   通过在类内进行声明, 然后在类外 :: 进行实现



/* class Point
{
    public:
    void setPoint(int x, int y); //在类内对成员函数进行声明
    void printPoint();
    private:
    int xPos;
    int yPos;
};
 
void Point::setPoint(int x, int y) //通过作用域操作符 '::' 实现setPoint函数
{
    xPos = x;
    yPos = y;
}
void Point::printPoint() //实现printPoint函数
{
    cout<< "x = " << xPos << endl;
    cout<< "y = " << yPos << endl;
}
 */





//构造函数  可以自己带参数 名字一定和class类名一样

/* class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // 这是构造函数
 
   private:
      double length;
};
 
// 构造函数的定义
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}
 
int main( )
{
   Line line(10.0);  // 默认设置的长度

} */
 



int  main ()
{











return 0;
}