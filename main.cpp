#include "Board.h"

using namespace std;

int main() {
	int rr, ll, gg;
	
	cout << "请输入棋盘大小：" << endl;
	cout << "行：";	cin >> rr;
	cout << "列：";	cin >> ll;
	cout << "请输入胜利所需棋子数：";	cin >> gg;
	while (gg <= 0) {
		cout << "胜利所需棋子数非法！请重新输入：" << endl;
		cin >> gg;
	}

	Board board(rr, ll, gg);
	
	board.display();

	int pis = 1;
	int i, j;
	int winner = 0;
	while (winner == 0 && !board.is_full()) {
		cin >> i >> j;
		int t = board.drop(i, j, pis);

		if (t == 0) {
			cout << "当前位置已经有棋子了！请重新落子：" << endl;
			continue;
		}
		else if (t == -1) {
			cout << "当前位置超出棋盘范围！请重新落子：" << endl;
			continue;
		}
		else {
			board.display();
			pis *= -1;
			winner = board.is_win();
		}
	}

	if (winner == -1)
		cout << "-1棋子胜利！" << endl;
	else if (winner == 1)
		cout << "1棋子胜利！" << endl;
	else
		cout << "平局！" << endl;
}
