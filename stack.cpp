#include <iostream>
#include <string>
using namespace std;

struct ArrayStack
{
	int *stack; // đổi thành int
	int top;
	int max;

	ArrayStack(int n = 50) // cho rộng hơn
	{
		max = n;
		stack = new int[max];
		top = -1;
	}

	bool isFull()
	{
		return top == max - 1;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	int push(int x)
	{
		if (!isFull())
		{
			stack[++top] = x;
			return 1;
		}
		return 0;
	}

	int pop(int &x)
	{
		if (!isEmpty())
		{
			x = stack[top--];
			return 1;
		}
		return 0;
	}

	// Đảo ngược chuỗi thi chuyen int thanh char
	void daoNguocChuoi(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			push(s[i]);
		}

		cout << "Chuoi sau khi dao nguoc la: ";
		while (!isEmpty())
		{
			char c = stack[top--]; // ép về char
			cout << c;
		}
		cout << endl;
	}

	// Tính biểu thức hậu tố
	int tinhHauTo(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];

			if (c >= '0' && c <= '9') // nếu là số
			{
				push(c - '0'); // chuyển ký tự sang số
			}
			else // nếu là toán tử
			{
				int b = stack[top--];
				int a = stack[top--];
				int kq;

				if (c == '+') kq = a + b;
				if (c == '-') kq = a - b;
				if (c == '*') kq = a * b;
				if (c == '/') kq = a / b;

				push(kq);
			}
		}
		return stack[top];
	}
};

int main()
{
	ArrayStack st;
	string s;

	cout << "Nhap chuoi hau to: ";
	getline(cin, s);

	/*int kq = st.tinhHauTo(s);
	cout << "Ket qua la: " << kq << endl;*/

	st.daoNguocChuoi(s);
	return 0;
}
