#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//累了用AI寫上限

class GameCharacter {
public:
	string name;
	int HP;
	int maxHP;
	int Level;
	const int MAX_LEVEL = 100;

	GameCharacter(string n, int h, int l) {
		name = n;
		Level = min(l, MAX_LEVEL);
		maxHP = max(1, h);
		HP = min(h, maxHP);
	}

	void Damage(int value) {
		if (value < 0) return;
		HP = HP - value;
		if (HP < 0) {
			HP = 0;
		}
	}

	void heal(int value) {
		if (value < 0) return;
		HP = HP + value;
		if (HP > maxHP) {
			HP = maxHP;
		}
	}

	void LevelUp() {
		if (Level >= MAX_LEVEL) {
			cout << name << " 已經達到最高等級 (" << MAX_LEVEL << ")，無法再升級！" << endl;
			return;
		}
		Level = Level + 1;
		maxHP += 20;
		HP = maxHP;
		cout << "角色升級成功！" << endl;
	}

	void show() {
		cout << "Name: " << name << endl;
		cout << "HP: " << HP << " / " << maxHP << endl;
		cout << "Level: " << Level << " / " << MAX_LEVEL << endl;
	}
};

int main() {
	string inputName;
	int inputHP;
	int inputLevel;

	cout << "建立角色" << endl;
	cout << "輸入角色1名字: ";
	cin >> inputName;
	cout << "輸入角色1初始血量: ";
	cin >> inputHP;
	cout << "輸入角色1初始等級: ";
	cin >> inputLevel;

	GameCharacter player1(inputName, inputHP, inputLevel);

	cout << "\n建立角色" << endl;
	cout << "輸入角色2名字: ";
	cin >> inputName;
	cout << "輸入角色2初始血量: ";
	cin >> inputHP;
	cout << "輸入角色2初始等級: ";
	cin >> inputLevel;

	GameCharacter player2(inputName, inputHP, inputLevel);

	int choice;

	while (true) {
		cout << "\n-----選單-----" << endl;
		cout << "1. 扣血" << endl;
		cout << "2. 回血" << endl;
		cout << "3. 升級" << endl;
		cout << "4. 角色資料" << endl;
		cout << "5. 全部角色" << endl;
		cout << "0. 結束程式" << endl;
		cout << "請選擇選項: ";
		cin >> choice;

		if (choice == 0) {
			cout << "結束程式~" << endl;
			break;
		}

		if (choice == 1) {
			int ID, val;
			cout << "請選擇角色編號(1或是2): ";
			cin >> ID;
			cout << "輸入傷害值: ";
			cin >> val;
			if (ID == 1) {
				player1.Damage(val);
				player1.show();
			}
			else if (ID == 2) {
				player2.Damage(val);
				player2.show();
			}
		}
		else if (choice == 2) {
			int ID, val;
			cout << "請選擇角色編號(1或是2): ";
			cin >> ID;
			cout << "輸入回血量: ";
			cin >> val;
			if (ID == 1) {
				player1.heal(val);
				player1.show();
			}
			else if (ID == 2) {
				player2.heal(val);
				player2.show();
			}
		}
		else if (choice == 3) {
			int ID;
			cout << "請選擇角色編號(1或是2): ";
			cin >> ID;
			if (ID == 1) {
				player1.LevelUp();
				player1.show();
			}
			else if (ID == 2) {
				player2.LevelUp();
				player2.show();
			}
		}
		else if (choice == 4) {
			int ID;
			cout << "請選擇角色編號(1或是2): ";
			cin >> ID;
			if (ID == 1) {
				player1.show();
			}
			else if (ID == 2) {
				player2.show();
			}
		}
		else if (choice == 5) {
			cout << "\n[角色1]" << endl;
			player1.show();
			cout << "\n[角色2]" << endl;
			player2.show();
		}
		else {
			cout << "輸入錯誤" << endl;
		}
	}
	return 0;
}