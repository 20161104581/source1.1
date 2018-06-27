//
//  main.c
//  source
//
//  Created by 20161104581 on 18/6/26.
//  Copyright © 2018年 20161104581. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#define Total 5

struct People {
    int ID;
    char sex[5];
    int number;
    char jiemu;
    char name[20];
    double score[5];
    double final_score;
    int rank;
} people[Total];


struct Rater {
    int Rater_ID;
    int Rater_number;
    char Rater_name[20];
    char Rater_sex;
    double Rater_score[5];
        int rank;
} Rater[Total];


void inputInfo()
{
    printf("请输入选手信息:\n");
    for (int i = 0; i < Total; i ++) {
        scanf("%d", &people[i].ID);
        getchar();
        scanf("%s", people[i].name);
        scanf("%s", people[i].sex);
        scanf("%d", &people[i].number);
        scanf("%lf", &people[i].score[0]);
        scanf("%lf", &people[i].score[1]);
        scanf("%lf", &people[i].score[2]);
        scanf("%lf", &people[i].score[3]);
        scanf("%lf", &people[i].score[4]);
        people[i].final_score = 0.0;
        people[i].rank = i + 1;
    }
}


void inputInfoRater()
{
    printf("请输入裁判信息:\n");
    for (int i = 0; i < Total; i ++) {
        scanf("%d", &Rater[i].Rater_ID);
        getchar();
        scanf("%s", Rater[i].Rater_name);
        scanf("%d", &Rater[i].Rater_number);
       
    }
}


void calculateScore()
{
    for (int i = 0; i < Total; i ++) {
        double max = people[i].score[0];
        double min = people[i].score[0];
        for (int j = 0; j < 5; j ++) {
            people[i].final_score += people[i].score[j];
            if (people[i].score[j] > max)
                max = people[i].score[j];
            if (people[i].score[j] < min)
                min = people[i].score[j];
        }
        people[i].final_score = people[i].final_score - max - min;
        people[i].final_score /= 3;
    }
    printf("分数计算成功!\n");
}

void sort()
{
    calculateScore();
    for (int i = 0; i < Total - 1; i ++) {
        for (int j = 0; j < Total - 1 - i; j ++) {
            if (people[j].final_score < people[j + 1].final_score && people[j].rank < people[j + 1].rank) {
                struct People tmp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = tmp;
                people[j].rank = j + 1;
                people[j + 1].rank = j + 2;
            }
            if (people[j].final_score > people[j + 1].final_score && people[j].rank > people[j + 1].rank) {
                struct People tmp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = tmp;
                people[j].rank = j + 1;
                people[j + 1].rank = j + 2;
            }
        }
    }
    printf("排序成功!\n");
}

void searchByID()
{
    int ID;
    printf("请输入id:");
    scanf("%d", &ID);
    for (int i = 0; i < Total; i ++) {
        if (people[i].ID == ID) {
            printf("-----------------------------------------\n");
            printf("--  你要查找的人 No.%d     \n", ID);
            printf("--  最终分数: %.2lf            \n", people[i].final_score);
            printf("--  排名为: %d                      \n", people[i].rank);
            printf("-----------------------------------------\n");
            return;
            
        }
    }
}
void searchByName()
{
    char name[20];
    printf("请输入姓名:");
    scanf("%s", name);
    for (int i = 0; i < Total; i ++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("-----------------------------------------------\n");
            printf("--  你要查找的人: %s       \n", name);
            printf("--  最终分数: %.2lf            \n", people[i].final_score);
            printf("--  排名为: %d                      \n", people[i].rank);
            printf("-----------------------------------------------\n");
            return;
            
        }
    }
    
}

void quertPeople()
{
    int choice;
    printf("根据姓名查找还是编号查找? 0-ID,1-name:");
    scanf("%d", &choice);
    if (choice == 0)
        searchByID();
    if (choice == 1)
        searchByName();
}

void menu()
{
    printf("-------------------------------------------------\n");
    printf("--  1 - 输入选手信息                             --\n");
    printf("--  2 - 输入裁判信息                             --\n");
    printf("--  3 - 计算分数并排序数据  --\n");
    printf("--  4 - 查询选手                     --\n");
    printf("--  0 - 退出                                  --\n");
    printf("-------------------------------------------------\n");
    
}

int main() {
    int choice;
    menu();
    scanf("%d", &choice);
    while (choice != 0){
        switch (choice) {
            case 1:
                inputInfo();
                break;
            case 2:
                inputInfoRater();
                break;
            case 3:
                sort();
                break;
            case 4:
                quertPeople();
                break;
            default:
                break;
        }
        menu();
        scanf("%d", &choice);
    }
    return 0;
}
