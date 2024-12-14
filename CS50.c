#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* This program calculates BMI ( body mass index). Allows user to insert their names, height and weight*/
typedef struct{
	char institution[100];
	char fname[20];
	char lname[20];
}Medicalcare;
float IndexCalculate(float w,float h)
{
	float bmi=w/(h*h);
	return bmi;
}
main(){
	float weight, height, bmi;
	char Range[][20]={"THIN","HEALTHY","OVERWEIGHT","OBESE"};
	Medicalcare child;
	strcpy( child.institution," NOTES CLINIQUE\n  Better services for better life");

	printf("  ENTER INFORMATIONS REQUIRED \n");
	printf("Enter your first name : ");
	scanf("%s",&child.fname);
	
	//conversion of all characters in fname to upper case

for( int i=0; child.fname[i]!='\0'; i++)
      {
	child.fname[i]=toupper(child.fname[i]);
         }
	printf("Enter your last name : ");
	scanf("%s",&child.lname);
//Conversion of first character of lname to upper case and the rest to lower case
	child.lname[0]= toupper(child.lname[0]);
	for( int i=1; child.lname[i]!='\0'; i++)
      {
	child.lname[i]=tolower(child.lname[i]);
         }
	printf("Enter your height in centimeters : ");
	scanf("%f",&height);
	if(height<=0) //validation of height
    {
           printf(" INVALID HEIGHT\n THE HEIGHT OF A NORMAL PERSON SHOULD BE A NUMBER GREATER                       THAN ZERO.");
        return 0;    
    }
	printf("Enter your weight in grams : ");
	scanf("%f",&weight);
	if(weight<=0) //validation of weight
    {
       printf(" INVALID WEIGHT\n WEIGHT OF A NORMAL PERSON SHOULD BE A NUMBER GREATER THAN ZERO.");
        return 0; 
     }
    height/=100;
	weight/=1000;
	
	printf(" %s\n\n",child.institution);
	printf(" %s %s\n",child.fname, child.lname);
	printf(" Height : %.2f m\n",height);
	printf(" weight : %.2f kg\n",weight);
	
	bmi=IndexCalculate(weight, height);
	printf(" BMI : %.2f\n",bmi);
	// condition to display the range of BMI using pointers.
	if(bmi<18.6){
		printf(" Your BMI is considered as %s",*Range);
	}else if(bmi<25){
		printf(" Your BMI is considered as %s",*(Range+1));
	}else if(bmi<30){
		printf(" Your BMI is considered as %s",*(Range+2));
	}else{
		printf(" Your BMI is considered as %s",*(Range+3));
	}
	return 0;
}

