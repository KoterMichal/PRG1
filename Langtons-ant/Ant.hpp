#ifndef Mrowki_hpp
#define Mrowki_hpp

#include <stdlib.h>

enum Direction {NORTH,EAST,SOUTH,WEST};


struct Ant{
	int OX;
	int OY;
	Direction direction{Direction::NORTH};
    bool moved{false};
    bool turned{false};
    int const color_1;
    int const color_2;

	Ant(int, int, int const, int const);
    ~Ant();

	auto turn(bool const&) -> void;
	auto print_arrow(Direction) const -> void;
    auto show(bool const&) const -> void;
	auto move(Direction const&) -> void;
    auto set(int const&) -> void;
	auto change_full(bool&) const -> void;
};

#endif
