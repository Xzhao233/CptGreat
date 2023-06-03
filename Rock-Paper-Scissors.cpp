#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));

    cout << "识相点就快来玩石头剪刀布！" << endl;

    int userWins = 0;
    bool playAgain = true;
    while (playAgain) {
        int userChoice = 0;

        while (true) {
            cout << "请输入你的选择（1=石头，2=剪子，3=布，exit退出）：";
            if (cin >> userChoice) {
                break;
            }
            cerr << "无效的输入，请重新输入" << endl;
            cin.clear();
        }

        if (userChoice == 4) {
            if (userWins >= 5) {
                cout << "你释放了必杀技并赢得了比赛！" << endl;
                userWins = 0;
            } else {
                cout << "你还没有解锁必杀技哦" << endl;
                continue;
            }
        }

        if (userChoice == 0) {
            break;
        }

        if (userChoice < 1 || userChoice > 3) {
            cout << "无效的选择" << endl;
            continue;
        }

        int computerChoice = rand() % 3 + 1;

        cout << "你出了";
        switch (userChoice) {
            case 1:
                cout << "石头";
                break;
            case 2:
                cout << "剪子";
                break;
            case 3:
                cout << "布";
                break;
        }

        cout << "，电脑出了";
        switch (computerChoice) {
            case 1:
                cout << "石头";
                break;
            case 2:
                cout << "剪子";
                break;
            case 3:
                cout << "布";
                break;
        }
        cout << "。" << endl;

        if (userChoice == computerChoice) {
            cout << "平局！" << endl;
        } else if ((userChoice == 1 && computerChoice == 3) ||
                   (userChoice == 2 && computerChoice == 1) ||
                   (userChoice == 3 && computerChoice == 2)) {
            userWins++;
            cout << "你赢了！" << endl;
            if (userWins >= 5) {
                cout << "你解锁了必杀技！" << endl;
            }
        } else {
            userWins = userWins;
            cout << "电脑赢了！作为惩罚，我要告诉你：爱莉希雅死了！" << endl;
        }
    }

    return 0;
}