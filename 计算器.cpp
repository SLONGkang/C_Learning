
#include<stdio.h>

 

int Add(int a, int b)

{

	return a + b;

}

int Sub(int a, int b)

{

	return a - b;

}

int Mul(int a, int b)

{

	return a * b;

}

int Div(int a, int b)

{

	return a / b;

}

 

void menu()

{

	printf("****************************\n");

	printf("***** 1.add      2.sub *****\n");

	printf("***** 3.mul      4.div *****\n");

	printf("******     0.exit      *****\n");

	printf("****************************\n");

}

int main()

{

	int input = 1;

	int x = 0;

	int y = 0;

	int ret = 0;

	while (input)

	{

		menu();

		printf("��ѡ��");

		scanf("%d", &input);

		if (input >= 1 && input <= 4)

		{

			printf("������������");

			scanf("%d%d", &x, &y);

		}

		switch (input)

		{

		case 1:

			ret = Add(x, y);

			break;

		case 2:

			ret = Sub(x, y);

			break;

		case 3:

			ret = Mul(x, y);

			break;

		case 4:

			ret = Div(x, y);

			break;

		case 0:

			printf("�˳�\n");

			break;

		default:

			printf("�������\n");

			break;

		}

		printf("ret = %d\n", ret);

	}

	return 0;

}

