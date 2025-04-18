#include <iostream>
#include <vector>
#include <string.h>
#include <set>



int turretOutpost [4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void placeTurret(std::vector<std::vector<char>> &map, int R, int C){
    for(int i = 0; i < 4; i++){
        int newR = R + turretOutpost[i][0];
        int newC = C + turretOutpost[i][1];

        if(newR >= 0 && newR < map.size() && newC >= 0 && newC < map[0].size()){
            if(map[newR][newC] == '.'){
                map[newR][newC] = 'T';

                //Percorrer para baixo na mesma coluna
                for(int j = newR + 1; j < map.size(); j++){
                    if(map[j][newC] == '#' || isdigit(map[j][newC])){
                        break;
                    } else if(map[j][newC] == '.'){
                        map[j][newC] = 'c';
                    }
                }

                //Percorrer para cima na mesma coluna
                for(int j = newR - 1; j >= 0; j--){
                    if(map[j][newC] == '#' || isdigit(map[j][newC])){
                        break;
                    } else if(map[j][newC] == '.'){
                        map[j][newC] = 'c';
                    }
                }

                //Percorrer para a esquerda na mesma linha
                for(int k = newC - 1; k >= 0; k--){
                    if(map[newR][k] == '#' || isdigit(map[newR][k])){
                        break;
                    } else if(map[newR][k] == '.'){
                        map[newR][k] = 'c';
                    }
                }

                //Percorrer para a direita na mesma linha
                for(int k = newC + 1; k < map[0].size(); k++){
                    if(map[newR][k] == '#' || isdigit(map[newR][k])){
                        break;
                    } else if(map[newR][k] == '.'){
                        map[newR][k] = 'c';
                    }
                }
            }
        }
    }
}


int check_outposts(std::vector<std::vector<char>> &map, int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if((i == 0 && j == 0) || (i == 0 && j == C - 1) || (i == R - 1 && j == 0) || (i == R - 1 && j == C - 1)){
                if(map[i][j] == '2'){
                    placeTurret(map, i, j);
                }
            }
        }
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 0;
    int R,C = 0;
    std::vector<std::vector<char>> map;
    std::cin >> T;  
    if(T < 1 || T > 100){
        std::cout << "T must be an int between 1 and 100\n";
        return 0;
    }
    for(int i = 0; i < T; i++){
        map.clear();
        std::cin >> R >> C;
        if(R < 1 || R > 15 || C < 1 || C > 15){
            std::cout << "R and C must be an int between 1 and 15\n";
            return 0;
        }
        map.resize(R);
        for(int j = 0; j < R; j++){
            map[j].resize(C);
            for(int k = 0; k < C; k++){
                std::cin >> map[j][k];
            }
        }
        check_outposts(map, R, C);
        for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
                std::cout << map[j][k];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }


    
    return 0;
}
