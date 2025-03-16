#include <iostream>
#include <time.h> //���� ���ڸ� ���� ����

using namespace std;

//enum == ������
enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END //�Ʒ� �ڵ忡�� ��������� �������� ���� /���� : ���� �߰��� �� �������ص���.
};

#define NAME_SIZE 32

//�÷��̾� ���� ����ü
struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB ejob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
};

//����
struct _tagMonster {
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};

int main() {

	srand((unsigned int)time(0));

	//������ ������ �� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer tPlayer = {};

	//�÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(tPlayer.strJobName, NAME_SIZE - 1); //���ڿ� ���� null������ ���� -1

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. ���" << '\n';
		cout << "2. �ü�" << '\n';
		cout << "3. ������" << '\n';
		cout << "������ �����ϼ��� : " << '\n';
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear(); //������Ʈ �����
			cin.ignore(1024, '\n'); //(�о���� ������ ����, �о���̸� ������ ����)�� ������.
			continue;
		}

		//���ڸ� �߸� �Է����� �� �ʱ�ȭ��
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
		
	}

	//ĳ���� ������ �⺻ ������
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.ejob = (JOB)iJob;

	switch (tPlayer.ejob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "���"); //���ڿ� ����
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "�ü�"); 
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "������"); 
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
		 
	}

	//���͸� �����Ѵ�.
	_tagMonster tMonsterArr[MT_BACK - 1] = {}; //�� �� ���� 0���� �ʱ�ȭ

	//��� ����
	strcpy_s(tMonsterArr[0].strName, "���");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	//Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	//�巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;


	while (true) {
		system("cls"); //ȭ�� ����� (clean screen)
		cout << "========================== �κ� ==========================" << '\n';
		cout << "1. ��" << '\n';
		cout << "2. ����" << '\n';
		cout << "3. ����" << '\n';
		cout << "4. ����" << '\n';
		cout << "�޴��� �����ϼ���. : ";
		int iMenu;
		cin >> iMenu;

		//�߸� �Է����� ��(������ ������ ���ڸ� �ִ� ���� �Ǽ�)
		if (cin.fail())
		{
			cin.clear(); //������Ʈ �����
			cin.ignore(1024, '\n'); //(�о���� ������ ����, �о���̸� ������ ����)�� ������.
			continue;
		}

		//����
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "========================== �� ==========================" << '\n';
				cout << "1. ����" << '\n';
				cout << "2. ����" << '\n';
				cout << "3. �����" << '\n';
				cout << "4. �ڷΰ���" << '\n';
				cout << "���� �����ϼ��� : " << '\n';
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear(); //������Ʈ �����
					cin.ignore(1024, '\n'); //(�о���� ������ ����, �о���̸� ������ ����)�� ������.
					continue;
				}

				//�� if���� ���� break�� �� �޴��� �����ֱ� ���� while�� ���� �����Ƿ�
				//�� while���� ����������.
				if(iMenu == MT_BACK)
					break;
				//������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�.
				//�׷��� �ؼ� �ش� ���� ���͸� �������ش�.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				//����
				while (true) {
					switch (iMenu) {
					case MT_EASY:
						cout << "========================== ���� ==========================" << '\n';
						break;
					case MT_NORMAL:
						cout << "========================== ���� ==========================" << '\n';
						break;
					case MT_HARD:
						cout << "========================== ����� ==========================" << '\n';
						break;
					}

					// �÷��̾� ������ ����Ѵ�.
				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "�߸� �����ϼ̾��ϴ�." << '\n';
		}

	}

	return 0;
}