#include "header.hpp"

using namespace std;

class SeaBedSecurity{
	private:
		int					_round;				// Number of rounds
		int					_target_type;		// Target type (3 = save mode)
		int					_creature_count;	// Number of creatures
		vector<creature>	_creature;			// List of all creatures
	public:
		SeaBedSecurity(void);
		~SeaBedSecurity();

		void		print(void);
		void		incrementRound(void);
		void		incrementTargetType(void);

		// Getters & setters
		int			&getRound(void);
		int			&getTargetType(void);
		creature	&getCreature(int creature_id);
};

class SeaBedSecurityLocal{
	private:
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
		drone						_my_drone[2];				// My list of drones
		int							_foe_drone_count;			// Foe number of drones (should be 2)
		drone						_foe_drone[2];				// Foe list of drones

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

		void	print(void);
		bool	isDroneScan(int creature_id);
		void	moveUp(int &i);
		void	moveTL(int &i);
		void	moveTR(int &i);
		void	moveBR(int &i);
		void	moveBL(int &i);
		void	game(SeaBedSecurity &sbs);
};
