
#include <stdio.h>
#include <math.h>

//藻类种类商法富营养化评价-1:根据复合藻指标

void varyOfAlgae(double green, double drum, double blue, double si, double euglena) {

    double type = (green + blue + si + euglena)  / drum;   //水质类型

    if (type > 0 && type < 1) {
        printf("根据复合藻类指标判断该水体属于贫营养型\n");
    } else if (type >= 1 && type < 2.5) {
        printf("根据复合藻类指标判断该水体属于弱富营养型\n");

    } else if (type >= 3 && type < 5) {
        printf("根据复合藻类指标判断该水体属于中度富营养型\n");

    } else if (type >= 5 && type < 20) {
        printf("根据复合藻类指标判断该水体属于重度富营养型\n");

    } else if (type >= 20 && type < 43) {
        printf("根据复合藻类指标判断该水体属于重富营养型\n");

    }else {
        printf("无效的输入值\n");
    }


}

//藻类种类商法富营养化评价-2:根据绿藻指标
void varyOfGr(double green, double drum) {
    double type = green * 1.0 / drum;
    if (type >= 0 && type < 1) {
        printf("根据绿藻类指标判断该水体属于贫营养型\n");
    } else if (type >= 1 && type < 5) {
        printf("根据绿藻类指标判断该水体属于富营养型\n");
    } else if (type >= 5 && type < 15) {
        printf("根据绿藻类指标判断该水体属于重度营养型\n");
    } else {
        printf("无效的输入值\n");
    }
}

//营养负荷法
void vollenweider(double P,double Rp) {
    double Pp = P * (1 - Rp) ; // 湖泊年均浓度
    if (Pp >= 0 && Pp < 1) {

        printf("根据湖泊年均磷浓度指标判断该水体属于贫营养型\n");
    } else if (Pp >= 1 && Pp < 5) {

        printf("根据湖泊年均磷浓度指标判断该水体属于中营养型（前期）\n");
    } else if (Pp >= 5 && Pp < 10) {

        printf("根据湖泊年均磷浓度指标判断该水体属于中营养型（后期）\n");

    } else if (Pp >= 20 && Pp < 50) {

        printf("根据湖泊年均磷浓度指标判断该水体属于富营养型\n");
    } else if (Pp >= 50 ) {

        printf("根据湖泊年均磷浓度指标判断该水体属于重度营养型\n");
    }else {
        printf("无效的输入值\n");
    }

}


//营养状况指数法
void carlson(double TP) {
    double TSI = 9.81 * (1.449 * log(TP) - 2.616) + 30.6;   //TSI指标
    if (TSI < 37) {
        printf("根据营养状况指数法判断该水体属于贫营养型\n");
    } else if (TSI >= 38 && TSI <= 50) {

        printf("根据营养状况指数法判断该水体属于中营养型\n");
    } else if (TSI > 54 ) {

        printf("根据营养状况指数法判断该水体属于富营养型\n");

    }else {
        printf("无效的输入值\n");
    }
}


int main() {
    int choice = 1;
    double green, drum, blue, si, euglena, P, Rp, TP;
    printf("=========================水体富营养化评价=================================\n1, 根据复合藻类指标判断\n2, 根据绿藻类指标判断\n3, 根据营养复合法判断\n4, 根据营养状况指数法判断\n====================================================================\n请输入您的选择");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1:
            printf("请输入绿藻种数： ");
            scanf(" %lf", &green);
            printf("请输入鼓藻种数： ");
            scanf(" %lf", &drum);
            printf("请输入蓝藻种数： ");
            scanf(" %lf", &blue);
            printf("请输入硅藻种数： ");
            scanf(" %lf", &si);
            printf("请输入裸藻种数： ");
            scanf(" %lf", &euglena);
            varyOfAlgae(green, drum, blue, si, euglena);
            break;
        case 2:
            printf("请输入绿藻种数： ");
            scanf("%lf", &green);
            printf("请输入鼓藻种数： ");
            scanf("%lf", &drum);
            varyOfGr(green, drum);
            break;
        case 3:
            printf("请输入年均输入磷浓度(ug/L)： ");
            scanf("%lf", &P);
            printf("请输入年输入磷沉积率： ");
            scanf("%lf", &Rp);
            vollenweider(P, Rp);
            break;
        case 4:
            printf("请输入总磷浓度（mg/M3）： ");
            scanf("%lf", &TP);
            carlson(TP);
            break;

        default:
            printf("无效选择\n");
            break;
    }
    return 0;
}