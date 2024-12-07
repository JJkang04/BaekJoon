#include <iostream>
using namespace std;


int base_HP, base_MP, base_ATK, base_DEF;
int item_HP, item_MP, item_ATK, item_DEF;
int result_HP, result_MP, result_ATK, result_DEF;
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> base_HP >> base_MP >> base_ATK >> base_DEF >> item_HP >> item_MP >> item_ATK >> item_DEF;
        result_HP = base_HP + item_HP;
        result_MP = base_MP + item_MP;
        result_ATK = base_ATK + item_ATK;
        result_DEF = base_DEF + item_DEF;
        if(result_HP < 1) result_HP = 1;
        if(result_MP < 1) result_MP = 1;
        if(result_ATK < 0) result_ATK = 0;

        cout << result_HP + 5 * result_MP + 2 * result_ATK + 2 * result_DEF << '\n';
    }
    return 0;
}