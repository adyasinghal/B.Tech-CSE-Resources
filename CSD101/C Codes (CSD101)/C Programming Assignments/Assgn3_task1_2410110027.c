#include<stdio.h>




int main()
              {
               float mbmi;
               float hbmi;
               float cbmi;
               float ibmi;
               float addm_h;
               float addc_i;


               printf("Enter Mohan's BMI: ");
               scanf("%f" , &mbmi) ;
               printf("Enter Hari's's BMI: ");
               scanf("%f" , &hbmi) ;
               printf("Enter Charu's BMI: ");
               scanf("%f" , &cbmi) ;
               printf("Enter Ishika's BMI: ");
               scanf("%f" , &ibmi) ;
               addm_h = (mbmi+hbmi);
               addc_i = (cbmi+ibmi);
               printf("The comparison score for > operator is %d\n" , (addm_h>addc_i));
               printf("The comparison score for = operator is %d\n" , (addm_h==addc_i));
               printf("The comparison score for < operator is %d\n" , (addm_h<addc_i));

}
