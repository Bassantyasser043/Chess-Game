#include <stdio.h>
#include <stdlib.h>
char boardhistory[10000000][10][10]= {0};
char boardredo[100000][10][10]={0};
int turn=0;
int s;
int bla=0;
int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char *black[25]={'p','k','q','b','r','n'};
char *white[25]={'P','K','Q','B','N','R'};
char *eaten_white[100]={'0','0','0','0','0'};
char *eaten_black[100]={'0','0','0','0','0'};
char *eaten_O[100]={'0','0','0','0','0','0'};
int empty_bishop[25][2]=
{
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
{0,0},
};
char p;
int attackonrow,attackoncoulomn=0;
int initial_black=0,sum_black=0,knigh1_pos=0,t=0,sum=0,knigh2_pos=0,e=0,g=0,l=0,y=0,yu=0,c=0,u=0,count_empty_checked=0,attackerrow,attackcolumn;
int initial=0,x=0,col=0,king_check=0;
int counter_dup_black=0,aytt=0,attackoncoulomn_black=0,attackonrow_black=0;
int bbb=0,bbb_black=0,pos_kingi_black=0,pos_kingj_black=0,valid_black;
int attackoncol_black,attackr_black;
int attackonrow;
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
{' ','A','B','C','D','E','F' ,'G','H'},//black
{'1','R','N','B','Q','K','B','N','R'},
{'2','P','P','P','P','P','P','P','P'},
{'3','-','.','-','.',' ','.','-','.'},
{'4','.','-','.','-','.','-','.','-'},
{'5','-','.','-','.','-','.','-','.'},
{'6','.','-','.','-','.','-','.','-'},
{'7','p','p','p','p','p','p','p','p'},
{'8','r','n','b','q','k','b','n','r'},};

char emptyboard[9][9]={
{' ','A','B','C','D','E','F' ,'G','H'},//black
{'1','-','.','-','.','-','.','-','.'},
{'2','.','-','.','-','.','-','.','-'},
{'3','-','.','-','.','-','.','-','.'},
{'4','.','-','.','-','.','-','.','-'},
{'5','-','.','-','.','-','.','-','.'},
{'6','.','-','.','-','.','-','.','-'},
{'7','-','.','-','.','-','.','-','.'},
{'8','.','-','.','-','.','-','.','-'},};

char checkboard[9][9]={
{' ','A','B','C','D','E','F','G','H'},//black
{'1','-','.','-','.','-','.','-','.'},
{'2','.','-','.','-','.','-','.','-'},
{'3','-','.','-','.','-','.','-','.'},
{'4','.','-','.','-','.','-','.','-'},
{'5','-','.','-','.','-','.','-','.'},
{'6','.','-','.','-','.','-','.','-'},
{'7','-','.','-','.','-','.','-','.'},
{'8','.','-','.','-','.','-','.','-'},};

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
int draw();
int main(){
    display();
    int s = draw();
    if(s) {
        printf("\n\n THE GAME ENDED IN A DRAW!!!\n\n");
        exit(0);
    }
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
            if(!isEmpty(z,j))
             {
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
                if(!isEmpty(z,j))
         {
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
                if(!isEmpty(i,z)){
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
                if(!isEmpty(i,z)){
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

      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            printf("lalalarightright_QUEENwgite\n");
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow&&y!=attackoncoulomn) {
                if(!isEmpty(x,y)) {

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
                if(!isEmpty(f,uu))
 {
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
                if(!isEmpty(f64,u37))
            {
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
                if(!isEmpty(fail,utre))
           {
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
         valid=0;
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==white[c]){
               int  protect_row=i;
               int protect_col=j;

         if(white[c]=='P'){
        ///*pawn check if it can eat checked piece to king///
         if(((attackonrow==i+1)&&(attackoncoulomn==j+1))){
               valid=1;
               break;
                 }
        else if(((attackonrow==i+1)&&(attackoncoulomn==j-1))){
        valid=1;
        break;
            }}
      else if(white[c]=='N'){
            ///*KNIGHT check if it can eat checked piece to king///
      if ((attackonrow==i+2) &&(attackoncoulomn==j+1)) {
          valid=1;
          break;
          }
            else if ((attackonrow==i+2) &&(attackoncoulomn==j-1)){
               if( (j-1) > -1 ) {
            valid=1;
            break; }}

    else if((attackonrow==i+1) &&(attackoncoulomn==j+2)) {
            if( (j+2) != 8 ){
                valid=1;

                break; }}
    else if ((attackonrow==i-1) &&(attackoncoulomn==j+2)) {
               valid=1;
               break; }

    else if ((attackonrow==i-2) &&(attackoncoulomn==j-1)) {
        if( (j-1) != -1 ){
               valid=1;
               break; }}
    else if ((attackonrow==i-2) &&(attackonrow==j+1)) {
        valid=1;
        break;}

    else if ((attackonrow==i+1) &&(attackoncoulomn==j-2)) {

                        valid=1;                                   break; }
    else if ((attackonrow==i-1) &&(attackoncoulomn==j-2)) {
        if( (j-2) != -1 ){
            valid=1;
                                   break;
}}}
   ///*KING check if it can eat checked piece to king///
    else if(white[c]=='K'){
      if (attackonrow==i && attackoncoulomn==j+1 ){
king_check=2;
                          break;
   }
   else if (attackonrow==i && attackoncoulomn==j-1 ){
king_check=2;

      break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j ){
king_check=2;

                                   break;
  }
    else if(attackonrow==i-1 && attackoncoulomn==j ){
king_check=2;

                                   break;

            }
    else if(attackonrow==i+1 && attackoncoulomn==j+1 ) {
king_check=2;

                                   break;
}
    else if(attackonrow==i-1 && attackoncoulomn==j-1 ){
king_check=2;

                                  break;
}
    else if (attackonrow==i-1 && attackoncoulomn==j+1 ){
king_check=2;

                                   break;
}
    else if (attackonrow==i+1 && attackoncoulomn==j-1 ){
 king_check=2;

                                   break;
}

}
    ///*ROOK check if it can eat checked piece to king///
  else if(white[c]=='R'){
   ///UP


      if(j==attackoncoulomn){
        for(v=i;v<=8;v++){
        if(board[i+1][j]==board[attackonrow][attackoncoulomn]){
            valid=1;
            break;
             }}
        int k=1;
        int z = i + k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;
        }
        }
    ///down

         if(j==attackoncoulomn){int k=-1;
         int z = i+k;
        while(z!=attackonrow) {
            if(board[z][j]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow){
            valid=1;

        }

        }
     ///right
     if(i==attackonrow){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
        }
        }

          ///left
    for(v=j;v>=1;v--){
        if((i==attackonrow)&&(j-1==attackoncoulomn)){
                      valid=1;

                      break;}}
      if(i==attackonrow){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn){
            valid=1;
        }
        }
        }
            ///*BISHOP check if it can eat checked piece to king///
    else if(white[c]=='B'&&i!=0&&j!=0){
      ///RIGHT RIGHT
      if( i+1== attackonrow&&j+1==attackoncoulomn){
            valid=1;
            counter_dup++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;
        while(x != attackonrow&&y!=attackoncoulomn) {
           if(board[x][y]!=' ') {
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow&&y==attackoncoulomn){
            valid=1;
        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow&&uu!=attackoncoulomn) {
           if(board[f][uu]!=' ') {
            break;}
            else{ f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow&&uu==attackoncoulomn){
            valid=1;
        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow&&u37!=attackoncoulomn) {
           if(board[f64][u37]!=' ') {
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow&&u37==attackoncoulomn){
            valid=1;
        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow&&utre!=attackoncoulomn) {
           if(board[fail][utre]!=' ') {
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow&&utre==attackoncoulomn){
            valid=1;
        }


}

///*QUEEN check if it can eat checked piece to king///
else if(white[c]=='Q'){
     valid_queen_white(attackonrow,attackoncoulomn);
}
}}}}

}
}
/////////////////////////////////////////////////////////////////////////////////////
void queen_verify(int attackonrow_black,int attackoncoulomn_black){
   ///UP
      if(j==attackoncoulomn_black){
        int k=1;
        int z = i + k;
        while(z!=attackonrow_black) {
            if(board[z][j]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow_black){
            valid_black=1;
            counter_dup_black++;
        }}

    ///down
    for(v=i;v>=1;v--){
        if((i-1==attackonrow_black)&&(j==attackoncoulomn_black)){
           valid_black=1;
            counter_dup_black++;
            break;}}
         if(j==attackoncoulomn_black){
         int k=-1;
         int z = i + k;
        while(z!=attackonrow_black) {
            if(board[z][j]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow_black){
            valid_black=1;
            counter_dup_black++;
        }}
     ///right
     if(i==attackonrow_black){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn_black) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn_black){
          valid_black=1;
            counter_dup_black++;
        }}

          ///left
      if(i==attackonrow_black){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn_black) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;
        }}

            ///*BISHOP check if it can eat checked piece to king///

      ///RIGHT RIGHT
      if( i+1== attackonrow_black&&j+1==attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow_black&&y!=attackoncoulomn_black) {
           if(board[x][y]!=' ') {
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow_black&&y==attackoncoulomn_black){
          valid_black=1;
            counter_dup_black++;
        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow_black&&uu!=attackoncoulomn_black) {
           if(board[f][uu]!=' ') {
            break;}
            else{
                    f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow_black&&uu==attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;
        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow_black&&u37!=attackoncoulomn_black) {
           if(board[f64][u37]!=' ') {
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow_black&&u37==attackoncoulomn_black){
           valid_black=1;
            counter_dup_black++;
        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow_black&&utre!=attackoncoulomn_black) {
           if(board[fail][utre]!=' ') {
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow_black&&utre==attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;}
}
/////////////////////////////////////////////////////////
///function to see if there is any piece that will eat enemy piece that checked the king///
///COMPARE WITH BLACK PIECES
void DISCOVER_EAT_PIECE_CHECK_white(int attackonrow_black,int attackoncoulomn_black){
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==black[c]){
               int  protect_row=i;
               int protect_col=j;
         if(black[c]=='p'){
        ///*pawn check if it can eat checked piece to king///
         if(((attackonrow_black==i-1)&&(attackoncoulomn_black==j-1))){
               valid_black=1;
               counter_dup_black++;
               break;
                 }
        else if(((attackonrow_black==i-1)&&(attackoncoulomn_black==j+1))){
        valid_black=1;
        counter_dup_black++;
        break;
            }}
      else if(black[c]=='n'){
    ///*KNIGHT check if it can eat checked piece to king///
      if ((attackonrow_black==i+2) &&(attackoncoulomn_black==j+1)) {
          valid_black=1;
          counter_dup_black++;
          break;
          }
            else if ((attackonrow_black==i+2) &&(attackoncoulomn_black==j-1)){
               if( (j-1) > -1 ) {
            valid_black=1;
            counter_dup_black++;
break; }}

    else if((attackonrow_black==i+1) &&(attackoncoulomn_black==j+2)) {
            if( (j+2) != 8 ){

                valid_black=1;
                counter_dup_black++;
                break; }}
    else if ((attackonrow_black==i-1) &&(attackoncoulomn_black==j+2)) {
               valid_black=1;
               counter_dup_black++;
               break; }

    else if ((attackonrow_black==i-2) &&(attackoncoulomn_black==j-1)) {
        if( (j-1) != -1 ){
               valid_black=1;
               counter_dup_black++;
               break; }}
    else if ((attackonrow_black==i-2) &&(attackoncoulomn_black==j+1)) {
        valid_black=1;
        counter_dup_black++;
        break;}

    else if ((attackonrow_black==i+1) &&(attackoncoulomn_black==j-2)) {

                        valid_black=1;
                        counter_dup_black++;
                        break; }
    else if ((attackonrow_black==i-1) &&(attackoncoulomn_black==j-2)) {
        if( (j-2) != -1 ){
            valid_black=1;
                        counter_dup_black++;
                                   break;
}}}
   ///*KING check if it can eat checked piece to king///
    else if(black[c]=='k'){
      if (attackonrow_black==i && attackoncoulomn_black==j+1 ){
          valid_black=1;
            counter_dup_black++;
            break;

   }
   else if (attackonrow_black==i && attackoncoulomn_black==j-1 ){
       valid_black=1;
    counter_dup_black++;
      break;
}
    else if (attackonrow_black==i+1 && attackoncoulomn_black==j ){
            valid_black=1;
                      counter_dup_black++;
                                   break;
  }
    else if(attackonrow_black==i-1 && attackoncoulomn_black==j ){
            valid_black=1;
                               counter_dup_black++;
                                   break;

            }
    else if(attackonrow_black==i+1 && attackoncoulomn_black==j+1 ) {
            valid_black=1;
                               counter_dup_black++;
                                   break;
}
    else if(attackonrow_black==i-1 && attackoncoulomn_black==j-1 ){
           valid_black=1;
                                counter_dup_black++;
                                  break;
}
    else if (attackonrow_black==i-1 && attackoncoulomn_black==j+1 ){
            valid_black=1;
                                counter_dup_black++;
                                   break;
}
    else if (attackonrow_black==i+1 && attackoncoulomn_black==j-1 ){
            valid_black=1;
                                   counter_dup_black++;
                                   break;
}}
    ///*ROOK check if it can eat checked piece to king///
  else if(black[c]=='r'){
   ///UP

      if(j==attackoncoulomn_black){
        int k=1;

        int z = i + k;

        while(z!=attackonrow_black) {
            if(board[z][j]!=' ') {

                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow_black){
            valid_black=1;
                        counter_dup_black++;

        }}
    ///down
    for(v=i;v>=1;v--){
        if((i-1==attackonrow_black)&&(j==attackoncoulomn_black)){
           valid_black=1;
            counter_dup_black++;
            break;}}
         if(j==attackoncoulomn_black){
         int k=-1;
         int z = i + k;
        while(z!=attackonrow_black) {
            if(board[z][j]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackonrow_black){
            valid_black=1;
            counter_dup_black++;
        }}
     ///right
     if(i==attackonrow_black){  int k=1;
       int  z = j + k;
        while(z!=attackoncoulomn_black) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;
        }}

          ///left
      if(i==attackonrow_black){
            int k=-1;
        int  z = j + k;
        while(z!=attackoncoulomn_black) {
            if(board[i][z]!=' ') {
                break;
            }
            else {
                z = z + k;
            }
        }
        if(z == attackoncoulomn_black){
            valid_black=1;
                        counter_dup_black++;
        }}
        }
            ///*BISHOP check if it can eat checked piece to king///
    else if(black[c]=='b'){
      ///RIGHT RIGHT
      if( i+1== attackonrow_black&&j+1==attackoncoulomn_black){
            valid_black=1;
            counter_dup_black++;
        }
      int k=1,m=1;
        int x=i+k,y=j+m;

        while(x != attackonrow_black&&y!=attackoncoulomn_black) {
           if(board[x][y]!=' ') {
            break;}
            else{ x=x+k,y=y+m;
            }
        }
         if(x == attackonrow_black&&y==attackoncoulomn_black){
            valid_black=1;
                        counter_dup_black++;

        }
       ///LEFT RIGHT
         int op1=1,mu=1;
        int f=i-op1,uu=j+mu;
        while(f != attackonrow_black&&uu!=attackoncoulomn_black) {
           if(board[f][uu]!=' ') {
            break;}
            else{
                    f=f-op1,uu=uu+mu;
            }
        }
         if(f == attackonrow_black&&uu==attackoncoulomn_black){
            valid_black=1;
                        counter_dup_black++;

        }
        ///LEFT LEFT
        int op5=1,mu45=1;
        int f64=i-op5,u37=j-mu45;
        while(f64 != attackonrow_black&&u37!=attackoncoulomn_black) {
           if(board[f64][u37]!=' ') {
            break;}
            else{ f64=f64-op5,u37=u37-mu45;
            }
        }
         if(f64 == attackonrow_black&&u37==attackoncoulomn_black){
            valid_black=1;
                        counter_dup_black++;
        }
        ///RIGHTLEFT
          int pass=1,urttt=1;
        int fail=i+pass,utre=j-urttt;
        while(fail != attackonrow_black&&utre!=attackoncoulomn_black) {
           if(board[fail][utre]!=' ') {
            break;}
            else{ fail=fail+pass,utre=utre-urttt;
            }
        }
         if(fail == attackonrow_black&&utre==attackoncoulomn_black){
            valid_black=1;
                        counter_dup_black++;}

}
///*QUEEN check if it can eat checked piece to king///
else if(black[c]=='q'){
     queen_verify(attackonrow_black,attackoncoulomn_black);
}
}}}}
            if(counter_dup_black>1){
                counter_dup_black=1;
            }
            sum_black=sum_black+counter_dup_black;
            counter_dup_black=0;
}
///////////////////////////////////////////
///**display Board function**///
void display(){
 for (i=8;i>=0;i--){
        for(j=0;j<9;j++){
            printf("%c ||",board[i][j]);
        }
        printf("\n");
    }
}
////////////////////////////////////////////////////////////
void displaycheck(){
 for (i=8;i>=0;i--){
        for(j=0;j<9;j++){
            printf("%c ||",checkboard[i][j]);
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
        printf("%c , ",eaten_white[i]);
    }

printf("\nEaten white pieces: \n");
 for (j=0;j<kb;j++){
        printf("%c , ",eaten_black[j]);
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
  board[rank_place][c]=emptyboard[rank_place][c];
  count_play=0;
  display();

}
void read_check(int attackonrow, int attackoncoulomn,int i,int j){

  checkboard[attackonrow][attackoncoulomn]= 'k';
  displaycheck();

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
                if(isEmpty(r1+1,c1))
          {
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnwhite(r2,c2);
        }
               else {
            printf("invalid move\n");
            pawn_black(r1,c1);
            return;
        } }
        if((c2==c1 &&r2==r1+2)){
            if(isEmpty(r1+1, c1) && isEmpty(r1+2, c1))
           {
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnwhite(r2,c2);
        }
        }
        else if(((r2==r1+1)&&(c2==c1+1))&&(isEmpty(r1+1, c1+1))){
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
        else if(((r2==r1+1)&&(c2==c1-1))&&(isEmpty(r1+1, c1-1))){
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
                if(isEmpty(r1+1, c1))
          {
            pwstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
                ch_pawnwhite(r2,c2);
                printf("r= %d , c = %d", r1,c1);
                promoteBlack(r1,c1,p);

        }
        }

        if(((r2==r1+1)&&(c2==c1+1))&&(!isEmpty(r1+1, c1+1))){
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
        else if(((r2==r1+1)&&(c2==c1-1))&&(!isEmpty(r1+1, c1-1))){
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

       else {
            printf("invalid move\n");
            pawn_black(r1,c1);
            return;    }
    print_eat();
    }

    //////////////////////////////check piece white
void pawn_black( int r1 , int c1 )
{
        print_g();
   if( pbstatus[c1] == 0 )
    {if((c2==c1 && r2==r1-1)){
        if(isEmpty(r1-1, c1))
           {
            pbstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

        }
        else {
            printf("invalid move\n");
            pawn_black(r1,c1);
            return;
        }
        }
        if((c2==c1 &&r2==r1-2)){
                if((isEmpty(r1-1, c1)) && (isEmpty(r1-2, c1)))
    {
            pbstatus[c1]++;
            read_piece(r1,c1,r2,c2) ;
            ch_pawnblack(r2,c2);
            if(count_check==1){
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);}
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();
        }
                else {
            printf("invalid move\n");
            pawn_black(r1,c1);
            return;
        }
        }
        if(((r2==r1-1)&&(c2==c1-1))&&(!isEmpty(r1-1, c1-1))){
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
        else if(((r2==r1-1)&&(c2==c1+1))&&(!isEmpty(r1-1, c1+1))){
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
       if(isEmpty(r1-1, c1))
           {
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
        if(((r2==r1-1)&&(c2==c1-1))&&(!isEmpty(r1-1, c1-1))){
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
        else if(((r2==r1-1)&&(c2==c1+1))&&(!isEmpty(r1-1, c1+1))){
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

            printf("invalid move\n");
            pawn_black(r1,c1);
            return;
          }
    print_eat();
    }
/////////////////////KING
void king( int r1 , int c1 )
{
        print_g();
    if (r2==r1 && c2==c1+1 ){
            if(isEmpty(r1, c1+1))
      {
            read_piece(r1,c1,r2,c2);
            KIng_white_indanger();
            }
        else if (!isEmpty(r1, c1+1))
{
           for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2,c2+1);
                          KIng_white_indanger();

                  }
                       else if(board[r1][c1+1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
     else if(board[r1][c1+1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }
              }
                }

   else if (r2==r1 && c2==c1-1 ){
        if(isEmpty(r1, c1-1))
          {
                read_piece(r1,c1,r2,c2);
                }
        else if (!isEmpty(r1, c1-1))
       {
           for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2,c2-1);
                          KIng_white_indanger();

                  }
                else if(board[r1][c1-1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
        else if(board[r1][c1-1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }
              }
                }

    else if (r2==r1+1 && c2==c1 ){
            if(isEmpty(r1+1, c1))
            {
            read_piece(r1,c1,r2,c2);
                KIng_white_indanger();

            if(count_play==2){
                                read_piece(r1,c1,r2,c2);

                                      KIng_white_indanger();

            }}
            else if (!isEmpty(r1+1, c1))
               {
          for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2);
                          KIng_white_indanger();

                  }
                else if(board[r1+1][c1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
        else if(board[r1+1][c1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }
                 }
                   }


    else if(r2==r1-1 && c2==c1 ){
            if(isEmpty(r1-1, c1))

    {
                read_piece(r1,c1,r2,c2);


         }
         else if (!isEmpty(r1-1, c1))
            {
for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2);
                                            KIng_white_indanger();

                  }
                else if(board[r1-1][c1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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

        else if(board[r1-1][c1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                   }
                      }                 }
    }
    else if(r2==r1+1 && c2==c1+1 ) {
            if(isEmpty(r1+1, c1+1))

    {
                        read_piece(r1,c1,r2,c2);
                        KIng_white_indanger();


    }
            else if (!isEmpty(r1+1,c1+1))
                {
            for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2+1);
                          KIng_white_indanger();

                  }
                else if(board[r1+1][c1+1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
      else if(board[r1+1][c1+1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }                           }
                            }
    else if(r2==r1-1 && c2==c1-1 ){
            if(isEmpty(r1-1, c1-1))
           {
                    read_piece(r1,c1,r2,c2) ;
                          KIng_white_indanger();

            }
               else if (!isEmpty(r1-1, c1-1))
{
          for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1-1]==black[i]){
                  eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2-1);

                  }
                else if(board[r1-1][c1-1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
      else if(board[r1-1][c1-1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }                                     }
                                      }
    else if (r2==r1-1 && c2==c1+1 ){
            if(isEmpty(r1-1, c1+1))
           {
                             read_piece(r1,c1,r2,c2);
                                                       KIng_white_indanger();


                                          }
            else if (!isEmpty(r1-1, c1+1))
                {
               for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1-1][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2-1,c2+1);
                  }
                else if(board[r1-1][c1+1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
                else if(board[r1-1][c1+1]==black[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
                }
                      }
                      }                         }
                          }
    else if (r2==r1+1 && c2==c1-1 ){
            if(isEmpty(r1+1, c1-1))
         {
                    read_piece(r1,c1,r2,c2) ;
            }
             else if (!isEmpty(r1+1, c1-1))

            {
             for (i=0;i<9;i++){
                if(count_play==1){
                 if(board[r1+1][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_king_white(r2+1,c2-1);
                  }
                else if(board[r1+1][c1-1]==white[i]){
                    printf("invalid move\n");
                    king(r1,c1);
                    return;
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
                      else if(board[r1+1][c1-1]==black[i]) {
                        printf("invalid move\n");
                        king(r1,c1);
                        return;
                      }
                      }                     }
                      }
    else  {
        printf("invalid move\n");
        king(r1,c1);
        return;
    }
    print_eat();

}

/////////////////////////////////////////////////// knight
void knight( int r1 , int c1 )
{
       print_g();
    if(count_play==1){
    if ((r2==r1+2) &&(c2==c1+1)) {
            if(isEmpty(r1+2, c1+1))
       {
            read_piece(r1,c1,r2,c2) ;
            ch_knight_white(r2,c2);

                           }
             else if (!isEmpty(r1+2, c1+1))
            {
               for (i=0;i<9;i++){
                 if(board[r1+2][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);}
                 else if(board[r1+2][c1+1]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }}
                  }}
            else if ((r2==r1+2) &&(c2==c1-1)){
               if( (c1-1) > -1 ) {
                    if(isEmpty(r1+2, c1-1))
               {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_white(r2,c2);
            }
            else if (!isEmpty(r1+2,c1-1))
                {
             for (i=0;i<9;i++){
                 if(board[r1+2][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }
                else if(board[r1+2][c1-1]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }
                  }}}}

    else if((r2==r1+1) &&(c2==c1+2)) {
            if( (c1+2) != 8 ){
                    if(isEmpty(r1+1,c1+2))
                {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_white(r2,c2);
            }
            else if (!isEmpty(r1+1,c1+2))
{
              for (i=0;i<9;i++){
                 if(board[r1+1][c1+2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);}
                                  else if(board[r1+1][c1+2]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }
                  }}}}
    else if ((r2==r1-1) &&(c2==c1+2)) {
            if(isEmpty(r1-1, c1+2))
                {
                    read_piece(r1,c1,r2,c2) ;
                    ch_knight_white(r2,c2);
            }
                else if (!isEmpty(r1-1, c1+2))
              {
                for (i=0;i<9;i++){
                 if(board[r1-1][c1+2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }
                else if(board[r1-1][c1+2]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }
                  }}}

    else if ((r2==r1-2) &&(c2==c1-1)) {

        if( (c1-1) != -1 ){
                if(isEmpty(r1-2,c1-1))
               {
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                    }
            else if (!isEmpty(r1-2,c1-1))
            {
                for (i=0;i<9;i++){
                 if(board[r1-2][c1-1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                   }
                else if(board[r1-2][c1-1]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }
                   }}}}

    else if ((r2==r1-2) &&(c2==c1+1)) {
            if(isEmpty(r1-2,c1+1))
         {
                read_piece(r1,c1,r2,c2);
                ch_knight_white(r2,c2);
        }
        else if (!isEmpty(r1-2,c1+1)){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1+1]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                   }
                else if(board[r1-2][c1+1]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                   }}}

    else if ((r2==r1+1) &&(c2==c1-2)) {
            if(isEmpty(r1+1,c1-2))
    {
        read_piece(r1,c1,r2,c2)  ;
        ch_knight_white(r2,c2);
    }
    else if (!isEmpty(r1+1,c1-2)){
                 for (i=0;i<9;i++){
                 if(board[r1+1][c1-2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }
                else if(board[r1+1][c1-2]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                  }}}
    else if ((r2==r1-1) &&(c2==c1-2)) {

        if( (c1-2) != -1 ){
                if(isEmpty(r1-1,c1-2))
            {
            read_piece(r1,c1,r2,c2) ;
            ch_knight_white(r2,c2);
            }
            else if (!isEmpty(r1-1,c1-2)){
              for (i=0;i<9;i++){
                 if(board[r1-1][c1-2]==black[i]){
                 eat_white();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_white(r2,c2);
                  }
                    else if(board[r1-1][c1-2]==white[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }
                   }}}}}
    else if(count_play==2){
    if ((r2==r1+2) &&(c2==c1+1)) {
            if(isEmpty(r1+2,c1+1)){
            read_piece(r1,c1,r2,c2) ;
            ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                           }
             else if (!isEmpty(r1+2,c1+1)){
               for (i=0;i<9;i++){
                 if(board[r1+2][c1+1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }
                else if(board[r1+2][c1+1]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                  }}}
          else if ((r2==r1+2) &&(c2==c1-1)){
               if( (c1-1) > -1 ) {
                    if(isEmpty(r1+2,c1-1))
               {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

            }
            else if (!isEmpty(r1+2,c1-1)){
             for (i=0;i<9;i++){
                 if(board[r1+2][c1-1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }
                else if(board[r1+2][c1-1]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                  }}}}

    else if((r2==r1+1) &&(c2==c1+2)) {
            if( (c1+2) != 8 ){
                    if(isEmpty(r1+1,c1+2))
               {
                read_piece(r1,c1,r2,c2) ;
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
            else if (!isEmpty(r1+1,c1+2)){
              for (i=0;i<9;i++){
                 if(board[r1+1][c1+2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                }
               else if(board[r1+1][c1+2]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                }}}}
         else if ((r2==r1-1) &&(c2==c1+2)) {
                if(isEmpty(r1-1,c1+2))
                {
                    read_piece(r1,c1,r2,c2) ;
                    ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
                else if (!isEmpty(r1-1,c1+2)){
                for (i=0;i<9;i++){
                 if(board[r1-1][c1+2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                 }
                else if(board[r1-1][c1+2]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }


                 }}}

    else if ((r2==r1-2) &&(c2==c1-1)) {

        if( (c1-1) != -1 ){
                if(isEmpty(r1-2,c1-1))
                {
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                    }
                else if (!isEmpty(r1-2,c1-1)){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1-1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                }
                  else if(board[r1-2][c1-1]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

                }}}}

    else if ((r2==r1-2) &&(c2==c1+1)) {
            if(isEmpty(r1-2,c1+1))
       {
                read_piece(r1,c1,r2,c2);
                ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


        }
        else if (!isEmpty(r1-2,c1+1)){
                for (i=0;i<9;i++){
                 if(board[r1-2][c1+1]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                }
              else if(board[r1-2][c1+1]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }


                }}}

    else if ((r2==r1+1) &&(c2==c1-2)) {
            if (isEmpty(r1+1,c1-2))
    {
        read_piece(r1,c1,r2,c2);
        ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


    }
    else if (!isEmpty(r1+1,c1-2)){
                 for (i=0;i<9;i++){
                 if(board[r1+1][c1-2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                  }
               else if(board[r1+1][c1-2]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }


                  }}}
    else if ((r2==r1-1) &&(c2==c1-2)) {

        if( (c1-2) != -1 ){
            if(isEmpty(r1-1,c1-2)){
            read_piece(r1,c1,r2,c2) ;
            ch_knight_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


            }
            else if (!isEmpty(r1-1,c1-2)){
              for (i=0;i<9;i++){
                 if(board[r1-1][c1-2]==white[i]){
                 eat_black();
                  read_piece(r1,c1,r2,c2) ;
                  ch_knight_black(r2,c2);}
                    else if(board[r1-1][c1-2]==black[i]){
                    printf("invalid move\n");
                  knight(r1,c1);
                  return;
                  }

            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
//            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                   }

                   }}}}
                   else{
                    printf("invalid move\n");
                    knight(r1,c1);
                    return;
                   }
    print_eat();
}
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
                printf("invalid move\n");
                bishop(r1,c1);
                return;
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
        if(!isEmpty(x,y) && x!= r2)
  {
                printf("invalid move\n");
                bishop(r1,c1);
                return;
            }
                 x = x + n1;
            y = y + m1;
        }
        if(!isEmpty(r2,c2))
        {
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
           validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();


                }
            }
    }
    else {
        printf("invalid move\n");
        bishop(r1,c1);
        return;
    }
    print_eat();
}

////////////////////////////// function to move the rook according to its valid moves
void rook( int r1 , int c1 )
{
    // conversion of input
    int i , j , n, x, m ;
    int p1 , p2 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
        printf("Enter file of the place2 that you want\n");
        scanf(" %c %d",&file6,&rank_place6);
        v2=rank_place6*10;
        x2=read_place(file6);
        p2=v2+x2;
        c2 = p2 % 10 ;
        r2 = p2 / 10  ;

    /// horizontal move
        if(r1 == r2) {
            if(c1 == c2) {
                printf("invalid move\n");
                rook(r1,c1);
                return;
            }
        else if(c1 < c2)
            n = 1;
        else {
            n = -1;
        }
        x = c1 + n;
    // check clear way

        while(x != c2) {
                if(!isEmpty(r2,x))
            {
                printf("invalid move\n");
                rook(r1,c1);
                return;
            }
             x = x + n;
              }

        if(!isEmpty(r2,x))
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][x]==black[i]){
               eat_white();
               print_eat();
                read_piece(r1,c1,r2,x) ;
                ch_rook_white(r2,c2);
                 }
                 else if(board[r2][c2] == white[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
                 }
                  }
        else if (count_play==2){
        if(board[r2][x]==white[i]){
            eat_black();
            print_eat();
              read_piece(r1,c1,r2,c2) ;
            ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

            }
            else if(board[r2][c2] == black[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
            }
            }

       else if(count_play==1){
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

                } }
                }
                              else{
               read_piece(r1,c1,r2,c2);
                ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
                          KIng_white_indanger();

                }   }

    else if(c1 == c2) {
        if(r1 == r2) {
            printf("invalid move\n");
            rook(r1,c1);
            return;
        }
        else if(r1 <r2)
            m = 1;
        else {
            m = -1;
        }
        x = r1 + m;
        while(x != r2) {
                if(!isEmpty(x2,c2))
            {
            printf("invalid move\n");
            rook(r1,c1);
            return;
               }
             x = x + m;
              }

            if(!isEmpty(r2,c2))

            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][c2]==black[i]){
               eat_white();
               print_eat();
                read_piece(r1,c1,r2,c2) ;
                ch_rook_white(r2,c2);
                 }
            else if(board[r2][c2] == white[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
                 }
                  }
            else if (count_play==2){
                if(board[r2][c2]==white[i]){
                eat_black();
                print_eat();
              read_piece(r1,c1,r2,c2) ;
              ch_rook_black(r2,c2);
            DISCOVER_EAT_PIECE_CHECK(attackerrow,attackcolumn);
            validation_white(attackerrow, attackcolumn);
            Empty_SPACES_INDANGER(attackerrow,attackcolumn);
            KIng_white_indanger();

            }
                        else if(board[r2][c2] == black[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
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
    else {
        printf("invalid move\n");
        rook(r1,c1);
        return;
    }
print_eat();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void player1()
{   count_check=0;
    int p1 , p2 , c1 , r1 , c2 , r2,x1,file3,y1,v1,v2,y2,x2,rank_place,file6,rank_place6;
    char a;
    printf( "\nPLAYER 1 - large Case \n") ;
   printf("Enter file of the place1 that you want\n");
    scanf(" %c %d",&file3,&rank_place);
    a = file3;
    printf("%c", a);
    if(a=='U'||a=='u') {
        redo();
        boardhistoryload();
        turn--;
    }
    else  if(a=='R'||a=='r') {
        board_redo();
        turn++;
    }
    else  if(a=='S'||a=='s') {
        save();
    }
    else  if(a=='L'||a=='l') {
        load();
    }
    else {
   v1=rank_place*10;
    x1=read_place(file3);
    p1=v1+x1;
    c1 = p1 % 10 ;
    r1 = p1 / 10 ;
    boardhistorywrite();

switch( board[r1][c1] )
{
    case 'P':
            pawn_white( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;
    case 'R': rook( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;
    case 'N': knight( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;
    case 'B': bishop( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;
    case 'K': king( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;
    case 'Q': queen( r1 , c1 ) ;
            turn++;
            count_play=2;
            break ;

    default: printf( "Invalid Position ! " ) ;
   }

} }
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
// diagonal move like bishop
   if(abs(r1-r2) == abs(c1-c2)) {
        int n, m, n1, m1, x, y;
        n = r2 - r1;
        m = c2 - c1;
        n1 = n / abs(n);
        m1 = m / abs(m);

        x = r1 + n1;
        y = c1 + m1;
        while(x != r2) {
                if((!isEmpty(x,y)) && (x != r2))
                printf("invalid move\n");
                queen(r1,c1);
                return;
            }
            x = x + n1;
            y = y + m1;
        }
        if(!isEmpty(r2,c2))
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
    }

/// HORIZONTAL
        if(r1 == r2) {
            if(c1 == c2) {
                printf("invalid move\n");
                queen(r1,c1);
                return;
            }
        else if(c1 < c2)
            n = 1;
        else {
            n = -1;
        }
        x = c1 + n;

        while(x != c2) {
                if(!isEmpty(r2,x2))
            {
                printf("invalid move\n");
                queen(r1,c1);
                return;
            }
             x = x + n;
                     }
        if(!isEmpty(r2,x))
            {
           for (i=0;i<9;i++){
            if (count_play==1){
             if(board[r2][x]==black[i]){
               eat_white();
                read_piece(r1,c1,r2,x) ;
                ch_rook_white(r2,c2);
                 }
                 else if(board[r2][c2] == white[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
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
            else if(board[r2][c2] == black[i]) {
                    printf("invalid move\n");
                    rook(r1,c1);
                    return;
            }
            }

       else if(count_play==1){
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

                } }
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
        if(r1 == r2) {
            printf("invalid move\n");
            queen(r1,c1);
            return; }
        else if(r1 <r2)
            m = 1;
        else {
            m = -1;
        }
        x = r1 + m;
        while(x != r2) {
                if(!isEmpty(x,c2))
            {
                printf("invalid move\n");
            queen(r1,c1);
                return;
            }
             x = x + m;
              }

            if(!isEmpty(r2,c2))
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
    else {
        printf("invalid move\n");
        queen(r1,c1);
        return;
    }
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
                if(!isEmpty(r2+2,c2+1))
             {
               compare_play1(r2+2,c2+1);
                               }
            if( (c2-1) > -1 ) {
            if(!isEmpty(r2+2,c2-1)){
             compare_play1(r2+2,c2-1);

                 }
                    }
            if( (c2+2) != 8 ){
             if(!isEmpty(r2+1,c2+2)){
                compare_play1(r2+1,c2+2);
                       }  }

                if(!isEmpty(r2-1,c2+2))
             {
                  compare_play1(r2-1,c2+2);
                    }
              if( (c2-1) != -1 )
            {
                if(!isEmpty(r2-2,c2-1))
             {
             compare_play1(r2-2,c2-1); }}
             if(!isEmpty(r2-2,c2+1))
           {
 compare_play1(r2-2,c2+1);
                  }
                  if(!isEmpty(r2+1,c2-2))
     {
 compare_play1(r2+1,c2-2);
            }
        if( (c2-2) != -1 ){
                if(!isEmpty(r2-1,c2-2))
        {
          compare_play1(r2-1,c2-2);
            }}

}
///////////////////////////////////////////
int ch_knight_black(int r2,int c2){
                if(!isEmpty(r2+2,c2+1))
             {
               compare_play2(r2+2,c2+1);
                                       count_check=1;

                attackerrow=r2,attackcolumn=c2;                }
            if( (c2-1) > -1 ) {
                    if(!isEmpty(r2+2,c2-1))
          {
             compare_play2(r2+2,c2-1);
                                     count_check=1;

              attackerrow=r2,attackcolumn=c2;
    }
                    }
            if( (c2+2) != 8 ){
                    if(!isEmpty(r2+1,c2+2))
             {
 compare_play2(r2+1,c2+2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;              }  }
        if(!isEmpty(r2-1,c2+2))
             {
 compare_play2(r2-1,c2+2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
                    }
              if( (c2-1) != -1 )
            {
                if(!isEmpty(r2-2,c2-1))
            {
             compare_play2(r2-2,c2-1);
                                     count_check=1;

              attackerrow=r2,attackcolumn=c2; }}
          if(!isEmpty(r2-2,c2+1))
{

 compare_play2(r2-2,c2+1);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
                  }
                  if(!isEmpty(r2+1,c2-2))
 {
 compare_play2(r2+1,c2-2);
                         count_check=1;

  attackerrow=r2,attackcolumn=c2;
            }
        if( (c2-2) != -1 ){
                if(!isEmpty(r2-1,c2-2))
           {
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
        else if(isEmpty(i+1,c2))
         {
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
    else if(isEmpty(i-1,c2))
     {
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
        else if(isEmpty(r2,i+1))
                {
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
    else if(isEmpty(r2,i-1))
           {
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
        else if(isEmpty(r2+1,c2+1))
       {
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
        else if(isEmpty(r2-1,c2+1))

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
        else if(isEmpty(r2+1,c2-1))
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
        else if(isEmpty(r2-1,c2-1))
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
        else if(isEmpty(i+1,c2))
           {
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
    else if(isEmpty(i-1,c2))
        {
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
        else if(isEmpty(r2,i+1))
       {
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
    else if(isEmpty(r2,i-1))
    {
          if(board[r2][i-2]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
             break;
            }
             }
            }
}
void check_bishop_black(int r2,int c2){
///up_right
         for(i=1;i<=8;i++){
        if(checkboard[r2+1][c2+1]=='k'){
            printf("\nCheck!!\n");

            break;}
        else if(checkisEmpty(r2+1, c2+1))
       {
          if(checkboard[r2+1+i][c2+1+i]=='k'){
            printf("\nCheck!!\n");

            }
             }
            }

    ///up_left
        for(i=1;i<=8;i++){
        if (checkboard[(r2-1)][c2+1]=='k'){
            printf("\nCheck!!\n");
            count_check_player2=1;
            attackerrow=r2,attackcolumn=c2;
            break;
         }
          else if(checkisEmpty(r2-1, c2+1))
            if(checkboard[r2-(i+1)][c2+(i+1)]=='k'){
            printf("\nCheck!!\n");

            }}
   ///down_right
         for(i=1;i<=8;i++){
        if (checkboard[(r2+1)][c2-1]=='k'){
            printf("\nCheck!!\n");

            break;
         }
          else if(checkisEmpty(r2+1, c2-1))
            if(checkboard[r2+(i+1)][c2-(i+1)]=='k'){
            printf("\nCheck!!\n");

            }}
///down_left
           for(i=1;i<=8;i++){
        if (checkboard[(r2-1)][c2-1]=='k'){
            printf("\nCheck!!\n");

            break;
         }
          else if(checkisEmpty(r2-1, c2-1))
            if(checkboard[r2-(i+1)][c2-(i+1)]=='k'){
            printf("\nCheck!!\n");

            }}
}
void ch_bishop_black(int r2,int c2){
///up_right
         for(i=1;i<=8;i++){
        if(board[r2+1][c2+1]=='K'){
            printf("\nCheck!!\n");
            count_check_player2=1;
             attackerrow=r2,attackcolumn=c2;
            return;}
             else if(checkisEmpty(r2+1, c2+1))
     {
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
          else if(checkisEmpty(r2-1, c2+1))

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
          else if(checkisEmpty(r2+1, c2-1))
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
          else if(checkisEmpty(r2-1, c2-1))
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
/////////////////////////////////////////////////////////////////////////////////////////
///**function to make sure that spaces between dangerous checked king can be saved**///
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
 if(board[attackonrow][attackoncoulomn]=='r'||board[attackonrow][attackoncoulomn]=='q'){
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==white[c]){
            int yryt=1;
         ///horizontal position of rook and king
         while((isEmpty(attackonrow+yryt,attackoncoulomn))){
         empty_bishop[bbb][0] =attackonrow+yryt;
         empty_bishop[bbb][1] =attackoncoulomn;
           DISCOVER_EAT_PIECE_CHECK(attackonrow+yryt,attackoncoulomn);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
           yryt++;}
            yryt=1;
         ///horizontal position of rook and king
         while((isEmpty(attackonrow-yryt,attackoncoulomn))){
         empty_bishop[bbb][0] =attackonrow-yryt;
         empty_bishop[bbb][1] =attackoncoulomn;
           DISCOVER_EAT_PIECE_CHECK(attackonrow-yryt,attackoncoulomn);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
           yryt++;}
           ///vertical position of rook and king
          yryt=1;
           while(isEmpty(attackonrow,attackoncoulomn+yryt)){
         empty_bishop[bbb][0] =attackonrow;
         empty_bishop[bbb][1] =attackoncoulomn+yryt;
           DISCOVER_EAT_PIECE_CHECK(attackonrow,attackoncoulomn+yryt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
           yryt++;}
         ///vertical position of rook and king
          yryt=1;
           while((isEmpty(attackonrow,attackoncoulomn-yryt))){
         empty_bishop[bbb][0] =attackonrow;
         empty_bishop[bbb][1] =attackoncoulomn-yryt;
           DISCOVER_EAT_PIECE_CHECK(attackonrow,attackoncoulomn-yryt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
           yryt++;
           bbb++;}}

     else if(white[c]=='P'&&i!=0&&j!=0){
    int f=0;
    for(f=0; f<8;f++) {
            if(pwstatus[c]==0) {
        if(( attackoncoulomn+f==i+1)){
           if(board[i+1][j]==' '){
                valid = 1;
        }
        }

        if((attackoncoulomn+f==i+2)){
           if((board[i+1][j]==' ')&&(board[i+2][j]==' ')){
                valid = 1;
        }
        }
    }
    else if(pwstatus[c] == 1) {
                if(( attackoncoulomn+f==i+1)){
           if(board[i+1][j]==' '){
                valid = 1;
                break;

        }}}}}}}}}
///
  else if(board[attackonrow][attackoncoulomn]=='b'||board[attackonrow][attackoncoulomn]=='q'){
for(i=1;i<9;i++){
    for(j=1;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==white[c] && i!=0 &&j!=0){
        int yyt=1;
         while((isEmpty(attackonrow+yyt,attackoncoulomn+yyt))&&(attackonrow+yyt<posi&&attackoncoulomn+yyt<posj)){
         empty_bishop[bbb][0] =attackonrow+yyt;
         empty_bishop[bbb][1] =attackoncoulomn+yyt;
           DISCOVER_EAT_PIECE_CHECK(attackonrow+yyt,attackoncoulomn+yyt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
           yyt++;
           bbb++;
}

///SOUTH_EAST
       while((isEmpty(attackonrow-yyt,attackoncoulomn+yyt))){

           DISCOVER_EAT_PIECE_CHECK(attackonrow-yyt,attackoncoulomn+yyt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }

                      yyt++;

}
///SOUTH_EAST
       while(isEmpty(attackonrow-yyt,attackoncoulomn-yyt)){

           DISCOVER_EAT_PIECE_CHECK(attackonrow-yyt,attackoncoulomn-yyt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }

                      yyt++;

}
///NORTH_WEST
       while((isEmpty(attackonrow+yyt,attackoncoulomn-yyt)==' ')){

           DISCOVER_EAT_PIECE_CHECK(attackonrow+yyt,attackoncoulomn-yyt);
           if((king_check==2)&&(valid==0)){
            valid=0;
           }
yyt++;}}
else if(white[c]=='P'&&i!=0&&j!=0){
    int f=0;
    for(f=0; f<8;f++) {
            if(pwstatus[c]==0) {
        if(( attackoncoulomn+f==i+1)){
           if(isEmpty(i+1,j)){
                valid = 1;
        }
        }

       else if(attackoncoulomn+f==i+2){
           if((isEmpty(i+1,j))&&(isEmpty(i+2,j))){
                valid = 1;
        }
        }
    }
    else if(pwstatus[c] == 1) {
                if(( attackoncoulomn+f==i+1)){
           if(isEmpty(i+1,j)){
                valid = 1;
                break;

        }}}}}
}}}}}

}
/////////////////////////////////////////////////////////////////////////////////////////
///**function to make sure that spaces between dangerous checked king can be saved**///
void valid_blackation_black(int attackonrow_black,int attackoncoulomn_black){
DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black,attackoncoulomn_black);
pos_attacki=attackonrow_black;
pos_attackj=attackoncoulomn_black;
for(e=0;e<9;e++){
    for (g=0;g<9;g++){
        if(board[e][g]=='k'){
            posi=e;
            posj=g;}}}
if(valid_black==0){
 if(board[attackonrow_black][attackoncoulomn_black]=='R'||board[attackonrow_black][attackoncoulomn_black]=='Q'){
for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==black[c]){
            int yryt=1;
         ///horizontal position of rook and king
         while((isEmpty(attackonrow_black+yryt,attackoncoulomn_black))){
         empty_bishop[bbb_black][0] =attackonrow_black+yryt;
         empty_bishop[bbb_black][1] =attackoncoulomn_black;
           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black+yryt,attackoncoulomn_black);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }
           yryt++;}
            yryt=1;
         ///horizontal position of rook and king
         while((isEmpty(attackonrow_black-yryt,attackoncoulomn_black))){
         empty_bishop[bbb_black][0] =attackonrow_black-yryt;
         empty_bishop[bbb_black][1] =attackoncoulomn_black;
           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black-yryt,attackoncoulomn_black);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }
           yryt++;}
           ///vertical position of rook and king
          yryt=1;
           while((isEmpty(attackonrow_black,attackoncoulomn_black+yryt))){
         empty_bishop[bbb_black][0] =attackonrow_black;
         empty_bishop[bbb_black][1] =attackoncoulomn_black+yryt;
           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black,attackoncoulomn_black+yryt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }
           yryt++;}
         ///vertical position of rook and king
          yryt=1;
           while((isEmpty(attackonrow_black,attackoncoulomn_black-yryt))){
         empty_bishop[bbb_black][0] =attackonrow_black;
         empty_bishop[bbb_black][1] =attackoncoulomn_black-yryt;
           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black,attackoncoulomn_black-yryt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }
           yryt++;}}

     else if(black[c]=='p'&&i!=0&&j!=0){
    int f=0;
    for(f=0; f<8;f++) {
            if(pwstatus[c]==0) {
        if(( attackoncoulomn_black+f==i+1)){
           if(board[i+1][j]==' '){
                valid_black = 1;
        }
        }

        if((attackoncoulomn_black+f==i+2)){
           if((board[i+1][j]==' ')&&(board[i+2][j]==' ')){
                valid_black = 1;
        }
        }
    }
    else if(pwstatus[c] == 1) {
                if(( attackoncoulomn_black+f==i+1)){
           if(isEmpty(i+1,j)){
                valid_black = 1;
                break;

        }}}}}}}}}
///
  else if(board[attackonrow_black][attackoncoulomn_black]=='B'||board[attackonrow_black][attackoncoulomn_black]=='Q'){
for(i=1;i<9;i++){
    for(j=1;j<9;j++){
        for(int c=0;c<6;c++){
        if(board[i][j]==black[c] && i!=0 &&j!=0){
        int yyt=1;
         while((isEmpty(attackonrow_black+yyt,attackoncoulomn_black+yyt))&&(attackonrow_black+yyt<posi&&attackoncoulomn_black+yyt<posj)){
         empty_bishop[bbb_black][0] =attackonrow_black+yyt;
         empty_bishop[bbb_black][1] =attackoncoulomn_black+yyt;
           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black+yyt,attackoncoulomn_black+yyt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }
           yyt++;
}

///SOUTH_EAST
           yyt=1;

       while((isEmpty(attackonrow_black-yyt,attackoncoulomn_black+yyt))){

           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black-yyt,attackoncoulomn_black+yyt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }

                      yyt++;

}
///SOUTH_EAST
           yyt=1;

       while(isEmpty(attackonrow_black-yyt,attackoncoulomn_black-yyt)){

           DISCOVER_EAT_PIECE_CHECK_white(attackonrow_black-yyt,attackoncoulomn_black-yyt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }

                      yyt++;

}
///NORTH_WEST
           yyt=1;

       while((isEmpty(attackonrow_black+yyt,attackoncoulomn_black-yyt))){

           DISCOVER_EAT_PIECE_CHECK_white
           (attackonrow_black+yyt,attackoncoulomn_black-yyt);
           if((king_check==2)&&(valid_black==0)){
            valid_black=0;
           }

                      yyt++;}}

else if(black[c]=='p'&&i!=0&&j!=0){
    int f=0;
    for(f=0; f<8;f++) {
            if(pwstatus[c]==0) {
        if(( attackoncoulomn_black+f==i+1)){
           if(isEmpty(i+1,j)){
                valid_black = 1;
        }
        }

        if((attackoncoulomn_black+f==i+2)){
           if((isEmpty(i+1,j))&&(isEmpty(i+2,j))){
                valid_black = 1;
        }
        }
    }
    else if(pwstatus[c] == 1) {
                if(( attackoncoulomn_black+f==i+1)){
           if(isEmpty(i+1,j)){
                valid_black = 1;
                break;

        }}}}}}}}}}}

//////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////
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
if((isEmpty(pos_kingi, pos_kingj-1)) && (pos_kingi!=0&&pos_kingj-1!=0))
      {
            DISCOVER_EAT_PIECE_CHECK_white(pos_kingi,pos_kingj-1);
            initial++;
   }
    if((isEmpty(pos_kingi, pos_kingj+1)) &&(pos_kingi!=0&&pos_kingj+1!=0)){
       DISCOVER_EAT_PIECE_CHECK_white(pos_kingi,pos_kingj+1);
       initial++;
}
     if ((isEmpty(pos_kingi+1, pos_kingj))&&(pos_kingi+1!=0&&pos_kingj!=0 )){
DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj);
initial++;
  }
     if ((isEmpty(pos_kingi-1, pos_kingj)) &&(pos_kingi-1!=0&&pos_kingj!=0)){
                    DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj);
                            initial++;
            }
     if((isEmpty(pos_kingi+1, pos_kingj+1))&&(pos_kingi+1!=0&&pos_kingj+1!=0)) {
                         DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj+1);
                         initial++;
}
     if((isEmpty(pos_kingi-1, pos_kingj-1))&&(pos_kingi-1!=0&&pos_kingj-1!=0)){
                DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj-1);
                initial++;
}
     if ((isEmpty(pos_kingi-1, pos_kingj+1))&&(pos_kingi-1!=0&&pos_kingj+1!=0)){
                    DISCOVER_EAT_PIECE_CHECK_white(pos_kingi-1,pos_kingj+1);
                    initial++;
}
     if ((isEmpty(pos_kingi+1, pos_kingj-1))&&(pos_kingi+1!=0&&pos_kingj-1!=0)){
                    DISCOVER_EAT_PIECE_CHECK_white(pos_kingi+1,pos_kingj-1);
                    initial++;
}
}

/////////////////////////////////////////////////////////////////////////////
///**empty spaceschecked used in stale mate and checkmate function_black king**///
void Empty_SPACES_INDANGER_black(int attackonrow_black,int attackoncoulomn){
initial_black=0;
sum_black=0;
for(int e=1;e<9;e++){
    for(int h=1;h<9;h++){
        if(board[e][h]=='k'){
             pos_kingi_black=e;
             pos_kingj_black=h;
        }
    }
}
       if (isEmpty(pos_kingi_black,pos_kingj_black-1)&&pos_kingi_black!=0&&pos_kingj_black-1!=0){
            DISCOVER_EAT_PIECE_CHECK(pos_kingi_black,pos_kingj_black-1);
            initial_black++;
   }
    if( isEmpty(pos_kingi_black,pos_kingj_black+1)&&pos_kingi_black!=0&&pos_kingj_black+1!=0){
       DISCOVER_EAT_PIECE_CHECK(pos_kingi_black,pos_kingj_black+1);
       initial_black++;
}
     if (isEmpty(pos_kingi_black+1,pos_kingj_black)&&pos_kingi_black+1!=0&&pos_kingj_black!=0 ){
      DISCOVER_EAT_PIECE_CHECK(pos_kingi_black+1,pos_kingj_black);
      initial_black++;
  }
     if (isEmpty(pos_kingi_black-1,pos_kingj_black)&&pos_kingi_black-1!=0&&pos_kingj_black!=0){
            DISCOVER_EAT_PIECE_CHECK(pos_kingi_black-1,pos_kingj_black);
                    initial_black++;
            }
     if(isEmpty(pos_kingi_black+1,pos_kingj_black+1)&&pos_kingi_black+1!=0&&pos_kingj_black+1!=0) {
                         DISCOVER_EAT_PIECE_CHECK(pos_kingi_black+1,pos_kingj_black+1);
                         initial_black++;
}
     if(isEmpty(pos_kingi_black-1,pos_kingj_black-1)&&pos_kingi_black-1!=0&&pos_kingj_black-1!=0){
                DISCOVER_EAT_PIECE_CHECK(pos_kingi_black-1,pos_kingj_black-1);
                initial_black++;
}
     if (isEmpty(pos_kingi_black-1,pos_kingj_black+1)&&pos_kingi_black-1!=0&&pos_kingj_black+1!=0){
                    DISCOVER_EAT_PIECE_CHECK(pos_kingi_black-1,pos_kingj_black+1);
                    initial_black++;
}
     if ( isEmpty(pos_kingi_black+1,pos_kingj_black-1)&&pos_kingi_black+1!=0&&pos_kingj_black-1!=0){
                    DISCOVER_EAT_PIECE_CHECK(pos_kingi_black+1,pos_kingj_black-1);
                    initial_black++;
}
}

////////////////////////////////////////////////////////////////////
///**function used to make sure if the white king is in checkmate or stalemate**///
///**WHITE KING
void KIng_white_indanger(int attackonrow,int attackoncoulomn){
validation_white(attackonrow,attackoncoulomn);
Empty_SPACES_INDANGER(attackonrow,attackoncoulomn);
if(count_check_player2==1&&initial==sum){
    printf("WHITE KIng is in checkmate\n");
    count_check_player2=0;
}
else if(count_check_player2==0&&initial==sum&&valid==1){
      printf("WHITE KIng is in Stalemate\n");
}
}
  ////////////////////////////////////////////////////////////////////
///**function used to make sure if the BLACK king is in checkmate or stalemate**///
void KIng_white_indanger_black(int attackonrow_black_black,int attackoncoulomn_black_black){
valid_blackation_black(attackonrow_black,attackoncoulomn_black);
Empty_SPACES_INDANGER_black(attackonrow_black,attackoncoulomn_black);
if(count_check==1&&initial_black==sum_black){
    printf("BLACK KIng is in checkmate\n");
    count_check=0;
}
else if(count_check==0&&initial_black==sum_black&&valid_black==1){
      printf("BLACK KIng is in Stalemate\n");
}
}

///////////////////////////////////
///**SAVE FUNCTION TO SOLVE LAST PLAY**///
void save()
{
char data[500];
FILE *saved;
char name[30];
saved = fopen("hi.txt","w");

if(saved==NULL)
{
  printf("can`t open file");
  exit(1);
}

else

{
    int i=0;
 int j=0;

for(j=0;j<8;j++)
 {
 for(i=0;i<8;i++)
     {
         fputc(board[i][j],saved);

  } }


 if(count_play==1) {
    putw(1,saved);
 }
 else
{
     putw(2,saved);
 }

   fclose(saved);
}
}

void boardhistorywrite()
{
    int i,j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            boardhistory[turn][i][j]=board[i][j];
        }
    }
}
void boardhistoryload()
{
    int i,j;
    int top=turn-1;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            board[i][j]=boardhistory[top][i][j];
            printf("boardhistory is %c \n", board[i][j]);

        }
    }
   // top--;
                            display();
printf("Turn %d\n", turn);
}
void redo()
{
    int bla;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            boardredo[bla][i][j]=board[i][j];

        }
    }
    bla++;
    }
void board_redo()
{
    int i,j;
    int bot=bla-1;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            board[i][j]=boardredo[0][i][j];

        }
    }
                            display();

}

//// dead positions
//function to check known cases for draw
int draw(){
    int n_count = 0, b_count = 0;
    int N_count = 0, B_count = 0;
    int others_count = 0;
    int k_count = 0, K_count = 0;
    int m=0;
    int same = 0;
    int b_r = 0, b_c = 0;
    int B_r = 0, B_c = 0;
    for(int y=1; y<=8; y++){
        for(int x=1; x<=8; x++){
            char s = board[y][x];
            if(isEmpty(s)){

            }
            else if(s == 'n'){
                n_count++;
            }
            else if(s == 'N'){
                N_count++;
            }
            else if(s == 'b'){
                b_r = y;
                b_c = x;
                b_count++;
            }
            else if(s == 'B'){
                B_r = y;
                B_c = x;
                B_count++;
            }
            else if(tolower(s) != 'k'){
                others_count++;
            }
        }
    }
    if(abs(b_r-B_r) == abs(b_c-B_c)) {
        m = 1;
    }
    else if(b_r == B_r) {
        if((b_c - B_c) % 2 == 0) {
            same = 1;
        }
        }
    else if(b_c == B_c) {
        if((b_r - B_r) % 2 == 0) {
            same = 1;
        }
    }



     //king vs king
    if(!N_count && !n_count && !B_count && !b_count && !others_count){
        return 1;
    }
        //king and bishop vs king
    else if(!N_count && !n_count && !others_count && ((!B_count && b_count == 1) || (!b_count && B_count == 1))){
        return 1;
    }
        //king and knight vs king
    else if(!B_count && !b_count && !others_count && ((!N_count && n_count == 1) || (!n_count && N_count == 1))){
        return 1;
    }
        //king and bishop vs king and bishop same color of bishops
    else if(!N_count && !n_count && !others_count && b_count == 1 && B_count == 1 && (same || m)){
        return 1;
    }
    return 0;
}

void load()

{
 FILE *saved=fopen("hi.txt","r");

if(saved==NULL)
{printf("Can`t open file");

}
else
{int data=0,i,j,z=0,turn;
char psuedo_board[64];
fgets(psuedo_board,64,saved);
while(fgetc(saved)!='\n')
    {data++;}
fscanf(saved,"%d",&turn);
//*p=turn;
    for(j=0;j<8;j++)
    {for(i=0;i<8;i++)
    {
    board[i][j]=psuedo_board[z];
     z++;
    }

    }



}
fclose(saved);

}

int isEmpty(int r2, int c2) {
    if(board[r2][c2] == '.' || board[r2][c2] == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
int checkisEmpty(int r2, int c2){
    if(checkboard[r2][c2] == '.' || checkboard[r2][c2] == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
