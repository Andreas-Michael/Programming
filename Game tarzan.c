#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void epipedo(int epi, int N, int M, char** p);
void print(int n,int m, char **p);                                            //tupwnei ton pinaka
void putChar(int N, int M, char** p, int times, char charSymbol);
void copyTarzan(int N, int M, char** from, char** to);
char moveTarzan(char** p, char **h, int x1, int y1, int x2, int y2);
void del(char** t, int n);

int main() {
    srand(time(NULL));
    int i=0,j, k, s,m,n,epi, l, sosto, x, y, z, sc, tsc=0;                    //epi= epipedo
    char **p, **h, pex[50], kin[50], a;

    srand(time(NULL));


    printf("DWSE TIS ARXIKES DIASTASIS TOY TAMPLO NxM (max 30x30): \n");
    scanf("%d%d",&n,&m);
    while(n>30||n<1){                                                       //edw kano elenxo TON DIASTASEON TU PINAKA
        printf("DWSE DIASTASI N apo 1-30: \n");
        scanf("%d",&n);
    }
    while (m>30||m<1){                                                      //edw kano elenxo TON DIASTASEON TU PINAKA
        printf("DWSE DIASTASIS M apo 1-30: \n");
        scanf("%d",&m);
    }

    printf("DWSE TO ONOMA TU PEXTI: \n");
    scanf("%s",pex);

    printf("DIALEKSE EPIPEDO DISKOLIAS: EUKOLO=1 METRIO=2 DISKOLO=3 AKATORTHOTO=4\n");
    scanf("%d",&epi);

    do{

        p=(char**)malloc(n*sizeof(char*));
        if(p==NULL){
            printf("\n DEN IPARXI DIATHESIMI MNIMI!! \n");
            exit(0);
        }

        for(i=0;i<n;i++){
            p[i]=(char*)malloc(m*sizeof(char));
            if(p[i]==NULL){
                printf("\n DEN IPARXI DIATHESIMI MNIMI!!\n");
                exit(0);
            }
        }



        for(i=0; i <n; i++ ) {
            for(k=0;k<m;k++){
                p[i][k]='.';

            }
        }


        h=(char**)malloc(n*sizeof(char*));
        if(h==NULL){
            printf("\n DEN IPARXI DIATHESIMI MNIMI!! \n");
            exit(0);
        }

        for(i=0;i<n;i++){
            h[i]=(char*)malloc(m*sizeof(char));
            if(h[i]==NULL){
                printf("\n DEN IPARXI DIATHESIMI MNIMI!!\n");
                exit(0);
            }
        }
        for(i=0; i <n; i++ ) {
            for(k=0;k<m;k++){
                h[i][k]='#';

            }
        }


        z = 0;


        epipedo(epi, n, m, p);
        copyTarzan(n, m, p, h);

        print(n, m , p);
        printf("Player %s press a key when ready\n", pex);
        fflush(stdin);                                              //flush an output stream
        getchar();

        sc = 1000;                                                  //sc=score


        do{
            print(n, m, h);
            printf("Player %s make your move(s)\n", pex);
            scanf("%s", kin);

            l = strlen(kin);
            sosto = 1;
            for (i = 0 ; i < l ; i++){
                if (kin[i] != 'D' && kin[i] != 'U' && kin[i] != 'L' && kin[i] != 'R' && kin[i] != 'H' && kin[i] != 'X' &&
                    kin[i] != 'd' && kin[i] != 'u' && kin[i] != 'l' && kin[i] != 'r' && kin[i] != 'h' && kin[i] != 'x')
                {
                    printf("Wrong instruction %c\n", kin[i]);
                    sosto = 0;
                }
            }

            if (sosto == 1){
                                                                        // pou einai o tarzan?
                for (i = 0 ; i < n ; i++)
                    for (j = 0 ; j < m ; j++)
                        if (p[i][j] == 'T' || p[i][j] == '@'){
                            x = i;
                            y = j;
                        }

                for (i = 0 ; i < l ; i++){
                    if (kin[i] == 'D' || kin[i]    == 'd'){
                                                                    // an einai sta oria tou pinaka i an i nea thesi einai anoikti
                        if (x == n - 1 || h[x+1][y] != '#'){
                            printf("Tarzan cannot move!\n");
                            a = 'B';
                            break;
                        }
                        else {
                            a = moveTarzan(p, h, x, y, x+1, y);
                            x++;
                        }
                    }
                    else if (kin[i] == 'U' || kin[i] == 'u'){
                                                                        // an einai sta oria tou pinaka i an i nea thesi einai anoikti
                        if (x == 0 || h[x-1][y] != '#'){
                            printf("Tarzan cannot move!\n");
                            a = 'B'; // B opos break
                            break;
                        }
                        else {
                            a = moveTarzan(p, h, x, y, x-1, y);
                            x--;
                        }
                    }
                    else if (kin[i] == 'L' || kin[i]== 'l'){
                                                                        // an einai sta oria tou pinaka i an i nea thesi einai anoikti
                        if (y == 0 || h[x][y-1] != '#'){
                            printf("Tarzan cannot move!\n");
                            a = 'B';
                            break;
                        }
                        else {
                            a = moveTarzan(p, h, x, y, x, y-1);
                            y--;
                        }
                    }
                    else if (kin[i] == 'R' || kin[i] == 'r'){
                                                                        // an einai sta oria tou pinaka i an i nea thesi einai anoikti
                        if (y == m - 1 || h[x][y+1] != '#'){
                            printf("Tarzan cannot move!\n");
                            a = 'B';
                            break;
                        }
                        else {
                            a = moveTarzan(p, h, x, y, x, y+1);
                            y++;
                        }
                    }
                    else if (kin[i] == 'X' || kin[i] == 'x'){
                        a = 'X';
                        break;
                    }
                                                                            // telika pou pige o tarzan?
                    if (a == 'Z'){
                        z++;
                        if (z == 1){
                            printf("Tarzan injured!\n");
                        }
                        else {
                            printf("Tarzan killed by zulu!\n");
                            a = 'L';
                            break;
                        }

                    }
                    else if (a == 'L'){
                        printf("Tarzan eaten by lion!\n");
                        break;
                    }
                    else if (a == 'B'){
                        break;
                    }
                    else if (a == 'J'){
                        printf("Tarzan is with Jane!\n");
                        break;
                    }
                }
                if (a != 'B' && a != 'L' && a != 'X') sc -= 150 / (i+1);
            }
        }while(a != 'J' && a != 'L' && kin[i] != 'X' && kin[i] != 'x');

        del(h, n);
        del(p, n);

        if (a == 'J'){
            i = rand() % 2;
            if (i == 0) n++;
            else m++;
            if (sc > 0) tsc += sc;
            printf("Score: %d\n", sc);
        }

    }while(a == 'J');
    printf("Total score: %d\n", tsc);
    scanf("%s", kin);


    return 0;
}
void del(char** t, int n){
    int i;

    for (i = 0 ; i < n ; i++){
        free(t[i]);
    }

    free(t);
}
char moveTarzan(char** p, char **h, int x1, int y1, int x2, int y2){
    char a = p[x2][y2];

                                            // diagrafi apo palia thesi
    if (p[x1][y1] == '@'){
        h[x1][y1] = p[x1][y1] = 'Z';
    }
    else {
        h[x1][y1] = p[x1][y1] = '.';
    }


                                            // topothetisi se nea thesi
    if (p[x2][y2] == '.'){
        h[x2][y2] = p[x2][y2] = 'T';
    }
    else if (p[x2][y2] == 'Z'){
        h[x2][y2] = p[x2][y2] = '@';
    }
    else if (p[x2][y2] == 'L'){
        h[x2][y2] = p[x2][y2] = 'D';            // D opos dead!
    }
    else if (p[x2][y2] == 'J'){
        h[x2][y2] = p[x2][y2] = 'H';            // H opos happy!
    }

    return a;
}
void print(int n,int m, char **p){
    int i, j;

    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < m ; j++)
            printf("%c ", p[i][j]);
        printf("\n");
    }
}
void copyTarzan(int N, int M, char** from, char** to){
    int i, j;

    for (i = 0 ; i < N ; i++)
        for (j = 0 ; j < M ; j++)
            if (from[i][j] == 'T')
                to[i][j] = 'T';
}
void epipedo(int epi, int N, int M, char** p){
    int L,Z;

    switch(epi)
    {
    case 1:                     // TO POSOSTO TWN LIODARIWN EINAI 2%
        L=(M*N)*0.02;
        Z=(L/2)+L;
        break;
    case 2:                     // TO POSOSTO TWN LIODARIWN EINAI 5%
        L=(M*N)*0.05;
        Z=(L/2)+L;
        break;
    case 3:                     // TO POSOSTO TWN LIODARIWN EINAI 10%
        L=(M*N)*0.1;
        Z=(L/2)+L;
        break;
    case 4:                     // TO POSOSTO TWN LIODARIWN EINAI 20%
        L=(M*N)*0.2;
        Z=(L/2)+L;
        break;
    default:
        printf("O aritmos pou dwsate den antistoixei se epipedo duskolias\n");
        L=(M*N)*0.02;
        Z=(L/2)+L;
        break;
    }

    putChar(N, M, p, Z, 'Z');
    putChar(N, M, p, L, 'L');
    putChar(N, M, p, 1, 'J');
    putChar(N, M, p, 1, 'T');
}

void putChar(int N, int M, char** p, int times, char charSymbol){
    int i, x, y;

    i = 0;
    while (i < times){
        x = rand() % N;
        y = rand() % M;
        if (p[x][y]=='.'){
            p[x][y]=charSymbol;
            i++;
        }
    }
}
