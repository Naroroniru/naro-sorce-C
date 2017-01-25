#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int go = 0;
    int user = 1;
    char save;
    char cmd;
    int much = 1;
    int cnt = 4;
    int GetRandom(int min,int max);
    int random = 0;
    int userhp = 10;
    int enemyhp ;
    int enemyrandom = 0;
    int enemy = 0;
    int act;
    int enemyact = 0;
    int dmg ;
    int esc ;
    int result = 0;
    int error;

    printf("ゲームスタート！\n");
    printf("あなたは*です。@を目指して進んでください。\n");
    printf("途中には魔物も出現することがあります。頑張ってください。\n");

    char a[21] = " ___________________"; 
    char b[22] = "|_|_|_|_|_|_|_|_|_|@|";
    char c[22] = "|_|_|_|_|_|_|_|_|_|_|";
    char d[22] = "|_|_|_|_|_|_|_|_|_|_|";
    char e[22] = "|*|_|_|_|_|_|_|_|_|_|";
//  printf("%c\n", a[7]);
  
    char now[2] = "*";
    char goal[2] = "@";

    while(much != 0){

        printf("%s\n", a);
        printf("%s\n", b);
        printf("%s\n", c);
        printf("%s\n", d);
        printf("%s\n", e);

        printf("残HP%d\n",userhp); 
        printf("\n");
        printf("左に進む:1\n");
        printf("右に進む:2\n");
        printf("前に進む:3\n");
        printf("後ろに戻る:4\n\n");
  
        printf("どっちに進め？数字を入力してください。:"); 
        cmd = getchar();
        while (getchar() != '\n');
        go = cmd &0x0f;
        printf("--------------------------------------------------------\n");

    //  printf("%d\n", go);

        if (go == 1){
            if (user - 2 >= 0){
                error = 0;

                if (cnt == 4){
                    save = e[user];
                    e[user] = e[user - 2];
                    user = user - 2;
                    now[0] = e[user];
                    e[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 3){
                    save = d[user];
                    d[user] = d[user -2];
                    user = user - 2;
                    now[0] = d[user];
                    d[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 2){
                    save = c[user];
                    c[user] = c[user - 2];
                    user = user - 2;
                    now[0] = c[user];
                    c[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 1){
                    save = b[user];
                    b[user] = b[user - 2];
                    user = user - 2;
                    now[0] = b[user];
                    b[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 0){
                    save = a[user];
                    a[user] = a[user - 2];
                    user = user - 2;
                    now[0] = a[user];
                    a[user] = save;
                    much = strcmp(now, goal);
                }

            }else if (user - 2 < 0){
                printf("そっちは壁だよ！\n");
                error = 1;
            }

        }else if (go == 2){
            if (user + 2 <= 20){
                error = 0;

                if (cnt == 4){
                    save = e[user];
                    e[user] = e[user + 2];
                    user = user + 2;
                    now[0] = e[user];
                    e[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 3){
                    save = d[user];
                    d[user] = d[user + 2];
                    user = user + 2;
                    now[0] = d[user];
                    d[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 2){
                    save = c[user];
                    c[user] = c[user + 2];
                    user = user + 2;
                    now[0] = c[user];
                    c[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 1){
                    save = b[user];
                    b[user] = b[user + 2];
                    user = user + 2;
                    now[0] = b[user];
                    b[user] = save;
                    much = strcmp(now, goal);
                }else if (cnt == 0){
                    save = a[user];
                    e[user] = a[user + 2];
                    user = user + 2;
                    now[0] = a[user];
                    a[user] = save;
                    much = strcmp(now, goal);
                }
            }else if (user + 2 > 20){
                printf("そっちは壁だよ！\n");
                error = 1;
            }  

        }else if (go == 3){
            error = 0;

            if (cnt == 4){
                save = e[user];
                e[user] = d[user]; 
                now[0] = d[user];
                d[user] = save;
                much = strcmp(now,goal);
                cnt = cnt - 1;
            }else if (cnt == 3){
                save = d[user];
                d[user] = c[user]; 
                now[0] = c[user];
                c[user] = save;
                much = strcmp(now,goal);
                cnt = cnt - 1;
            }else if (cnt == 2){
                save = c[user];
                c[user] = b[user]; 
                now[0] = b[user];
                b[user] = save;
                much = strcmp(now,goal);
                cnt = cnt - 1;
            }else if (cnt == 1){
                printf("そっちは壁だよ！\n");
                error = 1;
            }
        
        }else if (go == 4){
            error = 0;

            if (cnt == 3){
                save = d[user];
                d[user] = e[user]; 
                now[0] = e[user];
                e[user] = save;
                much = strcmp(now,goal);
                cnt = cnt + 1;
            }else if (cnt == 2){
                save = c[user];
                c[user] = d[user]; 
                now[0] = d[user];
                d[user] = save;
                much = strcmp(now,goal);
                cnt = cnt + 1;
            }else if (cnt == 1){
                save = b[user];
                b[user] = c[user]; 
                now[0] = c[user];
                c[user] = save;
                much = strcmp(now,goal);
                cnt = cnt + 1;
            }else if (cnt == 4){
                printf("そっちは壁だよ！\n");
                error = 1; 
            }  
        }else{
            printf("もう一度入力してね！\n");
            error = 1;
        }

    if (error == 0){
        srand((unsigned int)time(NULL));
        random = GetRandom(1,3);

        if (random == 1){
            printf("なにも起きなかった...\n");
        }else if (random == 2){
            printf("休憩した。体力が2回復した。\n");
            userhp = userhp + 2;
        }else if (random == 3){
            enemyrandom = GetRandom(1,3);
            enemy = 1;
            if (enemyrandom == 1){
                printf("スライムが現れた！\n");
                enemyhp = 3;
                enemyact = 1;
            }else if (enemyrandom == 2){
                printf("ゴブリンが現れた！\n");
                enemyhp = 5;
                enemyact = 3;
            }else if (enemyrandom == 3){
                printf("オークが現れた！\n");
                enemyhp = 7;
                enemyact = 5;
            }
        }
        if (enemy == 1){
            while (enemyhp > 0){
                error = 0;
                printf("残HP%d:",userhp); printf("敵残HP%d\n",enemyhp);
                printf("戦う:1\n");
                printf("逃げる:2\n");
                printf("どうする？数字を入力してください。:"); 
                cmd = getchar();
                while (getchar() != '\n');
                act = cmd &0x0f;
                printf("--------------------------------------------------------\n");

                if (act == 1){
                    dmg = GetRandom(1,4);
                    printf("攻撃！敵に%dのダメージ。",dmg);
                    enemyhp = enemyhp - dmg;
                }else if (act == 2){
                    esc = GetRandom(1,2);
                    if (esc == 1){
                        printf("逃げ切れた。\n");
                        break ;
                    }else if (esc == 2){
                        printf("まわり込まれた！\n");
                    }
                }else{
                    printf("もう一度入力してね！\n");
                    error = 1;
                }

                if (error == 0){
                    printf("敵の攻撃！%dのダメージ！！\n",enemyact);
                    userhp = userhp - enemyact;
                }
                printf("--------------------------------------------------------\n");

                if (userhp <= 0){
                    printf("残念！やられてしまった！\n");
                    result = 1;
                    break ;
                }
            } 
            if (result == 1){
                break ;
            }  
            if (act == 1){
                printf("やった！敵を倒した。\n");
            }else if (act == 2){
                printf("次に進もう。\n");
            }
            enemy = 0;
        }
    }
    printf("--------------------------------------------------------\n"); 
  
    }
    if (result == 0){
        printf("おめでとう！クリアしたよ！\n");
    }
    printf("--------------------------------------------------------\n");
    return 0;  
}

int GetRandom(int min,int max)
{
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
