#include <iostream>

int n, m;
int sDSize = 0, rCount = 0;
int movx[4] = {0,1,0,-1};
int movy[4] = {-1,0,1,0};
int posx[4];
int posy[4];
int rx;
int ry;
bool r = false;

bool validChar(char a){
	switch (a){
		case '.':
			return true;
		break;
		
		case 'F':
			return true;
		break;
		
		case 'S':
			return true;
		break;
		
		case 'R':
			return true;
		break;
		
		case '@':
			return true;
		break;
		
		case 'X':
			return true;
		break;
		
		case '#':
			return true;
		break;
	
		default:
			return false;
	}
}

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

void printMap(char **map){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m;  j++){
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

bool checkMap(char **map){
	
	printMap(map);
	int count = 0, k = 0;
	bool gSpot = false;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m;  j++){
			
			if(!validChar(map[i][j])){
				return false;
			}
			
			if(map[i][j] == 'X' || map[i][j] == 'x') {
				count++;
				sDSize++;
				posx[k] = i;
				posy[k] = j;
				k++;
			}
			
			if(map[i][j] == 'R' || map[i][j] == 'r') {
				rx = i;
				ry = j;
				r = true;
			}
		}
	}
	
	if(!r && rCount > 1){
		return false;
	}
	
	if(!checkShip(count)){
		return false;
	}
	
	if(count == 1){
		std::cout << "Una X" << std::endl;
		if(posx[0] == 0 && posy[0] == 0){
			posx[3] = 0; posy[3] = 0;
			posx[0] = -1; posy[0] = -1;
			posx[1] = -1; posy[1] = 0;
			posx[2] = 0; posx[2] = -1;
			gSpot = true;
		}
		
		if(posx[0] == n-1 && posy[0] == 0){
			posx[1] = n-1; posy[1] = 0;
			posx[0] = n-1; posy[0] = -1;
			posx[2] = n; posy[2] = -1;
			posx[3] = n; posy[3] = 0;
			gSpot = true;
		}
		
		if(posx[0] == 0 && posy[0] == m-1){
			posx[2] = 0; posy[2] = m-1;
			posx[0] = -1; posy[0] = m-1;
			posx[1] = -1; posy[1] = m;
			posx[3] = 0; posy[3] = m;
			gSpot = true;
		}
		
		if(posx[0] == n-1 && posy[0] == m-1){
			posx[1] = n-1; posy[1] = m;
			posx[2] = n; posy[2] = m-1;
			posx[3] = n; posy[3] = m;
			gSpot = true;
		}
	}
	
	if(count == 2){
		std::cout << "Dos X" << std::endl;
		if(posx[0] == 0 && posy[0] > -1 && posy[0] < m-1 && posx[1] == posx[0] && posy[1] != posy[0]){
			
			if(!(posy[1] - posy[0] == 1)){
				return false;
			}
			posx[2] = posx[0]; posy[2] = posy[0];
			posx[3] = posx[1]; posy[3] = posy[1];
			posx[0] = posx[2]-1;
			posx[1] = posx[3]-1;
			gSpot = true;
		}
		
		if(posx[0] == n-1 && posy[0] > -1 && posy[0] < m-1 && posx[1] == posx[0] && posy[1] != posy[0]){
			
			if(!(posy[1] - posy[0] == 1)){
				return false;
			}
			posx[2] = posx[0] + 1; posy[2] = posy[0];
			posy[3] = posx[1] + 1; posy[3] = posy[1];
			gSpot = true;
		}
		
		if(posy[0] == 0 && posx[0] > -1 && posx[0] < n-1 && posy[1] == posy[0] && posy[1] != posy[0]){
			if(!(posx[1] - posx[0] == 1)){
				return false;
			}
			posx[2] = posx[1]; posy[2] = posy[1];
			posx[1] = posx[0]; posy[1] = posy[0] + 1;
			posx[3] = posx[1]; posx[3] = posy[0] + 1;
			gSpot = true;
		}
		
		if(posy[0] == m-1 && posx[0] > -1 && posx[0] < n-1 && posy[1] == posy[0] && posy[1] != posy[0]){
			if(!(posx[1] - posx[0] == 1)){
				return false;
			}
			posx[2] = posx[1]; posy[2] = posx[1];
			posx[1] = posx[0]; posy[1] = posy[0] + 1;
			posx[3] = posx[2]; posy[3] = posy[2] + 1;
			gSpot = true; 
		}  
	}
	
	if(count == 4){
		std::cout << "Cuatro X" << std::endl;
		if(posx[0] - posx[1]){
			return false;
		}
		if(posx[2] - posx[3]){
			return false;
		}
		if(posy[0] - posy[2]){
			return false;
		}
		if(posy[1] - posy[3]){
			return false;
		}		
		if(posx[2] - posx[0] != 1){
			return false;
		}
		if(posx[3] - posx[1] != 1){
			return false;
		}
		if(posy[1] - posy[0] != 1){
			return false;
		}
		if(posy[3] - posy[2] != 1){
			return false;
		}
		gSpot = true;
	}
	
	if(gSpot){
		std::cout << count << std::endl;
		return true;
	}else{
		std::cout << count << std::endl;
		return false;
	}
}

int main(){
	
	int b, k, mov;
	std::cin >> n >> m;
	std::cin >> b;
	int ubix[4];
	int ubiy[4];
	
	char **map;

	map = new char *[n];
	
	for(int i = 0; i < n; i++){
		map[i] = new char[m];
	}
	
	if ( n > 8 || n < 4 ){
		std::cout << "NO VALIDO" << std::endl;
		return 0;
	}
	
	if ( m > 8 || m < 4 ){
		std::cout << "NO VALIDO" << std::endl;
		return 0;
	}
	
	for (int i = 0; i < n; i++){
			std::cin >> map[i]; 
	}
	
	if(!(checkMap(map))){
		std::cout << "NO VALIDO" << std::endl;
		return 0;
	}else{
		std::cout << "VALIDO" << std::endl;
		return 0;
	}
	
	std::cin >> k;
	
	
	
	return 0;
}
