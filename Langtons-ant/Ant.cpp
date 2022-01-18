#include <ncurses.h>
#include <stdlib.h>
#include <random>
#include <unistd.h>
#include "Ant.hpp"

// creating global board
bool board[100][100];

// funtions declartaion
auto random_int() -> int;
auto show_board(bool const&) -> void;
auto colision_detection_move(Ant, Ant) -> bool;
auto colision_detection_set(Ant, Ant, int) -> bool;
auto action(Ant& moving_ant, Ant const& ant_1, Ant const& ant_2) -> void;
auto instruction_set() -> void;
auto instruction_action() -> void;
auto my_border() -> void;


// Ant's methods implementation start
Ant::Ant(int x, int y, int co1, int co2)
	: OX{x}
	, OY{y}
    , color_1{co1}
    , color_2{co2}
{}

Ant::~Ant(){}

// Ant change its Direction deapending on bool
auto Ant::turn(bool const& space) -> void{
	if(space == true){
		if(direction == 0){
			direction = EAST;
		} else if(direction == 1){
			direction = SOUTH;
		} else if(direction == 2){
			direction = WEST;
		} else {
			direction = NORTH;
		}
	} else {
        if(direction == 0){
            direction = WEST;
        } else if(direction == 1){
            direction = NORTH;
        } else if(direction == 2){
            direction = EAST;
        } else {
            direction = SOUTH;
        }
	}
}

// Ant print arrow deapending on this Direction
auto Ant::print_arrow(Direction dir) const -> void{
	switch(dir){
		case Direction::NORTH:
			printw("^");
			break;
		case Direction::EAST:
			printw(">");
			break;
		case Direction::SOUTH:
			printw("v");
			break;
		case Direction::WEST:
			printw("<");
			break;
	}
}

// getting bool change color of printing Ant
auto Ant::show(bool const& space) const -> void{
    if (space == true){
        attron(COLOR_PAIR(color_2) | A_BOLD);
        this -> print_arrow(direction);
        attroff(COLOR_PAIR(color_2) | A_BOLD);
    } else {
        attron(COLOR_PAIR(color_1) | A_BOLD);
        this -> print_arrow(direction);
        attroff(COLOR_PAIR(color_1) | A_BOLD);
    }
}

// changing Ant's OX or OY value deapend on their Direction
auto Ant::move(Direction const& dir) -> void{
    switch(dir){
        case Direction::NORTH:
            OY--;
            if(OY < 0){
                OY += 100;
            }
            break;
        case Direction::EAST:
            OX++;
            if(OX > 99){
                OX -= 100;
            }
            break;
        case Direction::SOUTH:
            OY++;
            if(OY > 99){
                OY -= 100;
            }
            break;
        case Direction::WEST:
            OX--;
            if(OX < 0){
                OX += 100;
            }
            break;
    }
}

// changing Ant's OX or OY value depend on pressed key
auto Ant::set(int const& ch) -> void{
    if(ch == KEY_UP){
        --OY;
        if(OY<0){
            OY += 100;
        }
    } else if(ch == KEY_RIGHT){
        ++OX;
        if(OX>99){
            OX -= 100;
        }
    } else if(ch == KEY_DOWN){
        ++OY;
        if(OY>99){
            OY -= 100;
        }
    } else if(ch == KEY_LEFT){
        --OX;
        if(OX<0){
            OX += 100;
        }
    } else if(ch == 'R' || ch == 'r'){
        this -> turn(false);
    }
}

// change bool of one veriable in the board
auto Ant::change_full(bool &space) const -> void{
    if(space == false){
        space = true;
    } else {
        space = false;
    }
}
// Ant's methods implementation end


// MAIN start
auto main() -> int
{
    // assigning an initial value to table of bools
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            board[i][j] = false;
        }
    }

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    if(!has_colors()){
      printf("Terminal does not support color");
      endwin();
      return -1;
    }

    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_WHITE);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_WHITE);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_WHITE);

    auto x = random_int(); // variable to creat Ant that tells about the coordinate OX
    auto y = random_int(); // variable to creat Ant that tells about the coordinate OY

    int ch; // it stores information about a pressed key

    auto red_ant = Ant{x,y,1,2};

    // setting start position of red_ant
    do{
        clear();
        instruction_set();
        my_border();
        for(int i=0; i<100; i++){
            printw("#");
            for(int j=0; j<100; j++){
                if(red_ant.OX == j && red_ant.OY == i){
                    red_ant.show(board[j][i]);
                } else {
                    show_board(board[j][i]);
                }
            }
            printw("#\n");
        }
        my_border();
        refresh();
        ch = getch();
        red_ant.set(ch);
    }while(ch!=10);

    // generate new coordinates for green_ant
    do{
        x = random_int();
    }while(x == red_ant.OX);
    do{
        y = random_int();
    }while(y == red_ant.OY);

    auto green_ant = Ant{x,y,3,4};

    // setting start position of green_ant
    do{
        clear();
        instruction_set();
        my_border();
        for(int i=0; i<100; i++){
            printw("#");
            for(int j=0; j<100; j++){
                if(red_ant.OX == j && red_ant.OY == i){
                    red_ant.show(board[j][i]);
                } else if(green_ant.OX == j && green_ant.OY == i){
                    green_ant.show(board[j][i]);
                } else {
                    show_board(board[j][i]);
                }
            }
            printw("#\n");
        }
        my_border();
        refresh();
        ch = getch();
        if(colision_detection_set(green_ant, red_ant, ch)){
            green_ant.set(ch);
        }
    }while(ch!=10);

    // generate new coordinates for blue_ant
    do{
        x = random_int();
    }while(x == red_ant.OX || x == green_ant.OX);
    do{
        y = random_int();
    }while(y == red_ant.OY || y == green_ant.OY);

    auto blue_ant = Ant{x,y,5,6};

    //setting start position of blue_ant
    do{
        clear();
        instruction_set();
        my_border();
        for(int i=0; i<100; i++){
            printw("#");
            for(int j=0; j<100; j++){
                if(red_ant.OX == j && red_ant.OY == i){
                    red_ant.show(board[j][i]);
                } else if(green_ant.OX == j && green_ant.OY == i){
                    green_ant.show(board[j][i]);
                } else if(blue_ant.OX == j && blue_ant.OY == i){
                    blue_ant.show(board[j][i]);
                } else {
                    show_board(board[j][i]);
                }
            }
            printw("#\n");
        }
        my_border();
        refresh();
        ch = getch();
        if(colision_detection_set(blue_ant, red_ant, ch) && colision_detection_set(blue_ant, green_ant, ch)){
            blue_ant.set(ch);
        }
    }while(ch!=10);


    nodelay(stdscr, TRUE);
    unsigned int speed = 500000; // delay between runs of while loop
    int round = 0; // information aobut Ant ture

    while(true){
        clear();
        instruction_action();
        my_border();
        if(round == 0){
            action(red_ant, green_ant, blue_ant);
            round = 1;
        } else if(round == 1){
            action(red_ant, green_ant, blue_ant);
            round = 2;
        } else if(round == 2){
            action(green_ant, red_ant, blue_ant);
            round = 3;
        } else if(round ==3){
            action(green_ant, red_ant, blue_ant);
            round = 4;
        } else if(round ==4){
            action(blue_ant, red_ant, green_ant);
            round = 5;
        } else if(round ==5){
            action(blue_ant, red_ant, green_ant);
            round = 0;
        }
        my_border();
        refresh();

        ch = getch();
        if(ch == KEY_UP){
            speed /= 2;
        } else if(ch == KEY_DOWN){
            speed *= 2;
        }
        usleep(speed);
    }

    getch();
    endwin();

    return 0;
}
// MAIN end

// functions implementation start
// generate random integer
auto random_int() -> int{
    std::random_device rd;
    std::uniform_int_distribution<int> d100(0,99);
    auto number = d100(rd);
    return number;
}

// drawing the board
auto show_board(bool const& b) -> void{
    if(b == true){
        attron(COLOR_PAIR(2));
        printw(" ");
        attroff(COLOR_PAIR(2));;
    } else {
        attron(COLOR_PAIR(1));
        printw(" ");
        attroff(COLOR_PAIR(1));
    }
}

// inform about possibility of Ant's move
auto colision_detection_move(Ant ant_1, Ant ant_2) -> bool{
    ant_1.move(ant_1.direction);
    if(ant_1.OX == ant_2.OX && ant_1.OY == ant_2.OY){
        return false;
    } else {
        return true;
    }
}

// inform about pssibility of Ant's set
auto colision_detection_set(Ant ant_1, Ant ant_2, int ch) -> bool{
    ant_1.set(ch);
    if(ant_1.OX == ant_2.OX && ant_1.OY == ant_2.OY){
        return false;
    } else {
        return true;
    }
}

// call all Ant's behaviors by referring to the remaining functions and methods
auto action(Ant& moving_ant, Ant const& ant_1, Ant const& ant_2) -> void{
    moving_ant.moved = false;
    for(int i=0; i<100; i++){
        printw("#");
        for(int j=0; j<100; j++){
            if(moving_ant.OX == j && moving_ant.OY == i && moving_ant.moved == false){
                if(moving_ant.turned == false){
                    moving_ant.show(board[j][i]);
                    moving_ant.turn(board[j][i]);
                    moving_ant.moved = true;
                    moving_ant.turned = true;
                } else {
                    moving_ant.show(board[j][i]);
                    if(colision_detection_move(moving_ant, ant_1) && colision_detection_move(moving_ant, ant_2)){
                        moving_ant.move(moving_ant.direction);
                    }
                    moving_ant.change_full(board[j][i]);
                    moving_ant.moved = true;
                    moving_ant.turned = false;
                }
            } else if(ant_1.OX == j && ant_1.OY == i){
                ant_1.show(board[j][i]);
            } else if(ant_2.OX == j && ant_2.OY == i){
                ant_2.show(board[j][i]);
            } else {
                show_board(board[j][i]);
            }
        }
    printw("#\n");
    }
}

auto instruction_set() -> void{
    printw("Instruction:\n");
    printw("press KEY_ARROW to change ant's position\n");
    printw("press KEY_R to turn ant left\n");
    printw("press KEY_ENTER to accept ant's position\n");
}

auto instruction_action() -> void{
    printw("Instruction:\n");
    printw("press KEY_UP to speed up program twice\n");
    printw("press KEY_DOWN to slow down program twice\n");
    printw("press CTRL+C to close program\n");
}

// draw upper/buttom border of board
auto my_border() -> void{
    for(int i=0; i<102; i++){
        printw("#");
    }
    printw("\n");
}
// functions implementation end
