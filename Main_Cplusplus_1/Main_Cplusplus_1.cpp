
#include "iostream"
#include "math.h"
#include "string.h"
#include "conio.h"
#include "dos.h"
using namespace std;



//  ***********************************************************************
//  ************************* Region Area Program *************************
//  ***********************************************************************


//float Distance(int, int, int, int);   // function of distance
//float Triangle_Area(int, int, int, int, int, int);    // function of triangule area
//
//
//void main()
//{
//	int x1, y1, x2, y2, x3, y3, x4, y4;
//	float TA1, TA2, RA;
//
//	cout << "Enter first point (x1, y1) where x1>0 and y1>0:" << endl;
//	do {
//		cin >> x1;
//		cin >> y1;
//		if (x1 <= 0 || y1 <= 0)
//		{
//			cout << "Enter x1,y1>0" << endl;
//		}
//	} while (x1 <= 0 || y1 <= 0);
//
//
//	cout << "Enter second point (x2, y2) where x2<0 and y2>0:" << endl;
//	do {
//		cin >> x2;
//		cin >> y2;
//		if (x2 >= 0 || y2 <= 0)
//		{
//			cout << "Enter x2<0,y2>0" << endl;
//		}
//	} while (x2 >= 0 || y2 <= 0);
//
//
//	cout << "Enter third point (x3, y3) where x3<0 and y3<0:" << endl;
//	do {
//		cin >> x3;
//		cin >> y3;
//		if (x3 >= 0 || y3 >= 0)
//		{
//			cout << "Enter x3,y3<0" << endl;
//		}
//	} while (x3 >= 0 || y3 >= 0);
//
//
//	cout << "Enter forth point (x4, y4) where x4>0 and y4<0:" << endl;
//	do {
//		cin >> x4;
//		cin >> y4;
//		if (x4 <= 0 || y4 >= 0)
//		{
//			cout << "Enter x4>0 and y4<0" << endl;
//		}
//	} while (x4 <= 0 || y4 >= 0);
//
//
//	TA1 = Triangle_Area(x1, y1, x2, y2, x3, y3);
//	TA2 = Triangle_Area(x1, y1, x3, y3, x4, y4);
//	RA = TA1 + TA2;
//
//	cout << "Region Area is: " << RA;
//
//	//getch();
//
//}
//
//float Distance(int a1, int b1, int a2, int b2)
//{
//	float D;
//	D = sqrt(pow((a1 - a2), 2) + pow((b1 - b2), 2));
//	return D;
//}
//
//float Triangle_Area(int a1, int b1, int a2, int b2, int a3, int b3)
//{
//	float D12, D13, D23, T_A;
//
//	D12 = Distance(a1, b1, a2, b2);
//	D13 = Distance(a1, b1, a3, b3);
//	D23 = Distance(a2, b2, a3, b3);
//
//	float s = (D12 + D13 + D23) / 2;
//	T_A = sqrt(s * (s - D12) * (s - D13) * (s - D23));
//	return T_A;
//}



//  ***********************************************************************
//  ********************* Max, Min, Average, Median, Std ******************
//  *********************************************************************** 


float findmax(float[], int);
float findmin(float[], int);
float average(float[], int);
float median(float[], int);
float standard_dev(float[], int);
void read(float[], int, int&);


void main()
{
	int N;
	cout << "Enter the vencor length:";
	cin >> N;

	float a[1000];
	int k = 0;
	read(a, N, k);

	cout << endl;
	cout << "******************";
	cout << endl;

	cout << "max(a): " << findmax(a, k) << endl;
	cout << "min(a): " << findmin(a, k) << endl;
	cout << "average(a): " << average(a, k) << endl;
	cout << "median(a): " << median(a, k) << endl;
	cout << "std(a): " << standard_dev(a, k);

	_getch();
}


float findmax(float b[], int k)
{
	float max = b[0];
	for (int i = 0; i <= k; i++)
		if (b[i] > max)
			max = b[i];
	return max;
}

float findmin(float b[], int k)
{
	float min = b[0];
	for (int i = 0; i <= k; i++)
		if (b[i] < min)
			min = b[i];
	return min;
}


float average(float b[], int k)
{
	float sum = 0;
	for (int i = 0; i <= k; i++)
		sum += b[i];
	return sum / (k + 1);
}


float median(float b[], int k)
{
	for (int j = 1; j < k + 1; j++)
	{
		for (int i = 0; i < k + 1 - j; i++)
		{
			int b1 = b[i];             // before element
			int a1 = b[i + 1];         // agter element
			if (b1 > a1)
			{
				b[i] = a1;
				b[i + 1] = b1;
			}
		}
	}
	if ((k + 1) % 2 != 0)
		return b[k / 2];
	else
		return (b[(k + 1) / 2 - 1] + b[(k + 1) / 2]) / 2;
}



float standard_dev(float b[], int k)
{
	float standard_dev = 0;
	for (int i = 0; i <= k; i++)
		standard_dev += pow((b[i] - average(b, k)), 2);
	return sqrt(standard_dev / k);
}


void read(float a[], int N, int& k)
{
	do {
		cout << "a[" << k << "]:";
		cin >> a[k];
		k++;
	} while (k < N);
	--k;
}




//  ***********************************************************************
//  ******************* find element(s) - (linear search) *****************
//  *********************************************************************** 


//void main()
//
//{
//	const int size = 10;
//	int a[size] = { 19,8,25,4,7,1,-4,13,2,7 };
//	int key;
//
//	cout << "enter key:";
//	cin >> key;
//
//	int b[size] = {};
//	int ind = 0;
//	for (int i = 0; i < size; i++)
//		if (a[i] == key)
//		{
//			b[ind] = i;
//			ind++;
//		}
//	for (int k=0; k<ind; k++)
//			cout << b[k]<<" ";
//
//	_getch();
//}
//
//


//  ***********************************************************************
//  ************************* bubble sort *********************************
//  *********************************************************************** 

// bubble sort
//void  sort(int[], int, char);
//
//int main()
//{
//	const int size = 4;
//	int a[size] = {2, 6, 7, 1};
//
//
//	sort(a, size, 'a');
//
//	for (int i = 0; i < size; i++)
//		cout << a[i] << ' ';
//
//	_getch();
//
//}
//
//
//void  sort(int a[], int len, char type)
//{
//	for (int j = 1; j < len; j++)
//	{
//		for (int k = 0; k < len - j; k++)
//		{
//			int b1 = a[k];             // before element
//			int a1 = a[k + 1];         // agter element
//
//			if (type == 'a')           // ascend sort
//			{
//				if (b1 > a1)
//				{
//					a[k] = a1;
//					a[k + 1] = b1;
//				}
//			}
//			if (type == 'd')          // descend sort
//			{
//				if (b1 <  a1)
//				{
//					a[k] = a1;
//					a[k + 1] = b1;
//				}
//			}
//		}
//	}
//}
//


//  ***********************************************************************
//  ******************* binary search (for sorted vectors) ****************
//  ***********************************************************************  


//int  bsearch(int[], int, int, int, int);
//int main()
//{
//	const int size = 12;
//	int a[size] = { 1, 5, 7, 9, 13, 40, 72, 112, 132, 242, 321, 543};
//
//	int key;
//
//	cout << "enter key:";
//	cin >> key;
//
//
//	int  p;
//	p = bsearch(a, size, key, 0, size - 1);
//	if (p == -1)
//		cout << "not found :" << endl;
//	else
//		cout << " found in element:" << p << endl;
//
//}
//
//
//int  bsearch(int a[], int len, int k, int low, int high)
//{
//	int mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (a[mid] == k)
//			return mid;
//		else if (k < a[mid])
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	return -1;
//}

