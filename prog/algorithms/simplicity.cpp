#include <iostream>
#include <cmath>

using namespace std;

int modexp(int a, int m, int n)  // Возведения в степень по модулю
{
	if (m == 0) return 1;
	int z = modexp(a, m / 2, n);
	if (m % 2 == 0)
		return (z * z) % n;
	else
		return (a * z * z) % n;
}

int M_R (int n,int k) 
{
	// Представляем n-1 в виде 2^s * t
	int t = n-1, s = 0;
	while (t > 0)  
	{
		t /= 2;
		s++;
		if (t % 2 != 0) 
		{
			break;
		}
	}

	cout << "Разложение числа n - 1 : 2^" << s << "*" << t << endl;

	while (k) // Количество раундов
	{
		int a = (rand() % (n-2)) + 2;
		cout << "Случайное число : " << a << endl;
		int x = modexp(a, t, n);
		cout << "Возведения в степень по модулю (a^m mod n) : " << x << endl;
		
		if (x == 1) 
		{
			return 1;
		}
		if (x == n - 1) 
		{
			for (int i = 0; i < s; i++) 
			{
				x = modexp(a, t * (2 ^ i), n);
				cout << "Возведения в степень по модулю (a^((2^i)*m) mod n) : " << x << endl;
				if (x == n-1) 
				{
					return 1;
				}
			}
		}
		k--;
	}
	return 0;
}

int main() 
{
	setlocale(LC_ALL, "RUS");

	int n, k;
	cout << "Введите число > 3: " << endl;
	cin >> n;

	cout << "Введите кол-во раундов: " << endl;
	cin >> k;

	if (M_R(n,k)) 
	{
		cout << "Вероятно простое" << endl;
	}
	else 
	{
		cout << "Составное" << endl;
	}

	return 0;
}