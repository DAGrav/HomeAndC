#include <stdio.h>
#include <inttypes.h>
#include <math.h>
int32_t scales (uint32_t weight)
{
    if ((weight > 1000000) || (weight <= 0))
        return -1;
    int32_t w_counter = 0;
    uint32_t cur_weight = weight, all_weight = 0;
    while (cur_weight > 0) {
        int32_t remain = cur_weight % 3;
        if (remain < 1) {
            cur_weight /= 3;
        } else if (remain > 1) {
            w_counter++;
            cur_weight = cur_weight / 3 + 1;
            if (pow(3, all_weight) > 1000000)
                return -1;
        } else {
            w_counter++;
            cur_weight = cur_weight  / 3;
            if (pow(3, all_weight) > 1000000)
                return -1;
        }
        all_weight++;
    }
    return w_counter;
}

int main(void)
{
    uint32_t digit = 0;
    scanf( "%du", &digit );
    printf("%d\n", scales(digit));
    return 0;
}
