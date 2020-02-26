#include <iostream>

int n, m;

bool checkShip (int n){
	switch (n){
		case 1:
			return true;
		break;
		
		case 2:
			return true;
		break;
		
		case 4:
			return true;
		break;
		
		default:
			return false; 
	}
}

int checkMap(char map[n][m]){
	
	int count = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m;  j++){
			if(map[i][j] == 'X' || map[i][j] == 'x') {
				count++;
			}
		}
	}
	
	return count;
}

int main(){
	
	int b, k, mov;
	int movx[4] = {0,1,0,-1};
	int movy[4] = {-1,0,1,0};
	std::cin >> n >> m;
	std::cin >> b;
	int ubix[4];
	int ubiy[4];
	
	char map[n][m];
	
	if ( n > 8 || m < 4 ){
		std::cout << "NO VALIDO" << std::endl;
		return 0;
	}
	
	for (int i = 0; i < n; i++){
			std::cin >> map[i]; 
	}
	
	if(!(checkShip(checkMap(map, n, m)))){
		std::cout << "NO VALIDO" << std::endl;
		return 0;
	}
	
	std::cin >> k;
	
	
	
	return 0;
}
