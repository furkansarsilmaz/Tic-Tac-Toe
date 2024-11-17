#include <iostream>
#include <ctime>
void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout<<"|" << " " << " " << spaces[0] << " " << " " << "|";
    std::cout<< " " << " " << spaces[1] << " " << " " << "|";
    std::cout<< " " << " " << spaces[2] << " " << " " << "|" << '\n';
    std::cout<<"|" << " " << " " << spaces[3] << " " << " " << "|";
    std::cout << " " << " " << spaces[4] << " " << " " << "|";
    std::cout << " " << " " << spaces[5] << " " << " " << "|" << '\n';
    std::cout<<"|" << " " << " " << spaces[6] << " " << " " << "|";
    std::cout << " " << " " << spaces[7] << " " << " " << "|";
    std::cout << " " << " " << spaces[8] << " " << " " << "|" << std::endl;
}

void playerChoice(char *spaces,int &choice){
    std::cout << "Where you want to play : " ;
    std::cin >> choice ;
    while (spaces[choice] != ' '){
        std::cout << "Where you want to play : " ;
        std::cin >> choice ;        
    }
    spaces[choice] = 'X';
    drawBoard(spaces);
}

bool checkWin(char *spaces, char symbol){
    // columns
    if( 
        (spaces[0] == symbol && spaces[3] == symbol && spaces[6] == symbol)||
        (spaces[1] == symbol && spaces[4] == symbol && spaces[7] == symbol)||
        (spaces[2] == symbol && spaces[5] == symbol && spaces[8] == symbol)
    ){return true;}

    // rows
    if(
        ( spaces[0] == symbol && spaces[1] == symbol && spaces[2] == symbol ) ||
        ( spaces[3] == symbol && spaces[4] == symbol && spaces[5] == symbol ) ||
        ( spaces[6] == symbol && spaces[7] == symbol && spaces[8] == symbol )
    ){return true;}

    // cross
    if(
        ( spaces[0] == symbol && spaces[4] == symbol && spaces[8] == symbol ) ||
        ( spaces[2] == symbol && spaces[4] == symbol && spaces[6] == symbol ) 
    ){return true;}
    else{
        return false;
    }    
}

void botChoice(char *spaces){
    int num;

    do{
        num = rand() % 9 ;
    }while (spaces[num] != ' ');
    
    spaces[num] = 'O';
    std::cout << "bot played to : " << num ;
}

bool checkDraw(char *spaces){
    for(int i = 0 ; i < 9 ; i++){
        if(spaces[i] == ' '){
            return false ;
        }
    }
    return true ;

}

int main(){
    srand(time(NULL));
    int choice ;
    bool game = true ;
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '} ;
    
    while (game){
        playerChoice(spaces,choice);
        drawBoard(spaces);
        if(checkWin(spaces,'X')){
            std::cout << "You Win!!";
            game = false ;
        }
        if(checkDraw(spaces)){
            std::cout << "Its draw !!" ;
            break;
        }


        botChoice(spaces);
        drawBoard(spaces);
        if(checkWin(spaces,'O')){
            std::cout << "You lose..";
            game = false ;
        }

        if(checkDraw(spaces)){
            std::cout << "Its draw !!" ;
            break;
        }


    }
    return 0 ;
}