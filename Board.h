#pragma once

#include <iostream>

using namespace std;

class Board {
	//��ʼΪ0����������Ϊ1��-1��
public:
	Board(int rr, int ll, int gg) : r(rr), l(ll), goal(gg) {
		bod = new int* [r];
		for (int i = 0; i < r; i++) {
			bod[i] = new int[l];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				bod[i][j] = 0;
			}
		}
	}

	~Board() {
		for (int i = 0; i < r; i++) {
			delete[] bod[i];
		}
		// delete[] bod;
	}

	// ����1Ϊ1ʤ������-1Ϊ-1ʤ������0Ϊδ�ֳ�ʤ��
	int is_win() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				// ����ÿһ�����ж�
				int sum = 0;
				// ��
				// sum = 0;
				for (int k = 0; k < goal && j + k < l; k++)
					sum += bod[i][j + k];
				if (sum == goal)
					return 1;
				else if (-1 * sum == goal)
					return -1;
				
				// ��
				sum = 0;
				for (int k = 0; k < goal && i + k < r; k++)
					sum += bod[i + k][j];
				if (sum == goal)
					return 1;
				else if (-1 * sum == goal)
					return -1;
				
				// ��б
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j + k < l; k++)
					sum += bod[i + k][j + k];
				if (sum == goal)
					return 1;
				else if (-1 * sum == goal)
					return -1;
				
				// ��б
				sum = 0;
				for (int k = 0; k < goal && i + k < r && j - k >= 0; k++)
					sum += bod[i + k][j - k];
				if (sum == goal)
					return 1;
				else if (-1 * sum == goal)
					return -1;
			}
		}
		return 0;
	}

	int drop(int i, int j, int pis) {
		if (i < 0 || i >= r || j < 0 || j >= l)
			return -1;

		if (bod[i][j])
			return 0;
		
		bod[i][j] = pis;
		return 1;
	}

	void display() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				cout << bod[i][j] << '\t';
			}
			cout << endl;
		}
		cout << '\n';
	}

	bool is_full() {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < l; j++) {
				if (!bod[i][j])
					return false;
			}
		}
		return true;
	}

private:
	int r;
	int l;
	int** bod;
	int goal;
};

// class Piece {
// public:

// private:
// };
