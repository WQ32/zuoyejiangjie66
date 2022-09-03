#include <stdio.h>

//
////3.法二：写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串
//#include <string.h>
//int is_move_left(char* str1, char* str2)
//{ 
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	//1.在str1字符串中追加一个str1字符串
//	//用strncat函数
//	strncat(str1, str1,len1);
//	//2.判断str2指向的字符串是否是str1指向的字符串的字串
//	//用strstr -- 找字符串的函数
//	char* ret = strstr(str1, str2); //返回一个指针，找到位置
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdef";
//	int ret = is_move_left(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("Yes!\n");
//	}
//	else
//	{
//		printf("No……\n");
//	}
//	return 0;
//}

////strcat用法   - 在一个字符串后面追加一个字符串（自己追加自己，不能用这个函数）
// 原理是把要追加的字符串的第一个元素放在上一个字符串的\0处，再依次追加，最后第二个字符串的\0放在最后
// 而自己追加自己时，如果也把第一个元素追加到\0的位置，那么，后面就不能停止下来，没有剩余的\0了
// 所以程序崩溃
//// string.h是字符串操作函数
//#include <string.h>
//
//int main()
//{
//	char arr1[30] = "abc";
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//4.杨氏矩阵
// 有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下递增的，
//  请编写程序在这样的矩阵中查找某个数字是否存在（时间复杂度 < o(N)）;
//1 2 3
//4 5 6
//7 8 9

//1 2 3
//2 3 4
//3 4 5

// 再返回这个数在其中的具体位置
int FindNum(int arr[3][3], int k, int* px, int* py)
{
	int x = 0;
	int y = *(py) - 1;
	while (x <= *(px) - 1 && y >= 0)
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		else if (arr[x][y] > k)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	//找不到
	return 0;
}

//int FindNum(int arr[3][3], int k, int row, int col)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	//找不到
//	return 0;
//}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 3;
	int x = 3;
	int y = 3;
	// int ret = FindNum(arr, k, 3, 3);
	int ret =FindNum(arr,k,&x,&y);
	if (ret == 0)
	{
		printf("不在其中……");
	}
	else
	{
		printf("k在其中!\n");
		printf("k的坐标为:%d %d", x, y);
	}
	return 0;
}