#include <stdio.h>
#include <stdlib.h>
int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char *black[25]={'p','k','q','b','r','n'};
char *white[25]={'P','K','Q','B','N','R'};
char *eaten_white[100]={'0','0','0','0','0'};
char *eaten_black[100]={'0','0','0','0','0'};
char *eaten_O[100]={'0','0','0','0','0','0'};
char p;
int attackonrow,attackoncoulomn=0;
int knigh1_pos=0,t=0,sum=0,knigh2_pos=0,e=0,g=0,l=0,y=0,yu=0,c=0,u=0,count_empty_checked=0,attackerrow,attackcolumn;
int initial=0,x=0,col=0;
int counter_dup=0;
int pos_kingi;
int pos_kingj;
int pos_rook_i=0;
int pos_rook_j=0;
char *promotionBlack[100]={'q','r','b','n'};
char *promotionWhite[100]={'Q','R','B','N'};
int pos_attacki=0;
int pos_attackj=0;
int *duplicate_square[25][2]=
{
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0}};
int *empty_pos[25][2]=
{
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0}};

char board[9][9]={
{' ','A','B','C','D','E','F','G','H'},//black
{'1',' ',' ',' ',' ',' ',' ',' ',' '},
{'2',' ',' ',' ',' ','r',' ',' ',' '},
{'3',' ',' ',' ',' ',' ',' ',' ',' '},
{'4',' ',' ',' ',' ','B',' ',' ',' '},
{'5',' ',' ',' ',' ',' ',' ',' ',' '},
{'6',' ',' ',' ',' ',' ',' ','K',' '},
{'7',' ',' ',' ',' ',' ',' ',' ',' '},
{'8',' ',' ',' ',' ',' ',' ',' ',' '},};


void bishop(int r1,int c1);
void ch_bishop_white();
int pawn_status[8]={0,0,0,0,0,0,0,0};
int count_play=1,kw=0,kb=0,i=0,j=0,count_check_player2=0,total=0;
int p1,p2,c2,r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6,c1,r1,count_check,v=0,m=0,dup=0,posi=0,valid=0,posj=0;
////////////////////functions
void display();
//player 1=1 ,player 2=2
void read_piece();
void read_rank();
int read_place();
void king_white(int r1,int c1);
void player1();
void validation_white(int attackonrow,int attackoncoulomn);
int main(){
    display();
    while(count_play!=-1){
    if (count_play==1){
        count_check=0;
          player1();
          }
    if (count_play==2){
          player2();
          }
    }

    return 0;
}
/////////////////////////////////////////////////////////

/////**QUEEN**///
//void valid_queen_white(int attackonrow,int attackoncoulomn){
//
//   ///UP
//   for(v=i;v<=8;v++){
//        if((i+1==attackonrow)&&(j==attackoncoulomn)){
//            valid=1;
//        printf("ght\n");
//            break;}
//        else if(board[v+1][j]!=' '){
//          if((v+2==attackonrow)&&(j==attackoncoulomn)){
//                    valid=1;
//                    printf("minYONNGI\n");
//                        break;}}}
//    ///down
//    for(v=i;v>=1;v--){
//    if((i-1==attackonrow)&&(j==attackoncoulomn)){
//           valid=1;
//           printf("KIM TAEHUNG\n");
//            break;}
//    else if(board[v-1][j]==' '){
//          if((v-2==attackonrow)&&(j==attackoncoulomn)){
//                     valid=1;
//                    printf("CHA EUNWOO\n");
//                    break;}}}
//     ///right
//     for(v=j;v<=8;v++){
//        if((i==attackonrow)&&(j+1==attackoncoulomn)){
//                      valid=1;
//                printf("JEON JEONGOOK\n");
//                 break;}
//        else if(board[i][v+1]==' '){
//          if((i==attackonrow)&&(v+2==attackoncoulomn)){
//                      valid=1;
//            printf("KIM NAMJOON\n");
//                      break;}}}
//          ///left
//    for(v=j;v>=1;v--){
//        if((i==attackonrow)&&(j-1==attackoncoulomn)){
//        valid=1;
//    printf("JEON HOESUK\n");
//    break;}
//    else if(board[i][v-1]==' '){
//    if((i==attackonrow)&&(v-2==attackoncoulomn)){
//        valid=1;
//        printf("JIMIN\n");
//        break;}}}
//    ///**BISHOP check if it can eat checked piece to king*///
//   ///up_right
//         for(v=1;v<=8;v++){
//        if(((i+1)==attackonrow)&&((j+1)==attackoncoulomn)){
//            valid=1;
//               printf("JIN\n");
//            break;}
//        else if(board[i+1][j+1]==' '){
//          if(((i+1+v)==attackonrow)&&((j+1+v)==attackoncoulomn)){
//            valid=1;
//               printf("BTS\n");
//               break;}}}
//    ///up_left
//        for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&(j+1==attackoncoulomn)){
//            valid=1;
//               printf("JAEHUNG NCT\n");
//               break;}
//        else if(board[i-1][j+1]==' ')
//            if(((i-(v+1))==attackonrow)&&(j+(v+1)==attackoncoulomn)){
//            valid=1;
//            printf("DOJOUNG\n");
//            break;}}
//         for(v=1;v<=8;v++){
//        if (((i+1)==attackonrow)&&(j-1==attackoncoulomn)){
//           valid=1;
//            printf("JUNGWOO\n");
//            return;
//         }
//        else if(board[i+(1)][j-(1)]==' ')
//            if((i+(v+1)==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("CHENLE\n");
//               break;
//
/////////////////////////////////////////////////////
valid_queen_white(int attackonrow,int attackoncoulomn){
  ///UP
//       for(v=i;v<=8;v++){
//        if(board[i+1][j]==board[attackonrow][attackoncoulomn]){
//            valid=1;
//        printf("ght\n");
//            break;}}
      if(j==attackoncoulomn){
        int k=1;
        int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosUP_QUEENwhite\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
            printf("lalalaUP_QUEENwhite\n");
                        counter_dup++;

        }}
//        else if(board[v+1][j]==' '){
//          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
//                    valid=1;
//                    printf("hurg\n");
//                        break;
    ///down
//    for(v=i;v>=1;v--){
//        if((i-1==attackonrow)&&(j==attackoncoulomn)){
//           valid=1;
//                                  printf("yui_QUEENwhite\n");
//            counter_dup++;
//            break;}}
         if(j==attackoncoulomn){
         int k=-1;
         int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosDOWN_QUEENwhite\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
                        counter_dup++;

            printf("lalalaDOWN_QUEENwhite\n");
        }}
     ///right
//     for(v=j;v<=8;v++){
//        if((i==attackonrow)&&(j+1==attackoncoulomn)){
//                      valid=1;
//            printf("rcxzas\n");
//            break;}}
     if(i==attackonrow){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosRIGHT_QUEENwhite\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
            counter_dup++;
        }}

          ///left
//    for(v=j;v>=1;v--){
//        if((i==attackonrow)&&(j-1==attackoncoulomn)){
//                      valid=1;
//                printf("gtrs\n");
//                      break;}}
      if(i==attackonrow){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosLEFT_QUEEN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
                        counter_dup++;
            printf("lalalaLEFT_QUEENwhite\n");
        }}

            ///*BISHOP check if it can eat checked piece to king///

//   ///up_right
//         for(v=1;v<=8;v++){
//        if(((i+1)==attackonrow)&&((j+1)==attackoncoulomn)){
//            valid=1;
//               printf("1LFKDU\n");
//            break;}
//        else if(board[i+1][j+1]==' '){
//          if(((i+1+v)==attackonrow)&&((j+1+v)==attackoncoulomn)){
//            valid=1;
//               printf("DKLSNJVOS");
//               break;}}}
//    ///up_left
//        for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&(j+1==attackoncoulomn)){
//            valid=1;
//               printf("1DSHOVIOSJDPOC MC;KLSDK\n");
//               break;}
//        else if(board[i-1][j+1]==' '){
//            if(((i-(v+1))==attackonrow)&&(j+(v+1)==attackoncoulomn)){
//            valid=1;
//            printf("FNKLWFPWEDSL,DS,DWKEF[PE;DW]A546");
//            break;}}}
//         for(v=1;v<=8;v++){
//        if (((i+1)==attackonrow)&&(j-1==attackoncoulomn)){
//           valid=1;
//            printf("GRIOEJG865865S4");
//            return;
//         }
//        else if(board[i+(1)][j-(1)]==' '){
//            if((i+(v+1)==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("01271400542");
//               break;
//            }}}
//          ///left
//           for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&((j-1)==attackoncoulomn)){
//           valid=1;
//            printf("KPRO;DSKPGPOPSPQ5525E8");
//            break;
//         }
//        else if(board[i-(1)][j-(1)]==' '){
//            if(((i-(v+1))==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("1IJGROPKLLDOLDLLDOWklLO");
//               break;}}}}
      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            printf("lalalarightright_QUEENwgite\n");
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow&&y!=attackoncoulomn) {
           if(board[x][y]!=' ') {
            printf("bosbosrightright_QUEENwhite\n");
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow&&y==attackoncoulomn){
            valid=1;
            printf("lalalarightright_QUEENwhite\n");
                        counter_dup++;

        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow&&uu!=attackoncoulomn) {
           if(board[f][uu]!=' ') {
            printf("bosbos_LEFTRIGHT_QUEENwhite\n");
            break;}
            else{
                    f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow&&uu==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTRIGHT_QUEENwhite\n");
                        counter_dup++;

        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow&&u37!=attackoncoulomn) {
           if(board[f64][u37]!=' ') {
            printf("bosbos_LEFTLEFT_QUEENwhite\n");
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow&&u37==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTLEFT_QUEENwhite\n");
                        counter_dup++;

        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow&&utre!=attackoncoulomn) {
           if(board[fail][utre]!=' ') {
            printf("bosbos_RIGHTLEFT_QUEENwhite\n");
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow&&utre==attackoncoulomn){
            valid=1;
            printf("lalala_RIGHTLEFT_QUEEN_white\n");
                        counter_dup++;


        }
}






/////////////////////////////////////////////////////////
///function to see if there is any piece that will eat enemy piece that checked the king///
void DISCOVER_EAT_PIECE_CHECK(int attackonrow,int attackoncoulomn){
if(count_check_player2==1){
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==white[c]){
               int   protect_row=i;
               int protect_col=j;
         if(white[c]=='P'){
        ///*pawn check if it can eat checked piece to king///
         if(((attackonrow==i+1)&&(attackoncoulomn==j+1))){
               valid=1;
               printf("1\n");
               break;
                 }
        else if(((attackonrow==i+1)&&(attackoncoulomn==j-1))){
        valid=1;
        printf("2\n");
        break;
            }}
      else if(white[c]=='N'){
            ///*KNIGHT check if it can eat checked piece to king///
      if ((attackonrow==i+2) &&(attackoncoulomn==j+1)) {
          valid=1;
          printf("3\n");
          break;
          }
            else if ((attackonrow==i+2) &&(attackoncoulomn==j-1)){
               if( (j-1) > -1 ) {
            valid=1;
            printf("4\n");
            break; }}

    else if((attackonrow==i+1) &&(attackoncoulomn==j+2)) {
            if( (j+2) != 8 ){

                valid=1;
                printf("5\n");
                break; }}
    else if ((attackonrow==i-1) &&(attackoncoulomn==j+2)) {
               valid=1;
               printf("6\n");
               break; }

    else if ((attackonrow==i-2) &&(attackoncoulomn==j-1)) {
        if( (j-1) != -1 ){
               valid=1;
               printf("7\n");
               break; }}
    else if ((attackonrow==i-2) &&(attackonrow==j+1)) {
        valid=1;
        printf("8\n");
        break;}

    else if ((attackonrow==i+1) &&(attackoncoulomn==j-2)) {

                        valid=1;
                        printf("9\n");
                                   break; }
    else if ((attackonrow==i-1) &&(attackoncoulomn==j-2)) {
        if( (j-2) != -1 ){
            valid=1;

                                   printf("rt\n");break;
}}}
   ///*KING check if it can eat checked piece to king///
    else if(white[c]=='K'){
      if (attackonrow==i && attackoncoulomn==j+1 ){
          valid=1;
                        printf("tu\n");
                          break;

   }
   else if (attackonrow==i && attackoncoulomn==j-1 ){
       valid=1;
      break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j ){
            valid=1;
                                   printf("bassa\n");
                                   break;
  }
    else if(attackonrow==i-1 && attackoncoulomn==j ){
            valid=1;
                                   printf("yfr\n");
                                   break;

            }
    else if(attackonrow==i+1 && attackoncoulomn==j+1 ) {
            valid=1;
                                   printf("maks\n");
                                   break;
}
    else if(attackonrow==i-1 && attackoncoulomn==j-1 ){
           valid=1;
                                  printf("yarab\n");
                                  break;
}
    else if (attackonrow==i-1 && attackoncoulomn==j+1 ){
            valid=1;
                                   printf("ttt\n");
                                   break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j-1 ){
            valid=1;
                                   printf("f,v\n");
                                   break;
}}
    ///*ROOK check if it can eat checked piece to king///
  else if(white[c]=='R'||white[c]=='Q'){
   ///UP
       for(v=i;v<=8;v++){
        if(board[i+1][j]==board[attackonrow][attackoncoulomn]){
            valid=1;
        printf("ght\n");
            break;}}
      if(j==attackoncoulomn){
        int k=1;
        int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosUP\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
            printf("lalalaUP\n");
        }}
//        else if(board[v+1][j]==' '){
//          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
//                    valid=1;
//                    printf("hurg\n");
//                        break;
    ///down
//    for(v=i;v>=1;v--){
//        if((i-1==attackonrow)&&(j==attackoncoulomn)){
//           valid=1;
//                                   printf("yui\n");
//
//            break;}}
         if(j==attackoncoulomn){int k=-1;
         int z = i+k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosDOWN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
            printf("lalalaDOWN\n");
        }}
     ///right
//     for(v=j;v<=8;v++){
//        if((i==attackonrow)&&(j+1==attackoncoulomn)){
//                      valid=1;
//            printf("rcxzas\n");
//            break;}}
     if(i==attackonrow){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosRIGHT\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
            printf("lalalaRIGHT\n");
        }}

          ///left
    for(v=j;v>=1;v--){
        if((i==attackonrow)&&(j-1==attackoncoulomn)){
                      valid=1;
                printf("gtrs\n");
                      break;}}
      if(i==attackonrow){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosLEFT\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
            printf("lalalaLEFT\n");
        }}
        }
            ///*BISHOP check if it can eat checked piece to king///
    else if(white[c]=='B'||white[c]=='Q'){
//   ///up_right
//         for(v=1;v<=8;v++){
//        if(((i+1)==attackonrow)&&((j+1)==attackoncoulomn)){
//            valid=1;
//               printf("1LFKDU\n");
//            break;}
//        else if(board[i+1][j+1]==' '){
//          if(((i+1+v)==attackonrow)&&((j+1+v)==attackoncoulomn)){
//            valid=1;
//               printf("DKLSNJVOS");
//               break;}}}
//    ///up_left
//        for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&(j+1==attackoncoulomn)){
//            valid=1;
//               printf("1DSHOVIOSJDPOC MC;KLSDK\n");
//               break;}
//        else if(board[i-1][j+1]==' '){
//            if(((i-(v+1))==attackonrow)&&(j+(v+1)==attackoncoulomn)){
//            valid=1;
//            printf("FNKLWFPWEDSL,DS,DWKEF[PE;DW]A546");
//            break;}}}
//         for(v=1;v<=8;v++){
//        if (((i+1)==attackonrow)&&(j-1==attackoncoulomn)){
//           valid=1;
//            printf("GRIOEJG865865S4");
//            return;
//         }
//        else if(board[i+(1)][j-(1)]==' '){
//            if((i+(v+1)==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("01271400542");
//               break;
//            }}}
//          ///left
//           for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&((j-1)==attackoncoulomn)){
//           valid=1;
//            printf("KPRO;DSKPGPOPSPQ5525E8");
//            break;
//         }
//        else if(board[i-(1)][j-(1)]==' '){
//            if(((i-(v+1))==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("1IJGROPKLLDOLDLLDOWklLO");
//               break;}}}}
      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            printf("lalalarightright\n");
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;
        while(x != attackonrow&&y!=attackoncoulomn) {
           if(board[x][y]!=' ') {
            printf("bosbosrightright\n");
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow&&y==attackoncoulomn){
            valid=1;
            printf("lalalarightright\n");
        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow&&uu!=attackoncoulomn) {
           if(board[f][uu]!=' ') {
            printf("bosbos_LEFTRIGHT\n");
            break;}
            else{ f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow&&uu==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTRIGHT\n");
        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow&&u37!=attackoncoulomn) {
           if(board[f64][u37]!=' ') {
            printf("bosbos_LEFTLEFT\n");
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow&&u37==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTLEFT\n");
        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow&&utre!=attackoncoulomn) {
           if(board[fail][utre]!=' ') {
            printf("bosbos_RIGHTLEFT\n");
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow&&utre==attackoncoulomn){
            valid=1;
            printf("lalala_RIGHTLEFT\n");
        }

}

///*QUEEN check if it can eat checked piece to king///
else if(white[c]=='Q'){
     valid_queen_white(attackonrow,attackoncoulomn);
}
}}}}

}
printf("\nUOKK%d\n",valid);
int p=valid;
printf("fff%d\n",attackonrow);
printf("fff%d\n",attackoncoulomn);
}
void queen_verify(int attackonrow,int attackoncoulomn){
   ///UP
//       for(v=i;v<=8;v++){
//        if(board[i+1][j]==board[attackonrow][attackoncoulomn]){
//            valid=1;
//        printf("ght\n");
//            break;}}
      if(j==attackoncoulomn){
        int k=1;
        int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosUP_QUEEN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
            printf("lalalaUP_QUEEN\n");
                        counter_dup++;

        }}
//        else if(board[v+1][j]==' '){
//          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
//                    valid=1;
//                    printf("hurg\n");
//                        break;
    ///down
    for(v=i;v>=1;v--){
        if((i-1==attackonrow)&&(j==attackoncoulomn)){
           valid=1;
                                  printf("yui_QUEEN\n");
            counter_dup++;
            break;}}
         if(j==attackoncoulomn){
         int k=-1;
         int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosDOWN_QUEEN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
                        counter_dup++;

            printf("lalalaDOWN_QUEEN\n");
        }}
     ///right
//     for(v=j;v<=8;v++){
//        if((i==attackonrow)&&(j+1==attackoncoulomn)){
//                      valid=1;
//            printf("rcxzas\n");
//            break;}}
     if(i==attackonrow){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosRIGHT_QUEEN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
            counter_dup++;
        }}

          ///left
//    for(v=j;v>=1;v--){
//        if((i==attackonrow)&&(j-1==attackoncoulomn)){
//                      valid=1;
//                printf("gtrs\n");
//                      break;}}
      if(i==attackonrow){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosLEFT_QUEEN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
                        counter_dup++;
            printf("lalalaLEFT_QUEEN\n");
        }}

            ///*BISHOP check if it can eat checked piece to king///

//   ///up_right
//         for(v=1;v<=8;v++){
//        if(((i+1)==attackonrow)&&((j+1)==attackoncoulomn)){
//            valid=1;
//               printf("1LFKDU\n");
//            break;}
//        else if(board[i+1][j+1]==' '){
//          if(((i+1+v)==attackonrow)&&((j+1+v)==attackoncoulomn)){
//            valid=1;
//               printf("DKLSNJVOS");
//               break;}}}
//    ///up_left
//        for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&(j+1==attackoncoulomn)){
//            valid=1;
//               printf("1DSHOVIOSJDPOC MC;KLSDK\n");
//               break;}
//        else if(board[i-1][j+1]==' '){
//            if(((i-(v+1))==attackonrow)&&(j+(v+1)==attackoncoulomn)){
//            valid=1;
//            printf("FNKLWFPWEDSL,DS,DWKEF[PE;DW]A546");
//            break;}}}
//         for(v=1;v<=8;v++){
//        if (((i+1)==attackonrow)&&(j-1==attackoncoulomn)){
//           valid=1;
//            printf("GRIOEJG865865S4");
//            return;
//         }
//        else if(board[i+(1)][j-(1)]==' '){
//            if((i+(v+1)==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("01271400542");
//               break;
//            }}}
//          ///left
//           for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&((j-1)==attackoncoulomn)){
//           valid=1;
//            printf("KPRO;DSKPGPOPSPQ5525E8");
//            break;
//         }
//        else if(board[i-(1)][j-(1)]==' '){
//            if(((i-(v+1))==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("1IJGROPKLLDOLDLLDOWklLO");
//               break;}}}}
printf("\n\n SSSSSSSS %d %d", attackonrow, attackoncoulomn);
      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            printf("lalalarightright_QUEEN\n");
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow&&y!=attackoncoulomn) {
           if(board[x][y]!=' ') {
            printf("bosbosrightright_QUEEN\n");
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow&&y==attackoncoulomn){
            valid=1;
            printf("lalalarightright_QUEEN\n");
                        counter_dup++;

        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow&&uu!=attackoncoulomn) {
           if(board[f][uu]!=' ') {
            printf("bosbos_LEFTRIGHT_QUEEN\n");
            break;}
            else{
                    f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow&&uu==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTRIGHT_QUEEN\n");
                        counter_dup++;

        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow&&u37!=attackoncoulomn) {
           if(board[f64][u37]!=' ') {
            printf("bosbos_LEFTLEFT_QUEEN\n");
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow&&u37==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTLEFT_QUEEN\n");
                        counter_dup++;

        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow&&utre!=attackoncoulomn) {
           if(board[fail][utre]!=' ') {
            printf("bosbos_RIGHTLEFT_QUEEN\n");
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow&&utre==attackoncoulomn){
            valid=1;
            printf("lalala_RIGHTLEFT_QUEEN\n");
                        counter_dup++;


        }
}
/////////////////////////////////////////////////////////
///function to see if there is any piece that will eat enemy piece that checked the king///
void DISCOVER_EAT_PIECE_CHECK_white(int attackonrow,int attackoncoulomn){
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==black[c]){
               int  protect_row=i;
               int protect_col=j;
         if(black[c]=='p'){
        ///*pawn check if it can eat checked piece to king///
         if(((attackonrow==i-1)&&(attackoncoulomn==j-1))){
               valid=1;
               printf("1\n");
               counter_dup++;
               break;
                 }
        else if(((attackonrow==i-1)&&(attackoncoulomn==j+1))){
        valid=1;
        printf("2\n");
        counter_dup++;
        break;
            }}
      else if(black[c]=='n'){
    ///*KNIGHT check if it can eat checked piece to king///
      if ((attackonrow==i+2) &&(attackoncoulomn==j+1)) {
          valid=1;
          printf("3\n");
          counter_dup++;
          break;
          }
            else if ((attackonrow==i+2) &&(attackoncoulomn==j-1)){
               if( (j-1) > -1 ) {
            valid=1;
            printf("4\n");
            counter_dup++;
break; }}

    else if((attackonrow==i+1) &&(attackoncoulomn==j+2)) {
            if( (j+2) != 8 ){

                valid=1;
                printf("5\n");
                counter_dup++;
                break; }}
    else if ((attackonrow==i-1) &&(attackoncoulomn==j+2)) {
               valid=1;
               printf("6\n");
               counter_dup++;
               break; }

    else if ((attackonrow==i-2) &&(attackoncoulomn==j-1)) {
        if( (j-1) != -1 ){
               valid=1;
               printf("7\n");
               counter_dup++;
               break; }}
    else if ((attackonrow==i-2) &&(attackoncoulomn==j+1)) {
        valid=1;
        printf("8\n");
        counter_dup++;
        break;}

    else if ((attackonrow==i+1) &&(attackoncoulomn==j-2)) {

                        valid=1;
                                   printf("9\n");
                                   counter_dup++;
                                   break; }
    else if ((attackonrow==i-1) &&(attackoncoulomn==j-2)) {
        if( (j-2) != -1 ){
            valid=1;
                                   printf("rt\n");
                        counter_dup++;
                                   break;
}}}
   ///*KING check if it can eat checked piece to king///
    else if(black[c]=='k'){
      if (attackonrow==i && attackoncoulomn==j+1 ){
          valid=1;
                          printf("tu\n");
                        counter_dup++;
                          break;

   }
   else if (attackonrow==i && attackoncoulomn==j-1 ){
       valid=1;
    counter_dup++;
      break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j ){
            valid=1;
                                   printf("bassa\n");
                      counter_dup++;
                                   break;
  }
    else if(attackonrow==i-1 && attackoncoulomn==j ){
            valid=1;
                                   printf("yfr\n");
                               counter_dup++;
                                   break;

            }
    else if(attackonrow==i+1 && attackoncoulomn==j+1 ) {
            valid=1;
                                   printf("maks\n");
                               counter_dup++;
                                   break;
}
    else if(attackonrow==i-1 && attackoncoulomn==j-1 ){
           valid=1;
                                  printf("yarab\n");
                                counter_dup++;
                                  break;
}
    else if (attackonrow==i-1 && attackoncoulomn==j+1 ){
            valid=1;
                                   printf("ttt\n");
                                counter_dup++;
                                   break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j-1 ){
            valid=1;
                                   printf("f,v\n");
                                   counter_dup++;
                                   break;
}}
    ///*ROOK check if it can eat checked piece to king///
  else if(black[c]=='r'){
   ///UP
//       for(v=i;v<=8;v++){
//        if(board[i+1][j]==board[attackonrow][attackoncoulomn]){
//            valid=1;
//        printf("ght\n");
//            break;}}
      if(j==attackoncoulomn){
        int k=1;
        printf("i %d j %d",i,j);
        int z = i + k;
        printf("z %d attackonrow %d",z,attackonrow);
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosUP\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
            printf("lalalaUP\n");
                        counter_dup++;

        }}
//        else if(board[v+1][j]==' '){
//          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
//                    valid=1;
//                    printf("hurg\n");
//                        break;
    ///down
    for(v=i;v>=1;v--){
        if((i-1==attackonrow)&&(j==attackoncoulomn)){
           valid=1;
                                  printf("yui\n");
            counter_dup++;
            break;}}
         if(j==attackoncoulomn){
         int k=-1;
         int z = i + k;
        printf("z %d attackonrow %d\n",z,attackonrow);
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                    printf("bosbosDOWN\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
                        counter_dup++;

            printf("lalalaDOWN\n");
        }}
     ///right
//     for(v=j;v<=8;v++){
//        if((i==attackonrow)&&(j+1==attackoncoulomn)){
//                      valid=1;
//            printf("rcxzas\n");
//            break;}}
     if(i==attackonrow){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosRIGHT\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
            counter_dup++;
        }}

          ///left
//    for(v=j;v>=1;v--){
//        if((i==attackonrow)&&(j-1==attackoncoulomn)){
//                      valid=1;
//                printf("gtrs\n");
//                      break;}}
      if(i==attackonrow){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                    printf("bosbosLEFT\n");
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
                        counter_dup++;
            printf("lalalaLEFT\n");
        }}
        }
            ///*BISHOP check if it can eat checked piece to king///
    else if(black[c]=='b'){
//   ///up_right
//         for(v=1;v<=8;v++){
//        if(((i+1)==attackonrow)&&((j+1)==attackoncoulomn)){
//            valid=1;
//               printf("1LFKDU\n");
//            break;}
//        else if(board[i+1][j+1]==' '){
//          if(((i+1+v)==attackonrow)&&((j+1+v)==attackoncoulomn)){
//            valid=1;
//               printf("DKLSNJVOS");
//               break;}}}
//    ///up_left
//        for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&(j+1==attackoncoulomn)){
//            valid=1;
//               printf("1DSHOVIOSJDPOC MC;KLSDK\n");
//               break;}
//        else if(board[i-1][j+1]==' '){
//            if(((i-(v+1))==attackonrow)&&(j+(v+1)==attackoncoulomn)){
//            valid=1;
//            printf("FNKLWFPWEDSL,DS,DWKEF[PE;DW]A546");
//            break;}}}
//         for(v=1;v<=8;v++){
//        if (((i+1)==attackonrow)&&(j-1==attackoncoulomn)){
//           valid=1;
//            printf("GRIOEJG865865S4");
//            return;
//         }
//        else if(board[i+(1)][j-(1)]==' '){
//            if((i+(v+1)==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("01271400542");
//               break;
//            }}}
//          ///left
//           for(v=1;v<=8;v++){
//        if (((i-1)==attackonrow)&&((j-1)==attackoncoulomn)){
//           valid=1;
//            printf("KPRO;DSKPGPOPSPQ5525E8");
//            break;
//         }
//        else if(board[i-(1)][j-(1)]==' '){
//            if(((i-(v+1))==attackonrow)&&(j-(v+1)==attackoncoulomn)){
//            valid=1;
//               printf("1IJGROPKLLDOLDLLDOWklLO");
//               break;}}}}
printf("\n\n SSSSSSSS %d %d", attackonrow, attackoncoulomn);
      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            printf("lalalarightright\n");
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow&&y!=attackoncoulomn) {
           if(board[x][y]!=' ') {
            printf("bosbosrightright\n");
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow&&y==attackoncoulomn){
            valid=1;
            printf("lalalarightright\n");
                        counter_dup++;

        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow&&uu!=attackoncoulomn) {
           if(board[f][uu]!=' ') {
            printf("bosbos_LEFTRIGHT\n");
            break;}
            else{
                    f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow&&uu==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTRIGHT\n");
                        counter_dup++;

        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow&&u37!=attackoncoulomn) {
           if(board[f64][u37]!=' ') {
            printf("bosbos_LEFTLEFT\n");
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow&&u37==attackoncoulomn){
            valid=1;
            printf("lalala_LEFTLEFT\n");
                        counter_dup++;

        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow&&utre!=attackoncoulomn) {
           if(board[fail][utre]!=' ') {
            printf("bosbos_RIGHTLEFT\n");
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow&&utre==attackoncoulomn){
            valid=1;
            printf("lalala_RIGHTLEFT\n");
                        counter_dup++;


        }

}

///*QUEEN check if it can eat checked piece to king///
else if(black[c]=='q'){
     queen_verify(attackonrow,attackoncoulomn);
}
}}}}


printf("\nUOKK%d\n",valid);
int p=valid;
printf("fff%d\n",attackonrow);
printf("fff%d\n",attackoncoulomn);
           printf("DUPLICATION %d\n",counter_dup);
            if(counter_dup>1){
                counter_dup=1;
            }
            sum=sum+counter_dup;
            counter_dup=0;
            printf("SUM %d\n",sum);
}
///////////////////////////////////////////display
void display(){
 for (i=8;i>=0;i--){
        for(j=0;j<9;j++){
            printf("%c ||",board[i][j]);
        }
        printf("\n");
    }
}
/////////////////////////////////////////place
int read_place(char file[25]){
int p;
char file3=file;
int rank_place;

switch(file3){
case 'A':{
   p=1;
    break;
}
case 'B':{
   p=2;
    break;
}
case 'C':{
   p=3;
    break;
}
case 'D':{
   p=4;
    break;
}
case 'E':{
   p=5;
    break;
}
case 'F':{
   p=6;
    break;
}
case 'G':{
   p=7;
    break;
}
case 'H':{
   p=8;
    break;
}
default:{
printf("Invalid!\n");
}
}
return p;
}
//////////////
void print_g(){
 printf("Enter file of the place2 that you want\n");
        scanf(" %c %d",&file6,&rank_place6);
        v2=rank_place6*10;
        x2=read_place(file6);
        p2=v2+x2;
        c2 = p2 % 10 ;
        r2 = p2 / 10  ;
        }
//////////////////

/////////////////
void print_eat(){
    printf("Eaten black pieces: \n");
    for (i=0;i<kw;i++){
        printf("%c, ",eaten_white[i]);
    }

printf("\nEaten white pieces: \n");
 for (j=0;j<kb;j++){
        printf("%c, ",eaten_black[j]);
    }
}
//////////////////
void eat_white(){
    eaten_white[kw]=black[i];
    kw++;
}
//////////////////
void eat_black(){
    eaten_black[kb]=white[i];
    kb++;
}
///////////////////////////////////////////////////////////////piece_change
void read_piece(int rank_place,int c,int rank,int c2){
    char file;

  board[rank][c2]= board[rank_place][c];
  board[rank_place][c]=' ';
  count_play=0;
  display();

}
//////////////////////////
void compare_white_black(int r1,int c1){
for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1][c1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  }
                   }
                   else if(count_play==2){
                     if(board[r1][c1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;}
                      }
                      }
                      }


//////////////////////////////check piece white
void pawn_white( int r1 , int c1 )
{
       print_g();

   if( pwstatus[c1] == 0 )
    {
        if((c2==c1 && r2==r1+1)){
           if(board[r1+1][c1]==' '){
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnwhite(r2,c2);
        }
        }
        if((c2==c1 &&r2==r1+2)){
           if((board[r1+1][c1]==' ')&&(board[r1+2][c1]==' ')){
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnwhite(r2,c2);
        }
        }
        else if(((r2==r1+1)&&(c2==c1+1))&&(board[r1+1][c1+1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1+1][c1+1]==black[i])){
              pwstatus[c1]++;
              eat_white();
              read_piece(r1,c1,r2,c2) ;
             ch_pawnwhite(r2,c2);
            }
             else if(board[r1+1][1]==black[i]){
                pwstatus[c1]++;
              eaten_white[kw]=black[i];
               kw++;
               read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);

            }
                }
                 }
        else if(((r2==r1+1)&&(c2==c1-1))&&(board[r1+1][c1-1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1+1][c1-1]==black[i])){
              pwstatus[c1]++;
              eat_white();
              read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);
            }
            }
            }
            }
     else if(pwstatus[c1]>=1)
    {
          if((c2==c1 && r2==r1+1)){
           if(board[r1+1][c1]==' '){
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);
                printf("r= %d , c = %d", r1,c1);
                promoteBlack(r1,c1,p);

        }
        }

        if(((r2==r1+1)&&(c2==c1+1))&&(board[r1+1][c1+1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1+1][c1+1]==black[i])){
              pwstatus[c1]++;
              eat_white();
              read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);
                promoteBlack(r1,c1,p);

            }
//             else if(board[r1+1][1]==black[i]){
//                pwstatus[c1]++;
//              eaten_white[kw]=black[i];
//               kw++;
//               read_piece(r1,c1,r2,c2) ;
//                ch_pawnwhite(r2,c2);
//                 promoteblack(r1,c1);
//                printf("Promote to piece:\n");
//                scanf(" %c ", &p);
//                blackverify(p);

                }
                 }
        else if(((r2==r1+1)&&(c2==c1-1))&&(board[r1+1][c1-1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1+1][c1-1]==black[i])){
              pwstatus[c1]++;
              eat_white();
              read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);
                promoteBlack(r1,c1,p);

            }
                }
                 }
              }
    else{
        printf("Invalid position!!\n");
    }
    print_eat();
    }

    //////////////////////////////check piece white
void pawn_black( int r1 , int c1 )
{
        print_g();
   if( pbstatus[c1] == 0 )
    {if((c2==c1 && r2==r1-1)){
           if(board[r1-1][c1]==' '){
            pbstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

        }
        }
        if((c2==c1 &&r2==r1-2)){
           if((board[r1-1][c1]==' ')&&(board[r1-2][c1]==' ')){
            pbstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();
        }
        }
        if(((r2==r1-1)&&(c2==c1-1))&&(board[r1-1][c1-1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1-1][c1-1]==white[i])){
              pbstatus[c1]++;
              eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_pawnblack(r2,c2);
             if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

            }
             else if(board[r1+1][1]==white[i]){
                pbstatus[c1]++;
              eaten_black[kw]=white[i];
               kb++;
               read_piece(r1,c1,r2,c2) ;
               ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();
            }
                }
                 }
        else if(((r2==r1-1)&&(c2==c1+1))&&(board[r1-1][c1+1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1-1][c1+1]==white[i])){
              pbstatus[c1]++;
              eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();
            }
            }
            }

                 }
    else if(pbstatus[c1]>=1)
    {
   {if((c2==c1 && r2==r1-1)){
           if(board[r1-1][c1]==' '){
            pbstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            promoteWhite(r1,c1,p);
            KIng_white_indanger();

        }
        }
        if(((r2==r1-1)&&(c2==c1-1))&&(board[r1-1][c1-1]!=' ')){
        for (i=0;i<6;i++){
            if((board[r1-1][c1-1]==white[i])){
              pbstatus[c1]++;
              eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            promoteWhite(r1,c1,p);
            KIng_white_indanger();

            }
                }
                 }
        else if(((r2==r1-1)&&(c2==c1+1))&&(board[r1-1][c1+1]!=' ')){
        for (i=0;i<9;i++){
            if((board[r1-1][c1+1]==white[i])){
              pbstatus[c1]++;
              eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_pawnblack(r2,c2);
              promoteWhite(r1,c1,p);
              KIng_white_indanger();
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            promoteWhite(r1,c1,p);
            KIng_white_indanger();

            }
            }
            }
                 }
    }
    else{
        printf("Invalid position!!");
    }
    print_eat();
    }
/////////////////////KING
void king( int r1 , int c1 )
{
        print_g();
    if (r2==r1 && c2==c1+1 ){
       if( board[r1][c1+1] == ' ' ){
            read_piece(r1,c1,r2,c2);
            KIng_white_indanger();
            }
        else if ( board[r1][c1+1] != ' ' ){
           for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2,c2+1);
                          KIng_white_indanger();

                  }
                   }
                   else if(count_play==2){
                     if(board[r1][c1+1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2,c2+1);
//            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            }
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }
              }
                }

   else if (r2==r1 && c2==c1-1 ){
           if (board[r1][c1-1] == ' ') {
                read_piece(r1,c1,r2,c2);
                }
        else if ( board[r1][c1-1] != ' ' ){
           for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2,c2-1);
                          KIng_white_indanger();

                  }
                   }
                   else if(count_play==2){
                     if(board[r1][c1-1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2,c2-1);

            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }
              }
                }

    else if (r2==r1+1 && c2==c1 ){
            if (board[r1+1][c1] == ' ' ) {
            read_piece(r1,c1,r2,c2);
                KIng_white_indanger();

            if(count_play==2){
                                read_piece(r1,c1,r2,c2);

                                      KIng_white_indanger();

            }}
            else if ( board[r1+1][c1] != ' ' ){
          for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2);
                          KIng_white_indanger();

                  }
                   }
                   else if(count_play==2){
                     if(board[r1+1][c1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2+1,c2);

//            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            }
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }
                 }
                   }


    else if(r2==r1-1 && c2==c1 ){
             if (board[r1-1][c1] == ' ' )
    {
                read_piece(r1,c1,r2,c2);


         }
         else if ( board[r1-1][c1] != ' ' ){
for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2);
                                            KIng_white_indanger();

                  }
                   }
                   else if(count_play==2){
                     if(board[r1-1][c1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2-1,c2);
//            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);

//            }
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);

}
                      }
                      }                 }
    }
    else if(r2==r1+1 && c2==c1+1 ) {
            if (board[r1+1][c1+1] == ' ')
    {
                        read_piece(r1,c1,r2,c2);
                        KIng_white_indanger();


    }
            else if ( board[r1+1][c1+1] != ' ' ){
            for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2+1);
                          KIng_white_indanger();

                  }
                   }
                   else if(count_play==2){
                     if(board[r1+1][c1+1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2+1,c2+1);
//            if(count_check_player2==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            }
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }                           }
                            }
    else if(r2==r1-1 && c2==c1-1 ){
            if( board[r1-1][c1-1] == ' ' ){
                    read_piece(r1,c1,r2,c2) ;
                          KIng_white_indanger();

            }
               else if ( board[r1-1][c1-1] != ' ' ){
          for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1-1]==black[i]){
                  eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2-1);

                  }
                   }
                   else if(count_play==2){
                     if(board[r1-1][c1-1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2-1,c2-1);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }                                     }
                                      }
    else if (r2==r1-1 && c2==c1+1 ){
            if(board[r1-1][c1+1] == ' '){
                             read_piece(r1,c1,r2,c2);
                                                       KIng_white_indanger();


                                          }
            else if ( board[r1-1][c1+1] != ' ' ){
               for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2+1);
                  }
                   }
                   else if(count_play==2){
                     if(board[r1-1][c1+1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2-1,c2+1);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }                         }
                          }
    else if (r2==r1+1 && c2==c1-1 ){
            if( board[r1+1][c1-1] == ' ' ){
                    read_piece(r1,c1,r2,c2) ;
            }
             else if ( board[r1+1][c1-1] != ' ' ){
             for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2-1);
                  }
                   }
                   else if(count_play==2){
                     if(board[r1+1][c1-1]==white[i]){
                      eat_black();
                      read_piece(r1,c1,r2,c2) ;
                      ch_king_black(r2+1,c2-1);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

}
                      }
                      }                     }
                      }
    else  {
        printf("not available\n");
    }
    print_eat();

}

/////////////////////////////////////////////////// knight
void knight( int r1 , int c1 )
{
       print_g();
    if(count_play==1){
    if ((r2==r1+2) &&(c2==c1+1)) {
       if (board[r1+2][c1+1] == ' ' ) {
            read_piece(r1,c1,r2,c2) ;
            ch_knight_white(r2,c2);

                           }
             else if ( board[r1+2][c1+1] != ' ' ){
               for (i=0;i<9;i++){
                 if(board[r1+2][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);}}}}
            else if ((r2==r1+2) &&(c2==c1-1)){
               if( (c1-1) > -1 ) {
                if (board[r1+2][c1-1] == ' ' ) {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_white(r2,c2);
            }
            else if ( board[r1+2][c1-1] != ' ' ){
             for (i=0;i<9;i++){
                 if(board[r1+2][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }}}}}

    else if((r2==r1+1) &&(c2==c1+2)) {
            if( (c1+2) != 8 ){
                if (board[r1+1][c1+2] == ' ' ) {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_white(r2,c2);
            }
            else if ( board[r1+1][c1+2] != ' ' ){
              for (i=0;i<9;i++){
                 if(board[r1+1][c1+2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);}}}}}
    else if ((r2==r1-1) &&(c2==c1+2)) {
                if (board[r1-1][c1+2] == ' ' ) {
                    read_piece(r1,c1,r2,c2) ;
                    ch_knight_white(r2,c2);
            }
                else if ( board[r1-1][c1+2] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-1][c1+2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }}}}

    else if ((r2==r1-2) &&(c2==c1-1)) {

        if( (c1-1) != -1 ){
                if (board[r1-2][c1-1] == ' '){
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                    }
            else if ( board[r1-2][c1-1] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                   }}}}}

    else if ((r2==r1-2) &&(c2==c1+1)) {
        if (board[r1-2][c1+1] == ' ' ) {
                read_piece(r1,c1,r2,c2);
                ch_knight_white(r2,c2);
        }
        else if ( board[r1-2][c1+1] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                   }}}}

    else if ((r2==r1+1) &&(c2==c1-2)) {
            if (board[r1+1][c1-2] == ' ' )
    {
        read_piece(r1,c1,r2,c2)  ;
        ch_knight_white(r2,c2);
    }
    else if ( board[r1+1][c1-2] != ' ' ){
                 for (i=0;i<9;i++){
                 if(board[r1+1][c1-2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }}}}
    else if ((r2==r1-1) &&(c2==c1-2)) {

        if( (c1-2) != -1 ){
            if(board[r1-1][c1-2] == ' ' ){
            read_piece(r1,c1,r2,c2) ;
            ch_knight_white(r2,c2);
            }
            else if ( board[r1-1][c1-2] != ' ' ){
              for (i=0;i<9;i++){
                 if(board[r1-1][c1-2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);}
                   }}}}}
    else if(count_play==2){
    if ((r2==r1+2) &&(c2==c1+1)) {
       if (board[r1+2][c1+1] == ' ' ) {
            read_piece(r1,c1,r2,c2) ;
            ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                           }
             else if ( board[r1+2][c1+1] != ' ' ){
               for (i=0;i<9;i++){
                 if(board[r1+2][c1+1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }}}}
          else if ((r2==r1+2) &&(c2==c1-1)){
               if( (c1-1) > -1 ) {
                if (board[r1+2][c1-1] == ' ' ) {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

            }
            else if ( board[r1+2][c1-1] != ' ' ){
             for (i=0;i<9;i++){
                 if(board[r1+2][c1-1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }}}}}

    else if((r2==r1+1) &&(c2==c1+2)) {
            if( (c1+2) != 8 ){
                if (board[r1+1][c1+2] == ' ' ) {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
            else if ( board[r1+1][c1+2] != ' ' ){
              for (i=0;i<9;i++){
                 if(board[r1+1][c1+2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                }}}}}
         else if ((r2==r1-1) &&(c2==c1+2)) {
                if (board[r1-1][c1+2] == ' ' ) {
                    read_piece(r1,c1,r2,c2) ;
                    ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
                else if ( board[r1-1][c1+2] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-1][c1+2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                 }}}}

    else if ((r2==r1-2) &&(c2==c1-1)) {

        if( (c1-1) != -1 ){
                if (board[r1-2][c1-1] == ' '){
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                    }
                else if ( board[r1-2][c1-1] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1-1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                   }}}}}

    else if ((r2==r1-2) &&(c2==c1+1)) {
        if (board[r1-2][c1+1] == ' ' ) {
                read_piece(r1,c1,r2,c2);
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


        }
        else if ( board[r1-2][c1+1] != ' ' ){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1+1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                   }}}}

    else if ((r2==r1+1) &&(c2==c1-2)) {
            if (board[r1+1][c1-2] == ' ' )
    {
        read_piece(r1,c1,r2,c2)  ;
        ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


    }
    else if ( board[r1+1][c1-2] != ' ' ){
                 for (i=0;i<9;i++){
                 if(board[r1+1][c1-2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }}}}
    else if ((r2==r1-1) &&(c2==c1-2)) {

        if( (c1-2) != -1 ){
            if(board[r1-1][c1-2] == ' ' ){
            read_piece(r1,c1,r2,c2) ;
            ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
            else if ( board[r1-1][c1-2] != ' ' ){
              for (i=0;i<9;i++){
                 if(board[r1-1][c1-2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);}
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                   }}}}}
                   else{
                    printf("\n not available\n");
                   }
    print_eat();
}
///////////////////////////////////
//void bishop( int r1 , int c1 )
//{
//    int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
//        printf("Enter file of the place2 that you want\n");
//        scanf(" %c %d",&file6,&rank_place6);
//        v2=rank_place6*10;
//        x2=read_place(file6);
//        p2=v2+x2;
//        c2 = p2 % 10 ;
//        r2 = p2 / 10  ;
//    if(r1 == r2 || c1 == c2)
//        return;
//    else if(abs(r1-r2) == abs(c1-c2)) {
//        int n, m, n1, m1, x, y;
//        n = r2 - r1;
//        m = c2 - c1;
//        n1 = n / abs(n);
//        m1 = m / abs(m);
//
//        x = r1 + n1;
//        y = c1 + m1;
//        while(x != r2) {
//            printf("yaaaaaaaaa");
//            x = x + n1;
//            y = y + m1;
//            if(board[x][y] != ' ' && x != r2) {
//                return;
//            }
//        }
//        if(board[r2][c2] != ' ') {
//            for (i=0;i<9;i++){
//            if (count_play==1){
//             if(board[r2][c2]==black[i]){
//                eat_white();
//                read_piece(r1,c1,r2,c2) ;
//                 }
//                  }
//            else if (count_play==2){
//                if(board[r2][c2]==white[i]){
//                eat_black();
//              read_piece(r1,c1,r2,c2) ;
//            }
//            }
//              }
//                }
//            else
//                read_piece(r1,c1,r2,c2);
//    }
//    print_eat();
//}
void bishop( int r1 , int c1 )
{
    int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
        printf("Enter file of the place2 that you want\n");
        scanf(" %c %d",&file6,&rank_place6);
        v2=rank_place6*10;
        x2=read_place(file6);
        p2=v2+x2;
        c2 = p2 % 10 ;
        r2 = p2 / 10  ;
    while (r1 == r2 || c1 == c2)
        {
                printf("Invalid input. Please enter again: ");
                printf("Enter file of the place2 that you want\n");
                scanf(" %c %d",&file6,&rank_place6);
                v2=rank_place6*10;
                x2=read_place(file6);
                p2=v2+x2;
                c2 = p2 % 10 ;
                r2 = p2 / 10  ;

            }

  if(abs(r1-r2) == abs(c1-c2)) {
        int n, m, n1, m1, x, y;
        n = r2 - r1;
        m = c2 - c1;
        n1 = n / abs(n);
        m1 = m / abs(m);

        x = r1 + n1;
        y = c1 + m1;
        while(x != r2) {
            x = x + n1;
            y = y + m1;
            if(board[x][y] != ' ' && x != r2) {
                printf("Invalid input. Please enter again: ");
                printf("Enter file of the place2 that you want\n");
                scanf(" %c %d",&file6,&rank_place6);
                v2=rank_place6*10;
                x2=read_place(file6);
                p2=v2+x2;
                c2 = p2 % 10;
                r2 = p2 / 10;
                n = r2 - r1;
                m = c2 - c1;
                n1 = n / abs(n);
                m1 = m / abs(m);

                x = r1 + n1;
                y = c1 + m1;
            }
        }
        if(board[r2][c2] != ' ') {
            for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][c2]==black[i]){
                eat_white();
                read_piece(r1,c1,r2,c2) ;
                ch_bishop_white;
                 }
                  }
            else if (count_play==2){
                if(board[r2][c2]==white[i]){
                eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_king_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

            }
            }
              }
                }
            else {
                if(count_play==1) {
                    read_piece(r1,c1,r2,c2);
                    ch_bishop_white(r2,c2);
                }
                else {
                    read_piece(r1,c1,r2,c2);
                    ch_bishop_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                }
            }
    }
}

//////////////////////////////
void rook( int r1 , int c1 )
{
    int i , j , n, x, m ;
    int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
        printf("Enter file of the place2 that you want\n");
        scanf(" %c %d",&file6,&rank_place6);
        v2=rank_place6*10;
        x2=read_place(file6);
        p2=v2+x2;
        c2 = p2 % 10 ;
        r2 = p2 / 10  ;

    /// horizontal
        if(r1 == r2) {
            if(c1 == c2)
                return;
        else if(c1 < c2)
            n = 1;
        else {
            n = -1;
        }
        x = c1 + n;

        while(x != c2) {
            if(board[r2][x] != ' ') {
                return;
            }
             x = x + n;
              }

        if(board[r2][x] != ' ')
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][x]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,x) ;
                ch_rook_white(r2,c2);
                 }
                  }
        else if (count_play==2){
        if(board[r2][x]==white[i]){
            eat_black();
              read_piece(r1,c1,r2,c2) ;
            ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

            }
            }
              }
                }
            else{if(count_play==1){
                read_piece(r1,c1,r2,c2);
                ch_rook_white(r2,c2);
                }
                else{
               read_piece(r1,c1,r2,c2);
                ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                }
                }
    }
    else if(c1 == c2) {
        if(r1 == r2)
            return;
        else if(r1 <r2)
            m = 1;
        else {
            m = -1;
        }
        x = r1 + m;
        while(x != r2) {
            if(board[x][c2] != ' ') {
                return;
            }
             x = x + m;
              }


            if(board[r2][c2] != ' ')
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][c2]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,c2) ;
                ch_rook_white(r2,c2);
                 }
                  }
            else if (count_play==2){
                if(board[r2][c2]==white[i]){
                eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

            }
            }
              }
                }
            else{
                if(count_play==1) {
                read_piece(r1,c1,r2,c2);
                ch_rook_white(r2,c2);
                }
                else
                    {
                    read_piece(r1,c1,r2,c2);
                    ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                    }
                 }
        }
print_eat();
}


///////////////////////////////////////////////////////////
//void queen( int r1 , int c1 )
//{
//    int n, m, x;
//int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
//        printf("Enter file of the place2 that you want\n");
//        scanf(" %c %d",&file6,&rank_place6);
//        v2=rank_place6*10;
//        x2=read_place(file6);
//        p2=v2+x2;
//        c2 = p2 % 10 ;
//        r2 = p2 / 10  ;
//        ////// diagonaaaaaaaaaaaaaaaaaaaaaaaaaal moveeeeeeeeeeeeeeeessssssssssssssssssssssssssssssssssssssssssss
//
//   if(abs(r1-r2) == abs(c1-c2)) {
//        int n, m, n1, m1, x, y;
//        n = r2 - r1;
//        m = c2 - c1;
//        n1 = n / abs(n);
//        m1 = m / abs(m);
//
//        x = r1 + n1;
//        y = c1 + m1;
//        while(x != r2) {
//            printf("yaaaaaaaaa");
//            x = x + n1;
//            y = y + m1;
//            if(board[x][y] != ' ' && x != r2) {
//                return;
//            }
//        }
//        if(board[r2][c2] != ' ') {
//            for (i=0;i<9;i++){
//            if (count_play==1){
//             if(board[r2][c2]==black[i]){
//               eat_white();
//                read_piece(r1,c1,r2,c2) ;
//                 }
//                  }
//            else if (count_play==2){
//                if(board[r2][c2]==white[i]){
//                eat_black();
//              read_piece(r1,c1,r2,c2) ;
//            }
//            }
//              }
//                }
//            else
//                read_piece(r1,c1,r2,c2);
//    }
//
///// HORIZONTAL
//        if(r1 == r2) {
//            if(c1 == c2)
//                return;
//        else if(c1 < c2)
//            n = 1;
//        else {
//            n = -1;
//        }
//        x = c1 + n;
//
//        while(x != c2) {
//            if(board[r2][x] != ' ') {
//                return;
//            }
//             x = x + n;
//              }
//
//        if(board[r2][x] != ' ')
//            {
//           for (i=0;i<9;i++){
//            if (count_play==1){
//             if(board[r2][x]==black[i]){
//               eat_white();
//                read_piece(r1,c1,r2,x) ;
//                ch_rook_white(r2,x);
//                 }
//                  }
//            else if (count_play==2){
//                if(board[r2][x]==white[i]){
//                eat_black();
//              read_piece(r1,c1,r2,c2) ;
//            }
//            }
//              }
//                }
//            else
//                read_piece(r1,c1,r2,c2);
//    }
//    else if(c1 == c2) {
//        if(r1 == r2)
//            return;
//        else if(r1 <r2)
//            m = 1;
//        else {
//            m = -1;
//        }
//        x = r1 + m;
//        while(x != r2) {
//            if(board[x][c2] != ' ') {
//                return;
//            }
//             x = x + m;
//              }
//
//
//            if(board[r2][c2] != ' ')
//            {
//           for (i=0;i<9;i++){
//            if (count_play==1){
//             if(board[r2][c2]==black[i]){
//               eat_white();
//                read_piece(r1,c1,r2,c2) ;
//                ch_rook_white(r2,c2);
//                 }
//                  }
//            else if (count_play==2){
//                if(board[r2][c2]==white[i]){
//                eat_black();
//              read_piece(r1,c1,r2,c2) ;
//            }
//            }
//              }
//                }
//            else
//                read_piece(r1,c1,r2,c2);
//        }
//print_eat();
//}
/////////////////////////////////////CHECK
//
void player1()
{   count_check=0;
    int p1 , p2 , c1 , r1 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;

    printf( "\nPLAYER 1 - large Case \n") ;
   printf("Enter file of the place1 that you want\n");
    scanf(" %c %d",&file3,&rank_place);
   v1=rank_place*10;
    x1=read_place(file3);
    p1=v1+x1;
    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
  {
        case 'P':
               pawn_white( r1 , c1 ) ;
              count_play=2;
                  break ;
       case 'R': rook( r1 , c1 ) ;
                  count_play=2;
                 break ;
      case 'N': knight( r1 , c1 ) ;
                  count_play=2;
                 break ;
       case 'B': bishop( r1 , c1 ) ;
              count_play=2;
                break ;
       case 'K': king( r1 , c1 ) ;
             count_play=2;
                break ;
      case 'Q': queen( r1 , c1 ) ;
               count_play=2;
               break ;
        default: printf( "Invalid Position ! " ) ;
   }
}
void queen( int r1 , int c1 )
{
    int n, m, x;
int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
        printf("Enter file of the place2 that you want\n");
        scanf(" %c %d",&file6,&rank_place6);
        v2=rank_place6*10;
        x2=read_place(file6);
        p2=v2+x2;
        c2 = p2 % 10 ;
        r2 = p2 / 10  ;
        ////// diagonaaaaaaaaaaaaaaaaaaaaaaaaaal moveeeeeeeeeeeeeeeessssssssssssssssssssssssssssssssssssssssssss

   if(abs(r1-r2) == abs(c1-c2)) {
        int n, m, n1, m1, x, y;
        n = r2 - r1;
        m = c2 - c1;
        n1 = n / abs(n);
        m1 = m / abs(m);

        x = r1 + n1;
        y = c1 + m1;
        while(x != r2) {
            printf("yaaaaaaaaa");
            x = x + n1;
            y = y + m1;
            if(board[x][y] != ' ' && x != r2) {
                return;
            }
        }
        if(board[r2][c2] != ' ') {
            for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][c2]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,c2) ;
                ch_queen_white(r2,c2);
                 }
                  }
            else if (count_play==2){
                if(board[r2][c2]==white[i]){
                eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_queen_black(r2,c2);
                          DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
            }
              }
                }
            else{
                    if(count_play==1){
                read_piece(r1,c1,r2,c2);
                ch_queen_white(r2,c2);}
                else{
                  read_piece(r1,c1,r2,c2);
                ch_queen_black(r2,c2);
                            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                            KIng_white_indanger();

                }
    }}

/// HORIZONTAL
        if(r1 == r2) {
            if(c1 == c2)
                return;
        else if(c1 < c2)
            n = 1;
        else {
            n = -1;
        }
        x = c1 + n;

        while(x != c2) {
            if(board[r2][x] != ' ') {
                return;
            }
             x = x + n;
              }

        if(board[r2][x] != ' ')
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][x]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,x) ;
                ch_queen_white(r2,c2);
                 }
                  }
            else if (count_play==2){
                if(board[r2][x]==white[i]){
                eat_black();
              read_piece(r1,c1,r2,c2) ;
              ch_queen_black(r2,c2);
                          DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                          KIng_white_indanger();

            }
            }
              }
                }
            else{
               if(count_play==1){
                read_piece(r1,c1,r2,c2);
                ch_queen_white(r2,c2);}
                else{
                read_piece(r1,c1,r2,c2);
                ch_queen_black(r2,c2);
                            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                            KIng_white_indanger();

                }}}
    else if(c1 == c2) {
        if(r1 == r2)
            return;
        else if(r1 <r2)
            m = 1;
        else {
            m = -1;
        }
        x = r1 + m;
        while(x != r2) {
            if(board[x][c2] != ' ') {
                return;
            }
             x = x + m;
              }


            if(board[r2][c2] != ' ')
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][c2]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,c2) ;
                ch_queen_white(r2,c2);
                 }
                  }
            else if (count_play==2){
                if(board[r2][c2]==white[i]){
                eat_black();
              read_piece(r1,c1,r2,c2) ;
            ch_queen_black(r2,c2);
                        DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                        KIng_white_indanger();


            }
            }
              }
                }
            else{
                if(count_play==1){
                read_piece(r1,c1,r2,c2);
                ch_queen_white(r2,c2);}
                else{
                read_piece(r1,c1,r2,c2);
                ch_queen_black(r2,c2);
                            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
                            KIng_white_indanger();

                }

        }}
print_eat();
}
///////////////////////////////////player 2
void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
    printf( "\nPLAYER 2 - Small Case \n") ;
    printf("Enter file of the place2 that you want\n");
    scanf(" %c %d",&file3,&rank_place);
    v1=rank_place*10;
    x1=read_place(file3);
    p1=v1+x1;
    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'p': pawn_black(r1,c1) ;
                count_play=1;
                break ;
        case 'r': rook( r1 , c1 ) ;
                count_play=1;
                  break ;
        case 'n': knight( r1 , c1 ) ;
                count_play=1;
                break ;
        case 'b': bishop( r1 , c1 ) ;
                  count_play=1;
                  break ;
        case 'k': king( r1 , c1 ) ;
                count_play=1;
                break ;
        case 'q': queen( r1 , c1 ) ;
                count_play=1;
                  break ;
        default: printf( "Invalid Position ! " ) ;
    }
}
///////////////////////////////////////////////////////////
void ch_pawnwhite(int r2,int c2){
            if((board[r2+1][c2+1]=='k')){
                         count_check=1;
             printf("\nCHECK!!");
                         }
           else if((board[r2+1][c2-1]=='k')){
                         count_check=1;
             printf("\nCHECK!!");
            }
            count_check_player2=0;

    }
///////////////////////////////////////////////////////
void ch_pawnblack(int r2,int c2){
            if((board[r2-1][c2-1]=='K')){
                         count_check=1;
             attackerrow=r2;
            attackcolumn=c2;
}
           else if((board[r2-1][c2+1]=='K')){
                         count_check=1;
             attackerrow=r2;
            attackcolumn=c2;

            }

    }
 ////////////////////////////////////////////////////////////////////
    void ch_king_white(){
         if ( board[r2][c2+1] =='k' ){
            printf("CHECK!!");
                                  count_check=1;
                         }
        else if ( board[r2][c2-1]=='k' ){
                printf("CHECK!!");
                           count_check=1; }
        else if ( board[r2+1][c2] == 'k' ){
                printf("CHECK!!");
                                    count_check=1;  }
        else if ( board[r2-1][c2] == 'k' ){
                printf("CHECK!!");
                                     count_check=1;  }
        else if ( board[r2+1][c2+1] == 'k' ){
                printf("CHECK!!");
                                    count_check=1; }
        else if ( board[r2-1][c2-1] == 'k' ){
             printf("CHECK!!");
                            count_check=1;}
        else if ( board[r2-1][c2+1] == 'k' ){
                printf("CHECK!!");
                                        count_check=1;
}
        else if ( board[r2+1][c2-1] == 'k' ){
                printf("CHECK!!");
                        count_check=1;
                     }


    }
//////////////////////////////////////////////////////////
    void ch_king_black(int r2,int c2){
         if ( board[r2][c2+1] =='K' ){
            printf("CHECK!!\n");
                count_check_player2=1;
                attackerrow=r2,attackcolumn=c2;   }
        else if ( board[r2][c2-1]=='K' ){
                printf("CHECK!!\n");
               count_check_player2=1;
                attackerrow=r2,attackcolumn=c2; }
        else if ( board[r2+1][c2] == 'K' ){
                printf("CHECK!!\n");
                        count_check_player2=1;
                         attackerrow=r2,attackcolumn=c2;   }
        else if ( board[r2-1][c2] == 'K' ){
                printf("CHECK!!\n");
                         count_check_player2=1;
                          attackerrow=r2,attackcolumn=c2;  }
        else if ( board[r2+1][c2+1] == 'K' ){
                printf("CHECK!!\n");
                        count_check_player2=1;
                         attackerrow=r2,attackcolumn=c2;   }
        else if ( board[r2-1][c2-1] == 'K' ){
             printf("CHECK!!\n");
                count_check_player2=1;
                 attackerrow=r2,attackcolumn=c2; }
        else if ( board[r2-1][c2+1] == 'K' ){
                printf("CHECK!!\n");
                count_check_player2=1;
                 attackerrow=r2,attackcolumn=c2;}
        else if ( board[r2+1][c2-1] == 'K' ){
                printf("CHECK!!\n");
                count_check_player2=1;
                 attackerrow=r2,attackcolumn=c2;
                     }

    }
///////////////////////////
void compare_play2(int r1,int c1){
       if(board[r1][c1]=='K'){
                  printf("CHECK!!\n");
                  count_check_player2=1;
                  }
}
///////////////////////////
void compare_play1(int r1,int c1){
       if(board[r1][c1]=='k'){
                  printf("CHECK!!\n");
                              count_check=1;
    }
}

///////////////////////////////
int ch_knight_white(int r2,int c2){
              if ( board[r2+2][c2+1] != ' '){
               compare_play1(r2+2,c2+1);
                               }
            if( (c2-1) > -1 ) {
             if ( board[r2+2][c2-1] != ' ' ){
             compare_play1(r2+2,c2-1);

                 }
                    }
            if( (c2+2) != 8 ){
             if ( board[r2+1][c2+2] != ' ' ){
                compare_play1(r2+1,c2+2);           }  }
                if ( board[r2-1][c2+2] != ' ' ){
                  compare_play1(r2-1,c2+2);
                    }
              if( (c2-1) != -1 )
            {
             if ( board[r2-2][c2-1] != ' ' ){
             compare_play1(r2-2,c2-1); }}
            if ( board[r2-2][c2+1] != ' ' ){
 compare_play1(r2-2,c2+1);
                  }
     if ( board[r2+1][c2-2] != ' ' ){
 compare_play1(r2+1,c2-2);
            }
        if( (c2-2) != -1 ){
             if ( board[r2-1][c2-2] != ' ' ){
          compare_play1(r2-1,c2-2);
            }}

}
///////////////////////////////////////////
int ch_knight_black(int r2,int c2){

              if ( board[r2+2][c2+1] != ' '){
               compare_play2(r2+2,c2+1);
                                       count_check=1;

                attackerrow=r2,attackcolumn=c2;                }
            if( (c2-1) > -1 ) {
             if ( board[r2+2][c2-1] != ' ' ){
             compare_play2(r2+2,c2-1);
                                     count_check=1;

              attackerrow=r2,attackcolumn=c2;
    }
                    }
            if( (c2+2) != 8 ){
             if ( board[r2+1][c2+2] != ' ' ){
 compare_play2(r2+1,c2+2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;              }  }
                if ( board[r2-1][c2+2] != ' ' ){
 compare_play2(r2-1,c2+2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
                    }
              if( (c2-1) != -1 )
            {
             if ( board[r2-2][c2-1] != ' ' ){
             compare_play2(r2-2,c2-1);
                                     count_check=1;

              attackerrow=r2,attackcolumn=c2; }}
            if ( board[r2-2][c2+1] != ' ' ){
 compare_play2(r2-2,c2+1);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
                  }
     if ( board[r2+1][c2-2] != ' ' ){
 compare_play2(r2+1,c2-2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
            }
        if( (c2-2) != -1 ){
             if ( board[r2-1][c2-2] != ' ' ){
          compare_play2(r2-1,c2-2);
                                  count_check=1;

           attackerrow=r2,attackcolumn=c2; }}
}
///**rook_white**///
///////////////////////////////////////////////////
void ch_rook_white(int r2,int c2)
{
    for(i=r2;i<=8;i++){
        if(board[r2+1][c2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            break;}
        else if(board[i+1][c2]==' '){
          if(board[i+2][c2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }
             }
            }
    ///down
    for(i=r2;i>=1;i--){
        if(board[r2-1][c2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            break;}
    else if(board[i-1][c2]==' '){
          if(board[i-2][c2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }
             }
            }
     ///right
     for(i=c2;i<=8;i++){
        if(board[r2][c2+1]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            return;
                    }
        else if(board[r2][i+1]==' '){
          if(board[r2][i+2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }
             }
            }
          ///left
    for(i=c2;i>=1;i--){
        if(board[r2][c2-1]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            break;}
    else if(board[r2][i-1]==' '){
          if(board[r2][i-2]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }
             }
            }
}
void ch_bishop_white(int r2,int c2){
///up_right
         for(i=1;i<=8;i++){
        if(board[r2+1][c2+1]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            return;}
        else if(board[r2+1][c2+1]==' '){
          if(board[r2+1+i][c2+1+i]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }
             }
            }

    ///up_left
        for(i=1;i<=8;i++){
        if (board[(r2-1)][c2+1]=='k'){
            printf("\nCheck!!\n");
                                    count_check=1;

            return;
         }
        else if(board[r2-1][c2+1]==' ')
            if(board[r2-(i+1)][c2+(i+1)]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }}
         for(i=1;i<=8;i++){
        if (board[(r2+1)][c2-1]=='k'){
            printf("\nCheck!!\n");
                                    count_check=1;

            return;
         }
        else if(board[r2+(1)][c2-(1)]==' ')
            if(board[r2+(i+1)][c2-(i+1)]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }}
          ///left
           for(i=1;i<=8;i++){
        if (board[(r2-1)][c2-1]=='k'){
        printf("\nCheck!!\n");
                        count_check=1;
            return;
         }
        else if(board[r2-(1)][c2-(1)]==' ')
            if(board[r2-(i+1)][c2-(i+1)]=='k'){
            printf("\nCheck!!\n");
                        count_check=1;
            }}
}
void ch_rook_black(int r2,int c2)
{
    for(i=r2;i<=8;i++){
        if(board[r2+1][c2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            break;}
        else if(board[i+1][c2]==' '){
          if(board[i+2][c2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
             break;
            }
             }
            }
    ///down
    for(i=r2;i>=1;i--){
        if(board[r2-1][c2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
            attackerrow=r2,attackcolumn=c2;
            break;}
    else if(board[i-1][c2]==' '){
          if(board[i-2][c2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
            attackerrow=r2,attackcolumn=c2;
            }
             }
            }
     ///right
     for(i=c2;i<=8;i++){
        if(board[r2][c2+1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            break;
                    }
        else if(board[r2][i+1]==' '){
          if(board[r2][i+2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
             break;
            }
             }
            }
          ///left
    for(i=c2;i>=1;i--){
        if(board[r2][c2-1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            break;}
    else if(board[r2][i-1]==' '){
          if(board[r2][i-2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
             break;
            }
             }
            }
}
void ch_bishop_black(int r2,int c2){
///up_right
         for(i=1;i<=8;i++){
        if(board[r2+1][c2+1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            return;}
        else if(board[r2+1][c2+1]==' '){
          if(board[r2+1+i][c2+1+i]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            }
             }
            }

    ///up_left
        for(i=1;i<=8;i++){
        if (board[(r2-1)][c2+1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
            attackerrow=r2,attackcolumn=c2;
            return;
         }
        else if(board[r2-1][c2+1]==' ')
            if(board[r2-(i+1)][c2+(i+1)]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            }}
   ///down_right
         for(i=1;i<=8;i++){
        if (board[(r2+1)][c2-1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            return;
         }
        else if(board[r2+(1)][c2-(1)]==' ')
            if(board[r2+(i+1)][c2-(i+1)]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            }}
///down_left
           for(i=1;i<=8;i++){
        if (board[(r2-1)][c2-1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            return;
         }
        else if(board[r2-(1)][c2-(1)]==' ')
            if(board[r2-(i+1)][c2-(i+1)]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            }}
}
void ch_queen_white(int r2,int c2){
ch_rook_white(r2,c2);
ch_bishop_white(r2,c2);
}
void ch_queen_black(int r2,int c2){
ch_rook_black(r2,c2);
ch_bishop_black(r2,c2);
}
void validation_white(int attackonrow,int attackoncoulomn){
DISCOVER_EAT_PIECE_CHECK(attackonrow,attackoncoulomn);
pos_attacki=attackonrow;
pos_attackj=attackoncoulomn;
for(e=0;e<9;e++){
    for (g=0;g<9;g++){
        if(board[e][g]=='K'){
            posi=e;
            posj=g;}}}
if(valid==0){

 for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(c=0;c<6;c++){
            if(board[i][j]=='K'){
            }
        }
    }
 }
 if(board[attackonrow][attackoncoulomn]=='r'){
      ///UP or DOWN or RIGHT or LEFT without any seperation
             ///UP
//             for(int v=1;v<8;v++){
//             DISCOVER_EAT_PIECE_CHECK(attackonrow+v,attackoncoulomn);
//             printf("MONSTER_\n");
//             }
       ///empty place upwared attacked piece
//       int emp_row,emp_col;
//       for(i=0;i<posj;i++){
//        emp_row=attackonrow+i;
//       DISCOVER_EAT_PIECE_CHECK(emp_row,attackoncoulomn);
//       printf("WHAT ARE YOU DOING HERE\n");
//       }
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==white[c]){
    ///*ROOK check if it can eat checked piece to king///
   if(white[c]=='R'){
         ///LEFT_FAR

//        j=pos_rook_j;
//        i=pos_rook_i;
//        attackonrow=pos_attacki;
//         attackoncoulomn=pos_attackj;
        if(j>attackoncoulomn){
        int k=-1;
        int z = j + k;
        int v=1;
        int ppp=attackonrow;
        while(z!=ppp) {
            if(board[i][z]!=' ') {
            printf("bosbosLEFTWOW_FAR\n");
                break;
            }
            else {
                z = z + k;
                ppp=ppp+v;
            }
        }
        if(z == ppp){
            valid=1;
            printf("lalalaLEFTWOW_FAR\n");
        }}
        ///RIGHT

        if(j<attackoncoulomn){
        int k=1;
//        j=pos_rook_j;
//        i=pos_rook_i;
        int z = j + k;
        int v=1;
        int ppp=attackonrow;
        while(z!=ppp) {
            if(board[i][z]!=' ') {
                    printf("bosbosRIGHTWOW_FAR\n");
                break;
            }
            else {
                z = z + k;
                ppp=ppp+v;
            }
        }
        if(z == ppp){
            valid=1;
            printf("lalalaRIGHTWOW_FAR\n");
        }}


        ///UP
//        j=pos_rook_j;
//        i=pos_rook_i;
//        attackonrow=pos_attacki;
//         attackoncoulomn=pos_attackj;
        if(i<attackonrow){
        int k=1;
//        j=pos_rook_j;
//        i=pos_rook_i;
        int z = i + k;


        int v=1;
        int ppp=attackoncoulomn;
        while(z!=ppp) {
            if(board[z][j]!=' ') {
                    printf("bosbosUPWOW_FAR\n");
                break;
            }
            else {
                z = z + k;
                ppp=ppp+v;
            }
        }
        if(z == ppp){
            valid=1;
            printf("lalalaUPWOW_FAR\n");
        }}}
            ///**BISHOP**///
///RIGHT RIGHT

//      if( i+1== attackonrow+u&&j+1==attackoncoulomn){
//            valid=1;
//            printf("lalalarightright\n");
//            counter_dup++;
//        }
       else if(white[c]=='B'&&i!=0&&j!=0){
       ///**up to the right
        int k=1,m=1,u=1;
        int rrrr=attackoncoulomn;
        for(u=0;u<6;u++){
        int x=i+k,y=j+m;
        int rrrr=attackoncoulomn+u;
            printf("I is %d attack on row is %d attackoncolumn is %d J is %d\n",i,attackonrow,attackoncoulomn,j);
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,attackonrow,attackoncoulomn,y);
        while(x != attackonrow) {
           if(board[x][y]!=' ') {
            printf("bosbosrightright_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,attackonrow,rrrr,y);
            break;
            }
            else{
            x=x+k,y=y+m;
            rrrr= attackoncoulomn+u;}}
            printf("x= %d attrow= %d y= %d rrr=%d", x, attackonrow, y, rrrr);
         if(x == attackonrow&&y==rrrr&&board[x][y]==' '){
            valid=1;
            printf("lalalarightright_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,rrrr,attackoncoulomn,y);

        }
        ///to the right
         int k2=1,m2=1,u2=1;
        for(u=0;u<6;u++){
        int x2=i+k2,y2=j+m2;
        int rrrr2=attackonrow+u;
            printf("I is %d attack on row is %d attackoncolumn is %d J is %d\n",i,attackonrow,attackoncoulomn,j);
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,attackonrow,attackoncoulomn,y);
        while(y != attackoncoulomn) {
           if(board[x2][y2]!=' ') {
            printf("bosbosrightrUPight_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x2,attackonrow,rrrr2,y2);
            break;
            }
            else{
            x2=x2+k,y2=y2+m2;
            rrrr2= attackonrow+u;}}
            printf("x= %d attrow= %d y= %d rrr=%d", x, attackonrow, y, rrrr);
         if(x2 == attackonrow&&y==rrrr&&board[x][y]==' '){
            valid=1;
            printf("lalalarightright_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,rrrr,attackoncoulomn,y);

        }
        int x1=i+k,y1=j+m;
        int rrrr1=attackonrow+u;
            printf("I is %d attack on row is %d attackoncolumn is %d J is %d\n",i,attackonrow,attackoncoulomn,j);
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x1,attackonrow,attackoncoulomn,y1);
        while(y1 != attackoncoulomn) {
           if(board[x1][y1]!=' ') {
            printf("bosbosleftleft_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x1,attackonrow,rrrr,y1);
            break;
            }
            else{
            x1=x1+k,y1=y1+m;
            rrrr1= attackonrow+u;}}
            printf("x= %d attrow= %d y= %d rrr=%d", x1, attackonrow, y1, rrrr1);
         if(x1 == rrrr1&&y1==attackoncoulomn&&board[x1][y1]==' '){
            valid=1;
            printf("lalalaLEFTLEFT_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,rrrr,attackoncoulomn,y);

        }

int x1=i+k,y1=j+m;
        int rrrr1=attackonrow+u;
            printf("I is %d attack on row is %d attackoncolumn is %d J is %d\n",i,attackonrow,attackoncoulomn,j);
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x1,attackonrow,attackoncoulomn,y1);
        while(y1 != attackoncoulomn) {
           if(board[x1][y1]!=' ') {
            printf("bosbosleftleft_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x1,attackonrow,rrrr,y1);
            break;
            }
            else{
            x1=x1+k,y1=y1+m;
            rrrr1= attackonrow+u;}}
            printf("x= %d attrow= %d y= %d rrr=%d", x1, attackonrow, y1, rrrr1);
         if(x1 == rrrr1&&y1==attackoncoulomn&&board[x1][y1]==' '){
            valid=1;
            printf("lalalaLEFTLEFT_empty\n");
            printf("x is %d attack on row is %d attackoncolumn is %d y is %d\n",x,rrrr,attackoncoulomn,y);

        }
//
//
//
//
}
}}}}
        }

//        else if(board[v+1][j]==' '){
//          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
//                    valid=1;
//                    printf("hurg\n");
//                        break;
}
        printf("\nUOKKLLDLF%d\n",valid);

}



// if(j==attackoncoulomn){
//        int k=1;
//        j=pos_rook_j;
//        i=pos_rook_i;
//        int z = i + k;
//        while(z!=attackonrow) {
//            if(board[z][j]!=' ') {
//                    printf("bosbosUP\n");
//                break;
//            }
//            else {
//                z = z + k;
//            }
//        }
//        if(z == attackonrow){
//            valid=1;
//            printf("lalalaUP\n");
//        }}
////        else if(board[v+1][j]==' '){
////          if(board[v+2][j]==board[attackonrow][attackoncoulomn]){
////                    valid=1;
////                    printf("hurg\n");
////                        break;
//    ///down
//    for(v=i;v<=8;v++){
//        if((i+1==attackonrow)&&(j==attackoncoulomn)){
//           valid=1;
//
//            printf("yui\n");
//            break;}}
//         if(j==attackoncoulomn){
//                int k=-1;
//         int z = i + k;
//        while(z!=attackonrow) {
//            if(board[z][j]!=' ') {
//                    printf("bosbosDOWN\n");
//                break;
//            }
//            else {
//                z = z + k;
//            }
//        }
//        if(z == attackonrow){
//            valid=1;
//            printf("lalalaDOWN\n");}}
}

void promoteBlack(int r1, int c1, char p)
{
    if(r1==7) {
        printf("Promote to piece:\n");
        scanf(" %c ", &p);
        printf("input is %c\n",p);
       int i=0;
       for(i=0;i<4;i++) {
        if(p==promotionBlack[i]) {
            board[r2][c2]=p;
        }
       }
    display();
    }
}
void promoteWhite(int r1, int c1, char p)
{
    if(r1==2) {
        printf("Promote to piece:\n");
        scanf(" %c ", &p);
        printf("input is %c\n",p);
       int i=0;
       for(i=0;i<4;i++) {
        if(p==promotionWhite[i]) {
            board[r2][c2]=p;
        }
       }
    display();
    }
}
///**empty spaceschecked**///
void Empty_SPACES_INDANGER(int attackonrow,int attackoncoulomn){
initial=0;
sum=0;
for(int e=1;e<9;e++){
    for(int h=1;h<9;h++){
        if(board[e][h]=='K'){
             pos_kingi=e;
             pos_kingj=h;
        }
    }
}

       if (board[pos_kingi][pos_kingj-1] == ' '&&pos_kingi!=0&&pos_kingj-1!=0){
            DISCOVER_EAT_PIECE_CHECK_white(pos_kingi,pos_kingj-1);
            printf("I AM\n");
            initial++;
   }
    if( board[pos_kingi][pos_kingj+1] == ' ' &&pos_kingi!=0&&pos_kingj+1!=0){
       DISCOVER_EAT_PIECE_CHECK_white(pos_kingi,pos_kingj+1);
       printf("I AM REALLY tired\n");
       initial++;
}
     if (board[pos_kingi+1][pos_kingj] == ' '&&pos_kingi+1!=0&&pos_kingj!=0 ){
DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj);
printf("IT IS TIRING\n");
initial++;
  }
     if (board[pos_kingi-1][pos_kingj] == ' ' &&pos_kingi-1!=0&&pos_kingj!=0){
                                  DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj);
                                  printf("IT IS HARD\n");
                                  initial++;
            }
     if(board[pos_kingi+1][pos_kingj+1] == ' '&&pos_kingi+1!=0&&pos_kingj+1!=0) {
                         DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj+1);
                         printf("I WANNA TO CRY\n");
                         initial++;
}
     if( board[pos_kingi-1][pos_kingj-1] == ' ' &&pos_kingi-1!=0&&pos_kingj-1!=0){
                DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj-1);
                printf("I HOPE IT WILL WORK\n");
                initial++;
}
     if (board[pos_kingi-1][pos_kingj+1] == ' '&&pos_kingi-1!=0&&pos_kingj+1!=0){
                    DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj+1);
                    printf("REALLY\n");
                    initial++;
}
     if ( board[pos_kingi+1][pos_kingj-1] == ' '&&pos_kingi+1!=0&&pos_kingj-1!=0){
                    DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj-1);
                    printf("EN SHAA ALLAH KHAIR\n");
                    initial++;
}
printf("JUST FINE %d\n",initial);
printf("Duplicated spaces");

}

void KIng_white_indanger(){
Empty_SPACES_INDANGER(attackonrow,attackoncoulomn);
printf("HHHHHHHHHHHH %d", count_check);
if(count_check==1&&initial==sum){
    printf("KIng is in checkmate\n");
}
else if(count_check==0&&initial==sum){
      printf("KIng is in Stalemate\n");
}
}
void check_white(){
ch_bishop_white(r2,c2);
ch_knight_white(r2,c2);
}
