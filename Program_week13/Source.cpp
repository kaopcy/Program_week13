#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void get_string(char* name);
void get_reverse(char name[], int lenght);
void print(char* name);
void pyramid(int lenght, char* name);
void printalpha(int lenght, char* name);
void printvowel_consonent(char* name);

int main()
{
	int lenght = 0;
	char name[100];
	get_string(name);
	lenght = strlen(name);
	get_reverse(name, lenght);
	print(name);
	cout << endl;
	pyramid(lenght, name);
	cout << endl;
	printalpha(lenght, name);
	cout << endl;
	printvowel_consonent(name);
	
	return 0;
}
void get_string(char* name)
{
	printf("Input a string : ");
SORT:cin.getline(name, 500);
	for (int i = 0; i < strlen(name); i++)
	{
		if (!(name[i] >= 48 and name[i] <= 57) and !(name[i] >= 65 and name[i] <= 90) and !(name[i] >= 97 and name[i] <= 122))
		{
			printf("\nnot right type \n");
			printf("Try again : ");
			goto SORT;
		}
		else if (name[i] == ' ')
		{
			printf("\nnot right type \n");
			printf("Try again : ");
			goto SORT;
		}
	}
}
void get_reverse(char names[], int lenght)
{
	int counter = 0;
	int i = 0;
	char temp = 0;

	lenght = lenght - 1;
	char* ptr = &names[0];

	for (i = 0; i <= lenght; i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[lenght];
		ptr[lenght] = temp;
		lenght--;
	}
}
void print(char* name)
{
	printf("Reverse of a string is %s", name);
}

void pyramid(int lenght, char* name)
{
	for (int i = lenght; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << name[j - 1] << " ";
		}
		cout << endl;
	}
}

void printalpha(int lenght, char* name)
{
	int i, tmp;
	i = 0;
	do
	{
		if (i < lenght - 1 && name[i] > name[i + 1])
		{
			tmp = name[i + 1];
			name[i + 1] = name[i];
			name[i] = tmp;
			i = 0;
		}
		else
		{
			i++;
		}

	} while (i < lenght);


	printf("Ascending order : ");
	for (i = 0; i < lenght; i++)
	{
		printf("%c", name[i]);
	}
}

void printvowel_consonent(char* name)
{
	int vowels, consonants;
	vowels = consonants = 0;

	for (int i = 0; name[i] != '\0'; ++i)
	{
		if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' ||
			name[i] == 'o' || name[i] == 'u' || name[i] == 'A' ||
			name[i] == 'E' || name[i] == 'I' || name[i] == 'O' ||
			name[i] == 'U')
		{
			++vowels;
		}
		else if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
		{
			++consonants;
		}

	}

	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
}
