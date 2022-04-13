#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string		linein;
	std::string		s1;
	std::string		s2;
	std::ifstream	fin;
	std::ofstream	fout;
	std::string		filename;

	if (ac != 4)
	{
		std::cout << "Need 3 parameters for correct work of this program: <filename> s1 s2" << std::endl;
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	fin.open(av[1], std::ios_base::in);
	if (!fin.is_open())
	{
		std::cout << "Cannot open the file. The program is closed." << std::endl;
		return (2);
	}
	filename.append(av[1]).append(".replace");
	fout.open(filename, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open())
	{
		std::cout << "Cannot open or create the replacefile. The program is closed." << std::endl;
		fin.close();
		return (3);
	}
	size_t	i = 0;
	bool	flag;
	while (std::getline(fin, linein))
	{
		flag = true;
		i = 0;
		while (flag)
		{
			if ((i = linein.find(s1)) < linein.length())
			{
				fout << linein.substr(0, i);
				fout << s2;
				i += s1.length();
				linein = linein.substr(i);
			}
			else
			{
				fout << linein;
				flag = false;
			}
		}
		fout << std::endl;
	}
	fin.close();
	fout.close();
}
