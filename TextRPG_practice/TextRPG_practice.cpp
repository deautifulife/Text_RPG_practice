#include <iostream>
#include <time.h> //랜덤 숫자를 쓰기 위해

using namespace std;

//enum == 열거형
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
	JOB_END //아래 코드에서 명시적으로 끝값으로 설정 /이유 : 직업 추가할 때 수정안해도됨.
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
	int iItemCount; //현재 아이템 얼마나 찼는지 카운트
	int iGold;
};

//플레이어 정보 구조체
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

//몬스터
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

	//게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};

	//플레이어 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1); //문자열 끝을 null공간을 위해 -1

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. 기사" << '\n';
		cout << "2. 궁수" << '\n';
		cout << "3. 마법사" << '\n';
		cout << "직업을 선택하세요 : " << '\n';
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear(); //에러비트 지우기
			cin.ignore(1024, '\n'); //(읽어들일 문자의 개수, 읽어들이면 종료할 문자)를 버린다.
			continue;
		}

		//숫자를 잘못 입력했을 때 초기화용
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
		
	}

	//캐릭터 생성시 기본 정보들
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.ejob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.ejob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사"); //문자열 복사
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
		strcpy_s(tPlayer.strJobName, "궁수"); 
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
		strcpy_s(tPlayer.strJobName, "마법사"); 
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

	//몬스터를 생성한다.
	_tagMonster tMonsterArr[MT_BACK - 1] = {}; //맵 별 몬스터 0으로 초기화

	//고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
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

	//트롤 생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
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

	//드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
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

	//상점에서 판매할 아이템 목록을 생성한다.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	//각 아이템 정보들을 설정해준다.


	while (true) {
		system("cls"); //화면 지우기 (clean screen)
		cout << "========================== 로비 ==========================" << '\n';
		cout << "1. 맵" << '\n';
		cout << "2. 상점" << '\n';
		cout << "3. 가방" << '\n';
		cout << "4. 종료" << '\n';
		cout << "메뉴를 선택하세요. : ";
		int iMenu;
		cin >> iMenu;

		//잘못 입력했을 때(숫자형 변수에 문자를 넣는 등의 실수)
		if (cin.fail())
		{
			cin.clear(); //에러비트 지우기
			cin.ignore(1024, '\n'); //(읽어들일 문자의 개수, 읽어들이면 종료할 문자)를 버린다.
			continue;
		}

		//종료
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "========================== 맵 ==========================" << '\n';
				cout << "1. 쉬움" << '\n';
				cout << "2. 보통" << '\n';
				cout << "3. 어려움" << '\n';
				cout << "4. 뒤로가기" << '\n';
				cout << "맵을 선택하세요 : " << '\n';
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear(); //에러비트 지우기
					cin.ignore(1024, '\n'); //(읽어들일 문자의 개수, 읽어들이면 종료할 문자)를 버린다.
					continue;
				}

				//이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로
				//이 while문을 빠져나간다.
				if(iMenu == MT_BACK)
					break;
				//선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				//그렇게 해서 해당 맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				//전투
				while (true) {
					system("cls");
					switch (iMenu) {
					case MT_EASY:
						cout << "========================== 쉬움 ==========================" << '\n';
						break;
					case MT_NORMAL:
						cout << "========================== 보통 ==========================" << '\n';
						break;
					case MT_HARD:
						cout << "========================== 어려움 ==========================" << '\n';
						break;
					}

					// 플레이어 정보를 출력한다.
					cout << "============== Player ==============" << '\n';
					cout << "이름 : " << tPlayer.strName << "\t직업 : " <<
						tPlayer.strJobName << '\n';
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " <<
						tPlayer.iExp << '\n';
					cout << "공격력 : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t방어력 : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << '\n';
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << endl << '\n';

					// 몬스터 정보 출력
					cout << "============== Monster ==============" << '\n';
					cout << "이름 : " << tMonster.strName << " 레벨 : " << 
						tPlayer.iLevel << '\n';
					cout << "공격력 : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << '\n';
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << '\n';
					cout << "획득 경험치 : " << tMonster.iExp << "\t획득골드 : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << '\n';

					cout << "1. 공격" << '\n';
					cout << "2. 도망가기" << '\n';
					cout << "메뉴를 선택하세요 : ";
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
						// 공격력 계산, min =5, max 15일 때 15-5+1 = 11, 11로 나눈 나머지는 0~10이 되고 여기에 5를 더한다.
						// 그러면 5에서 15사이의 랜덤값이 나온다.
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;
						int iDamage = iAttack - iArmor;
						//삼항연산자 : 조건식 ? true일때값 : false일때값;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//몬스터의 HP 감소
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " 가 " << tMonster.strName << "에게" << iDamage << "피해를 입혔습니다." << '\n';

						//몬스터가 죽었을 경우를 처리한다.
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " 몬스터를 해치웠습니다." << '\n';

							tPlayer.iExp += tMonster.iExp;
							int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득하였습니다." << '\n';
							cout << iGold << " Gold를 획득하였습니다." << '\n';

							//다음 전투를 위한 몬스터 리셋
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}

						//몬스터가 살아있다면 플레이어를 공격한다.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;
						iDamage = iAttack - iArmor;
						//삼항연산자 : 조건식 ? true일때값 : false일때값;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " 가 " << tPlayer.strName << "에게" << iDamage << "피해를 입혔습니다." << '\n';

						//플레이어가 죽었을 경우
						if (tPlayer.iHP < 0) {
							cout << tPlayer.strName << " 플레이어가 쓰러졌습니다." << '\n';

							//경험치와 골드를 드랍
							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 경험치를 잃었습니다." << '\n';
							cout << iGold << " Gold를 잃었습니다." << '\n';

							// 플레이어의 HP와 MP를 회복한다.
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
				cout << "========================== 상점 =========================="<<'\n';
				cout << "1. 무기 상점" << '\n';
				cout << "2. 방어구 상점" << '\n';
				cout << "3. 뒤로가기" << '\n';
				cout << "상점을 선택하세요 : " << '\n';
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

						cout << "========================== 무기 상점 ==========================" << '\n';
						//판매 목록을 보여준다.
					}
					break;
				case SM_ARMOR:
					break;
				}
			}
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하셨습니다." << '\n';
		}

	}

	return 0;
}