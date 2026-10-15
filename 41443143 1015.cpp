#include <iostream>

using namespace std;

class GameCharacter
{
public:
    string name;
    int hp;
    int level;
    // Constructor
    GameCharacter(){}
    GameCharacter(string n, int h, int l)
    {
        // 將 n 存入 name
        this->name = n;
        // 將 h 存入 hp
        this->hp = h;
        // 將 l 存入 level
        this->level = l;
    }
    void playerset(string n, int h, int l) {
        // 將 n 存入 name
        this->name = n;
        // 將 h 存入 hp
        this->hp = h;
        // 將 l 存入 level
        this->level = l;
    }
    // 受到傷害
    void damage(int value)
    {
        // 1. hp 扣掉 value
        this->hp -= value;
        // 2. 如果 hp 小於 0 ，將 hp 設為 0
        if (hp < 0)hp = 0;
    }
    // 回復生命值
    void heal(int value)
    {
        // 1. hp 加上 value
        this->hp += value;
        // 2. 如果 hp 大於 100 ，將 hp 設為 100
        if (hp > 100)hp = 100;
    }
    // 升級
    void levelUp()
    {
        // 1. level 加 1
        this->level += 1;
        // 2. hp 回復成 100
        this->hp = 100;
    }
    // 顯示角色資料
    void show()
    {
        // 顯示 name 、 hp 、 level
        cout << "Name: " << this->name << endl;
        cout << "HP: " << this->hp << endl;
        cout << "Level: " << this->level << endl << endl;
    }
};

void list() {
    cout << "======== 選單 ========" << endl;
    cout << "1. 扣寫" << endl;
    cout << "2. 回血" << endl;
    cout << "3. 升級" << endl;
    cout << "4. show角色資料" << endl;
    cout << "5. show全部角色" << endl;
    cout << "0. 結束程式" << endl;
    cout << "請選擇:";
}

int main()
{
    //std::cout << "Hello World!\n";
    GameCharacter player[10];
    int n;
    cout << "請輸入角色人數:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int hp, level;
        cout << "==== 角色" << i + 1 << " ===="<<endl;
        cout << "名稱:";
        cin >> name;
        cout << "血量:";
        cin >> hp;
        cout << "等級:";
        cin >> level;
        cout << endl;
        player[i].playerset(name, hp, level);
    }

    int ch;
    list();
    while (cin >> ch && ch != 0) {
        int playerch;
        cout << "選擇角色編號(1~" << n << "): ";
        cin >> playerch;
        cout << endl;

        playerch--;

        switch (ch)
        {
        case 1: {
            int dam;
            cout << "輸入扣血量:";
            cin >> dam;
            player[playerch].damage(dam);
            player[playerch].show();
            break;
        }
        case 2: {
            int hea;
            cout << "輸入回血量:";
            cin >> hea;
            player[playerch].heal(hea);
            player[playerch].show();
            break;
        }
        case 3: {
            player[playerch].levelUp();
            player[playerch].show();
            break;
        }
        case 4: {
            player[playerch].show();
            break;
        }
        case 5: {
            for (int i = 0; i < n; i++) {
                player[i].show();
            }
        }
        default:
            break;
        }
        list();
    }
}