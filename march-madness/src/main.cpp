#include "Simulator.h"

int main(int argc, char *argv[])
{
	int home_field_advantage = std::stoi(argv[1]);
	bool apply_scaling = argv[2];
    run(home_field_advantage,apply_scaling);
}
