#include "Board.h"

using namespace std;

int main() {
	int rr, ll, gg;
	
	cout << "���������̴�С��" << endl;
	cout << "�У�";	cin >> rr;
	cout << "�У�";	cin >> ll;
	cout << "������ʤ��������������";	cin >> gg;
	while (gg <= 0) {
		cout << "ʤ�������������Ƿ������������룺" << endl;
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
			cout << "��ǰλ���Ѿ��������ˣ����������ӣ�" << endl;
			continue;
		}
		else if (t == -1) {
			cout << "��ǰλ�ó������̷�Χ�����������ӣ�" << endl;
			continue;
		}
		else {
			board.display();
			pis *= -1;
			winner = board.is_win();
		}
	}

	if (winner == -1)
		cout << "-1����ʤ����" << endl;
	else if (winner == 1)
		cout << "1����ʤ����" << endl;
	else
		cout << "ƽ�֣�" << endl;
}
