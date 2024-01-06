#include "header.hpp"

using namespace std;

class SeaBedSecurity{
	private:
		int					_round;				// Number of rounds
		int					_target_type;		// Target type (3 = save mode)
		int					_creature_count;	// Number of creatures
		vector<creature>	_creature;			// List of all creatures
		bool				_go_down;			// Should the drones go down ?
		int					_pity;				// Pity for the fishs
	public:
		SeaBedSecurity(void);
		~SeaBedSecurity();

		void		incrementRound(void);
		void		incrementTargetType(void);
		void		decrementTargetType(void);

		// Getters & setters
		int			&getRound(void);
		int			&getTargetType(void);
		creature	&getCreature(int creature_id);
		bool		&getGoDown(void);
		int			&getPity(void);
		void		setTargetType(int target_type);
		void		setGoDown(bool go_down);
		void		setPity(int pity);
};

class SeaBedSecurityLocal{
	private:
		bool						_light;						// Should light be on

		// Score
		int							_my_score;					// My score
		int							_foe_score;					// Foe score
		
		// Scan
		int 						_my_scan_count;				// My number of scans saved
		vector<int>					_my_scan;					// My list of scans saved
		int							_foe_scan_count;			// Foe number of scans saved
		vector<int>					_foe_scan;					// Foe list of scans saved

		// Drone
		int 						_my_drone_count;			// My number of drones (should be 2)
		drone						_my_drone[2];				// My list of drones (0 = left 1 = right)
		int							_foe_drone_count;			// Foe number of drones (should be 2)
		drone						_foe_drone[2];				// Foe list of drones (0 = left 1 = right)

		// Drone scan
		int 						_drone_scan_count;			// Number of unsaved scans.
		vector<drone_scan>			_drone_scan;				// List if unsaved scans.

		// Visible creature
		int							_visible_creature_count;	// Number of visible creatures
		vector<visible_creature>	_visible_creature;			// List of visible creatures

		// Radar blip
		int							_radar_blip_count;			// Number of Radar blip
		vector<radar_blip>			_radar_blip;				// List of Radar blip
	public:
		SeaBedSecurityLocal(void);
		~SeaBedSecurityLocal();

		bool	isDroneScan(int creature_id);
		void	moveXY(int &i, int angle, vector<visible_creature> &monster);
		void	game(SeaBedSecurity &sbs);
};
