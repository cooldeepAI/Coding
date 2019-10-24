//
// Created by Yang Shuangzhen on 2019/10/6.
//

#include <iostream>
#include <string>
using namespace std;

void user_info(){
    string user_name;
    cout << "Please enter your first name: \t";
    cin >> user_name;
    cout << "\nHello, " << user_name
         << "! Welcome to the guess game, Have fun!" << endl;
}

bool again(){
    bool user_more = true;
    char usr_rsp;

    cout << "Go for it(Y or N)? ";
    cin >> usr_rsp;
    if (usr_rsp == 'N' || usr_rsp == 'n')
        user_more = false;
    else if(usr_rsp == 'Y' || usr_rsp == 'y')
        user_more = true;
    else
        cout << "Input error, please again, Y or N?";

    return user_more;
}

void playout(){
    int max_tries = 3;
    int tries_cnt = 0;
    bool usr_rsp = true;
    int next_elem = 2;
    int usr_guess;

    while(tries_cnt < max_tries && usr_rsp){
        // game
        tries_cnt++;
        cout << "Please input next number: \t";
        cin >> usr_guess;
        if(usr_guess == next_elem) {
            cout << "Congratulation!" << endl;
            break;
        }
        else {
            if (tries_cnt == 1){
                cout << "Oops! Nice guess but not quite it." << endl;
            }
            else if (tries_cnt == 2){
                cout << "Hmm, Sorry. Wrong a second time." << endl;
            }
            else if (tries_cnt == 3){
                cout << "It must be getting pretty frustrating by now!" << endl;
            }
            usr_rsp = again();
        }
    }
}

int main(){
//    user_info();
    playout();
    return 0;
}
