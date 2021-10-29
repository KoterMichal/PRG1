#include <iostream>

auto main(int argc, char* argv[]) -> int
{
    if(argv[1][0] == '-'){

        if(argv[2][0] == '-'){
            if((argv[1][1] == 'r' && argv[2][1] == 'l') || (argv[1][1] == 'l' && argv[2][1] == 'r')){
                for(int i = argc - 1; i > 0; i--){
                    std::cout << argv[i] << "\n";
                }
            }
            else if((argv[1][1] == 'r' && argv[2][1] == 'n') || (argv[1][1] == 'n' && argv[2][1] == 'r')){
                for(int i = argc - 1; i > 0; i--){
                    std::cout << argv[i] << " ";
                }
            }
            return 0;
        }

        if(argv[1][1] == 'n'){
            for(int i=1; i < argc; i++){
                std::cout << argv[i] << " ";
            }
        } else if(argv[1][1] == 'r'){
            for(int i=argc - 1; i > 0; i--){
                std::cout << argv[i] << " ";
            }
            std::cout << "\n";
        } else if(argv[1][1] == 'l'){
            for(int i=1; i < argc; i++){
                std::cout << argv[i] << "\n";
            }
        }
    }

    return 0;
}
