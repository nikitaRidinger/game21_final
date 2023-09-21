#include <iostream>
#include <cstdlib> 
#include <vector>
#include <string>
#include <map>
#include <unistd.h> //отвечае
#include<time.h> 


#include <iostream>
using namespace std;

struct literra
{
    string y_win = "player WIN!";
    string y_lose = "player LOSE!";
    string num_y = "your number is";
    string summ_y = "your summ is";
    string num_p1= "player 1 number is";
    string num_p2= "player 2 number is";
    string num_comp= "computer number is";
    string summ_p1= "player 1 summ is";
    string summ_p2= "player 2 summ is";
    string summ_comp= "computer summ is";
    string next_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string next_step = "next step";
    string c_win = "Computer WIN!";
    string c_lose = "Computer LOSE!";
    string player1 = "player1";
    string player2 = "player2";
    string computer = "computer";
    string check_player = "Would you like to play with player 2 or computer?\n'p' for player 2 or 'c' for computer";
    string stop_game = "STOP THIS GAME!!!";

};
int gen_chislo();//генерация числа
void push_in_vector(vector<int> & vec, int num);//отправка значений в векторы 
void summ_number_in_vector(vector<int> & vec, int & num);//суммирование чисел в векторе
void game_player(int num_player);//игрок
void print(string pr_str);//вывод информации из структуры literr
void print(string pr_str,int num);//вывод информации из структуры literr
void game_comp();//функционал компьютера
void check_game();//проверяет число
void print(int num_player,string pr_str);//вывод информации из структуры literr
void compare_numbers(string num1, string num2);//компиляция чисел
void check_num(int & summ, int num_player);//проверка чисел и номера игрока
bool check_game_p(int & summ); //проверяет сумму и управляет циклом
pair<bool, char> check_num_comp(int & summ);//пара числа и символа
pair<bool,string> check_vybor(char vybor);
vector<int> number_player1;//числа которые были сгенерированны попадают сюда для 1 игрока
vector<int> number_player2;//числа которые были сгенерированны попадают сюда для 2 игрока
vector<int> number_comp;//числа которые были сгенерированны попадают сюда для компьютера
int summ_player1;//создание переменной суммы числел 1 игрока
int summ_player2;//создание переменной суммы числел 2 игрока
int summ_comp;//создание переменной суммы числа компьютера
literra pr_str;//для вызова структуры литер


int main()
{
    srand((unsigned) time(NULL));//помогает рандому задействовать системное время
    game_player(1);
    return 0;
}
//#########################################################################################################################################################################################
void game_player(int num_player)
{  
    int gen_num = 0;
    char vybor;
    bool start_stop_game = true;
    bool next_game = true;
    pair<bool,string> check;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        if(num_player == 1)
        {
            push_in_vector(number_player1,gen_num);
            print(pr_str.num_p1,gen_num);
        }
        else if(num_player == 2)
        {
            push_in_vector(number_player2,gen_num);
            print(pr_str.num_p2,gen_num);
        }
        
        if(num_player == 1)
        {
            summ_number_in_vector(number_player1,summ_player1);
            print(pr_str.summ_p1,summ_player1);
            next_game = check_game_p(summ_player1);
        }
        else if(num_player == 2)
        {
            summ_number_in_vector(number_player2,summ_player2);
            print(pr_str.summ_p2,summ_player2);
            next_game = check_game_p(summ_player2);
        }
        if(next_game)
        {
            do
            {
                print(pr_str.next_or_stop);
                cin >> vybor;
                check = check_vybor(vybor);
                start_stop_game = check.first;
            }while(check.second == "error");
        }
        else
        {
            start_stop_game = false;
        }
        
    }
    if(num_player == 1)
    {
        check_num(summ_player1, num_player);
    }
    else if(num_player == 2)
    {
        check_num(summ_player2, num_player);
    }
    
}

//#########################################################################################################################################################################################
//[GAME_PLAYER]
bool check_game_p(int & summ)
{
    if(summ == 21)
    {
        return false;
    }
    else if(summ > 21)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//#########################################################################################################################################################################################
//[GAME_COMP]
void game_comp()
{
    int gen_num;
    bool start_stop_game = true;
    pair<bool, char> choose;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        push_in_vector(number_comp,gen_num);
        print(pr_str.num_comp,gen_num);
        summ_number_in_vector(number_comp,summ_comp);
        print(pr_str.summ_comp,summ_comp);
        choose = check_num_comp(summ_comp);
        start_stop_game = choose.first;
        if(choose.second == 'n')
        {
            print(pr_str.next_step);
        }
        usleep(1000 * 1000);
    }
    if(choose.second == 'w')
    {
        print(pr_str.c_win);
    }
    else if(choose.second == 'l')
    {
        print(pr_str.c_lose);
    }
    else if(choose.second == 's')
    {
        compare_numbers(pr_str.player1, pr_str.computer);
    }
} 
//#########################################################################################################################################################################################
//[GEN_CHISLO]
int gen_chislo()
{
    int rand_chislo = 0;
    rand_chislo = 2 + rand()%10;
    if(rand_chislo != 5)
    {
        return rand_chislo; 
    }
}
//#########################################################################################################################################################################################
//[PUSH_IN_VECTOR]
void push_in_vector(vector<int> & vec, int num)
{
    vec.push_back(num);
}
//[SUMM_NUMBER_IN_VECTOR]
void summ_number_in_vector(vector<int> & vec, int & num)
{
    num = 0;
    for(int i : vec)
    {
        num +=i;
    }
}
//[CHECK_VYBOR]
pair<bool,string> check_vybor(char vybor)
{
    if(vybor == 'y')
    {
        return make_pair(true,"yes");
    }
    else if(vybor == 'n')
    {
        return make_pair(false,"no");
    }
    else
    {
        return make_pair(true,"error");
    }
}
//#########################################################################################################################################################################################
//[CHECK_NUM]
void check_num(int & summ, int num_player)
{
    if(summ == 21)
    {
        print(num_player,pr_str.y_win);
    }
    else if(summ > 21)
    {
        print(num_player,pr_str.y_lose);
    }
    else if(summ < 21 && num_player == 1)
    {
        check_game();
    }
    else if(summ < 21 && num_player == 2)
    {
        compare_numbers(pr_str.player1, pr_str.player2);
    }
}
//#########################################################################################################################################################################################
//[CHECK_NUM_COMP]
pair<bool, char> check_num_comp(int & summ)
{
    if(summ == 21)
    {
        return make_pair(false, 'w');
    }
    else if(summ > 21)
    {
        return make_pair(false, 'l');
    }
    else if(summ == 18 || summ == 19 || summ == 20)
    {
        return make_pair(false, 's');//stop game
    }
    else
    {
        return make_pair(true, 'n');//next
    }
}

//#########################################################################################################################################################################################
//[CHECK_GAME]
void check_game()
{
    char check;
    do
    {
        print(pr_str.check_player);
        cin>>check;
    }
    while(check != 'p' && check != 'c');
    if(check == 'c')
    {
        game_comp();
    }
    else if(check == 'c')
    {
        game_player(2);
    }
    else
    {
        print(pr_str.stop_game);
    }
}
//#########################################################################################################################################################################################
//[COMPARE_NUMBERS]
void compare_numbers(string num1, string num2)
{
    if(num1 == "player1" && num2 == "player2")
    {
        if(summ_player2 > summ_player2)
        {
            print(1,pr_str.y_win);
        }
        else
        {
            print(2,pr_str.y_win);
        }
    }
    else if(num1 == "player1" && num2 == "computer")
    {
        if(summ_player2 > summ_comp)
        {
            print(1,pr_str.y_win);
        }
        else
        {
            print(pr_str.c_win);
        }
    }
}
//#########################################################################################################################################################################################
//[PRINT]
void print(string pr_str,int num)
{
    cout<<pr_str<<' '<<num<<endl;
}

//#########################################################################################################################################################################################
//[PRINT]
void print(string pr_str)
{
    cout<<pr_str<<endl;
}
//#########################################################################################################################################################################################
//[PRINT]
void print(int num_player,string pr_str)
{
    cout<<num_player<<" "<<pr_str<<endl;
}