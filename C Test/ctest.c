#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_ARR_LEN 128


typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    int math;
    int english;
    int history;
} Student;


void print_student(Student* std, int col) {
    switch (col) {
    case 2:
        printf("%d\t%s\t%d\t%d\t%d\t\n", std->age, std->name, std->math, std->english, std->history);
        break;
    case 3:
        printf("%d\t%s\t%d\t%d\t%d\t\n", std->math, std->name, std->age, std->english, std->history);
        break;
    case 4:
        printf("%d\t%s\t%d\t%d\t%d\t\n", std->english, std->name, std->age, std->math, std->history);
        break;
    case 5:
        printf("%d\t%s\t%d\t%d\t%d\t\n", std->history, std->name, std->age, std->math, std->english);
        break;
    default:
        printf("%s\t%d\t%d\t%d\t%d\t\n", std->name, std->age, std->math, std->english, std->history);
    }

    return;
}

void print_data(Student** std_arr, int arr_len, int col) {
    switch (col) {
    case 2:
        printf("No\tAge\tName\tMath\tEnglish\tHistory\n");
        break;
    case 3:
        printf("No\tMath\tName\tAge\tEnglish\tHistory\n");
        break;
    case 4:
        printf("No\tEnglish\tName\tAge\tMath\tHistory\n");
        break;
    case 5:
        printf("No\tHistory\tName\tAge\tMath\tEnglish\n");
        break;
    default:
        printf("No\tName\tAge\tMath\tEnglish\tHistory\n");
    }

    for (int i = 0; i < arr_len; i++) {
        printf("%d\t", i+1);
        print_student(std_arr[i], col);
    }

    printf("\n");
    printf("\n");
}


void sort_arr(Student** arr, int len, int col) {
    Student* tmp;

    if (col == 1) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-1; j++) {
                int cmp = strcmp(arr[i]->name, arr[j]->name);
                if (cmp == -1) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    else if (col == 2) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-1; j++) {
                if (arr[i]->age < arr[j]->age) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    else if (col == 3) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-1; j++) {
                if (arr[i]->math < arr[j]->math) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }else if (col == 4) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-1; j++) {
                if (arr[i]->english < arr[j]->english) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }else if (col == 5) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-1; j++) {
                if (arr[i]->history < arr[j]->history) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
}



int main() {

    int menu;
    int arr_len = 0;

    FILE* fp;
    Student** std_arr = (Student**) malloc (sizeof(Student*)*MAX_ARR_LEN);

    while (1) {
        printf("1) Insert\n");
        printf("2) Sort\n");
        printf("3) Quit\n");
        printf("Select a menu : ");

        scanf("%d", &menu);
        printf("\n");

        // 1) Insert
        if (menu == 1) {
            char file_name[MAX_NAME_LEN];
            printf("File name : ");
            scanf("%s", file_name);

            if ((fp = fopen(file_name, "r")) == NULL) {
                printf("Result : The file cannot be opened. Program terminates.\n");
                return -1;
            }

            // TODO : get data while checking them
            while(1){
                char tmp_chr;
                int tmp_int;
                int cnt_chr;
                int is_break = 0;

                Student* s = (Student*) malloc (sizeof(Student));

                for (int i = 0; i < MAX_NAME_LEN; i++) {
                    (s->name)[i] = 0;
                }

                // get name
                tmp_chr = 0;
                cnt_chr = 0;
                while (1) {
                    tmp_chr = getc(fp);
                    if (tmp_chr == EOF) {
                        is_break = 1;
                        break;
                    }
                    if (tmp_chr == ' ' || tmp_chr == '\t') break;
                    (s->name)[cnt_chr] = tmp_chr;
                    cnt_chr++;
                }
                if (is_break) {
                    break;
                }

                // get age
                fscanf(fp, "%d", &tmp_int);
                if (tmp_int <= 0) {
                    printf("Result : The age cannot be a negative number. Program terminates.\n");
                    return -4;
                }
                else {
                    s->age = tmp_int;
                }


                // get math
                fscanf(fp, "%d", &tmp_int);
                if (tmp_int < 0 || tmp_int > 100) {
                    printf("Result : The scores must be in [0, 100]. Program terminates.\n");
                    return -4;
                }
                else {
                    s->math = tmp_int;
                }

                // get eng
                fscanf(fp, "%d", &tmp_int);
                if (tmp_int < 0 || tmp_int > 100) {
                    printf("Result : The scores must be in [0, 100]. Program terminates.\n");
                    return -4;
                }
                else {
                    s->english = tmp_int;
                }

                // get history
                fscanf(fp, "%d", &tmp_int);
                if (tmp_int < 0 || tmp_int > 100) {
                    printf("Result : The scores must be in [0, 100]. Program terminates.\n");
                    return -4;
                }
                else {
                    s->history = tmp_int;
                }

                std_arr[arr_len] = s;
                arr_len++;

                getc(fp);
            }

            // TODO : print data
            printf("Result :\n");
            printf("No\tName\tAge\tMath\tEnglish\tHistory\n");


            for (int i = 0; i < arr_len; i++) {
                printf("%d\t", i+1);
                print_student(std_arr[i], 0);
            }

            printf("\n");
            printf("\n");

            fclose(fp);

        }

        // 2) Sort
        else if (menu == 2) {

            // TODO : 데이터가 존재하지 않으면 종료하기
            if (arr_len == 0) {
                printf("Result : There is no data to be sorted. Program terminated.\n");
                return -2;
            }

            int col;    // 정렬할 column의 number

            printf("1) Name\n");
            printf("2) Age\n");
            printf("3) Math\n");
            printf("4) English\n");
            printf("5) History\n");
            printf("Choose the field to sort by : ");
            scanf("%d", &col);
            printf("\n");

            switch (col) {
            case 1: case 2: case 3: case 4: case 5:
                // string으로 정렬
                sort_arr(std_arr, arr_len, col);

                printf("Result :\n");
                print_data(std_arr, arr_len, col);
                break;
            default :
                printf("Invalid menu number. Program terminates.\n");
                return -3;
            }

        }

        // 3) Quit
        else if (menu == 3) {
            return 0;
        }

        else {
            printf("Invalid menu number. Program terminates.\n");
            return -3;
        }
    }

    free(std_arr);
    fclose(fp);
    return 0;
}
