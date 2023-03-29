#include <stdio.h>
#include <stdlib.h>

int poker(char mao1[5][2],char mao2[5][2]){


    int BLACK,WHITE,state,i;
    char mao1num[5],mao2num[5],mao1suit[5],mao2suit[5];

    for(i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(mao1[i][0]>mao1[i+1][0]){
                mao1[i][0]=mao1[i+1][0];
                mao1[i+1][0]=mao1[i][0];
            }
            if(mao2[i][0]>mao2[i+1][0]){
                mao2[i][0]=mao2[i+1][0];
                mao2[i+1][0]=mao2[i][0];
        }
        }
    }

    for(i=0;i<5;i++){
        mao1num[i]=mao1[i][0];
        mao1suit[i]=mao1[i][1];
        mao2num[i]=mao2[i][0];
        mao2suit[i]=mao2[i][1];
    }


    if(mao1num==("%s%s%s%s%s",mao1num[0],mao1num[0]+1,mao1num[0]+2,mao1num[0]+3,mao1num[0]+4)){
        if(mao1suit=="DDDDD" || mao1suit=="CCCCC" || mao1suit=="HHHHH" || mao1suit=="SSSSS")
            BLACK=8; //STRAIGHT FLUSH
        else
            BLACK=4; //STRAIGHT
    }else if(mao1suit=="DDDDD" || mao1suit=="CCCCC" || mao1suit=="HHHHH" || mao1suit=="SSSSS"){
        BLACK=5; //FLUSH

    }else if((mao1num[0]== mao1num[1] && mao1num[1] == mao1num[2] && mao1num[2] == mao1num[3])||(mao1num[4]== mao1num[3] && mao1num[3] == mao1num[2] && mao1num[2] == mao1num[1])){
        BLACK=7; //FOUR OF A KIND

    }else if((mao1num[0]==mao1num[1] && mao1num[1]== mao1num[2])||(mao1num[1]==mao1num[2] && mao1num[2]==mao1num[3])||(mao1num[2]==mao1num[3] && mao1num[3]== mao1num[4])){
        if((mao1num[3]==mao1num[4])||(mao1num[0]==mao1num[4])||(mao1num[0]==mao1[1]))
            BLACK=6; //FULL HOUSE
        else
            BLACK=3; //THREE OF A KIND

    }else if((mao1num[0]==mao1num[1]&&(mao1num[2]==mao1num[3]||mao1num[3]==mao1num[4])||(mao1num[1]==mao1num[2]&& mao1num[3]==4))){

        BLACK=2; //TWO PAIR
    }else if(mao1num[0]==mao1num[1]|| mao1num[1]==mao1num[2] || mao1num[2]==mao1num[3] || mao1num[3]==mao1num[4]){

        BLACK=1; //PAIR
    }else{
        BLACK=0; //HIGHER
    }


    // MAO 2
    if(mao2num==("%s%s%s%s%s",mao2num[0],mao2num[0]+1,mao2num[0]+2,mao2num[0]+3,mao2num[0]+4)){
        if(mao2suit=="DDDDD" || mao2suit=="CCCCC" || mao2suit=="HHHHH" || mao2suit=="SSSSS")
            WHITE=8; //STRAIGHT FLUSH
        else
            WHITE=4; //STRAIGHT
    }else if(mao2suit=="DDDDD" || mao2suit=="CCCCC" || mao2suit=="HHHHH" || mao2suit=="SSSSS"){
        WHITE=5; //FLUSH

    }else if((mao2num[0]== mao2num[1] && mao2num[1] == mao2num[2] && mao2num[2] == mao2num[3])||(mao2num[4]== mao2num[3] && mao2num[3] == mao2num[2] && mao2num[2] == mao2num[1])){
        WHITE=7; //FOUR OF A KIND

    }else if((mao2num[0]==mao2num[1] && mao2num[1]== mao2num[2])||(mao2num[1]==mao2num[2] && mao2num[2]==mao2num[3])||(mao2num[2]==mao2num[3] && mao2num[3]== mao2num[4])){
        if((mao2num[3]==mao2num[4])||(mao2num[0]==mao2num[4])||(mao2num[0]==mao1[1]))
            WHITE=6; //FULL HOUSE
        else
            WHITE=3; //THREE OF A KIND

    }else if((mao2num[0]==mao2num[1]&&(mao2num[2]==mao2num[3]||mao2num[3]==mao2num[4])||(mao2num[1]==mao2num[2]&& mao2num[3]==4))){

        WHITE=2; //TWO PAIR
    }else if(mao2num[0]==mao2num[1]|| mao2num[1]==mao2num[2] || mao2num[2]==mao2num[3] || mao2num[3]==mao2num[4]){

        WHITE=1; //PAIR
    }else{
        WHITE=0; //HIGHER
    }


    if(BLACK==WHITE){

        if(mao1num[0]==mao2num[0] && mao1num[1]==mao2num[1] && mao1num[2]==mao2num[2] && mao1num[3]==mao2num[3] && mao1num[4]==mao2num[4]){

            printf("TIE!");
        }else{
            for(i=4;i>0;i--){

                if(mao1num[i]!=mao2num[i]){
                    if(mao1num[i]>mao2num[i]){
                        printf("BLACK WINS!");
                        break;
                    }else{
                        printf("WHITE WINS!");
                        break;}}

        }
        }

    }else if(BLACK>WHITE){
        printf("BLACK WINS!");
    }else if(WHITE>BLACK){
        printf("WHITE WINS!");
    }

    return 0;
}
int main()
{
    char mao1[5][2]={"1S","1S","1S","1S","6S"};
    char mao2[5][2]={"1S","1S","1S","1S","5S"};
    poker(mao1,mao2);
    return 0;
}
