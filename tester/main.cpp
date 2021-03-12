#include <bits/stdc++.h>

int main()
{
	int test_nb = 50;

	for (int i = 0; i < test_nb; i++)
	{
		std::string numbers;
		for (int j = 0; j < 5000; j++)
			numbers += std::to_string((rand()) * (rand() % 2 ? -1 : 1)) + " ";
		numbers.erase(numbers.end() - 1);
		std::string command = "ARG=\"" + numbers + "\" ; ./push_swap $ARG | wc -l";
		system(command.c_str());
	}
}
