#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{
private:
	typedef struct s_func
	{
		std::string	level;
		void (Karen::*ptr)(void);
	}	t_func;

	t_func func[4];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	void init(void);
public:
	Karen();
	~Karen();
	void complain(std::string level);
};

#endif
