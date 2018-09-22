#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <array>
using namespace std;

int factorial(int x){
    int result=1;
    for(int i = 1; i <=x; ++i){
        result*=i;
    }
}
int permutation(int stacks, int active){
    int result;
    result= (factorial(stacks)/factorial(stacks-active));
    return result;
}
float putDown(){
	return 0.5;
}
float pickUp(){
	return 0.5;
}
float moveStack(){
	return 1;
}
int stackNum(char* initial){
    int number = 0;
    for(int i=0; i<1024;i++){
        if(initial[i]==')'){
            number++;
        }
    }
    return number;
}
bool checkMax(char* desired, int maxheight){
	bool flag = true;
	int count = 1;
	int iterator =0;
	//65-90
	while(true){
		if(desired[iterator]==','){
			count++;
			if(count > maxheight){
				printf("No solution found");
				return false;
			}
			if(desired[iterator]==')'){
				count = 1;
			}
		}
	}
}
int main(int argc, char const *argv[])
{


    //printf("No solution found");
	char line1[1024] = {' '};
	char initial[1024] = {'*'};
	char desired[1024] = {'*'};
	fgets(line1, 1024, stdin);
	fgets(initial, 1024, stdin);
	fgets(desired, 1024, stdin);


    //position 0 is solution position 1 is start state
    //vector[#vector][inside vector]
    //rewrite vector 1 with next best possible step
    /*
	vector <vector<char> > stacks;
    vector<char>(desired,desired+ sizeof desired / sizeof desired[0]);
    stacks.push_back(vector<char>(initial,initial+ sizeof initial / sizeof initial[0]));
    */
	int maxheight = atoi(line1);
    int numstacks = stackNum(initial);
    int maxChance = permutation(numstacks,numstacks);
    char bufferInitial[numstacks][maxheight][maxChance+1]={' '};
    int movement[maxChance][2] = {0};
    int heighmatrix[numstacks]={0};
    int heightSelector[numstacks]={0};
    float cost=0;
    int path=1;

    char desiredMatrix[numstacks][maxheight]={' '};
    if(!checkMax(desired,maxheight)){
        return -1;
    }

    //navigators
    int st = 0;
    int hg =0;

    for(int y=0;y<1024;y++){
        if(desired[y]>=65 && desired[y]<=90 && desired[y]!='X'){
            desiredMatrix[st][hg]=desired[y];
            hg++;
        }else{
            if(desired[y]=='X' || desired[y]==')'){
                hg=0;
                st++;
            }
        }
    }
    st=0;
    hg=0;
    //valor absoluto de la negacion de las posiciones es el costo del movimiento

    for(int x=0;x<1024;x++){

        if(initial[x]>=65 && initial[x]<=90){
            bufferInitial[st][hg][0]=initial[x];
            hg++;
        }else{
            if(initial[x]==')'){
                st++;
                hg=0;
            }
        }
    }
    int canBeMoved=0;
    int Chance=0;
    bool flag=true;
    int stackmarker=1;
    int za =1;
    while(flag){
        canBeMoved =0;
        for(int i=0;i<numstacks;i++){
            if(bufferInitial[i][0][0]!=' '){
                canBeMoved++;
            }
        }
        Chance = permutation(numstacks,canBeMoved);

        for(int markerS=0; markerS<numstacks;markerS++){
            for(int markerH=0; markerH<maxheight;markerH){
                if(bufferInitial[markerS][markerH][0]==' '){
                    heighmatrix[markerS]=markerH;
                }
                //heighmatrix
            }
        }
        int markx=1;
        int ma=0;
        int mas=0;
        int marky=heighmatrix[0];
        int slash = Chance/numstacks;
        /*
        for(za;za<Chance;za++){
            if(bufferInitial[ma][0][0]==' '){
                ma++;
            }
            for(int take=0;take)
            bufferInitial[ma][heighmatrix[mas][za]

        }
        */
        int hel =za;
        int hal = za;
        for (za;za<za-Chance;za++){
            for(int pe=0;pe<maxheight;pe++){
                for(int pa=0;pa<numstacks;pa++){
                    bufferInitial[pa][pe][za]=bufferInitial[pa][pe][0];
                }
            }
        }
        for(hal;hal<hal-Chance;hal++){
            for(int pe=0;pe<numstacks;pe++){
                if(bufferInitial[pe][0][0]!=' '){
                    for(int va =0 ;va<numstacks;va++){
                        if(va==pe){
                            va++;
                        }
                        bufferInitial[va][heighmatrix[pe]][hal]=bufferInitial[pe][heighmatrix[pe]-1][0];
                    }

                    hal++;
                }else{
                    pe++;
                }

            }
        }
        int compare[Chance]={0};
        for(int ze=0;ze<Chance;ze++){
            for(int za=0; za<numstacks; za++){
                for(int zb=0; zb<maxheight;zb++){
                    if(bufferInitial[za][zb][0]==bufferInitial[za][zb][hel]){
                        compare[ze]++;
                    }

                }
            }
            hel++;
        }



    }

    //stacknum P active stacks
    //worst possible stacknum P stacknum all stacks active

}
