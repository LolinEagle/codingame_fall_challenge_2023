#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

struct	creature{
	int	creature_id;
	int	color;
	int	type;
};

struct	drone{
	int	drone_id;
	int	drone_x;
	int	drone_y;
	int	emergency;
	int	battery;
};

struct	drone_scan{
	int	drone_id;
	int	creature_id;
};

struct	visible_creature{
	int	creature_id;
	int	creature_x;
	int	creature_y;
	int	creature_vx;
	int	creature_vy;
};

struct	radar_blip{
	int		drone_id;
	int		creature_id;
	string	radar;
};
