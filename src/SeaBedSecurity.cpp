#include "SeaBedSecurity.hpp"

using namespace std;

int	sqr(int x){
	return (x * x);
}

double	find_dist(int x1, int y1, int x2, int y2){
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}

SeaBedSecurity::SeaBedSecurity(void){
	_round = 0;
	_target_type = 0;
	cin >> _creature_count; cin.ignore();
	for (int i = 0; i < _creature_count; i++){
		creature	c;
		cin >> c.creature_id >> c.color >> c.type; cin.ignore();
		_creature.push_back(c);
	}
};

SeaBedSecurity::~SeaBedSecurity(){
};

void		SeaBedSecurity::print(void){
	cerr << "_round=" << _round << endl;
	cerr << "_creature_count=" << _creature_count << endl;
	for (int i = 0; i < _creature_count; i++)
		cerr << "_creature[" << i << "] creature_id=" << _creature[i].creature_id << " color=" << _creature[i].color << " type=" << _creature[i].type << endl;
}

void		SeaBedSecurity::incrementRound(void){
	_round++;
}

void		SeaBedSecurity::incrementTargetType(void){
	_target_type++;
}

int			&SeaBedSecurity::getRound(void){
	return (_round);
}

int			&SeaBedSecurity::getTargetType(void){
	return (_target_type);
}

creature	&SeaBedSecurity::getCreature(int creature_id){
	int	i;

	for (i = 0; i < _creature_count - 1; i++){
		if (_creature[i].creature_id == creature_id)
			return (_creature[i]);
	}
	return (_creature[i]);
}

SeaBedSecurityLocal::SeaBedSecurityLocal(void){
	// Score
	cin >> _my_score; cin.ignore();
	cin >> _foe_score; cin.ignore();

	// Scan
	cin >> _my_scan_count; cin.ignore();
	for (int i = 0; i < _my_scan_count; i++){
		int creature_id;
		cin >> creature_id; cin.ignore();
		_my_scan.push_back(creature_id);
	}
	cin >> _foe_scan_count; cin.ignore();
	for (int i = 0; i < _foe_scan_count; i++){
		int creature_id;
		cin >> creature_id; cin.ignore();
		_foe_scan.push_back(creature_id);
	}

	// Drone
	cin >> _my_drone_count; cin.ignore();
	for (int i = 0; i < _my_drone_count; i++){
		drone	d;
		cin >> d.drone_id >> d.drone_x >> d.drone_y >> d.emergency >> d.battery; cin.ignore();
		(d.drone_x < 5000) ? _my_drone[0] = d : _my_drone[1] = d;
	}
	cin >> _foe_drone_count; cin.ignore();
	for (int i = 0; i < _foe_drone_count; i++){
		drone	d;
		cin >> d.drone_id >> d.drone_x >> d.drone_y >> d.emergency >> d.battery; cin.ignore();
		(d.drone_x < 5000) ? _foe_drone[0] = d : _foe_drone[1] = d;
	}

	// Drone scan
	cin >> _drone_scan_count; cin.ignore();
	for (int i = 0; i < _drone_scan_count; i++){
		drone_scan	ds;
		cin >> ds.drone_id >> ds.creature_id; cin.ignore();
		_drone_scan.push_back(ds);
	}

	// Visible creature
	cin >> _visible_creature_count; cin.ignore();
	for (int i = 0; i < _visible_creature_count; i++){
		visible_creature	vc;
		cin >> vc.creature_id >> vc.creature_x >> vc.creature_y >> vc.creature_vx >> vc.creature_vy; cin.ignore();
		_visible_creature.push_back(vc);
	}

	// Radar blip
	cin >> _radar_blip_count; cin.ignore();
	for (int i = 0; i < _radar_blip_count; i++){
		radar_blip	rb;
		cin >> rb.drone_id >> rb.creature_id >> rb.radar; cin.ignore();
		_radar_blip.push_back(rb);
	}
}

SeaBedSecurityLocal::~SeaBedSecurityLocal(){
};

void	SeaBedSecurityLocal::print(void){
	int	i;

	// Score
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_my_score=" << _my_score << endl;
	cerr << "_foe_score=" << _foe_score << endl;

	// Scan
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_my_scan_count=" << _my_scan_count << endl;
	for (i = 0; i < _my_scan_count; i++)
		cerr << "_my_scan[" << i << "] creature_id=" << _my_scan[i] << endl;
	cerr << "_foe_scan_count=" << _foe_scan_count << endl;
	for (i = 0; i < _foe_scan_count; i++)
		cerr << "_foe_scan[" << i << "] creature_id=" << _my_scan[i] << endl;

	// Drone
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_my_drone_count=" << _my_drone_count << endl;
	for (i = 0; i < _my_drone_count; i++)
		cerr << "_my_drone[" << i << "] drone_id=" << _my_drone[i].drone_id << " drone_x=" << _my_drone[i].drone_x << " drone_y=" << _my_drone[i].drone_y << " emergency=" << _my_drone[i].emergency << " battery=" << _my_drone[i].battery << endl;
	cerr << "_foe_drone_count=" << _foe_drone_count << endl;
	for (i = 0; i < _foe_drone_count; i++)
		cerr << "_foe_drone[" << i << "] drone_id=" << _foe_drone[i].drone_id << " drone_x=" << _foe_drone[i].drone_x << " drone_y=" << _foe_drone[i].drone_y << " emergency=" << _foe_drone[i].emergency << " battery=" << _foe_drone[i].battery << endl;

	// Drone scan
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_drone_scan_count=" << _drone_scan_count << endl;
	for (i = 0; i < _drone_scan_count; i++)
		cerr << "_drone_scan[" << i << "] drone_id=" << _drone_scan[i].drone_id << " creature_id=" << _drone_scan[i].creature_id << endl;

	// Visible creature
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_visible_creature_count=" << _visible_creature_count << endl;
	for (i = 0; i < _visible_creature_count; i++)
		cerr << "_visible_creature[" << i << "] creature_id" << _visible_creature[i].creature_id << " creature_x" << _visible_creature[i].creature_x << " creature_y" << _visible_creature[i].creature_y << " creature_vx" << _visible_creature[i].creature_vx << " creature_vy" << _visible_creature[i].creature_vy << endl;

	// Radar blip
	cerr << "---------------------------------------------------------" << endl;
	cerr << "_radar_blip_count=" << _radar_blip_count << endl;
	for (i = 0; i < _radar_blip_count; i++)
		cerr << "_radar_blip[" << i << "] drone_id=" << _radar_blip[i].drone_id << " creature_id=" << _radar_blip[i].creature_id << " radar=" << _radar_blip[i].radar << endl;
}

bool	SeaBedSecurityLocal::isDroneScan(int creature_id){
	for (int i = 0; i < _drone_scan_count; i++){
		if (_drone_scan[i].creature_id == creature_id)
			return (true);
	}
	return (false);
}

void	SeaBedSecurityLocal::moveUp(int &i){
	cout << "MOVE " << _my_drone[i].drone_x << " " << _my_drone[i].drone_y - 600 << " 1" << endl;
}

void	SeaBedSecurityLocal::moveTL(int &i){
	cout << "MOVE " << _my_drone[i].drone_x - 600 << " " << _my_drone[i].drone_y - 600 << " 1" << endl;
}

void	SeaBedSecurityLocal::moveTR(int &i){
	cout << "MOVE " << _my_drone[i].drone_x + 600 << " " << _my_drone[i].drone_y - 600 << " 1" << endl;
}

void	SeaBedSecurityLocal::moveBR(int &i){
	cout << "MOVE " << _my_drone[i].drone_x - 600 << " " << _my_drone[i].drone_y + 600 << " 1" << endl;
}

void	SeaBedSecurityLocal::moveBL(int &i){
	cout << "MOVE " << _my_drone[i].drone_x + 600 << " " << _my_drone[i].drone_y + 600 << " 1" << endl;
}

void	SeaBedSecurityLocal::game(SeaBedSecurity &sbs){
	int					i;		// For my drone
	int					j;		// For radar blip
	char				lr;		// Character for drone
	bool				move;	// Have move this round
	vector<radar_blip>	target;	// Drone target

	for (i = 0, move = false; i < 2; i++){
		// Look for every radar blip
		for (j = 0; j < _radar_blip_count; j++){
			if (_radar_blip[j].drone_id == _my_drone[i].drone_id){
				creature	c = sbs.getCreature(_radar_blip[j].creature_id);
				if (c.type == sbs.getTargetType() && !isDroneScan(_radar_blip[j].creature_id))
					target.push_back(_radar_blip[j]);
			}
		}

		// If no target founded
		if (target.empty()){
			moveUp(i);
			continue;
		}

		// Look for fish in border
		lr = (i == 0) ? 'L' : 'R';
		for (unsigned long l = 0; l < target.size(); l++){
			if (target[l].radar[1] == lr){
				if (lr == 'L')
					(_my_drone[i].drone_y < 3750 + (2500 * sbs.getTargetType())) ? moveBR(i) : moveTR(i);
				else
					(_my_drone[i].drone_y < 3750 + (2500 * sbs.getTargetType())) ? moveBL(i) : moveTL(i);
				move = true;
				break;
			}
		}

		// If no fish in border
		if (move == false){
			if (lr == 'L')
				(_my_drone[i].drone_y < 3750 + (2500 * sbs.getTargetType())) ? moveBL(i) : moveTL(i);
			else
				(_my_drone[i].drone_y < 3750 + (2500 * sbs.getTargetType())) ? moveBR(i) : moveTR(i);
			move = true;
		}

		// Clear target list
		target.clear();
	}
}
