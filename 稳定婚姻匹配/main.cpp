#include<iostream>
#include<utility>
using namespace std;

void gs(int** man, int** woman, int num){
	while(1){
		int m1 = 1;
		int m2 = 0;
		while(man[m1][0] != 0){ //判断是否已经匹配到woman
			m1++;
			if(m1 == num+1){
				for(int i = 1; i < num; i++)
					cout<<man[i][0]<<" ";
				cout<<man[num][0];
				return;
			}
		}//find a man

		for(int i = 1; i < num+1; i++){
			int temp = man[m1][i];
			if(woman[temp][0] == 0){
				m2 = temp;
				break;
			}//woman未匹配
			else{//woman已经匹配
				for(int j = 1; j < num+1; j++){
					if(woman[temp][j] == m1){//m1优先现在的匹配
						m2 = temp;
						man[woman[temp][0]][0] = 0;
						i = num+1;
						break;
					}
					if(woman[temp][j] == woman[temp][0]){//现在的匹配优先于m1
						break;
					}
				}
			}


		}//find a woman

		//成功匹配
		man[m1][0] = m2;
		woman[m2][0] = m1;
	}
}

int main(){
	int num;
	cin>>num;
	int ** man = new int*[num+1]; 
	int ** woman = new int*[num+1]; 
	for(int i = 1; i< num+1; i++){
		man[i] = new int[num+1];
		woman[i] = new int[num+1];
	}
	for(int i = 1; i < num+1 ; i++){
		for(int j = 1;j < num+1; j++){
			cin>>man[i][j];
		}		
		man[i][0] = 0;
	}

	for(int i = 1; i < num+1 ; i++){
		for(int j = 1;j < num+1; j++){
			cin>>woman[i][j];
		}		
		woman[i][0] = 0;
	}
	
	
	gs(man, woman, num);

	return 0;
}