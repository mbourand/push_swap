#include <unordered_set>
#include <fstream>

int main()
{
	int test_nb = 1;

	for (int i = 0; i < test_nb; i++)
	{
		std::unordered_set<int> numbers;
		for (int j = 0; j < 10; j++)
			numbers.insert(rand() % 10000);
		std::fstream file(std::string("test_" + std::to_string(i)), std::fstream::out | std::fstream::trunc);
		if (file.is_open())
		{
			for (int nb : numbers)
				file << nb << " ";
			file << '\n';
			file.flush();
			file.close();
		}
	}
}
