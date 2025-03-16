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

#define NAME_SIZE 32

//플레이어 정보 구조체
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
	cin.getline(tPlayer.strJobName, NAME_SIZE - 1); //문자열 끝을 null공간을 위해 -1

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
				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하셨씁니다." << '\n';
		}

	}

	return 0;
}