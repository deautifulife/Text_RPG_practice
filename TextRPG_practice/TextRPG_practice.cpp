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

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

struct _tagItem {
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType; 
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory {
	_tagItem tItem[INVENTORY_MAX];
	int iItemCount; //���� ������ �󸶳� á���� ī��Ʈ
	int iGold;
};

//�÷��̾� ���� ����ü
struct _tagPlayer {
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
	_tagInventory tInventory;
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
	cin.getline(tPlayer.strName, NAME_SIZE - 1); //���ڿ� ���� null������ ���� -1

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
	tPlayer.tInventory.iGold = 10000;

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

	//�������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	/*
	char strNAme[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
	*/

	//�� ������ �������� �������ش�.
	// =============== ���� ���� ���� ===============
	strcpy_s(tStoreWeapon[0].strName, "���");
	strcpy_s(tStoreWeapon[0].strTypeName, "����");
	strcpy_s(tStoreWeapon[0].strDesc, "������ ���� ��");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 3000;
	tStoreWeapon[0].iSell = 1500;

	strcpy_s(tStoreWeapon[1].strName, "����");
	strcpy_s(tStoreWeapon[1].strTypeName, "����");
	strcpy_s(tStoreWeapon[1].strDesc, "�߽��� Ȱ");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "������");
	strcpy_s(tStoreWeapon[2].strTypeName, "����");
	strcpy_s(tStoreWeapon[2].strDesc, "������ ���� ������");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	// =============== �� ���� ���� ===============
	strcpy_s(tStoreArmor[0].strName, "õ����");
	strcpy_s(tStoreArmor[0].strTypeName, "��");
	strcpy_s(tStoreArmor[0].strDesc, "õ���� ���� ������ ����");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "���װ���");
	strcpy_s(tStoreArmor[1].strTypeName, "��");
	strcpy_s(tStoreArmor[1].strDesc, "�������� ���� ���� ����");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "��ö����");
	strcpy_s(tStoreArmor[2].strTypeName, "��");
	strcpy_s(tStoreArmor[2].strDesc, "������ ö�� ���� ����");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 90;
	tStoreArmor[2].iMax = 150;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;


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
					system("cls");
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
					cout << "============== Player ==============" << '\n';
					cout << "�̸� : " << tPlayer.strName << "\t���� : " <<
						tPlayer.strJobName << '\n';
					cout << "���� : " << tPlayer.iLevel << "\t����ġ : " <<
						tPlayer.iExp << '\n';
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t���� : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << '\n';
					cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';
					cout << "������� : " << tPlayer.tInventory.iGold << " Gold" << endl << '\n';

					// ���� ���� ���
					cout << "============== Monster ==============" << '\n';
					cout << "�̸� : " << tMonster.strName << " ���� : " << 
						tPlayer.iLevel << '\n';
					cout << "���ݷ� : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t���� : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << '\n';
					cout << "ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t���� : " << tMonster.iMP << " / " << tMonster.iMPMax << '\n';
					cout << "ȹ�� ����ġ : " << tMonster.iExp << "\tȹ���� : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << '\n';

					cout << "1. ����" << '\n';
					cout << "2. ��������" << '\n';
					cout << "�޴��� �����ϼ��� : ";
					cin >> iMenu;


					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue; 
					}
					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu) {
					case BATTLE_ATTACK: {
						// ���ݷ� ���, min =5, max 15�� �� 15-5+1 = 11, 11�� ���� �������� 0~10�� �ǰ� ���⿡ 5�� ���Ѵ�.
						// �׷��� 5���� 15������ �������� ���´�.
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;
						int iDamage = iAttack - iArmor;
						//���׿����� : ���ǽ� ? true�϶��� : false�϶���;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//������ HP ����
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " �� " << tMonster.strName << "����" << iDamage << "���ظ� �������ϴ�." << '\n';

						//���Ͱ� �׾��� ��츦 ó���Ѵ�.
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " ���͸� ��ġ�����ϴ�." << '\n';

							tPlayer.iExp += tMonster.iExp;
							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "����ġ�� ȹ���Ͽ����ϴ�." << '\n';
							cout << iGold << " Gold�� ȹ���Ͽ����ϴ�." << '\n';

							//���� ������ ���� ���� ����
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}

						//���Ͱ� ����ִٸ� �÷��̾ �����Ѵ�.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;
						iDamage = iAttack - iArmor;
						//���׿����� : ���ǽ� ? true�϶��� : false�϶���;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//�÷��̾��� HP�� ���ҽ�Ų��.
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " �� " << tPlayer.strName << "����" << iDamage << "���ظ� �������ϴ�." << '\n';

						//�÷��̾ �׾��� ���
						if (tPlayer.iHP < 0) {
							cout << tPlayer.strName << " �÷��̾ ���������ϴ�." << '\n';

							//����ġ�� ��带 ���
							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " ����ġ�� �Ҿ����ϴ�." << '\n';
							cout << iGold << " Gold�� �Ҿ����ϴ�." << '\n';

							// �÷��̾��� HP�� MP�� ȸ���Ѵ�.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");

						break;
					}

					}
				}
			}
			break;
		case MM_STORE:
			while (true) {
				system("cls");
				cout << "========================== ���� =========================="<<'\n';
				cout << "1. ���� ����" << '\n';
				cout << "2. �� ����" << '\n';
				cout << "3. �ڷΰ���" << '\n';
				cout << "������ �����ϼ��� : " << '\n';
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu) {
				case SM_WEAPON:
					while (true) {
						system("cls");

						cout << "========================== ���� ���� ==========================" << '\n';
						//�Ǹ� ����� �����ش�.
						for (int i = 0; i < STORE_WEAPON_MAX; i++) {
							cout << i + 1 << ". �̸� : " << tStoreWeapon[i].strName <<
								"\t���� : " << tStoreWeapon[i].strTypeName << '\n';
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << " - " <<
								tStoreWeapon[i].iMax << '\n';
							cout << "�ǸŰ��� : " << tStoreWeapon[i].iPrice <<
								"\t���Ű��� : " << tStoreWeapon[i].iSell << '\n';
							cout << "���� : " << tStoreWeapon[i].strDesc << '\n' << '\n';
						}

						cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << '\n';
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " Gold" << '\n';
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << '\n';
						cout << "������ �������� �����ϼ��� : "<<'\n';
						cin >> iMenu;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1) {
							cout << "�߸� �����Ͽ����ϴ�." << '\n';
							system("pause");
							continue;
						}

						// ���� �ǸŸ�� �迭�� �ε����� �����ش�.
						int iWeaponIndex = iMenu - 1;

						// �κ��丮�� �� á���� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << "������ �� á���ϴ�." << '\n';
							system("pause");
							continue;
						}

						// ���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice) {
							cout << "���� �ݾ��� �����մϴ�." << '\n';
							system("pause");
							continue;
						}

						// ó���� iItemCount�� �ϳ��� �߰��Ǿ� �����ʱ� ������ 0���� �ʱ�ȭ �Ǿ� �����Ƿ�
						//0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸��� ī��Ʈ�� 1�� �ȴ�.
						//���� ���� �߰��� ���� 1�� �ε����� �߰��ϰԵȴ�.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];
						++tPlayer.tInventory.iItemCount;

						// ��带 �����Ѵ�.
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " �������� �����Ͽ����ϴ�.";
						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true) {
						system("cls");

						cout << "========================== �� ���� ==========================" << '\n';
						//�Ǹ� ����� �����ش�.
						for (int i = 0; i < STORE_ARMOR_MAX; i++) {
							cout << i + 1 << ". �̸� : " << tStoreArmor[i].strName <<
								"\t���� : " << tStoreArmor[i].strTypeName << '\n';
							cout << "���ݷ� : " << tStoreArmor[i].iMin << " - " <<
								tStoreArmor[i].iMax << '\n';
							cout << "�ǸŰ��� : " << tStoreArmor[i].iPrice <<
								"\t���Ű��� : " << tStoreArmor[i].iSell << '\n';
							cout << "���� : " << tStoreArmor[i].strDesc << '\n' << '\n';
						}

						cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << '\n';
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " Gold" << '\n';
						cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << '\n';
						cout << "������ �������� �����ϼ��� : " << '\n';
						cin >> iMenu;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1) {
							cout << "�߸� �����Ͽ����ϴ�." << '\n';
							system("pause");
							continue;
						}

						// ���� �ǸŸ�� �迭�� �ε����� �����ش�.
						int iArmorIndex = iMenu - 1;

						// �κ��丮�� �� á���� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << "������ �� á���ϴ�." << '\n';
							system("pause");
							continue;
						}

						// ���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice) {
							cout << "���� �ݾ��� �����մϴ�." << '\n';
							system("pause");
							continue;
						}

						// ó���� iItemCount�� �ϳ��� �߰��Ǿ� �����ʱ� ������ 0���� �ʱ�ȭ �Ǿ� �����Ƿ�
						//0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸��� ī��Ʈ�� 1�� �ȴ�.
						//���� ���� �߰��� ���� 1�� �ε����� �߰��ϰԵȴ�.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];
						++tPlayer.tInventory.iItemCount;

						// ��带 �����Ѵ�.
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << " �������� �����Ͽ����ϴ�.";
						system("pause");
					}
					break;
				}
			}
			break;
		case MM_INVENTORY:

			cout << "========================== ���� ==========================" << '\n';
			cout << "============== Player ==============" << '\n';
			cout << "�̸� : " << tPlayer.strName << "\t���� : " <<
				tPlayer.strJobName << '\n';
			cout << "���� : " << tPlayer.iLevel << "\t����ġ : " <<
				tPlayer.iExp << '\n';
			cout << "���ݷ� : " << tPlayer.iAttackMin << " - " <<
				tPlayer.iAttackMax << "\t���� : " << tPlayer.iArmorMin <<
				" - " << tPlayer.iArmorMax << '\n';
			cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
				"\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';
			cout << "������� : " << tPlayer.tInventory.iGold << " Gold" << endl << '\n';

			for (int i = 0; tPlayer.tInventory.iItemCount; i++) {
				cout << i + 1 << ". �̸� : " << tPlayer.tInventory.tItem[i].strName <<
					"\t���� : " << tPlayer.tInventory.tItem[i].strTypeName << '\n';
				cout << "���ݷ� : " << tPlayer.tInventory.tItem[i].iMin << " - " <<
					tPlayer.tInventory.tItem[i].iMax << '\n';
				cout << "�ǸŰ��� : " << tPlayer.tInventory.tItem[i].iPrice <<
					"\t���Ű��� : " << tPlayer.tInventory.tItem[i].iSell << '\n';
				cout << "���� : " << tPlayer.tInventory.tItem[i].strDesc << '\n' << '\n';
			}

			system("pause");
			break;
		default:
			cout << "�߸� �����ϼ̽��ϴ�." << '\n';
		}

	}

	return 0;
}