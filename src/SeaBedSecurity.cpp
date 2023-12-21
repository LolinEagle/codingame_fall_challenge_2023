#include "SeaBedSecurity.hpp"

using namespace std;

SeaBedSecurity::SeaBedSecurity(void){
	_round = 0;
	cin >> _creature_count; cin.ignore();
	for (int i = 0; i < _creature_count; i++){
		creature	c;
		cin >> c.creature_id >> c.color >> c.type; cin.ignore();
		_creature.push_back(c);
	}
};

SeaBedSecurity::~SeaBedSecurity(){
};

void	SeaBedSecurity::print_all(void){
	cerr << "_round=" << _round << endl;
	cerr << "_creature_count=" << _creature_count << endl;
	for (int i = 0; i < _creature_count; i++){
		cerr << "_creature[" << i << "] creature_id=" << _creature[i].creature_id << " color=" << _creature[i].color << " type=" << _creature[i].type << endl;
	}
}

SeaBedSecurityLocal::SeaBedSecurityLocal(void){
	// Score
	cin >> _my_score; cin.ignore();
	cin >> _foe_score; cin.ignore();

	// Scan count
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

	// Drone count
	cin >> _my_drone_count; cin.ignore();
	for (int i = 0; i < _my_drone_count; i++){
		drone	d;
		cin >> d.drone_id >> d.drone_x >> d.drone_y >> d.emergency >> d.battery; cin.ignore();
		_my_drone.push_back(d);
	}
	cin >> _foe_drone_count; cin.ignore();
	for (int i = 0; i < _foe_drone_count; i++){
		drone	d;
		cin >> d.drone_id >> d.drone_x >> d.drone_y >> d.emergency >> d.battery; cin.ignore();
		_foe_drone.push_back(d);
	}

	// Drone scan count
	cin >> _drone_scan_count; cin.ignore();
	for (int i = 0; i < _drone_scan_count; i++){
		drone_scan	ds;
		cin >> ds.drone_id >> ds.creature_id; cin.ignore();
		_drone_scan.push_back(ds);
	}

	// Visible creature count
	cin >> _visible_creature_count; cin.ignore();
	for (int i = 0; i < _visible_creature_count; i++){
		visible_creature	vc;
		cin >> vc.creature_id >> vc.creature_x >> vc.creature_y >> vc.creature_vx >> vc.creature_vy; cin.ignore();
		_visible_creature.push_back(vc);
	}

	// Radar blip count
	cin >> _radar_blip_count; cin.ignore();
	for (int i = 0; i < _radar_blip_count; i++){
		radar_blip	rb;
		cin >> rb.drone_id >> rb.creature_id >> rb.radar; cin.ignore();
		_radar_blip.push_back(rb);
	}
}

SeaBedSecurityLocal::~SeaBedSecurityLocal(){
};

void	SeaBedSecurityLocal::print_all(void){
	// Score
	cerr << "_my_score=" << _my_score << endl;
	cerr << "_foe_score=" << _foe_score << endl;

	// Drone count
	cerr << "_my_scan_count=" << _my_scan_count << endl;
	for (int i = 0; i < _my_scan_count; i++){
		cerr << "_my_scan[" << i << "]=" << _my_scan[i] << endl;
	}
	cerr << "_foe_scan_count=" << _foe_scan_count << endl;
	for (int i = 0; i < _foe_scan_count; i++){
		cerr << "_foe_scan[" << i << "]=" << _foe_scan[i] << endl;
	}

	// Drone scan count
}

void	SeaBedSecurityLocal::game(void){
	for (int i = 0; i < 2; i++){
		cout << "WAIT 1 I am stupid" << endl; // MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
	}
}
