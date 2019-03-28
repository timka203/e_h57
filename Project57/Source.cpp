#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
struct zapis
{
	char name[100],surname[100];
	int num : 10, num2 : 8, num3 : 8, num4 : 8;
};
void t(int g)
{
	ofstream my1("out1.txt");
	char str[100];
	for (size_t i = 0; i < g; i++)
	{
		cin.ignore();
		cout << "Write your name and surname" << endl;
		cin.getline(str,100);
		my1 << str << endl;
		cin >> str;
		my1 << str << endl;
		cin >> str;
		my1 << str << endl;
		cin >> str;
		my1 << str << endl;
		cin >> str;
		my1 << str << endl;
	}
}
void task1()
{
	ifstream in("out1.txt");
	int g;
	cin >> g;
	int k, l;
	int n, n2, n3, n4;
	t(g);
	int t = 1;
	zapis *s = new zapis[g];
	cin.ignore();
	for (size_t i = 0; i < g; i++)
	{
		in >> s[i].name;
		in >> s[i].surname;
		in >> n;
		in >> n2;
		in >> n3;
		in >> n4;
		s[i].num = n;
		s[i].num2 = n2;
		s[i].num3 = n3;
		s[i].num4 = n4;

	}
	for (size_t i = 0; i < g; i++)
	{
		cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
	}
	while (t == 1)
	{


		cout << "do you want to change something(1 for yes,0 for no)" << endl;
		cin >> k;
		int i;
		if (k == 1)
		{
			cout << "which one?" << endl;
			cin >> i;
			cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;

			int h;
			cout << "what you want to change(1 for name, 2 for surname,3 for first part of number,4 for second part of number,5 for third part of number,6for fourth part of number" << endl;
			cin >> h;
			switch (h)
			{
			case 1:cin >> s[i].name; break;
			case 2:cin >> s[i].surname; break;
			case 3:int q;
				cin >> q;
				s[i].num = q;
				break;
			case 4:int e;
				cin >> e;
				s[i].num2 = e;
				break;
			case 5:int i;
				cin >> i;
				s[i].num3 = i;
			case 6:int x;
				cin >> x;
				s[i].num4 = x;
			default:
				break;
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}

		cout << "do you want to sort them by names?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			for (int i = 0; i < g - 1; i++)
			{
				for (size_t j = 0; j < g - 1; j++)
				{
					if ((strcmp(s[j].name, s[j + 1].name) == 1))
					{
						swap(s[j], s[j + 1]);
					}
					else if ((strcmp(s[j].surname, s[j + 1].surname) == 1))
					{
						swap(s[j], s[j + 1]);
					}
				}
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		cout << "do you want to sort them by numbers?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			for (int i = 0; i < g - 1; i++)
			{
				for (size_t j = 0; j < g - 1; j++)
				{
					if (s[j].num > s[j + 1].num)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num2 > s[j + 1].num2)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num3 > s[j + 1].num3)
					{
						swap(s[j], s[j + 1]);
					}
					else if (s[j].num4 > s[j + 1].num4)
					{
						swap(s[j], s[j + 1]);
					}
				}
			}
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		cout << "do you want to delete something?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			int d, h = 0;;
			cout << " which?" << endl;
			cin >> d;
			zapis *tmp = new zapis[g - 1];
			for (size_t i = 0; i < g; i++)
			{
				if (i != d)
				{
					tmp[h] = s[i];
					h++;
				}
			}
			delete[] s;
			s = tmp;
			g = g - 1;
			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}

		cout << "do you want to add something?(1 for yes,0 for no)" << endl;
		cin >> l;
		if (l == 1)
		{
			int d;
			zapis *tmp = new zapis[g + 1];
			for (size_t i = 0; i < g; i++)
			{
				tmp[i] = s[i];
			}
			cin >> tmp[g].name;
			cin >> tmp[g].surname;
			cin >> n;
			cin >> n2;
			cin >> n3;
			cin >> n4;
			tmp[g].num = n;
			tmp[g].num2 = n2;
			tmp[g].num3 = n3;
			tmp[g].num4 = n4;
			delete[] s;
			s = tmp;
			g = g + 1;

			for (size_t i = 0; i < g; i++)
			{
				cout << s[i].name << " " << s[i].surname << " " << s[i].num << " " << s[i].num2 << " " << s[i].num3 << " " << s[i].num4 << endl;
			}
		}
		cout << "again?(1 for yes,0 for no)" << endl;
		cin >> t;
	}

}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int a, d;
	do
	{
		printf("Which task");
		scanf_s("%d", &d);
		switch (d)
		{

		case 1: task1(); break;

		default:
			break;
		}
		printf(" do you want continue y(1)/no(2)");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}