#include <stdio.h>
#define MINUTE 60 /*Number of minutes in an hour */
#define M_Liter 1000 
#define SENTINEL 5


int get_problem(void);
double get_n_nhours(double num_hours); /*To be completed */
void get_rate_drop_factor(double * /*pointers */, double * /*pointers */);
void get_kg_rate_conc(double *, double *, double *);
void get_units_conc(double *, double *);
double fig_drops_min(double ,double );
double fig_ml_hr(double );
double by_weight(double,double, double);
double by_units(double, double);

int main(void) {
  int value;
  double answer;
  double ml_hour;
  double drops_ml;
  double mg_kg_hour;
  double pat_weight;
  double mg_ml;
  double units_hour;
  double units_ml;
  double num_hours;
  value = get_problem();
  while(value !=SENTINEL){
    switch (value){
      case 1:
      /* ml/hr & tubing drop factor 8 */
      /* drops/min */
      fig_drops_min(ml_hour,drops_ml);
      printf("\n");
      break;
      case 2:
      /* 1 L for n hr */
      /* ml/hr */
      fig_ml_hr(num_hours);
      printf("\n");

      break;
      case 3:
      by_weight(mg_kg_hour, pat_weight, mg_ml);
      printf("\n");
      break;
      case 4:
      by_units(units_hour, units_ml);
      printf("\n");
      break;
      case 5:
      printf("Program will be terminated");
      break;
      /* uses the variables declared within the main() program and the given function prototypes,complete the body of the switch statement */
      default:
      printf("Wrong input. \n");
    }
    value = get_problem();
  }
  return 0;
}

/* function that displays menu and gets user's input */
int get_problem(void){
  int menu_number;
   printf("Enter the number of the problem you wish to solve.\n");
  printf("\tGiven A MEDICAL ORDER IN\t\t\t\t\tCALCULATE RATE IN\n");
  printf("\t(1) ml/hr & tubing drop factor\t\t\t\tdrops / min\n");
  printf("\t(2) 1 L for n hr\t\t\t\t\t\t\tml / ht\n");
  printf("\t(3) mg/kg/hr & concentration in units/ml\tml / hr\n");
  printf("\t(4) units/hr & concentration in units/ml\tml / hr\n");
  printf("\t(5) QUIT\n");
  printf("Response: ");
  scanf("%d", &menu_number);
  return (menu_number);
}

/*function to get the number of hours */
double get_n_hours(double num_hours){
  printf("Please enter the number of hours for one liter: ");
  scanf("%lf", &num_hours);
  return num_hours;
}

/* function prompts the user to enter rate and tubing's drop factor then returns values through output parameters */
void get_rate_drop_factor(double *ml_hour, double *drops_ml){
  printf("Please enter the drop rate in ml/hour and the Tubing Factor in drops/ml \n[Seperate each entry with the 'spacebar' key then press the 'enter' key to submit entries]: ");
  scanf("%lf %lf",ml_hour, drops_ml);
}

/* function prompts for rate, patients weight, and concentration then retunrs values through output parameters */
void get_kg_rate_conc(double *mg_kg_hour, double *pat_weight, double *mg_ml){
  printf("Please enter the rate in mg/kg/hr, the patient weight in kg and concentration in mg/ml \n[Separate each entry with the 'spacebar' key then press the 'enter' key to submit entries]: ");
  scanf("%lf %lf %lf", mg_kg_hour, pat_weight, mg_ml);
}

/* function prompts for rate and concentration then returns values through output parameters */
void get_units_conc(double *units_hour, double *units_ml){
  printf("Please enter the rate in units/hour and the concentration in units/ml \n[Separate each entry with the 'spacebar' key then press the 'enter' key to submit entries]: ");
  scanf("%lf %lf", units_hour, units_ml);
}

/* function takes as input rate and concentration then returns as its value the result of dividing their product by MINUTE */
double fig_drops_min(double ml_hour, double drops_ml){
  get_rate_drop_factor(&ml_hour, &drops_ml);
  double answer = (ml_hour*drops_ml)/MINUTE;
  printf("The drop rate per minute is %2.lf. \n", answer);
  return answer;
}

/* function takes as input num_hours and retunrs as its value the quotient of *100 and num_hours */
double fig_ml_hr(double num_hours){
  double answer = M_Liter/get_n_hours(num_hours);
  printf("The rate in ml per hour is %2.lf. \n", answer);
  return answer;
}

/* function takes 3 inputs and retunrs as its value the product of rate and patient's weight divided by concentration */
double by_weight(double mg_kg_hr, double pat_weight, double mg_ml){
  get_kg_rate_conc(&mg_kg_hr, &pat_weight, &mg_ml);
  double answer = (mg_kg_hr*pat_weight*mg_ml);
  printf("\nThe rate in milliliters per hour is %2.lf. \n",answer);
  return answer;
}

/* function takes 2 inputs and returns as its value the quotient of units_hr and units_ml*/
double by_units(double units_hour, double units_ml){
  get_units_conc(&units_hour,  &units_ml);
  double answer = (units_hour/units_ml);
  printf("\nThe rate in milliliters per hour is %2.lf. \n",answer);
  return answer;
}