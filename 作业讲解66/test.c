#include <stdio.h>

//
////3.������дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//#include <string.h>
//int is_move_left(char* str1, char* str2)
//{ 
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	//1.��str1�ַ�����׷��һ��str1�ַ���
//	//��strncat����
//	strncat(str1, str1,len1);
//	//2.�ж�str2ָ����ַ����Ƿ���str1ָ����ַ������ִ�
//	//��strstr -- ���ַ����ĺ���
//	char* ret = strstr(str1, str2); //����һ��ָ�룬�ҵ�λ��
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
//		printf("No����\n");
//	}
//	return 0;
//}

////strcat�÷�   - ��һ���ַ�������׷��һ���ַ������Լ�׷���Լ������������������
// ԭ���ǰ�Ҫ׷�ӵ��ַ����ĵ�һ��Ԫ�ط�����һ���ַ�����\0����������׷�ӣ����ڶ����ַ�����\0�������
// ���Լ�׷���Լ�ʱ�����Ҳ�ѵ�һ��Ԫ��׷�ӵ�\0��λ�ã���ô������Ͳ���ֹͣ������û��ʣ���\0��
// ���Գ������
//// string.h���ַ�����������
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

//4.���Ͼ���
// ��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ��µ����ģ�
//  ���д�����������ľ����в���ĳ�������Ƿ���ڣ�ʱ�临�Ӷ� < o(N)��;
//1 2 3
//4 5 6
//7 8 9

//1 2 3
//2 3 4
//3 4 5

// �ٷ�������������еľ���λ��
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
	//�Ҳ���
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
//	//�Ҳ���
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
		printf("�������С���");
	}
	else
	{
		printf("k������!\n");
		printf("k������Ϊ:%d %d", x, y);
	}
	return 0;
}