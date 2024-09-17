#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

enum WarriorType { DRAGON, NINJA, ICEMAN, LION, WOLF };

const char* WARRIOR_NAMES[] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class Headquarters {
private:
    string color;
    int life;
    int warriorIndex;
    vector<WarriorType> productionOrder;
    vector<int> warriorCounts;

public:
    Headquarters(const string& c, int l, const vector<WarriorType>& order)
        : color(c), life(l), warriorIndex(0), productionOrder(order), warriorCounts(5, 0) {}

    bool canProduce(const vector<int>& strengths) {
        for (size_t i = 0; i < productionOrder.size(); ++i) {
            WarriorType type = productionOrder[i];
            if (life >= strengths[type]) {
                return true;
            }
        }
        return false;
    }

    void produce(int time, const vector<int>& strengths) {
        for (size_t i = 0; i < productionOrder.size(); ++i) {
            WarriorType type = productionOrder[i];
            if (life >= strengths[type]) {
                life -= strengths[type];
                warriorIndex++;
                warriorCounts[type]++;

                cout << setfill('0') << setw(3) << time << " " << color << " "
                     << WARRIOR_NAMES[type] << " " << warriorIndex << " born with strength "
                     << strengths[type] << "," << warriorCounts[type] << " "
                     << WARRIOR_NAMES[type] << " in " << color << " headquarter" << endl;
                return;
            }
        }
        cout << setfill('0') << setw(3) << time << " " << color
             << " headquarter stops making warriors" << endl;
    }
};

int main() {
    int testCases;
    cin >> testCases;

    for (int caseNum = 1; caseNum <= testCases; caseNum++) {
        cout << "Case:" << caseNum << endl;

        int M;
        cin >> M;

        vector<int> strengths(5);
        for (int i = 0; i < 5; i++) {
            cin >> strengths[i];
        }

        vector<WarriorType> redOrder;
        redOrder.push_back(ICEMAN);
        redOrder.push_back(LION);
        redOrder.push_back(WOLF);
        redOrder.push_back(NINJA);
        redOrder.push_back(DRAGON);

        vector<WarriorType> blueOrder;
        blueOrder.push_back(LION);
        blueOrder.push_back(DRAGON);
        blueOrder.push_back(NINJA);
        blueOrder.push_back(ICEMAN);
        blueOrder.push_back(WOLF);

        Headquarters red("red", M, redOrder);
        Headquarters blue("blue", M, blueOrder);

        int time = 0;
        while (red.canProduce(strengths) || blue.canProduce(strengths)) {
            if (red.canProduce(strengths)) {
                red.produce(time, strengths);
            }
            if (blue.canProduce(strengths)) {
                blue.produce(time, strengths);
            }
            time++;
        }
    }

    return 0;
}