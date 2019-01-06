//
// Created on 2019/1/6.
//

#include <stdio.h>


//藻类种类商法富营养化评价-1:根据复合藻指标

void varyOfAlgae(int green, int drum, int blue, int si, int euglena) {

    double type = (green + blue + si + euglena) * 1.0 / drum;   //水质类型

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

    }


}
