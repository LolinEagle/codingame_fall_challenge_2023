#include "SeaBedSecurity.hpp"

using namespace std;

int	main(void){
	SeaBedSecurity	sbs;
	
	sbs.print_all();
	// Game loop
	while (1){
		SeaBedSecurityLocal	sbsl;

		sbsl.print_all();
		sbsl.game();
	}
}
