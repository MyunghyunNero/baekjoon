#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int sequence = 0;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    int maxHealth = health;
    int attackIdx = 0;
    int lastTime = attacks[attacks.size()-1][0];
    for(int i=1;i<=lastTime;i++) {
        if(attacks[attackIdx][0] == i) {
            sequence=0;
            health-=attacks[attackIdx][1];
            attackIdx++;
            if(health<=0) return -1;
            continue;
        }
        if(health + x <= maxHealth) {
            health+=x;
        }else {
            health = maxHealth;
        }
        sequence++;
        if(sequence == t) {
            if(health+y<=maxHealth) {
                health+=y;
            }else{
                health = maxHealth;
            }
            sequence=0;
        }
    }
    return health;
}