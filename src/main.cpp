#include "SeaBedSecurity.hpp"

using namespace std;

int	main(void){
	SeaBedSecurity	sbs;

	while (1){
		SeaBedSecurityLocal	sbsl;

		sbsl.game(sbs);
		sbs.increment_round();
	}
}
