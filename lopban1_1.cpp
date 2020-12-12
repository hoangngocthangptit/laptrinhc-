#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Line;
class Point{
	private:
		int x, y;
		char *color;
	public:
		Point()
		{
			x = y = 0;
			color = new char[10];
		}
		Point(int xx, int yy, char *cc){
			x = xx;
			y = yy;
			color = new char[10];
			strcpy(color, cc);
		}
		Point(Point &p){
			x = p.x;
			y = p.y;
			color = new char[10];
			strcpy(color, p.color);	
		}
		~Point(){
			if (color!=NULL)
				delete []color;
		}
		void Nhap(){
			cout << "Nhap x, y: ";
			cin >> x >> y;
			cout << "Nhap mau: ";
			gets(color);
		}
		void Xuat(){
			cout << "x = " << x << ", y = " << y << ", color = " << color << endl;
		}
		friend class Line;
};

class Line{
	private:
		Point dau, cuoi;
	public:
		Line(){
			
		}
		Line(Point d, Point c){
			dau.x = d.x;
			dau.y = d.y;
			strcpy(dau.color, d.color);
			cuoi.x = c.x;
			cuoi.y = c.y;
			strcpy(cuoi.color, c.color);
		}
		Line(Line &q){
			dau.x = q.dau.x;
			dau.y = q.dau.y;
			strcpy(dau.color, q.dau.color);
			cuoi.x = q.cuoi.x;
			cuoi.y = q.cuoi.y;
			strcpy(cuoi.color, q.cuoi.color);
		}
		~Line(){
		}
		void Nhap(){
			cout << "Nhap diem dau: ";
			dau.Nhap();
			cout << "Nhap diem cuoi: ";
			cuoi.Nhap();
		}
		void Xuat(){
			cout << "Diem dau: ";
			dau.Xuat();
			cout << "Diem cuoi: ";
			cuoi.Xuat();
			cout << "Do dai = " << DoDai();
		}
		float DoDai(){
			return(sqrt(pow(dau.x - cuoi.x, 2)+pow(dau.y - cuoi.y, 2)));
		}
};

int main(){
	Point d(10, 20,"Xanh");
	Point c(15, 25, "Do");
	Line p(d, c);
	p.Xuat();
	
	
}
