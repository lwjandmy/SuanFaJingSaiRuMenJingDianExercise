// 果园里的树排列成矩阵。它们的x和y坐标均是1~99的整数。
// 输入若干个三角形，依次统计每一个三角形内部和边界上共有多少棵树。
// 样例输入：
// 1.5  1.5   1.5 6.8   5.8  1.5
// 10.7 6.9   8.5 1.5   14.5 1.5
// 样例输出：
// 15
// 17

// 分析：对每个点，测试是否在三角形内的方法：
// S(ABC) = S(OAB) + S(OBC) + S(OCA)
// 即判断面积是否相等
// 注意：判断两个浮点数是否相等： fabs(a-b) < 1e-9

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

struct POINT
{
  double x, y;
};
inline istream &operator >> (istream &is, POINT &pt)
{
  is >> pt.x >> pt.y;
  return is;
}

struct TRIANGLE
{
  POINT A, B, C;
};
inline istream &operator >> (istream &is, TRIANGLE &tri)
{
  is >> tri.A >> tri.B >> tri.C;
  return is;
}

inline double area(POINT p1, POINT p2, POINT p3)
{
  return fabs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
	      (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x));
}

TRIANGLE tri;

#define DOUBLE_EQUAL(a,b)   (fabs((a)-(b))<1e-9)
int main()
{
  TRIANGLE tri;
  cin >> tri;

  POINT O;
  int iCnt = 0;


  for (O.y = 1; O.y <= 99; ++O.y)
    for (O.x = 1; O.x <= 99; ++O.x)
      {
	if (DOUBLE_EQUAL(area(tri.A, tri.B, tri.C),
			 area(O, tri.A, tri.B) +
			 area(O, tri.B, tri.C) +
			 area(O, tri.C, tri.A)))
	  {
	    ++iCnt;
	  }
      }

  printf("%d\n", iCnt);

  return 0;
}


// 1.5  1.5   1.5 6.8   5.8  1.5
