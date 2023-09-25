#include <vector>
#include <string>
#include <iostream>

int main()
{
	int Q;
	std::cin >> Q;

	std::vector<int> user_to_page(100001);
	std::vector<int> page_to_user(1001);

	for (int i = 0; i <= Q; ++i)
	{
		std::string querty;
		int num_user;

		std::cin >> querty >> num_user;		

		if (querty[0] == 'R')
		{
			int page;
			int after_page = 1;
			std::cin >> page;
			if (user_to_page[num_user] != 0)
			{
				after_page = user_to_page[num_user] + 1;
			}
			user_to_page[num_user] = page;
			for (int j = after_page; j <= page; ++j)
			{
				++page_to_user[j];
			}
		}
		else if (querty[0] == 'C')
		{
			if (user_to_page[num_user] == 0)
			{
				std::cout << 0 << std::endl;
			}
			else if(page_to_user[user_to_page[num_user]] == 1)
			{
				std::cout << 1 << std::endl;
			}
			else
			{
				std::cout << ((page_to_user[1]) - (page_to_user[user_to_page[num_user]])) * 1.0 / (page_to_user[1] - 1) << std::endl;
			}
		}
		else
		{
			continue;
		}
	}
}
